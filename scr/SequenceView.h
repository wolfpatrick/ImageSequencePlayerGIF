#ifndef SEQUENCEVIEW_H
#define SEQUENCEVIEW_H

#include <QWidget>

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
	class QPushButton;
	class QComboBox;
QT_END_NAMESPACE

class SequenceView : public QWidget
{

	Q_OBJECT

public:
	SequenceView(QWidget *parent = 0);
	QPushButton *testButton;
	QComboBox *sequenceBox;

private:
	QVBoxLayout *sequenceWindowMainLayout;

signals:
	void changeSequence(int);

private slots:
	void buttonClick();

};

#endif
