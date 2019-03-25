#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFileDevice>
#include<QTextStream>
#include<QMessageBox>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

//Header File for the Notepad. It describes the classes that are present in the
//program to make it function.

//UI Classes and Functions
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//Functions that deal with actions such as print, open etc.
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionEdit_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MainWindow *ui;
    QString thisFile = "";
};

#endif // MAINWINDOW_H
