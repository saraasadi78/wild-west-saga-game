#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&Dialog::on_positionchanged);
    connect(player,&QMediaPlayer::durationChanged,this,&Dialog::on_durationchanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_progressSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void Dialog::on_slider_sliderMoved(int position ) //volume
{
    player->setVolume(position);
}

void Dialog::on_start_clicked()
{
    //load the file
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\Sara-PC\\Desktop\\wws\\faded.mp3"));
    player->play();
    qDebug()<<player->errorString();
}

void Dialog::on_stop_clicked()
{
    player->stop();
}

void Dialog::on_durationchanged(qint64 position)
{
    ui->progressSlider->setMaximum(position);
}

void Dialog::on_positionchanged(qint64 position)
{
     ui->progressSlider->setValue(position);
}
