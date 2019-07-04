#ifndef METADATA_H
#define METADATA_H

#include <map.h>
#include "tile.h"

#include <QObject>
#include <QImage>
#include <QString>
#include <QVector>
#include <QPoint>

class MetaData : public QObject
{
    Q_OBJECT
public:
    explicit MetaData(QObject *parent = 0);
    ~MetaData();

    QString getName() const;
    void setName(const QString &value);

    Map *getMap() const;
    void setMap(Map *value, QPoint point);

    QImage *getImage() const;
    void setImage(QImage *value);

    QPoint getTileSize() const;
    void setTileSize(const QPoint &value);

    QString getCurTilesheetName() const;
    void setCurTilesheetName(const QString &curTilesheetName);

    Tile *getTmpTile() const;
    void setTmpTile(Tile *tmpTile);

    int AddTile(Tile *tile);
    Tile *GetTile(int id);
    Tile *GetCurTile() { return GetTile(getCurtileID()); }

    int getCurtileID() const;
    void setCurtileID(int value);

private:
    Map *p_map;
    QImage *p_TileSheetImage;
    QPoint m_tileSize;
    QString m_name;
    QString m_curTilesheetName;
    Tile *m_tmpTile;
    QVector<Tile*> v_tilesheet;
    int curtileID;

signals:
    void metaTileSheet_IsChanged(MetaData* metaData);
    void metaMap_IsChanged(MetaData* metaData);
    void metaMap_SetButton(bool value);
    void metaName_IsChanged(MetaData* metaData);

public slots:
};

#endif // METADATA_H
