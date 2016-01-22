#include "loadvideoutils.h"

#include <QString>
#include <QList>


ProjectSettings::ProjectSettings() {
}

ProjectSettings::~ProjectSettings() {
}


void ProjectSettings::setProjectName(QString projectName) {
	this->projectName = projectName;
}

QString ProjectSettings::getProjectName(){
	return this->projectName;
}

void ProjectSettings::setProjectPath(QString projectPath) {
	this->projectPath= projectPath;
}

QString ProjectSettings::getProjectPath() {
	return this->projectPath;
}

void ProjectSettings::setNumberOfSamples(int numberOfSamples) {
	this->numberOfSamples = numberOfSamples;
}

int ProjectSettings::getNumberOfSamples() {
	return this->numberOfSamples;
}

void ProjectSettings::setPerspectiveCamera(bool perspectiveCamera) {
	this->perspectiveCamera = perspectiveCamera;
}

bool ProjectSettings::getPerspectiveCamera() {
	return this->perspectiveCamera;
}

void ProjectSettings::setViewCubeCamera(bool cameraFlag) {
	this->viewCubeCamera = cameraFlag;
}

bool ProjectSettings::getViewCubeCamera() {
	return this->viewCubeCamera;
}

void ProjectSettings::setCustomCamera(QString camName) {
	customCamera = camName;
}

QString ProjectSettings::getCustomCamera() {
	return this->customCamera;
}

void ProjectSettings::setRotationCamera(int degrees) {
	this->rotationCamera = degrees;
}

int ProjectSettings::getRotationCamera() {
	return this->rotationCamera;
}


void ProjectSettings::setPerspectiveCameraImagesList() {
	perspectiveCameraImagesList = new QList<QString>();

	for (int iIndex = 0; iIndex < numberOfSamples; iIndex++) {
		QString path = "E:/TMP/1/out.gif";
		perspectiveCameraImagesList->append(path);
	}
}

// --------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------

void initProjectSettingValuesFromXMLFile();

LoadVideoUtils::LoadVideoUtils() {
	ProjectSettings globalProjectSeetings;
}

bool LoadVideoUtils::setGlobalProjectSettings() {
	// TODO "E:/WorkspaceVS2013/ImageSequencePlayerGIF/appt.xml"
	QFile xmlFile(projectRootDir);
	bool canAccessFile = xmlFileReader.setXmlDocument(xmlFile);
	if (!canAccessFile) {
		qDebug() << "Can not read file!";
		return false;
	}
	else{
		QString _projectPath = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "ProjectPath");
		globalProjectSeetings.setProjectPath(_projectPath);
		QString _projectSettings = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "ProjectName");
		globalProjectSeetings.setProjectName(_projectSettings);
		QString _samples = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "Samples");
		globalProjectSeetings.setNumberOfSamples(_samples.toInt());
		
		QString _perspectiveCamera = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "PerspectiveCamera");
		globalProjectSeetings.setPerspectiveCamera(qStringToBool(_perspectiveCamera));
		QString _viewCubeCamera = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "ViewCubeCamera");
		qDebug() << _viewCubeCamera;
		globalProjectSeetings.setViewCubeCamera(qStringToBool(_viewCubeCamera));
		QString _customCamera = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "CustomCamera");
		globalProjectSeetings.setCustomCamera(_customCamera);
		QString _rotationCamera = xmlFileReader.getAttributeFromXmlNode("GlobalSettings", "RotationCamera");
		globalProjectSeetings.setRotationCamera(qStringToInt_rotationCamera(_rotationCamera));

		qDebug() << globalProjectSeetings.getProjectName();
		qDebug() << globalProjectSeetings.getProjectPath();
		qDebug() << globalProjectSeetings.getNumberOfSamples();
		qDebug() << globalProjectSeetings.getPerspectiveCamera();
		qDebug() << globalProjectSeetings.getViewCubeCamera();
		qDebug() << globalProjectSeetings.getCustomCamera();
		qDebug() << globalProjectSeetings.getRotationCamera();
	}

	return true;
	

}

void LoadVideoUtils::setProjDirFromArgIn(QString path) {
	this->projectRootDir = path;
}

bool LoadVideoUtils::qStringToBool(QString value) {
	if (value == "1") {
		return true;
	}
	else {
		return false;
	}
}

int LoadVideoUtils::qStringToInt_rotationCamera(QString value) {
	int degrees = 0;
	degrees = value.toInt();

	return degrees;
}



ProjectSettings *LoadVideoUtils::getGlobalProjectSettings() {
	return &globalProjectSeetings;
}




