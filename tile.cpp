#include "tile.h"

Tile::Tile(QString name, QPoint position, QImage image)
    :  m_tileSheetName(name),
       m_tileSheetPosition(position),
       m_tile(image)
{

}

Tile::~Tile()
{

}

QString Tile::getTileSheetName() const
{
    return m_tileSheetName;
}

void Tile::setTileSheetName(const QString &value)
{
    m_tileSheetName = value;
}

QPoint Tile::getTileSheetPosition() const
{
    return m_tileSheetPosition;
}

void Tile::setTileSheetPosition(const QPoint &value)
{
    m_tileSheetPosition = value;
}

QImage Tile::getTile() const
{
    return m_tile;
}

void Tile::setTile(const QImage &value)
{
    m_tile = value;
}
