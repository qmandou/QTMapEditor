#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include "tilegraphicsview.h"
#include "supgraphicsview.h"

class MapGraphicsView : public SupGraphicsView
{
    Q_OBJECT

public:
    MapGraphicsView(QWidget* parent);
    virtual ~MapGraphicsView();

    QImage *getWorkImage() const;
    void setWorkImage(QImage *value);

protected:
    void mousePressEvent(QMouseEvent *mouseEvent);
    void mouseMoveEvent(QMouseEvent* mouseEvent);

private:
    QImage* p_workImage;

    void SceneUpdate();

public slots:
    void on_Map_IsChanged(MetaData* data);

signals:
    void on_Tile_IsAdded();
};

#endif // MAPGRAPHICSVIEW_H
