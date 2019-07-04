#include "mapgraphicsview.h"

MapGraphicsView::MapGraphicsView(QWidget* parent)
    : SupGraphicsView(parent)
{
}

MapGraphicsView::~MapGraphicsView()
{
    delete p_workImage;
}

void MapGraphicsView::SceneUpdate()
{

    QPen pen(Qt::black);
    p_scene->clear();
    p_scene->addPixmap(QPixmap::fromImage(*p_workImage));
    p_scene->addRect(p_workImage->rect(), pen);
    p_scene->setSceneRect(p_workImage->rect());
}

void MapGraphicsView::on_Map_IsChanged(MetaData *data)
{
    if(data->getMap() != NULL)
    {
        setWorkImage(new QImage(data->getMap()->getWidth() * data->getTileSize().x(),
                                data->getMap()->getHeight() * data->getTileSize().y(), QImage::Format_ARGB32));
    }
}

QImage *MapGraphicsView::getWorkImage() const
{
    return p_workImage;
}

void MapGraphicsView::setWorkImage(QImage *value)
{
    if(p_workImage != NULL)
        delete p_workImage;
    p_workImage = value;
    SceneUpdate();
}

void MapGraphicsView::mousePressEvent(QMouseEvent *mouseEvent)
{
    if(p_data->getMap() != NULL && p_data->GetCurTile() != NULL && inMouseArea(mouseEvent, this->rect()))
    {
        QPoint tileSize = p_data->getTileSize();
        QPoint tempPos(mousePosToTileID(MouseToGraphicsView(mouseEvent), tileSize));

        p_data->getMap()->setMapValue(tempPos.x(),tempPos.y(), p_data->getCurtileID());
        p_data->getMap()->Draw(p_workImage, p_data->GetCurTile()->getTile(), tempPos, tileSize);

        SceneUpdate();
    }
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    if(p_data->getMap() != NULL && p_data->GetCurTile() != NULL && inMouseArea(mouseEvent, this->rect()))
    {

        QPoint tileSize = p_data->getTileSize();
        QPoint tempPos(mousePosToTileID(MouseToGraphicsView(mouseEvent), tileSize));

        p_data->getMap()->setMapValue(tempPos.x(),tempPos.y(), p_data->getCurtileID());
        p_data->getMap()->Draw(p_workImage, p_data->GetCurTile()->getTile(), tempPos, tileSize);

        SceneUpdate();
    }
}
