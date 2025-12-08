#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("開啟檔案"), "", tr("文字檔 (*.txt);;所有檔案 (*)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("錯誤"), tr("無法開啟檔案:\n%1").arg(fileName));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
        file.close();
    }
}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionASave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存新檔"), "", tr("文字檔 (*.txt);;所有檔案 (*)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("錯誤"), tr("無法儲存檔案:\n%1").arg(fileName));
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();

        setWindowTitle(tr("DesignWindow - %1").arg(QFileInfo(fileName).fileName()));
        QMessageBox::information(this, tr("成功"), tr("檔案已儲存"));
    }
}

