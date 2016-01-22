#include "CameraViewSettings.h"

CameraViewSettings::CameraViewSettings() {
}

CameraViewSettings::~CameraViewSettings() {
}

void CameraViewSettings::setPerspectiveCameraImagesList(ProjectSettings &projectSettings) {
	
	bool perspecticeCameraValid = projectSettings.getPerspectiveCamera();
	if (perspecticeCameraValid) {
		perspectiveCameraImagesList = new QList<QString>();

		QString pathToPerspectiveImagesPrjDir = projectSettings.getProjectPath() + projectSettings.getProjectName() + QString("%1").arg('/');
		QString imagePath = QString("%1").arg("images") + QString("%1").arg("/") + QString("%1").arg("perspective") + QString("%1").arg("/") + QString("%1").arg("out.gif");
		
		for (int iIndex = 0; iIndex < projectSettings.getNumberOfSamples(); iIndex++) {
			QString tmp = pathToPerspectiveImagesPrjDir + QString("%1%2").arg(QString::number(iIndex), "/") + imagePath;
			if (checkIfImgExists(tmp)) {
				perspectiveCameraImagesList->append(tmp);
			}
			else {
				perspectiveCameraImagesList->append("");
			}
		}
	}
}

void CameraViewSettings::setViewCubeCameraImagesList(ProjectSettings &projectSettings) {
	
	QString pathToViewCuveImagesPrjDir = projectSettings.getProjectPath() + projectSettings.getProjectName() + QString("%1").arg('/');

	bool viewCuveCameraValid = projectSettings.getViewCubeCamera();
	if (viewCuveCameraValid) {

		// CAMERA: ViewCube - FRONT
		viewCube_Front_CameraImagesList = new QList<QString>();
		QString imagePath_vc_front = QString("%1").arg(CameraViewSettings::DIR_IMG_ROOT) + QString("%1").arg("/") + QString("%1").arg(CameraViewSettings::DIR_IMG_VC_FRONT) + QString("%1").arg("/") + QString("%1").arg("out.gif");
		for (int iIndex = 0; iIndex < projectSettings.getNumberOfSamples(); iIndex++) {
			QString tmp = pathToViewCuveImagesPrjDir + QString("%1%2").arg(QString::number(iIndex), "/") + imagePath_vc_front;
			if (checkIfImgExists(tmp)) {
				viewCube_Front_CameraImagesList->append(tmp);
			}
			else {
				viewCube_Front_CameraImagesList->append("");
			}
		}

		// CAMERA: ViewCube - BACK
		viewCube_Back_CameraImagesList = new QList<QString>();
		QString imagePath_vc_back = QString("%1").arg(CameraViewSettings::DIR_IMG_ROOT) + QString("%1").arg("/") + QString("%1").arg(CameraViewSettings::DIR_IMG_VC_BACK) + QString("%1").arg("/") + QString("%1").arg("out.gi");
		for (int iIndex = 0; iIndex < projectSettings.getNumberOfSamples(); iIndex++) {
			QString tmp = pathToViewCuveImagesPrjDir + QString("%1%2").arg(QString::number(iIndex), "/") + imagePath_vc_back;
			if (checkIfImgExists(tmp)) {
				viewCube_Back_CameraImagesList->append(tmp);
			}
			else {
				viewCube_Back_CameraImagesList->append("");
			}
		}
	}
}


QString CameraViewSettings::getElementAt(int seqNumber, const int cameraView) {

	switch (cameraView)
	{
		case CameraPositionControls::PERSPECTIVE_CAMERA:
			return perspectiveCameraImagesList->at(seqNumber);
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_FRONT:
			return viewCube_Front_CameraImagesList->at(seqNumber);
			break;
		case CameraPositionControls::VIEW_CUBE_CAMERA_BACK:
			return viewCube_Back_CameraImagesList->at(seqNumber);
			break;
	}

	return "";
}

bool CameraViewSettings::checkIfImgExists(QString path) {
	return QFile::exists(path);
}	


