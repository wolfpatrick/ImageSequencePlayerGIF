#include <QtWidgets>

#include "player.h"
#include "changecamerapositioncontrols.h"

CameraPositionControls::CameraPositionControls(QWidget *parent)
	: QWidget(parent) 
{
	QBoxLayout *cameraControlsLayout = new QHBoxLayout;

	cameraViewGroup = new QGroupBox(tr("Camera Views"));
	radioButtonPerspectiveCamera = new QRadioButton(tr("&Perspective Camera"));
	radioButtonViewCube = new QRadioButton(tr("&View Cube Camera"));

	QBoxLayout *cameraViewGroupLayout = new QHBoxLayout;
	cameraViewGroupLayout->addWidget(radioButtonPerspectiveCamera);
	cameraViewGroupLayout->addWidget(radioButtonViewCube);
	radioButtonPerspectiveCamera->setChecked(true);

	QObject::connect(radioButtonPerspectiveCamera, SIGNAL(clicked(bool)), this, SLOT(radioButtonPerspectiveCameraClicked(bool)));
	QObject::connect(radioButtonViewCube, SIGNAL(clicked(bool)), this, SLOT(radioButtonViewCubeClicked(bool)));
	
	leftArrowButton = new QPushButton("FRONT");
	rightArrowButton = new QPushButton("BACK");
	upArrowButton = new QPushButton("LEFT");
	downArrowButton = new QPushButton("RIGHT");
	connect(leftArrowButton, SIGNAL(clicked()), this, SLOT(leftArrowButtonClicked()));
	connect(rightArrowButton, SIGNAL(clicked()), this, SLOT(rightArrowButtonClicked()));
	connect(upArrowButton, SIGNAL(clicked()), this, SLOT(upArrowButtonClicked()));
	connect(downArrowButton, SIGNAL(clicked()), this, SLOT(downArrowButtonClicked()));
	this->enableAllArrowButtons(false);

	viewCubeCameraPositions = new QComboBox();
	viewCubeCameraPositions->addItem("FRONT");
	viewCubeCameraPositions->addItem("BACK");
	viewCubeCameraPositions->setEnabled(false);

	connect(viewCubeCameraPositions, SIGNAL(currentIndexChanged(int)), this, SLOT(viewCubeCameraPositionsChangedEvent(int)));

	cameraControlsLayout->addWidget(leftArrowButton);
	cameraControlsLayout->addWidget(rightArrowButton);
	cameraControlsLayout->addWidget(upArrowButton);
	cameraControlsLayout->addWidget(downArrowButton); 
	cameraControlsLayout->addWidget(viewCubeCameraPositions);

	cameraControlsLayout->addLayout(cameraViewGroupLayout);
	setLayout(cameraControlsLayout);
}

void CameraPositionControls::leftArrowButtonClicked() {
	emit changeCameraPosition(1);
}

void CameraPositionControls::rightArrowButtonClicked() {
	emit changeCameraPosition(1);
}

void CameraPositionControls::upArrowButtonClicked() {
	emit changeCameraPosition(1);
}

void CameraPositionControls::downArrowButtonClicked() {
	emit changeCameraPosition(1);
}

void CameraPositionControls::radioButtonPerspectiveCameraClicked(bool state) {
	this->enableAllArrowButtons(false);
	emit changeCameraPosition(PERSPECTIVE_CAMERA);
}

void CameraPositionControls::radioButtonViewCubeClicked(bool state) {
	enableViewCubeViewsElement(state);
	int currentVCIndex = viewCubeCameraPositions->currentIndex();
	switch (currentVCIndex) {
		case 0:
			emit changeCameraPosition(VIEW_CUBE_CAMERA_FRONT);
			break;
		case 1:
			emit changeCameraPosition(VIEW_CUBE_CAMERA_BACK);
			break;
	}
}

void CameraPositionControls::viewCubeCameraPositionsChangedEvent(int num) {
	int index = viewCubeCameraPositions->currentIndex();
	switch (index) {
		case CameraPositionControls::VIEW_CUBE_FRONT:
			emit chomboBoxVCChanged(1);
			break;
		case CameraPositionControls::VIEW_CUBE_BACK:
			emit chomboBoxVCChanged(2);
			break;
	}
}

void CameraPositionControls::enableAllArrowButtons(bool buttonState) {
	this->leftArrowButton->setEnabled(buttonState);
	this->rightArrowButton->setEnabled(buttonState);
	this->upArrowButton->setEnabled(buttonState);
	this->downArrowButton->setEnabled(buttonState);
}

void CameraPositionControls::enableViewCubeComboBox(bool state) {
	viewCubeCameraPositions->setEnabled(state);
}

int CameraPositionControls::getCurrentCameraPosition() {
	return this->currentCamerPosition;
}

void CameraPositionControls::setCurrentCameraPosition(int camarePositionIndex) {
	this->currentCamerPosition = camarePositionIndex;
}

void CameraPositionControls::enableAllRadioButtons(bool state) {
	this->radioButtonPerspectiveCamera->setEnabled(state);
	this->radioButtonViewCube->setEnabled(state);
}

void CameraPositionControls::enableViewCubeViewsElement(bool state) {
	this->viewCubeCameraPositions->setEnabled(state);
}