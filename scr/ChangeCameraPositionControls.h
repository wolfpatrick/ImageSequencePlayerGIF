#ifndef CHANGECAMERAPOSITIONCONTROLS
#define CHANGECAMERAPOSITIONCONTROLS

#include <QWidget>
#include <QMovie>

QT_BEGIN_NAMESPACE
	class QPushButton;
	class QGroupBox;
	class QRadioButton;
	class QComboBox;
QT_END_NAMESPACE

class CameraPositionControls : public QWidget
{
	
	Q_OBJECT

public:
	CameraPositionControls(QWidget *parent = 0);

	int getCurrentCameraPosition();
	void setCurrentCameraPosition(int camarePositionIndex);

	static const int VIDEO_FIRST_INDEX = 0;

	static const int PERSPECTIVE_CAMERA = 0;
	static const int VIEW_CUBE_CAMERA_FRONT = 1;
	static const int VIEW_CUBE_CAMERA_BACK = 2;

	static const int VIEW_CUBE_FRONT = 0;
	static const int VIEW_CUBE_BACK = 1;

	void enableAllRadioButtons(bool state);
	void enableViewCubeComboBox(bool state);

private slots:
	void leftArrowButtonClicked();
	void rightArrowButtonClicked();
	void upArrowButtonClicked();
	void downArrowButtonClicked();

	void radioButtonPerspectiveCameraClicked(bool state);
	void radioButtonViewCubeClicked(bool state);

	void viewCubeCameraPositionsChangedEvent(int num);

signals:
	void changeCameraPosition(int num);
	void chomboBoxVCChanged(int );

private:
	int currentCamerPosition = CameraPositionControls::PERSPECTIVE_CAMERA;

	QGroupBox *cameraViewGroup;
	QRadioButton *radioButtonPerspectiveCamera;
	QRadioButton *radioButtonViewCube;

	QPushButton *leftArrowButton;
	QPushButton *rightArrowButton;
	QPushButton *upArrowButton;
	QPushButton *downArrowButton;
	QComboBox *viewCubeCameraPositions;

	void enableAllArrowButtons(bool buttonState);
	void enableViewCubeViewsElement(bool state);
	
};

#endif // CHANGECAMERAPOSITIONCONTROLS

