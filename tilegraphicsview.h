#ifndef TILEGRAPHICSVIEW_H
#define TILEGRAPHICSVIEW_H

#include "metadata.h"
#include "supgraphicsview.h"

class TileGraphicsView : public SupGraphicsView
{
    Q_OBJECT

public:
    TileGraphicsView(QWidget* parent = 0);
    virtual ~TileGraphicsView();

protected:
    void mousePressEvent(QMouseEvent* mouseEvent);

public slots:
    void on_TileSheet_isChanged(MetaData* metaData);
};

#endif // TILEGRAPHICSVIEW_H
