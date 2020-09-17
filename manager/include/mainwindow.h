#pragma once

#include <memory>

#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QDebug>

#include "emulatorstablemodel.h"
#include "emulatoreditdialog.h"
#include "gameeditdialog.h"
#include "gamesimportwizard/wizard.h"
#include "gamestablemodel.h"
#include "platformeditdialog.h"
#include "platformstablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @ingroup manager
 * @brief Main window of manager application
 * @details Class to represent main window of application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Emulators table Qt model
    EmulatorsTableModel* p_emulators_table_model;

    /// Games table Qt model
    GamesTableModel* p_games_table_model;

    // Platforms table QT model
    PlatformsTableModel* p_platforms_table_model;

    /// Wizard
    std::shared_ptr<QWizard> wizard;

    /// UI elements
    Ui::MainWindow *ui;

    /// App translator
    QTranslator translator;

    /**
     * @brief Translates application to preferred locale
     * @param locale Locale to translate
     * @return True on success
     */
    bool setLanguage(const QLocale& locale);

public:
    /**
     * @brief Constructor-initializer
     * @param parent Parent widget
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /// Destructor
    ~MainWindow();

public slots:
    /// Imports games
    void importGames();

    /**
     * @brief Edits game info
     * @param index Game index
     */
    void editGame(const QModelIndex & index);

    void editPlatform(const QModelIndex& index);

    void editEmulator(const QModelIndex& index);

    void removeRecords();

    /// Translates app into English
    void setLanguageEnglish();

    /// Translates app into Russian
    void setLanguageRussian();
};
