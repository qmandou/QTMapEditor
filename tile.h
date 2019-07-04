#ifndef TILE_H
#define TILE_H

#include <QPoint>
#include <QImage>

class Tile
{

public:
    explicit Tile(QString name, QPoint position, QImage image);
    ~Tile();

    QString getTileSheetName() const;
    void setTileSheetName(const QString &value);

    QPoint getTileSheetPosition() const;
    void setTileSheetPosition(const QPoint &value);

    QImage getTile() const;
    void setTile(const QImage &value);

private:
    QString m_tileSheetName;
    QPoint m_tileSheetPosition;
    QImage m_tile;

};

#endif // TILE_H
