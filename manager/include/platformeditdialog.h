#pragma once

#include <QDialog>

#include <database.h>

namespace Ui {
    class PlatformEditDialog;
}

class PlatformEditDialog : public QDialog
{
    Q_OBJECT

protected:
    Database::Entities::Platform m_platform;

public:
    explicit PlatformEditDialog(QWidget *parent = nullptr);
    ~PlatformEditDialog();

    void load(const Database::Entities::Platform& platform);
    Database::Entities::Platform resultPlatform();

private:
    Ui::PlatformEditDialog *ui;
};

