#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //viewContext->setContextProperty("Game", game);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Game_clicked()
{
    game.show();
    game.parentWindow=this;
    this->close();

}

void MainWindow::on_exite_clicked()
{
    this->destroy();
}

void MainWindow::on_setting_clicked()
{
    setting.show();
    setting.parentWindo=this;
    this->close();
}
