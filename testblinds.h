#ifndef TESTBLINDS_H
#define TESTBLINDS_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPainter>
class testBlinds : public QWidget
{
	Q_OBJECT

public:
    testBlinds(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~testBlinds();
};

#endif // TESTBLINDS_H
