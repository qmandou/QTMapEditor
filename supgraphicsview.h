#ifndef SUPGRAPHICSVIEW_H
#define SUPGRAPHICSVIEW_H

#include "metadata.h"

#include <QGraphicsView>
#include <QWidget>

#include <QMouseEvent>
#include <QPoint>

#include <QDebug>
#include <QScrollBar>

class SupGraphicsView : public QGraphicsView
{
    Q_OBJECT


public:
    explicit SupGraphicsView(QWidget *parent = 0);
    virtual ~SupGraphicsView();

    void setData(MetaData *value);

private:

protected:
    inline QPoint MouseToGraphicsView(QMouseEvent* mouseEvent) { return QPoint( mouseEvent->pos().x() + this->horizontalScrollBar()->value(),
                                                                                mouseEvent->pos().y() + this->verticalScrollBar()->value()); }

    void AddImage(QImage img);
    void DrawGrid(QGraphicsScene *scene, int rect_Width, int rect_height, int tile_Width, int tile_height);

    bool inMouseArea(QMouseEvent* mouseEvent, QRect rect);
    QPoint mousePosToTileID(QPoint point, QPoint tileSize);

    QGraphicsScene* p_scene;
    MetaData *p_data;
signals:

public slots:
};

#endif // SUPGRAPHICSVIEW_H
