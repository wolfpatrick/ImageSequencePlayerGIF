#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QWidget>
#include <QMovie>

QT_BEGIN_NAMESPACE
	class QPushButton;
QT_END_NAMESPACE

class PlayerControls : public QWidget
{

	Q_OBJECT

public:
	PlayerControls(QWidget *parent = 0);
	QMovie::MovieState state() const;

	void updatePlayButton(bool state, QMovie &movie);

public slots:
	void setState(QMovie::MovieState state);

signals:
	void play();
	void setPaused1(bool);
	void stop();
	void begin();
	void end();
	void nextFrame();
	void previousFrame();

private slots:
	void playClicked();
	void stopClicked();
	void forwardClicked();
	void backwardClicked();
	void toBeginClicked();
	void toEndClicked();

private:
	QMovie::MovieState movieState;
	QPushButton *playButton;
	QPushButton *stopButton;
	QPushButton *forwardButton;
	QPushButton *backwardButton;
	QPushButton *toBeginButton;
	QPushButton *toEndButton;

};

#endif // PLAYERCONTROLS_H