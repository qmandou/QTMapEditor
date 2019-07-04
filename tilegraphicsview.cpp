#include "tilegraphicsview.h"

TileGraphicsView::TileGraphicsView(QWidget* parent)
    : SupGraphicsView(parent)
{

}

TileGraphicsView::~TileGraphicsView()
{

}

void TileGraphicsView::mousePressEvent(QMouseEvent *mouseEvent)
{
    if(p_data->getImage() != NULL && inMouseArea(mouseEvent, this->rect()))
    {
        QPoint tileSize = p_data->getTileSize();
        QPoint tempPos(mousePosToTileID(MouseToGraphicsView(mouseEvent), tileSize));

        QRect rect(tempPos.x() * tileSize.x(),
                   tempPos.y() * tileSize.y(),
                   tileSize.x(),
                   tileSize.y());

        Tile* tmp = p_data->getTmpTile();
        p_data->setTmpTile(NULL);
        if(tmp != NULL)
            delete tmp;

        p_data->setCurtileID(p_data->AddTile(new Tile(p_data->getName(), tempPos, p_data->getImage()->copy(rect))));
        on_TileSheet_isChanged(p_data);

        QPen pen(Qt::blue);
        QBrush brush(Qt::DiagCrossPattern);
        p_scene->addRect(QRect(rect), pen, brush);

    }
}

void TileGraphicsView::on_TileSheet_isChanged(MetaData *metaData)
{
    QImage* img = metaData->getImage();

    if(img != NULL)
    {
        p_scene->clear();
        p_scene->addPixmap(QPixmap::fromImage(*img));
        p_scene->setSceneRect(img->rect());
        DrawGrid(p_scene,
                 p_scene->width(),
                 p_scene->height(),
                 metaData->getTileSize().x(),
                 metaData->getTileSize().y());
    }
}

