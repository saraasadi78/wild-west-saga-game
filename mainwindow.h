#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "game.h"
#include <QMainWindow>
#include "setting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Game game;
    Setting setting;

private slots:
    void on_Game_clicked();

    void on_exite_clicked();

    void on_setting_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
