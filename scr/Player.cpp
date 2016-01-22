#include <QtWidgets>

#include "player.h"
#include "playercontrols.h"
#include "ChangeCameraPositionControls.h"
#include "SequenceView.h"
#include "CameraViewSettings.h"

#include "testUI.h"

void updateCurrentViewLabel(int);

Player::Player(QString rootDir, QWidget *parent) : QWidget(parent)
{
	int a = 2;

	if (a == 1) {
		Ui::Form::Ui_Form ui;
		ui.setupUi(this);
		//connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(fitToWindow(bool)));
	}
	else {

	// Sets the path to the project settings file from the command line arguments
	setProjectRootDir(rootDir);

		currentFrameNumber = 0;
		this->setLastValidStepFrameNumber(0);
	
		fitCheckBox = new QCheckBox("Scale");
		fitCheckBox->setChecked(false);

		speedLabel = new QLabel(tr("Speed: "));
		speedSpinBox = new QSpinBox();
		speedSpinBox->setRange(1, 500);
		speedSpinBox->setValue(100);
		speedSpinBox->setSuffix(tr("%"));
		speedSpinBox->setMaximumWidth(150);

		QBoxLayout *speedFitLayout = new QHBoxLayout;
		speedFitLayout->addWidget(fitCheckBox);
		speedFitLayout->addWidget(speedLabel);
		speedFitLayout->addWidget(speedSpinBox);

		movieLabel = new QLabel(tr("No animation loaded"));
		movieLabel->setAlignment(Qt::AlignCenter);
		movieLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		movieLabel->setBackgroundRole(QPalette::Dark);
		movieLabel->setAutoFillBackground(true);

		movie = new QMovie(this);
		movie->setCacheMode(QMovie::CacheAll);
	
		cameraPositionControls = new CameraPositionControls(this);
		QBoxLayout *cameraControlsLayout = new QHBoxLayout;
		cameraControlsLayout->addWidget(cameraPositionControls);


		controls = new PlayerControls(this);
		controls->setState(movie->state());
		connect(controls, SIGNAL(stateChanged(QMediaPlayer::State)), controls, SLOT(setState(QMediaPlayer::State)));

		QBoxLayout *controlsLayout = new QHBoxLayout;
		controlsLayout->addWidget(controls);

		connect(cameraPositionControls, SIGNAL(changeCameraPosition(int)), this, SLOT(changeCameraEvent(int)));
		connect(cameraPositionControls, SIGNAL(chomboBoxVCChanged(int)), this, SLOT(chomboBoxVCChangedEvent(int)));
		connect(fitCheckBox, SIGNAL(clicked(bool)), this, SLOT(fitToWindow(bool)));

		frameSlider = new QSlider(Qt::Horizontal);
		frameSlider->setTickPosition(QSlider::TicksBelow);
		frameSlider->setTickInterval(1);
	
		mainLayout = new QVBoxLayout;
		mainLayout->addWidget(movieLabel, 2);
		mainLayout->addWidget(frameSlider);
		mainLayout->addLayout(controlsLayout);
		mainLayout->addLayout(speedFitLayout);
	
		mainLayout->addLayout(cameraControlsLayout);
		setLayout(mainLayout);

		SequenceView *sequenceWindow = new SequenceView();
		sequenceWindow->show();

		connect(sequenceWindow, SIGNAL(changeSequence(int)), this, SLOT(sequenceChangedEvent(int)));
		connect(controls, SIGNAL(play()), movie, SLOT(start()));
		connect(controls, SIGNAL(stop()), movie, SLOT(stop()));
		connect(controls, SIGNAL(setPaused1(bool)), movie, SLOT(setPaused(bool)));
		connect(movie, SIGNAL(frameChanged(int)), this, SLOT(updateFrameSlider()));
		connect(frameSlider, SIGNAL(valueChanged(int)), this, SLOT(goToFrame(int)));
		connect(controls, SIGNAL(stop()), this, SLOT(stopClicked()));
		connect(controls, SIGNAL(begin()), this, SLOT(beginClicked()));
		connect(controls, SIGNAL(end()), this, SLOT(endClicked()));
		connect(controls, SIGNAL(nextFrame()), this, SLOT(nextFrameClicked()));
		connect(controls, SIGNAL(previousFrame()), this, SLOT(previousFrameClicked()));
		connect(speedSpinBox, SIGNAL(valueChanged(int)), movie, SLOT(setSpeed(int)));
		connect(movie, SIGNAL(stateChanged(QMovie::MovieState)), controls, SLOT(setState(QMovie::MovieState)));

		setWindowTitle(tr("Sequence Player"));
		resize(400, 400);

	
		//videoUtils = new LoadVideoUtils();
		//videoUtils->setGlobalProjectSettings();
		
	

		cameraViewSettings = new CameraViewSettings();
		//cameraViewSettings->setPerspectiveCameraImagesList();

		QString currentView = tr("[ Perspective Camera ]");
		currentViewLabel = new QLabel((currentView));
		mainLayout->addWidget(currentViewLabel);

		// Load global project settings
		videoUtils = new LoadVideoUtils();
		videoUtils->setProjDirFromArgIn(projectRootDir);
		bool settingsOK = videoUtils->setGlobalProjectSettings();
		if (!settingsOK) {
			qDebug() << "Can not read setting!";
			movieLabel->setText("Warning: Can not read project settings!");
			return;
		}
		else {
			projectSettings = videoUtils->getGlobalProjectSettings();
			
			// Load the images from different views
			// Start player
			initializeCameraViewImageLists();
			playerSetStartConfiguration();
			movie->start();
		}

		
	}
}

void Player::setProjectRootDir(QString path) {
	projectRootDir = path;
}
void Player::setLastValidStepFrameNumber(int number)
{
	this->lastValidStepFrameNumber = number;
}

int Player::getLastValidStepFrameNumber()
{
	return this->lastValidStepFrameNumber;
}

int Player::getCurrentFrameNumber()
{
	return currentFrameNumber;
}

int Player::getTotalFrameNumber() {
	return this->totalFrameNumber-1;
}

void Player::setTotalFrameNumber(int number) {
	this->totalFrameNumber = number;
}

void Player::fitToWindow(bool state)
{
	qDebug() << "dsdsdsds";
	movieLabel->setScaledContents(state);
}

void Player::updateFrameSlider()
{
	bool hasFrames = (movie->currentFrameNumber() >= 0);

	if (hasFrames == true) {
		if (movie->frameCount() > 0) {
			frameSlider->setMaximum(movie->frameCount() - 1);
		}
		else {
			if (movie->currentFrameNumber() > frameSlider->maximum())
				frameSlider->setMaximum(movie->currentFrameNumber());
		}
		frameSlider->setValue(movie->currentFrameNumber());
	}
	else {
		frameSlider->setMaximum(0);
	}

	frameSlider->setEnabled(hasFrames);
}

void Player::goToFrame(int frame)
{
	movie->jumpToFrame(frame);
	setCurrentFrameNumber(frame);
	qDebug() << "Frame:" << frame << " - [ " << movie->fileName() << " ]";
}


void Player::setCurrentFrameNumber(int frame) {
	this->currentFrameNumber = frame;
}

void Player::openFileSequence(const QString &fileName)
{
	// check if file exists
	if (QFile::exists(fileName)) {

		bool paused = false;
		bool stoped = false;
		bool jumpToFrame = false;
	
		switch (controls->state()) {
			case QMovie::Running:
				break;
			case QMovie::NotRunning:
				stoped = true;
				break;
			case QMovie::Paused:
				paused = true;
				jumpToFrame = true;
				oldFrameNumber = getCurrentFrameNumber();
			default:
				break;
		}

		movie->stop();
		movieLabel->setMovie(movie);
		movie->setFileName(fileName);
		movie->start();
	
		if (paused == true) {
			movie->setPaused(true);
		}

		if (jumpToFrame == true) {
			movie->jumpToFrame(oldFrameNumber);
		}

		if (stoped) {
			movie->start();
		}

		this->setTotalFrameNumber(movie->frameCount());

	}

	else {
		movieLabel->setText(Player::FILE_NOT_AVAILABLE);
	}

}

void Player::beginClicked()
{
	goToFrame(0);
	this->setLastValidStepFrameNumber(0);
}

void Player::stopClicked()
{
	goToFrame(0);
}

void Player::nextFrameClicked()
{
	int nextFrame = getCurrentFrameNumber() + 1;
	if (nextFrame <= getTotalFrameNumber()) {
		goToFrame(nextFrame);
		this->setLastValidStepFrameNumber(nextFrame);
		
	} 
	else {
		//goToFrame(0);
	}
	
}

void Player::previousFrameClicked()
{
	//q//Debug() << "PREVIOUS FRAME";
	int nextFrame = getCurrentFrameNumber() - 1;
	if (nextFrame >= 0) {
		goToFrame(nextFrame);
		this->setLastValidStepFrameNumber(nextFrame);
	}
	else {
		//goToFrame(0);
	}
}

void Player::endClicked()
{
	goToFrame(this->getTotalFrameNumber());
	this->setLastValidStepFrameNumber(this->getTotalFrameNumber());
}

void Player::changeCameraEvent(int num)
{
	oldFrameNumber = getCurrentFrameNumber();
	int changeToCamera;
	//qDebug() << "CHANGW CAMERA!" << num;
	switch (num)
	{
		case CameraPositionControls::PERSPECTIVE_CAMERA:
			changeToCamera = CameraPositionControls::PERSPECTIVE_CAMERA;
			cameraPositionControls->enableViewCubeComboBox(false);
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_FRONT:
			cameraPositionControls->enableViewCubeComboBox(true);
			changeToCamera = CameraPositionControls::VIEW_CUBE_CAMERA_FRONT;
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_BACK:
			changeToCamera = CameraPositionControls::VIEW_CUBE_CAMERA_BACK;
			break;
		default:
			break;
	}

	cameraPositionControls->setCurrentCameraPosition(changeToCamera);
	this->sequenceChangedEvent(this->getCurrentSequence());

	QString fileName = cameraViewSettings->getElementAt(this->getCurrentSequence(), cameraPositionControls->getCurrentCameraPosition());;
	if (!fileName.isEmpty()) {
		openFileSequence(fileName);
		goToFrame(oldFrameNumber);
	}
	else {
		movieLabel->setText(Player::FILE_NOT_AVAILABLE);
	}
}

void Player::sequenceChangedEvent(int sequenceNumber)
{
	QString sequnecePath("");
	this->setCurrentSequence(sequenceNumber);
	sequnecePath = cameraViewSettings->getElementAt(this->getCurrentSequence(), cameraPositionControls->getCurrentCameraPosition());

	QString strCurrentNumber = QString::number(cameraPositionControls->getCurrentCameraPosition());
	updateCurrentViewLabel(cameraPositionControls->getCurrentCameraPosition());

	QString fileName = sequnecePath;
		
	if (!fileName.isEmpty()) {
		openFileSequence(fileName);
	} 
	else {
		movieLabel->setText(Player::FILE_NOT_AVAILABLE);
	}
}


void Player::setCurrentSequence(int sequenceNumber) {
	this->currentSequence = sequenceNumber;
}

int Player::getCurrentSequence() {
	return this->currentSequence;
}

void Player::updateCurrentViewLabel(int cameraIndex) 
{
	QString strCurrentCamera;
	
	switch (cameraIndex)
	{
		case CameraPositionControls::PERSPECTIVE_CAMERA:
			strCurrentCamera = "[Perspectice Camera]";
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_FRONT:
			strCurrentCamera = "[ViewCube Camera - FRONT]";
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_BACK:
			strCurrentCamera = "[ViewCube Camera - BACK]";
			break;
		default:
			break;
	}
	//strCurrentCamera = strCurrentCamera + " " + movie->fileName();
	this->currentViewLabel->setText(strCurrentCamera);
}

void Player::chomboBoxVCChangedEvent(int num) {
	changeCameraEvent(num);
}

void Player::initializeCameraViewImageLists() {
	cameraViewSettings->setPerspectiveCameraImagesList(*projectSettings);
	cameraViewSettings->setViewCubeCameraImagesList(*projectSettings);
}

void Player::playerSetStartConfiguration()
{
	setCurrentSequence(0);	// 0 -> first sequnce
	openFileSequence(cameraViewSettings->getElementAt(getCurrentSequence(), CameraPositionControls::PERSPECTIVE_CAMERA));

	movie->start();
	goToFrame(0);
	movie->setPaused(true);

}

void Player::updateButtons() {
	controls->updatePlayButton(true, *movie);
}

