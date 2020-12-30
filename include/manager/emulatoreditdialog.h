#pragma once

#include <QDialog>

#include <QFileDialog>

#include <database/database.h>

#include "manager/platformlistmodel.h"

namespace Ui {
    class EmulatorEditDialog;
}

class EmulatorEditDialog : public QDialog
{
    Q_OBJECT

protected:
    Entities::Emulator m_emulator;

    PlatformListModel* p_platform_list_model;

public:
    explicit EmulatorEditDialog(QWidget *parent = nullptr);
    ~EmulatorEditDialog();

    void load(const Entities::Emulator& emulator);
    Entities::Emulator resultEmulator();

private:
    Ui::EmulatorEditDialog *ui;

public slots:
    void pathSelectDialog();
};

