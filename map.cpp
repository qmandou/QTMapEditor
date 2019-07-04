#include "map.h"

Map::Map(int width, int height)
    : m_width(width), m_height(height)
{
    a_map = new int[width * height];
    Init(0);
}

Map::~Map()
{
    delete a_map;
}

void Map::Init(int value)
{
    for(int i = 0; i < m_width; i++)
    {
        for(int j = 0; j < m_height; j++)
        {
            a_map[MapPosition(i,j, m_width)] = value;
        }
    }
}

void Map::Debug()
{
    qDebug() << getMapValue(3,4);
}

int Map::getWidth() const
{
    return m_width;
}

int Map::getHeight() const
{
    return m_height;
}

void Map::setWidth(int width)
{
    m_width = width;
}

void Map::setHeight(int height)
{
    m_height = height;
}

void Map::Draw(QImage *workImg, QImage tileImg, QPoint tilePos, QPoint tileSize)
{
    for(int i = 0; i < tileSize.x(); i++)
    {
        for(int j = 0; j < tileSize.y(); j++)
        {
            workImg->setPixelColor((tilePos.x() * tileSize.x()) + i,
                                   (tilePos.y() * tileSize.y()) + j,
                                    tileImg.pixelColor(i,j));
        }
    }
}

