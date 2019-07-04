#include "metadata.h"

MetaData::MetaData(QObject *parent) :
    QObject(parent),
    p_map(NULL),
    p_TileSheetImage(NULL),
    m_tileSize(0,0),
    m_name("Unamed"),
    m_curTilesheetName(""),
    m_tmpTile(NULL)
{

}

MetaData::~MetaData()
{
    v_tilesheet.clear();
    delete p_map;

}

QString MetaData::getName() const
{
    return m_name;
}

void MetaData::setName(const QString &value)
{
    m_name = value;
    emit metaName_IsChanged(this);
}

Map *MetaData::getMap() const
{
    return p_map;
}

void MetaData::setMap(Map *value, QPoint point)
{
    if(p_map != NULL)
        delete p_map;

    p_map = value;
    m_tileSize = point;

    emit metaMap_IsChanged(this);
    emit metaMap_SetButton(p_map != NULL ? true : false);
}

QImage *MetaData::getImage() const
{
    return p_TileSheetImage;
}

void MetaData::setImage(QImage *value)
{
    p_TileSheetImage = value;
    emit metaTileSheet_IsChanged(this);
}

QPoint MetaData::getTileSize() const
{
    return m_tileSize;
}

void MetaData::setTileSize(const QPoint &value)
{
    m_tileSize = value;
}

QString MetaData::getCurTilesheetName() const
{
    return m_curTilesheetName;
}

void MetaData::setCurTilesheetName(const QString &curTilesheetName)
{
    m_curTilesheetName = curTilesheetName;
}

Tile *MetaData::getTmpTile() const
{
    return m_tmpTile;
}

void MetaData::setTmpTile(Tile *tmpTile)
{
    if(m_tmpTile != NULL)
        delete m_tmpTile;

    m_tmpTile = tmpTile;
}

Tile *MetaData::GetTile(int id)
{
    if(id < v_tilesheet.count())
    {
        return v_tilesheet[id];
    }

    return 0;
}

int MetaData::getCurtileID() const
{
    return curtileID;
}

void MetaData::setCurtileID(int value)
{
    if(value >= v_tilesheet.count())
        curtileID = v_tilesheet.count() - 1;
    else
        curtileID = value;
}

int MetaData::AddTile(Tile* tile)
{
    for(int i = 0; i < v_tilesheet.count(); i++)
    {
        if(v_tilesheet[i]->getTileSheetName() == tile->getTileSheetName())
        {
            if(v_tilesheet[i]->getTileSheetPosition() == tile->getTileSheetPosition())
            {
                delete tile;
                return i;
            }
        }
    }

    v_tilesheet.append(tile);
    return v_tilesheet.count() - 1;
}
