#ifndef NEWMAPDIALOG_H
#define NEWMAPDIALOG_H

#include "metadata.h"

#include <QDialog>


namespace Ui {
class NewMapDialog;
}

class NewMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMapDialog(MetaData* metaData, QWidget *parent = 0);
    ~NewMapDialog();

private slots:
    void on_Button_Creat_clicked();

private:
    Ui::NewMapDialog *ui;

    MetaData* p_metaData;
};

#endif // NEWMAPDIALOG_H
