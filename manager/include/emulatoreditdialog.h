#pragma once

#include <QDialog>

#include <QFileDialog>

#include "database.h"
#include "platformlistmodel.h"

namespace Ui {
    class EmulatorEditDialog;
}

class EmulatorEditDialog : public QDialog
{
    Q_OBJECT

protected:
    Database::Entities::Emulator m_emulator;

    long m_result_platform_id;

    PlatformListModel* p_platform_list_model;

public:
    explicit EmulatorEditDialog(QWidget *parent = nullptr);
    ~EmulatorEditDialog();

    void load(const Database::Entities::Emulator& emulator);
    Database::Entities::Emulator resultEmulator();

private:
    Ui::EmulatorEditDialog *ui;

public slots:
    void pathSelectDialog();
    void selectPlatform(int index);
};

