#include "supgraphicsview.h"

SupGraphicsView::SupGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    p_scene = new QGraphicsScene();
    setScene(p_scene);
}

SupGraphicsView::~SupGraphicsView()
{

}

void SupGraphicsView::AddImage(QImage img)
{
    p_scene->addPixmap(QPixmap::fromImage(img));
}

bool SupGraphicsView::inMouseArea(QMouseEvent* mouseEvent, QRect rect)
{
    return mouseEvent->pos().x() > 0
        && mouseEvent->pos().y() > 0
        && mouseEvent->pos().x() <= rect.width()
            && mouseEvent->pos().y() <= rect.height() ? true : false;
}

QPoint SupGraphicsView::mousePosToTileID(QPoint point, QPoint tileSize)
{
    return QPoint(point.x() / tileSize.x(), point.y() / tileSize.y());
}

void SupGraphicsView::setData(MetaData *value)
{
    p_data = value;
}

void SupGraphicsView::DrawGrid(QGraphicsScene *scene, int rect_Width, int rect_height, int tile_Width, int tile_height)
{
    QPen pen(Qt::red);
    QRectF rect = scene->sceneRect();
    scene->addRect(rect, pen);

    for(int i = 1; i < (rect_Width / tile_Width) + 1; i++)
    {
        scene->addLine(i * tile_Width, 0, i * tile_Width, rect_height, pen);
    }

    for(int j = 1; j < (rect_height / tile_height) + 1; j++)
    {
        scene->addLine( 0, j * tile_height, rect.width(), j * tile_height, pen);
    }
}


