#pragma once

#include <memory>

#include <QMainWindow>
#include <QTranslator>
#include <QWidget>
#include <QDebug>

#include "manager/aboutdialog.h"
#include "manager/emulatorstablemodel.h"
#include "manager/emulatoreditdialog.h"
#include "manager/gameeditdialog.h"
#include "manager/gamesimportwizard/wizard.h"
#include "manager/gamestablemodel.h"
#include "manager/platformeditdialog.h"
#include "manager/platformstablemodel.h"

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

protected:
    /// List of tables indices
    enum TableIndex
    {
        Games = 0, ///< Games table
        Platforms = 1, ///< Platforms table
        Emulators = 2, ///< Emulators table
    };

    /// Emulators Qt table model
    EmulatorsTableModel* p_emulators_table_model;

    /// Games Qt table model
    GamesTableModel* p_games_table_model;

    /// Platforms Qt table model
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
     * @brief Opens dialog for editing game info
     * @param index Game index
     */
    void editGame(const QModelIndex & index);

    /**
     * @brief Opens dialog for editing platform info
     * @param index Platform index
     */
    void editPlatform(const QModelIndex& index);

    /**
     * @brief Opens dialog for editing emulator info
     * @param index Emulator index
     */
    void editEmulator(const QModelIndex& index);

    void insertRecord();

    void editRecord();

    void removeRecords();

    void showAboutDialog();

    /// Translates app into English
    void setLanguageEnglish();

    /// Translates app into Russian
    void setLanguageRussian();
};
