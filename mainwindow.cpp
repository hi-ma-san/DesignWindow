#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentFilePath = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("開啟檔案"), "",
        tr("文字檔 (*.txt);;所有檔案 (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("錯誤"),
                tr("無法開啟檔案:\n%1").arg(fileName));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
        file.close();

        currentFilePath = fileName;
        setWindowTitle(tr("DesignWindow - %1").arg(fileName));
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (currentFilePath.isEmpty()) {
        on_actionASave_triggered();
        return;
    }

    QFile file(currentFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("錯誤"),
            tr("無法儲存檔案:\n%1").arg(currentFilePath));
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.close();

    QMessageBox::information(this, tr("成功"),
        tr("檔案已儲存"));
}

void MainWindow::on_actionASave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("另存新檔"), "",
        tr("文字檔 (*.txt);;所有檔案 (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("錯誤"),
                tr("無法儲存檔案:\n%1").arg(fileName));
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();

        currentFilePath = fileName;
        setWindowTitle(tr("DesignWindow - %1").arg(fileName));
        QMessageBox::information(this, tr("成功"),
            tr("檔案已儲存"));
    }
}
