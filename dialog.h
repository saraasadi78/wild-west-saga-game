#ifndef DIALOG_H
#define DIALOG_H
#include<QMediaPlayer>
#include <QDialog>
#include<QDebug>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    private slots:
    void on_progressSlider_sliderMoved(int position);

    void on_slider_sliderMoved(int position);

    void on_start_clicked();

    void on_stop_clicked();

    void on_durationchanged(qint64 position);
    void on_positionchanged(qint64 position);

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
};

#endif // DIALOG_H
