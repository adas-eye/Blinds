#include "testblinds.h"
#include "vxLabelItem.h"

const int maxBlindsNum = 16; // 最大的百叶窗数

testBlinds::testBlinds(QWidget *parent, Qt::WindowFlags flags)
	: QWidget(parent, flags)
{
	setFixedSize(800,300);

	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint) ;

	// Create Image
	QImage backGroundImage = QImage(":/Resources/back2.jpg");

	{
		// 添加要显示的文字
		QFont font;
		font.setFamily(QString::fromUtf8("Aharoni"));
		font.setBold(true);
		font.setItalic(true);
		font.setPointSize(99);

		QPainter painter(&backGroundImage);
		painter.begin(this);
		painter.setFont(font);
		painter.setPen(QPen(Qt::green));
		painter.drawText(0, backGroundImage.height()-50, QString("Hello  ............."));
		painter.end();
	}

	{
		// 分成N个栏，每一栏是一个小的QLabel
		// Layout
		QHBoxLayout* hlay = new QHBoxLayout;
		hlay->setSpacing(0);
		hlay->setContentsMargins(0, 0, 0, 0);
		setLayout(hlay);

		QVector<vxLabelItem*> items;
		for(int i = 0; i < maxBlindsNum; ++i) 
		{
			vxLabelItem* item = new vxLabelItem(this);
			// 设置大小
			item->setFixedWidth(width()/maxBlindsNum); // 整个窗体宽度/叶数

			// 设置图片
			QImage image = backGroundImage.copy(i*width()/maxBlindsNum, 0, width()/maxBlindsNum, height());
			item->setImage(image);

			hlay->addWidget(item);

			items.push_back(item);
		}

		// 开始动画
		foreach(vxLabelItem* item, items) 
		{
			if(item)
				item->startDraw();
		}
	}
}

testBlinds::~testBlinds()
{

}
