#ifndef MAP_H
#define MAP_H

#include <QDebug>
#include <QImage>
class Map
{

public:
    Map(int width, int height);
    ~Map();

    void Init(int value);
    void Debug();

    inline int getMapValue(int x, int y){ return a_map[MapPosition(x,y, m_width)]; }
    inline void setMapValue(int x, int y, int value){ a_map[MapPosition(x,y, m_width)] = value; }

    inline static int MapPosition(int x, int y, int line_lenght) { return x * line_lenght + y; }

    int getWidth() const;
    int getHeight() const;

    void setWidth(int width);
    void setHeight(int height);

    void Draw(QImage* workImg, QImage tileImg, QPoint tilePos, QPoint tileSize);

private:
    int m_width;
    int m_height;
    int* a_map;
};

#endif // MAP_H
