#include "camviewer.h"

void CamViewer::setImage(QImage im)
{
image = im;
this->scene()->update();
}
void CamViewer::paintEvent(QPaintEvent* evnt){
    QPainter painter(viewport());
    QRect aRect = QRect(0,0,viewport()->width(),viewport()->height());
    QRect bRect = QRect(0,0,image.width(),image.height());
    painter.drawImage(aRect,image, bRect);
    QGraphicsView::paintEvent(evnt);
}
