#include "testblinds.h"
#include <QApplication>

// windows Vista + qt 4.7.2  + vs 2008 开发环境

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testBlinds w;
	w.show();
	return a.exec();
}
