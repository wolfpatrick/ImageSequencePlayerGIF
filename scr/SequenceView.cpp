#include <QtWidgets>
#include <QDebug>
#include "SequenceView.h"

SequenceView::SequenceView(QWidget *parent) : QWidget(parent) {
	testButton = new QPushButton("Show");
	sequenceBox = new QComboBox();
	
	for (int i = 0; i <= 3; i++) {
		QString strItem = QString("%1").arg(i);
		this->sequenceBox->addItem(QString::QString(strItem));
	}

	sequenceWindowMainLayout = new QVBoxLayout;
	sequenceWindowMainLayout->addWidget(sequenceBox);
	sequenceWindowMainLayout->addWidget(testButton);

	connect(testButton, SIGNAL(clicked()), this, SLOT(buttonClick()));

	// Window settings
	setLayout(sequenceWindowMainLayout);
	setWindowTitle(tr("Sequence Player"));
	resize(100, 100);
}

void SequenceView::buttonClick() {
	int signalStr = sequenceBox->currentText().toInt();
	emit changeSequence(signalStr);
}