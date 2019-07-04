#include "tilesheet.h"

TileSheet::TileSheet(QObject *parent) : QObject(parent)
{

}

TileSheet::~TileSheet()
{
    v_tilesheet.clear();
}

int TileSheet::getWidth() const
{
    return m_width;
}

void TileSheet::setWidth(int value)
{
    m_width = value;
}

int TileSheet::getHeight() const
{
    return m_height;
}

void TileSheet::setHeight(int value)
{
    m_height = value;
}
