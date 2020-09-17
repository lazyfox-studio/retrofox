QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    include \
    ../database/include \
    ../api-service/include \
    D:/Libraries/Python/include \
    E:/Libraries/Python/include \
    /usr/include/python3.8 \
    D:/Libraries/SQLite \
    E:/Libraries/SQLite

win32 {
LIBS += \
    -L"$$_PRO_FILE_PWD_/../sln/x64/Debug" \
    -lapi-service \
    -ldatabase \
    -L"D:/Libraries/Python/lib" \
    -L"E:/Libraries/Python/lib" \
    -lpython38_d \
    -L"D:/Libraries/SQLite" \
    -L"E:/Libraries/SQLite" \
    -lsqlite3
}

!win32 {
    LIBS += \
        -L"$$_PRO_FILE_PWD_/.." \
        -lapi-service \
        -ldatabase \
        -L "/usr/lib/x86_64-linux-gnu" \
        -lpython3.8 \
        -lsqlite3
}

SOURCES += \
    src/emulatoreditdialog.cpp \
    src/emulatorlistmodel.cpp \
    src/emulatorstablemodel.cpp \
    src/gamesimportwizard/dataprocessingpage.cpp \
    src/gamesimportwizard/finalpage.cpp \
    src/gamesimportwizard/gameselectpage.cpp \
    src/gamesimportwizard/pathselectpage.cpp \
    src/gamesimportwizard/scrapertablemodel.cpp \
    src/gamesimportwizard/shareddata.cpp \
    src/gamesimportwizard/welcomepage.cpp \
    src/gameeditdialog.cpp \
    src/gamesimportwizard/wizard.cpp \
    src/gamestablemodel.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/platformeditdialog.cpp \
    src/platformlistmodel.cpp \
    src/platformstablemodel.cpp \
    src/scraper.cpp \
    src/scraper/findgamesinformation.cpp \
    src/scraper/functions.cpp \
    src/scraper/scanfolder.cpp

HEADERS += \
    include/emulatoreditdialog.h \
    include/emulatorlistmodel.h \
    include/emulatorstablemodel.h \
    include/gameeditdialog.h \
    include/gamesimportwizard/dataprocessingpage.h \
    include/gamesimportwizard/finalpage.h \
    include/gamesimportwizard/finalpage.h \
    include/gamesimportwizard/gameselectpage.h \
    include/gamesimportwizard/pages.h \
    include/gamesimportwizard/pathselectpage.h \
    include/gamesimportwizard/scrapertablemodel.h \
    include/gamesimportwizard/shareddata.h \
    include/gamesimportwizard/welcomepage.h \
    include/gamesimportwizard/wizard.h \
    include/gamestablemodel.h \
    include/mainwindow.h \
    include/platformeditdialog.h \
    include//platformlistmodel.h \
    include/platformstablemodel.h \
    include/scraper.h \
    include/scraper/findgamesinformation.h \
    include/scraper/functions.h \
    include/scraper/scanfolder.h

FORMS += \
    ui/emulatoreditdialog.ui \
    ui/gamesimportwizard/dataprocessingpage.ui \
    ui/gamesimportwizard/finalpage.ui \
    ui/gamesimportwizard/gameselectpage.ui \
    ui/gamesimportwizard/pathselectpage.ui \
    ui/gamesimportwizard/welcomepage.ui \
    ui/gameeditdialog.ui \
    ui/mainwindow.ui \
    ui/platformeditdialog.ui

TRANSLATIONS += \
    translations/manager_en_US.ts \
    translations/manager_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

win32
{
    RC_ICONS = resources/icons/manager.ico
}
