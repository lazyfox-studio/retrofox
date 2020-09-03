#pragma once

#include <memory>

#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QDebug>

#include "gameeditdialog.h"
#include "gamesimportwizard/wizard.h"
#include "gamestablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    GamesTableModel* games_table_model;

    std::shared_ptr<QWizard> wizard;

private:
    Ui::MainWindow *ui;
    QTranslator translator;

    bool setLanguage(const QLocale& locale);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void importGames();
    void editGame(const QModelIndex & index);

    void setLanguageEnglish();
    void setLanguageRussian();
};
