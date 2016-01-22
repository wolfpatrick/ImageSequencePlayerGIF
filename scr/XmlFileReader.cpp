#include "xmlfilereader.h"

#include <QtXml>
#include <QFile>
#include <QString>

XmlFileReader::XmlFileReader() {
}

bool XmlFileReader::setXmlDocument(QFile &file) {
	bool couldReadFile = false;

	QString projectName("");

	if (!file.open(QIODevice::ReadOnly)){
		// Error while loading file
		qDebug() << "Error while loading file";
		couldReadFile = false;
		return couldReadFile;
	}
	else {
		couldReadFile = true;
	}

	// Set data into the QDomDocument before processing
	xmlBOM.setContent(&file);
	file.close();

	return couldReadFile;
}

QString XmlFileReader::getAttributeFromXmlNode(QString tag, QString child) {
	QString childValue("");

	// Extract the root markup
	QDomElement root = xmlBOM.documentElement();

	QDomNodeList globalSettings = xmlBOM.elementsByTagName(tag);
	for (int i = 0; i < globalSettings.size(); i++) {
		QDomNode n = globalSettings.item(i);
		QDomElement domElement = n.firstChildElement(child);
		childValue = domElement.text();
	}

	return childValue;
}

