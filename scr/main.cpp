#include <QApplication>
#include <QDebug>

#include "player.h"
#include "sequenceview.h"
#include "xmlfilereader.h"
#include "loadvideoutils.h"

#include <QtXml>
#include <QFile>
#include <QString>

#include <iostream> 
#include <string> 

#include "testUI.h"

using namespace std;

int main(int argc, char *argv[])
{
	static const string PROJECT_ROOT_DIR = "-projRootDir";
	QString projPath = "";
	if (argc == 3) {
		std::string arg_projDir(argv[1]);
		if (arg_projDir == PROJECT_ROOT_DIR) {
			qDebug() << argv[2];
			projPath = argv[2];
			qDebug() << projPath;
		}
	}

	/*
	qDebug() << "XML Test";

	XmlFileReader fileReader;
	QFile xmlFile(projPath);
	bool canAccessFile = fileReader.setXmlDocument(xmlFile);
	if (!canAccessFile) {
		qDebug() << "Can not read file!";
	} 
	else{
		QString aa = fileReader.getAttributeFromXmlNode("GlobalSettings", "ProjectName");
		qDebug() << aa;
	}
	
	//fileReader.setXmlDocument(xmlFile);


	
	QDomElement projectName;
	QDomElement samples;
	QString el_projectName("");
	QString el_samples("");

	//The QDomDocument class represents an XML document.
	// Load xml file
	QDomDocument xmlBOM;
	
	QFile f("E:/WorkspaceVS2013/ImageSequencePlayerGIF/appt.xml");
	if (!f.open(QIODevice::ReadOnly))
	{
		// Error while loading file
		qDebug() << "Error while loading file";
		return 1;
	}

	// Set data into the QDomDocument before processing
	xmlBOM.setContent(&f);
	f.close();
	

	// Extract the root markup
	QDomElement root = xmlBOM.documentElement();

	QDomNodeList globalSettings = xmlBOM.elementsByTagName("GlobalSettings");
	for (int i = 0; i < globalSettings.size(); i++) {
		qDebug() << "SSSSSSSSSSSSSSS";
		QDomNode n = globalSettings.item(i);

		projectName = n.firstChildElement("ProjectName");
		samples = n.firstChildElement("Samples");
	}

	el_projectName = projectName.text();
	el_samples = samples.text();
	int a = 15;

	qDebug() << "ProjectName" << " = " << el_projectName;
	qDebug() << "Samples" << " = " << el_samples;
	*/

	/*
	LoadVideoUtils *sett = new LoadVideoUtils();
	sett->setGlobalProjectSettings();
	ProjectSettings a = sett->getGlobalProjectSettings();
	qDebug() << a.getNumberOfSamples();
	a.setPerspectiveCameraImagesList();

	//QList<QString> aa = a.getPerspectiveCameraImagesList();
	//qDebug() << aa.size();
	//qDebug() << aa.at(3);

	qDebug() << a.getElementAt(6);
	delete sett;

	*/

	QApplication app(argc, argv);
	
	Player player(projPath);
	player.show();
	 
	QWidget *widget = new QWidget;
	Ui::Form::Ui_Form ui;
	ui.setupUi(widget);
	widget->show();
	
	ui.tab_2->setLayout(player.layout());
	return app.exec();
}

// QWidget *widget = new QWidget;
// Ui::Form::Ui_Form ui;
// ui.setupUi(widget);
// widget->show();
