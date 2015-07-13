#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighter.h"

class QTextEdit;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newFile();
    void openFile(); //const QString &path = QString()
    void saveFile();
    void about();
    void saveFileSource();


private:
    Ui::MainWindow *ui;
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    QTextEdit *editor;
    Highlighter *highlighter;
};

#endif // MAINWINDOW_H
