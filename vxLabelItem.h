#ifndef VXLABELITEM_H
#define VXLABELITEM_H

// 每一个小的窗叶

#include <QLabel>
#include <QTimeLine>
#include <QPainter>
#include <QDebug>

class vxLabelItem : public QLabel 
{
	Q_OBJECT

public:
	vxLabelItem(QWidget* parent = 0);
	~vxLabelItem();

	void setImage(const QImage& image);// 设置图片，片断的起始位置、宽度
	void startDraw();

public slots:
		void	slot_timeOut(int);

protected:
	void	paintEvent ( QPaintEvent * ev );

private:
	QImage	mDrawImage;
	QImage	mCurrentImage;
	QTimeLine* mTimeline;
	int m_currentWidth;
};
#endif
