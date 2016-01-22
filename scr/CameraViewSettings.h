#ifndef CAMERAVIEWSETTINGS_H
#define CAMERAVIEWSETTINGS_H

#include <iostream>

#include "LoadVideoUtils.h"
#include "xmlfilereader.h"
#include "ChangeCameraPositionControls.h"

#include <QtCore>
#include <QString>
#include <QList>

class CameraViewSettings
{
private:
	const QString DIR_IMG_ROOT = "images";
	const QString DIR_IMG_PERSPECTIVE = "perspective";
	const QString DIR_IMG_VC_FRONT = "vc_front";
	const QString DIR_IMG_VC_BACK = "vc_back";

	QList<QString> *perspectiveCameraImagesList;
	QList<QString> *viewCube_Front_CameraImagesList;
	QList<QString> *viewCube_Back_CameraImagesList;

	bool checkIfImgExists(QString path);

public:
	CameraViewSettings();
	~CameraViewSettings();

	void setPerspectiveCameraImagesList(ProjectSettings &projectSettings);
	void setViewCubeCameraImagesList(ProjectSettings &projectSettings);

	QString getElementAt(int seqNumber, const int cameraView);

};

#endif // LOADVIDEOUTILS_H