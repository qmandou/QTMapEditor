#ifndef TILESHEET_H
#define TILESHEET_H

#include <QObject>
#include <QImage>
#include <QVector>

#include "tile.h"

class TileSheet : public QObject
{
    Q_OBJECT
public:
    explicit TileSheet(QObject *parent = 0);
    ~TileSheet();

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    void ClearImage();
    inline Tile *GetTile(int id);
    int AddTile(Tile *tile);

private:


signals:

public slots:

};

#endif // TILESHEET_H
