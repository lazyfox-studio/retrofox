#pragma once

#include <QDialog>

#include <QString>

#include <database.h>

#include "emulatorlistmodel.h"

namespace Ui {
    class PlatformEditDialog;
}

class PlatformEditDialog : public QDialog
{
    Q_OBJECT

protected:
    Entities::Platform m_platform;

    EmulatorListModel* p_emulator_list_model;

public:
    explicit PlatformEditDialog(QWidget *parent = nullptr);
    ~PlatformEditDialog();

    void load(const Entities::Platform& platform,
              const std::vector<Entities::Extension>& extensions);
    Entities::Platform resultPlatform();
    std::vector<Entities::Extension> resultExtensions();


private:
    Ui::PlatformEditDialog *ui;
};

