#include "newmapdialog.h"
#include "ui_newmapdialog.h"

NewMapDialog::NewMapDialog(MetaData* metaData, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMapDialog)
{
    ui->setupUi(this);
    p_metaData = metaData;
    ui->nameLineEdit->setValidator(new QRegExpValidator( QRegExp("[a-z-A-Z-0-9]{1,20}"), this ));
}

NewMapDialog::~NewMapDialog()
{
    delete ui;
}

void NewMapDialog::on_Button_Creat_clicked()
{
    p_metaData->setMap(new Map(ui->SpinBox_MapWidth->value(),ui->SpinBox_MapHeight->value()),
                           QPoint(ui->SpinBox_TileWidth->value(), ui->SpinBox_TileHeight->value()));
    p_metaData->setName(ui->nameLineEdit->text());

    delete this;
}
