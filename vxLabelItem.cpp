#include "vxLabelItem.h"

vxLabelItem::vxLabelItem(QWidget* parent)
: QLabel(parent)
, m_currentWidth(0)
{
	mTimeline = new QTimeLine(3000, this);
	connect(mTimeline, SIGNAL(frameChanged(int)), this, SLOT(slot_timeOut(int)));
}

vxLabelItem::~vxLabelItem()
{

}

void vxLabelItem::paintEvent( QPaintEvent * ev )
{
	if(!mDrawImage.isNull())
	{
		QPainter p(this);
		p.setBrush(QBrush(mCurrentImage));
		p.setPen(Qt::NoPen);
		p.drawRect(0, 0, m_currentWidth, height());
	}

	QWidget::paintEvent(ev);
}

void vxLabelItem::setImage( const QImage& image )
{
	mDrawImage = image;
}

void vxLabelItem::startDraw()
{
	if(!mDrawImage.isNull())
	{
		qDebug()<<"mDrawImage.width() = "<<mDrawImage.width()<<endl;
		mTimeline->setFrameRange(0, mDrawImage.width());
		mTimeline->start();
	}
}

void vxLabelItem::slot_timeOut( int val)
{
	mCurrentImage = mDrawImage.copy(0, 0, val, 300);
	m_currentWidth = val;

	//mDrawImage.save("c:/" + QString::number(val) + ".jpg");
	update();
}