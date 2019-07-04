#include "mapeditor.h"
#include "ui_mapeditor.h"
#include "tilegraphicsview.h"
#include "QString"

MapEditor::MapEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapEditor),
    m_metaData()
{
    ui->setupUi(this);
    ui->TileView->setData(&m_metaData);
    ui->WorkView->setData(&m_metaData);

    ui->NewMap->setEnabled(false); // desactivate select tilesheet button avoid to used map = NULL

    connect(&m_metaData, SIGNAL(metaTileSheet_IsChanged(MetaData*)),
            ui->TileView, SLOT(on_TileSheet_isChanged(MetaData*)));

    connect(&m_metaData, SIGNAL(metaName_IsChanged(MetaData*)),
            this, SLOT(on_MetaName_IsChanged(MetaData*)));

    connect(&m_metaData, SIGNAL(metaMap_SetButton(bool)),
            ui->NewMap, SLOT(setEnabled(bool)));

    connect(&m_metaData, SIGNAL(metaMap_IsChanged(MetaData*)),
            ui->WorkView, SLOT(on_Map_IsChanged(MetaData*)));
}

MapEditor::~MapEditor()
{
    disconnect(&m_metaData, SIGNAL(metaTileSheet_IsChanged(MetaData*)),
               ui->TileView, SLOT(on_TileSheet_isChanged(MetaData*)));

    disconnect(&m_metaData, SIGNAL(metaName_IsChanged(MetaData*)),
               this, SLOT(on_MetaName_IsChanged(MetaData*)));

    disconnect(&m_metaData, SIGNAL(metaMap_SetButton(bool)),
                ui->NewMap, SLOT(setEnabled(bool)));

    disconnect(&m_metaData, SIGNAL(metaMap_IsChanged(MetaData*)),
            ui->WorkView, SLOT(on_Map_IsChanged(MetaData*)));

    delete ui;
}

void MapEditor::on_actionNew_triggered()
{
    NewMapDialog* dialog = new NewMapDialog(&m_metaData);
    dialog->show();
}

void MapEditor::on_MetaName_IsChanged(MetaData* metaData)
{
    this->setWindowTitle(metaData->getName());
}

void MapEditor::on_NewMap_clicked()
{
    QString fileDiag = QFileDialog::getOpenFileName(nullptr, tr("Images"), "Desktop", tr("Images (*.png)"));
    m_metaData.setImage(new QImage(fileDiag));
    QString tmp = "";

    for(QString::iterator iter = fileDiag.end() - 1;iter >= fileDiag.begin(); iter--)
    {
        if(*iter == '/')
        {
            iter = fileDiag.begin();
        }
        else
        {
            tmp.push_front(*iter);
        }
    }

    m_metaData.setCurTilesheetName(tmp);
}
