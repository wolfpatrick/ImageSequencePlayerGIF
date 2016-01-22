#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QList>

#include "LOADVIDEOUTILS.H"
#include "SequenceView.h"
#include "PlayerControls.h"
#include "CameraViewSettings.h"

QT_BEGIN_NAMESPACE
	class QCheckBox;
	class QGridLayout;
	class QHBoxLayout;
	class QLabel;
	class QMovie;
	class QSlider;
	class QSpinBox;
	class QToolButton;
	class QVBoxLayout;
QT_END_NAMESPACE

class Player : public QWidget
{

	Q_OBJECT

public:
	Player(QString rootDir, QWidget *parent = 0);
	QString projectRootDir;
	void setProjectRootDir(QString path);

	void openFileSequence(const QString &fileName);

	int getCurrentFrameNumber();
	void setCurrentFrameNumber(int);
	int getTotalFrameNumber();
	void setTotalFrameNumber(int number);

	void setLastValidStepFrameNumber(int number);
	int getLastValidStepFrameNumber();

	LoadVideoUtils *videoUtils;
	ProjectSettings *projectSettings;
	CameraViewSettings *cameraViewSettings;
	
	void setCurrentSequence(int sequenceNumber);
	int getCurrentSequence();

private slots:
	void beginClicked();
	void endClicked();
	void stopClicked();
	void nextFrameClicked();
	void previousFrameClicked();
	void goToFrame(int frame);
	void updateFrameSlider();
	void fitToWindow(bool state);
	void changeCameraEvent(int num);
	void sequenceChangedEvent(int sequenceNumber);
	void chomboBoxVCChangedEvent(int num);
	void updateButtons();

private:
	const QString FILE_NOT_AVAILABLE = "[File does not exists!]";

	int currentFrameNumber;
	int oldFrameNumber;
	int currentSequence;
	int lastValidStepFrameNumber;	// stores the number of the last visited frames after a 'stepFrameButton' was cklicked
	int totalFrameNumber;
	void createControls();
	void updateCurrentViewLabel(int);
	void initializeCameraViewImageLists();
	void playerSetStartConfiguration();

	CameraPositionControls *cameraPositionControls;
	PlayerControls *controls;
	QList<QString> *currentCameraViewImages;
	QLabel *movieLabel;
	QMovie *movie;
	QSlider *frameSlider;
	QCheckBox *fitCheckBox;
	QLabel *speedLabel;
	QSpinBox *speedSpinBox;
	QVBoxLayout *mainLayout;
	QLabel *currentViewLabel;

};

#endif
