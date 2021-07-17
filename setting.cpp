#include "setting.h"
#include "ui_setting.h"
#include "QMessageBox"
#include<QMediaPlayer>
#include<QDebug>
#include <QSound>
Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
 /*   player=new QMediaPlayer(this);
    connect(player,&QMediaPlayer::durationChanged,this,&Setting::on_durationchanged);
    connect(player,&QMediaPlayer::positionChanged,this,&Setting::on_positionchanged);*/
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_LoginBtn_clicked()
{
    QMessageBox::information(this,"login","Your information saved successfully!");
}

void Setting::on_pushButton_2_clicked() //about
{
     QMessageBox::information(this,"about","Game is so simple! Just click on the jobs to earn more money & to unlock more jobs! Hope you enjoy our little game!");
}

/*void Setting::on_pushButton_clicked()//stop
{
player->stop();

}

void Setting::on_horizontalSlider_sliderMoved(int position)//progress
{
player->setPosition(position);
}


void Setting::on_horizontalSlider_2_sliderMoved(int position)//volume
{
player->setVolume(position);
}

void Setting::on_pushButton_3_clicked()//start
{
//player->setMedia(QUrl::fromLocalFile("C:/Users/Sara-PC/Desktop/abc/wwsmenu/Hey Song (The Best Of) CD 1 TRACK 2 (320).mp3"));
player->setMedia(QUrl::fromLocalFile("C:/Users/Sara-PC/Desktop/abc/Hey.mp3"));
player->play();
qDebug()<<player->errorString();
QSound::play("C:/Users/Sara-PC/Desktop/abc/Hey.mp3");

}

void Setting::on_durationchanged(qint64 position)
{
ui->horizontalSlider->setMaximum(position);
}


void Setting::on_positionchanged(qint64 position)
{
ui->horizontalSlider->setValue(position);

}*/



void Setting::on_SoundPage_clicked()
{
    d.show();
}

void Setting::on_pushButton_3_clicked()
{
    parentWindo->show();
    this->close();
}
