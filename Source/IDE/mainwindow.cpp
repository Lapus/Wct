#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QFile>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupEditor();
    setupFileMenu();
    setCentralWidget(editor);
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::setupEditor()
 {

     QFont font;
     font.setFamily("Droid Sans Mono"); //Courier
     font.setFixedPitch(true);
     font.setPointSize(10);

     editor = new QTextEdit;
     editor->setFont(font);

     highlighter = new Highlighter(editor->document());

     QFile file("mainwindow.h");
     if (file.open(QFile::ReadOnly | QFile::Text))
         editor->setPlainText(file.readAll());
 }

  void MainWindow::openFile() //const QString &path
  {
           QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
              tr("Wct Project (*.wctpr);;Wct Source (*.wctsrc)"));


           if (fileName != "") {
               QFile file(fileName);
               if (!file.open(QIODevice::ReadOnly)) {
                   QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                   return;
               }
               QTextStream in(&file);
               editor->setText(in.readAll());
               file.close();
           }
       }
  void MainWindow::saveFile()
  {
           QString fileName = QFileDialog::getSaveFileName(this, tr("Save Project"), "",
           tr("Wct Project (*.wctpr)"));

           if (fileName != "") {
               QFile file(fileName);
               if (!file.open(QIODevice::WriteOnly)) {
                   QMessageBox::critical(this, tr("Error"), tr("Could not save"));
               } else {
                  QTextStream stream(&file);
                   stream << editor->toPlainText();
                   stream.flush();
                   file.close();
               }
           }
      }
 void MainWindow::newFile()
  {
      editor->clear();
  }


 void MainWindow::saveFileSource()
 {
   QString fileName = QFileDialog::getSaveFileName(this, tr("Save Source"), "",
   tr("Wct Source (*.wctpr)"));

   if (fileName != "") {
       QFile file(fileName);
       if (!file.open(QIODevice::WriteOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("Could not save"));
       } else {
          QTextStream stream(&file);
           //stream << editor->toPlainText();
           //stream.flush();
           //file.close();

           QStringList list = editor->toPlainText().split("\n");
           QStringList list2;
           foreach (QString line, list) {
               int pos = line.indexOf("//");
               if (pos != -1 && pos < line.size())
                   line = line.left(pos);
               list2 << line;
             }
               stream << list2.join("").replace(" ", "");
               stream.flush();
               file.close();

       }
   }

 }

 void MainWindow::about()
  {
      QMessageBox::about(this, tr("About Wct Editor"),
                  tr("<p>The <b>Wct Editor</b> was made by: <p>" \
                     "<p><b>Andrew Zimnitskiy</b> - Main Programmer <p>" \
                     "<A HREF='https://vk.com/macleopard'>VK PAGE</A>" \
                     "<p><b>Mihail Podivilov</b> - Creator of Wct Num. Sys. <p>" \
                     "<A HREF='https://vk.com/id172535832'>VK PAGE</A>" \
                     ));
  }

 void MainWindow::setupFileMenu()
  {
      QMenu *fileMenu = new QMenu(tr("&File"), this);
      menuBar()->addMenu(fileMenu);

      fileMenu->addAction(tr("&New"), this, SLOT(newFile()),
                          QKeySequence::New);

      fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()),
                          QKeySequence::Open);

      fileMenu->addAction(tr("&Save Wct project..."), this, SLOT(saveFile()),
                          QKeySequence::Save);

      fileMenu->addAction(tr("&Save Wct source..."), this, SLOT(saveFileSource()),
                          QKeySequence::SaveAs);

      fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()),
                          QKeySequence::Quit);

      QMenu *helpMenu = new QMenu(tr("&Help"), this);
           menuBar()->addMenu(helpMenu);

      helpMenu->addAction(tr("&About"), this, SLOT(about()));




  }

