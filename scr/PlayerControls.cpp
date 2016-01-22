#include "PlayerControls.h"

#include <QMovie>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStyle>
#include <QDebug>

PlayerControls::PlayerControls(QWidget *parent)
	: QWidget(parent)
	, movieState(QMovie::NotRunning)
	, playButton(0)
	, stopButton(0)
	, forwardButton(0)
	, backwardButton(0)
	, toBeginButton(0)
	, toEndButton(0)

{
	playButton = new QPushButton(this);
	playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));

	stopButton = new QPushButton(this);
	stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stopClicked()));

	forwardButton = new QPushButton(this);
	forwardButton->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
	connect(forwardButton, SIGNAL(clicked()), this, SLOT(forwardClicked()));

	backwardButton = new QPushButton(this);
	backwardButton->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
	connect(backwardButton, SIGNAL(clicked()), this, SLOT(backwardClicked()));

	toBeginButton = new QPushButton(this);
	toBeginButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
	connect(toBeginButton, SIGNAL(clicked()), this, SLOT(toBeginClicked()));

	toEndButton = new QPushButton(this);
	toEndButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
	connect(toEndButton, SIGNAL(clicked()), this, SLOT(toEndClicked()));

	QBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(toBeginButton);
	layout->addWidget(backwardButton);
	layout->addWidget(playButton);
	layout->addWidget(stopButton);
	layout->addWidget(forwardButton);
	layout->addWidget(toEndButton);
	setLayout(layout);
}

QMovie::MovieState PlayerControls::state() const {
	return movieState;
}

void PlayerControls::playClicked()  {
	
	switch (movieState) {
		case QMovie::Paused:
		case QMovie::NotRunning:
			emit play();
			break;
		case QMovie::Running:
			emit setPaused1(true);
			break;
	}
}


void PlayerControls::stopClicked() {
	emit stop();
}

void PlayerControls::forwardClicked() {
	emit nextFrame();
	stopButton->setEnabled(true);
}

void PlayerControls::backwardClicked() {
	emit previousFrame();
	stopButton->setEnabled(true);
}

void PlayerControls::toBeginClicked() {
	emit begin();
	stopButton->setEnabled(true);
}

void PlayerControls::toEndClicked() {
	emit end();
	stopButton->setEnabled(true);
}

void PlayerControls::setState(QMovie::MovieState state) {
	if (state != movieState) {
		movieState = state;

		switch (state) {
			case QMovie::NotRunning:
				stopButton->setEnabled(false);
				playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
				break;
			case QMovie::Running:
				stopButton->setEnabled(true);
				playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
				break;
			case QMovie::Paused:
				//stopButton->setEnabled(true);
				playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
				break;
		}
	}
}

void PlayerControls::updatePlayButton(bool state, QMovie &movie) {
}