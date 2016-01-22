#ifndef LOADVIDEOUTILS_H
#define LOADVIDEOUTILS_H

#include "xmlfilereader.h"
#include "ChangeCameraPositionControls.h"

#include <QString>
#include <QList>

class ProjectSettings
{

private:
	QString projectName = "";
	QString projectPath = "";
	int numberOfSamples = 0;
	
	bool perspectiveCamera = false;	// default value: 0
	bool viewCubeCamera = false;	// default value: 0
	QString customCamera = "";		// default value: ""
	int rotationCamera = 0;			// default value: 0

	QList<QString> *perspectiveCameraImagesList;
	QList<QString> *ViewCube_FrontCameraImagesList;

public:
	ProjectSettings();
	~ProjectSettings();

	void setProjectName(QString projectName);
	QString getProjectName();
	void setProjectPath(QString projectPath);
	QString getProjectPath();
	void setNumberOfSamples(int numberOfSamples);
	int getNumberOfSamples();
	
	void setPerspectiveCamera(bool perspectiveCamera);
	bool getPerspectiveCamera();

	void setViewCubeCamera(bool camFlag);
	bool getViewCubeCamera();

	void setCustomCamera(QString camName);
	QString getCustomCamera();

	void setRotationCamera(int degrees);
	int getRotationCamera();

	void setPerspectiveCameraImagesList();

};

class LoadVideoUtils
{

private:
	QString projectRootDir;
	ProjectSettings globalProjectSeetings;
	XmlFileReader xmlFileReader;

	bool qStringToBool(QString value);
	int qStringToInt_rotationCamera(QString value);

public:
	LoadVideoUtils();
	bool setGlobalProjectSettings();
	ProjectSettings *getGlobalProjectSettings();
	void setProjDirFromArgIn(QString path);
};

#endif // LOADVIDEOUTILS_H