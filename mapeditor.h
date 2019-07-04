#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "metadata.h"
#include "tilegraphicsview.h"
#include "newmapdialog.h"

#include <QMainWindow>
#include <QFileDialog>
#include <qiterator.h>
namespace Ui {
class MapEditor;
}

class MapEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapEditor(QWidget *parent = 0);
    ~MapEditor();

private:
    Ui::MapEditor *ui;

    MetaData m_metaData;

private slots:
    void on_actionNew_triggered();
    void on_MetaName_IsChanged(MetaData* metaData);
    void on_NewMap_clicked();

};

#endif // MAPEDITOR_H
