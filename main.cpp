#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Dark theme stylesheet
    a.setStyleSheet(
        "QMainWindow { background-color: #2b2b2b; }"
        "QMenuBar { background-color: #3c3f41; color: #bbbbbb; border-bottom: 1px solid #555555; }"
        "QMenuBar::item { background-color: transparent; padding: 4px 10px; }"
        "QMenuBar::item:selected { background-color: #4b6eaf; color: #ffffff; }"
        "QMenuBar::item:pressed { background-color: #4b6eaf; }"
        "QMenu { background-color: #3c3f41; color: #bbbbbb; border: 1px solid #555555; }"
        "QMenu::item { padding: 5px 25px 5px 20px; }"
        "QMenu::item:selected { background-color: #4b6eaf; color: #ffffff; }"
        "QMenu::separator { height: 1px; background-color: #555555; margin: 4px 10px; }"
        "QToolBar { background-color: #3c3f41; border: none; spacing: 3px; padding: 3px; }"
        "QToolBar::separator { background-color: #555555; width: 1px; margin: 4px 2px; }"
        "QToolButton { background-color: transparent; color: #bbbbbb; border: 1px solid transparent; border-radius: 3px; padding: 4px 8px; }"
        "QToolButton:hover { background-color: #4b6eaf; border: 1px solid #4b6eaf; color: #ffffff; }"
        "QToolButton:pressed { background-color: #3d5a96; }"
        "QStatusBar { background-color: #3c3f41; color: #bbbbbb; border-top: 1px solid #555555; }"
        "QWidget { background-color: #2b2b2b; color: #bbbbbb; }"
    );

    MainWindow w;
    w.show();
    return a.exec();
}
