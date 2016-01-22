#ifndef XMLFILEREADER_H
#define XMLFILEREADER_H

#include <QtXml>
#include <QFile>
#include <QString>

class XmlFileReader
{

private:
	QDomDocument xmlBOM;

public:
	XmlFileReader();
	bool setXmlDocument(QFile &file);
	QString getAttributeFromXmlNode(QString tag, QString child);

};

#endif