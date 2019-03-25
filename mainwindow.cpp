#include "mainwindow.h"
#include "ui_mainwindow.h"

//Qt generated code to show the main window
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui -> textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Creating a new file.
void MainWindow::on_actionNew_triggered()
{
    thisFile.clear();
    ui->textEdit->setText(QString());

}

//Opening a file
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open this file");
    QFile file(fileName);
    thisFile = fileName;

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString input = in.readAll();
    ui->textEdit->setText(input);
    file.close();
}

//Saving a file
void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }

    thisFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString output = ui->textEdit->toPlainText();
    out << output;
    file.close();
}

//Printing support
void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;

    printer.setPrinterName("Printer Name");

    QPrintDialog printerDialog(&printer, this);

    if(printerDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot access printer");
        return;
    }

    ui -> textEdit -> print(&printer);
}

//Quick functions for quiting, copying, cutting, pasting, redo/undo

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionEdit_triggered()
{
    ui-> textEdit ->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui-> textEdit ->cut();

}

void MainWindow::on_actionPaste_triggered()
{
    ui-> textEdit ->paste();

}

void MainWindow::on_actionUndo_triggered()
{
    ui-> textEdit ->undo();

}

void MainWindow::on_actionRedo_triggered()
{
    ui-> textEdit ->redo();

}
