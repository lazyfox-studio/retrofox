#pragma once

#include <QDialog>

#include <QString>

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

    void load(const Database::Entities::Platform& platform, const std::vector<std::string>& extensions);
    Database::Entities::Platform resultPlatform();
    std::vector<std::string> resultExtensions();


private:
    Ui::PlatformEditDialog *ui;
};

