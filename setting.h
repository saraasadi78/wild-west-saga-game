#ifndef SETTING_H
#define SETTING_H
#include "game.h"
#include <QWidget>
#include "dialog.h"

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
      QWidget *parentWindo;
//QMediaPlayer* player;
Dialog d;
private slots:
    void on_LoginBtn_clicked();

    void on_pushButton_2_clicked();

   /* void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_pushButton_3_clicked();
    void on_durationchanged(qint64 position);
    void on_positionchanged(qint64 position);


    void on_pushButton_clicked();*/

    void on_SoundPage_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
