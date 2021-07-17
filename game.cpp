#include "game.h"
#include "ui_game.h"
#include "job.h"
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <fstream>
#include <iostream>
#include <QTextStream>
#include<QString>
#include<QApplication>


Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
   // load();
    QTimer *timer = new QTimer();
                  timer->setInterval(1000);
                  timer->start();


                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock1()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock2()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock3()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock4()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock5()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock6()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock7()));
                 connect(timer, SIGNAL(timeout()),SLOT(UpdateClock8()));

                 job1.secondtime=10;
                 job1.upgrademoney=2;
                 job1.firstmoney=11;
                 job1.firsttime=job1.secondtime;

                 job2.secondtime=14;
                 job2.upgrademoney=4;
                 job2.firstmoney=15;
                 job2.firsttime=job2.secondtime;
                 job2.oppeningprice=50;

                 job3.secondtime=18;
                 job3.upgrademoney=7;
                 job3.firstmoney=19;
                 job3.firsttime=job3.secondtime;
                 job3.oppeningprice=100;

                 job4.secondtime=22;
                 job4.upgrademoney=10;
                 job4.firstmoney=21;
                 job4.firsttime=job4.secondtime;
                 job4.oppeningprice=150;

                 job5.secondtime=25;
                 job5.upgrademoney=12;
                 job5.firstmoney=24;
                 job5.firsttime=job5.secondtime;
                 job5.oppeningprice=200;

                 job6.secondtime=28;
                 job6.upgrademoney=15;
                 job6.firstmoney=26;
                 job6.firsttime=job6.secondtime;
                 job6.oppeningprice=250;

                 job7.secondtime=31;
                 job7.upgrademoney=18;
                 job7.firstmoney=30;
                 job7.firsttime=job7.secondtime;
                 job7.oppeningprice=300;

                 job8.secondtime=34;
                 job8.upgrademoney=21;
                 job8.firstmoney=32;
                 job8.firsttime=job8.secondtime;
                 job8.oppeningprice=350;
    check ();

//movie
prolabel->setMovie(movie);
QSize a;
a.setHeight(500);
a.setWidth(500);
movie->setScaledSize(a);
movie->start();


}

Game::~Game()
{
    delete ui;
}

void Game::save()
{
    QFile file( "data.txt" );
    if(!file.exists()){
        qDebug()<<file.fileName()<<" does not exist!\n";
    }
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream txtstream( &file );
        txtstream<<QString::number(money)<<"\n";

        txtstream<< QString::number(job1.firstmoney) <<","<<QString::number(job1.firsttime)<<","<<QString::number(job1.upgrademoney)<<","<<
                    QString::number(job1.level)<<","<<QString::number(job1.secondtime)<<"\n";

        txtstream<< QString::number(job2.firstmoney) <<","<<QString::number(job2.firsttime)<<","<<QString::number(job2.upgrademoney)<<","<<
                    QString::number(job2.level)<<","<<QString::number(job2.secondtime)<<","<<QString::number(job2.oppeningprice)<<"\n";

        txtstream<< QString::number(job3.firstmoney) <<","<<QString::number(job3.firsttime)<<","<<QString::number(job3.upgrademoney)<<","<<
                    QString::number(job3.level)<<","<<QString::number(job3.secondtime)<<","<<QString::number(job3.oppeningprice)<<"\n";

        txtstream<< QString::number(job4.firstmoney) <<","<<QString::number(job4.firsttime)<<","<<QString::number(job4.upgrademoney)<<","<<
                    QString::number(job4.level)<<","<<QString::number(job4.secondtime)<<","<<QString::number(job4.oppeningprice)<<"\n";

        txtstream<< QString::number(job5.firstmoney) <<","<<QString::number(job5.firsttime)<<","<<QString::number(job5.upgrademoney)<<","<<
                    QString::number(job5.level)<<","<<QString::number(job5.secondtime)<<","<<QString::number(job5.oppeningprice)<<"\n";

        txtstream<< QString::number(job6.firstmoney) <<","<<QString::number(job6.firsttime)<<","<<QString::number(job6.upgrademoney)<<","<<
                    QString::number(job6.level)<<","<<QString::number(job6.secondtime)<<","<<QString::number(job6.oppeningprice)<<"\n";

        txtstream<< QString::number(job7.firstmoney) <<","<<QString::number(job7.firsttime)<<","<<QString::number(job7.upgrademoney)<<","<<
                    QString::number(job7.level)<<","<<QString::number(job7.secondtime)<<","<<QString::number(job7.oppeningprice)<<"\n";

        txtstream<< QString::number(job8.firstmoney) <<","<<QString::number(job8.firsttime)<<","<<QString::number(job8.upgrademoney)<<","<<
                    QString::number(job8.level)<<","<<QString::number(job8.secondtime)<<","<<QString::number(job8.oppeningprice)<<"\n";
  }
}

void Game::load()
{
    QFile file("data.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error opening file: " << file.error();
        return;
    }

    QString line="";
    QTextStream stream(&file);
  //  while (!stream.atEnd()){

    line = stream.readLine();
    QString temp="";
    temp=line.split(",")[0];

    money=temp.toInt();

           line = stream.readLine();
           temp="";
           temp=line.split(",")[0];
           job1.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job1.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job1.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job1.level=temp.toInt();
           temp=line.split(",")[4];
           job1.secondtime=temp.toInt();


           line = stream.readLine();
          // temp="";
           temp=line.split(",")[0];
           job2.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job2.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job2.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job2.level=temp.toInt();
           temp=line.split(",")[4];
           job2.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job2.oppeningprice=temp.toInt();


           line = stream.readLine();
          // temp="";
           temp=line.split(",")[0];
           job3.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job3.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job3.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job3.level=temp.toInt();
           temp=line.split(",")[4];
           job3.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job3.oppeningprice=temp.toInt();

           line = stream.readLine();
         //  temp="";
           temp=line.split(",")[0];
           job4.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job4.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job4.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job4.level=temp.toInt();
           temp=line.split(",")[4];
           job4.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job4.oppeningprice=temp.toInt();


           line = stream.readLine();
       //    temp="";
           temp=line.split(",")[0];
           job5.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job5.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job5.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job5.level=temp.toInt();
           temp=line.split(",")[4];
           job5.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job5.oppeningprice=temp.toInt();

           line = stream.readLine();
        //   temp="";
           temp=line.split(",")[0];
           job6.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job6.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job6.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job6.level=temp.toInt();
           temp=line.split(",")[4];
           job6.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job6.oppeningprice=temp.toInt();

           line = stream.readLine();
     //      temp="";
           temp=line.split(",")[0];
           job7.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job7.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job7.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job7.level=temp.toInt();
           temp=line.split(",")[4];
           job7.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job7.oppeningprice=temp.toInt();

           line = stream.readLine();
      //     temp="";
           temp=line.split(",")[0];
           job8.firstmoney=temp.toInt();
           temp=line.split(",")[1];
           job8.firsttime=temp.toInt();
           temp=line.split(",")[2];
           job8.upgrademoney=temp.toInt();
           temp=line.split(",")[3];
           job8.level=temp.toInt();
           temp=line.split(",")[4];
           job8.secondtime=temp.toInt();
           temp=line.split(",")[5];
           job8.oppeningprice=temp.toInt();

           //testLabel->setText(line+"\n");
      // }
    //QString line = instream.readLine();

    qDebug() << "first line: " << line;
    setup();
    file.close();
    return;

}

void Game::setup()
{
    ui->Money->setText(QString::number(money));

    ui->Level1->setText(QString::number(job1.level));
    ui->Timer1->setText(QString::number(job1.firsttime));

    ui->Level2->setText(QString::number(job2.level));
    ui->Timer2->setText(QString::number(job2.firsttime));

    ui->Level3->setText(QString::number(job3.level));
    ui->Timer3->setText(QString::number(job3.firsttime));

    ui->Level4->setText(QString::number(job4.level));
    ui->Timer4->setText(QString::number(job4.firsttime));

    ui->Level5->setText(QString::number(job5.level));
    ui->Timer5->setText(QString::number(job5.firsttime));

    ui->Level6->setText(QString::number(job6.level));
    ui->Timer6->setText(QString::number(job6.firsttime));

    ui->Level7->setText(QString::number(job7.level));
    ui->Timer7->setText(QString::number(job7.firsttime));

    ui->Level8->setText(QString::number(job8.level));
    ui->Timer8->setText(QString::number(job8.firsttime));

}

/*void Game::playsound()
{
    music->setMedia(QUrl("res.qrc:/sounds/Hey Song (The Best Of) CD 1 TRACK 2 (320).mp3"));
    //music->setMedia(QUrl::fromLocalFile("C:/Users/Sara-PC/Desktop/ax/Hey Song (The Best Of) CD 1 TRACK 2 (320).mp3"));
    music->setVolume(50);
    music->play();
}*/

/*_________________________________________________________________________________________________*/
void Game::set(){
    ui->Money->setText(QString::number(money));
}

void Game:: check (){
    if (job2.level==0)
    {
        ui->UpdateClock2->setDisabled(true);
        ui->Upgrade2->setDisabled(true);
    }
    if(job3.level==0)
    {
        ui->UpdateClock3->setDisabled(true);
        ui->Upgrade3->setDisabled(true);
    }
    if(job4.level==0)
    {
        ui->UpdateClock4->setDisabled(true);
        ui->Upgrade4->setDisabled(true);
    }
    if(job5.level==0)
    {
        ui->UpdateClock5->setDisabled(true);
        ui->Upgrade5->setDisabled(true);
    }
    if(job6.level==0)
    {
        ui->UpdateClock6->setDisabled(true);
        ui->Upgrade6->setDisabled(true);
    }
    if(job7.level==0)
    {
        ui->UpdateClock7->setDisabled(true);
        ui->Upgrade7->setDisabled(true);
    }
    if(job8.level==0)
    {
        ui->UpdateClock8->setDisabled(true);
        ui->Upgrade8->setDisabled(true);
    }
}

/*__________________________________________________________________________*/

void Game::on_UpdateClock1_clicked()
{
    job1.clickflag=1;
    UpdateClock1();
    s.clickcounterfunction();
}

void Game::on_Upgrade1_clicked()
{
     upgradejob1();
}
void Game::UpdateClock1()
    {
    if( job1.firsttime>0&&job1.clickflag==1){
        job1.firsttime--;
        ui->Timer1->setText(QString::number(job1.firsttime));
        ui->progressBar1->setValue(100-job1.firsttime*100/job1.secondtime);
       }
    if(job1.firsttime==0){
        money+=job1.firstmoney;
        job1.clickflag=0;
        job1.firsttime=job1.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob1()
            {
    if(job1.upgrademoney<=money){
          money-=job1.upgrademoney;
              job1.firstmoney+=5;
              job1.level++;
              job1.upgrademoney+=7;
              set();
                       ui->Level1->setText(QString::number(job1.level));

        if(job1.level%10==0)
        {
            job1.secondtime--;
            job1.firsttime=job1.secondtime;
        }
    }
}
/*_______________________________________________________________________________________*/


void Game::UpdateClock2()
    {
    if( job2.firsttime>0&&job2.clickflag==1){
        job2.firsttime--;
        ui->Timer2->setText(QString::number(job2.firsttime));
               ui->progressBar2->setValue(100-job2.firsttime*100/job2.secondtime);
       }
    if(job2.firsttime==0){
        money+=job2.firstmoney;
        job2.clickflag=0;
        job2.firsttime=job2.secondtime;
        set();

     }save();
    }

void Game::upgradejob2()
            {
    if(job2.upgrademoney<=money){
          money-=job2.upgrademoney;
              job2.firstmoney+=6;
              job2.level++;
              job2.upgrademoney+=9;
              set();
                       ui->Level2->setText(QString::number(job2.level));
        if(job2.level%10==0)
        {
            job2.secondtime-=2;
            job2.firsttime=job2.secondtime;
         }
    }
 }


void Game::on_UpdateClock2_clicked()
{
    job2.clickflag=1;
        UpdateClock2();
          s.clickcounterfunction();
}

void Game::on_Upgrade2_clicked()
{
    upgradejob2();
}
/*_______________________________________________________________________________________*/

void Game::on_UpdateClock3_clicked()
{
    job3.clickflag=1;
        UpdateClock3();
       s.clickcounterfunction();
}

void Game::on_Upgrade3_clicked()
{
    upgradejob3();
}

void Game::UpdateClock3()
    {
    if( job3.firsttime>0&&job3.clickflag==1){
        job3.firsttime--;
        ui->Timer3->setText(QString::number(job3.firsttime));
               ui->progressBar3->setValue(100-job3.firsttime*100/job3.secondtime);
       }
    if(job3.firsttime==0){
        money+=job3.firstmoney;
        job3.clickflag=0;
        job3.firsttime=job3.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob3()
            {
    if(job3.upgrademoney<=money){
          money-=job3.upgrademoney;
              job3.firstmoney+=7;
              job3.level++;
              job3.upgrademoney+=10;
              set();
                       ui->Level3->setText(QString::number(job3.level));
      if(job3.level%10==0)
      {
          job3.secondtime-=2;
          job3.firsttime=job3.secondtime;
      }
}}


/*_______________________________________________________________________________*/

void Game::on_UpdateClock4_clicked()
{
    job4.clickflag=1;
       UpdateClock4();
         s.clickcounterfunction();
}

void Game::on_Upgrade4_clicked()
{
     upgradejob4();
}
void Game::UpdateClock4()
    {
    if( job4.firsttime>0&&job4.clickflag==1){
        job4.firsttime--;
        ui->Timer4->setText(QString::number(job4.firsttime));
               ui->progressBar4->setValue(100-job4.firsttime*100/job4.secondtime);
       }
    if(job4.firsttime==0){
        money+=job4.firstmoney;
        job4.clickflag=0;
        job4.firsttime=job4.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob4()
            {
    if(job4.upgrademoney<=money){
          money-=job4.upgrademoney;
              job4.firstmoney+=8;
              job4.level++;
              job4.upgrademoney+=10;
              set();
                       ui->Level4->setText(QString::number(job4.level));
     if(job4.level%10==0)
     {
        job4.secondtime-=3;
           job4.firsttime=job4.secondtime;
     }
   }
}

/*_____________________________________________________________________________*/
void Game::on_UpdateClock5_clicked()
{
    job5.clickflag=1;
        UpdateClock5();
          s.clickcounterfunction();
}

void Game::on_Upgrade5_clicked()
{
      upgradejob5();
}
void Game::UpdateClock5()
    {
    if( job5.firsttime>0&&job5.clickflag==1){
        job5.firsttime--;
        ui->Timer5->setText(QString::number(job5.firsttime));
         ui->progressBar5->setValue(100-job5.firsttime*100/job5.secondtime);
       }
    if(job5.firsttime==0){
        money+=job5.firstmoney;
        job5.clickflag=0;
        job5.firsttime=job5.secondtime;
        set();

     }save();
    }

void Game::upgradejob5()
            {
    if(job5.upgrademoney<=money){
          money-=job5.upgrademoney;
              job5.firstmoney+=9;
              job5.level++;
              job5.upgrademoney+=11;
              set();
                       ui->Level5->setText(QString::number(job5.level));
             if(job5.level%10==0)
             {
               job5.secondtime-=3;
               job5.firsttime=job5.secondtime;
             }
}}

/*___________________________________________________________________________*/



void Game::on_UpdateClock6_clicked()
{
    job6.clickflag=1;
       UpdateClock6();
         s.clickcounterfunction();
}

void Game::on_Upgrade6_clicked()
{
    upgradejob6();
}
void Game::UpdateClock6()
    {
    if( job6.firsttime>0&&job6.clickflag==1){
        job6.firsttime--;
        ui->Timer6->setText(QString::number(job6.firsttime));
         ui->progressBar6->setValue(100-job6.firsttime*100/job6.secondtime);
       }
    if(job6.firsttime==0){
        money+=job6.firstmoney;
        job6.clickflag=0;
        job6.firsttime=job6.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob6()
            {
    if(job6.upgrademoney<=money){
          money-=job6.upgrademoney;
              job6.firstmoney+=9;
              job6.level++;
              job6.upgrademoney+=11;
              set();
                       ui->Level6->setText(QString::number(job6.level));
    if(job6.level%10==0)
      {
       job6.secondtime-=4;
       job6.firsttime=job6.secondtime;
       }
}}

/*_______________________________________________________________________________*/


void Game::on_UpdateClock7_clicked()
{
    job7.clickflag=1;
        UpdateClock7();
          s.clickcounterfunction();
}

void Game::on_Upgrade7_clicked()
{
  upgradejob7();
}
void Game::UpdateClock7()
    {
    if( job7.firsttime>0&&job7.clickflag==1){
        job7.firsttime--;
        ui->Timer7->setText(QString::number(job7.firsttime));
         ui->progressBar7->setValue(100-job7.firsttime*100/job7.secondtime);
       }
    if(job7.firsttime==0){
        money+=job7.firstmoney;
        job7.clickflag=0;
        job7.firsttime=job7.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob7()
            {
    if(job7.upgrademoney<=money){
          money-=job7.upgrademoney;
              job7.firstmoney+=10;
              job7.level++;
              job7.upgrademoney+=12;
              set();
                       ui->Level7->setText(QString::number(job7.level));
            if(job7.level%10==0)
              {
                job7.secondtime-=4;
                job7.firsttime=job7.secondtime;
              }
}}

/*_______________________________________________________________________________*/


void Game::on_UpdateClock8_clicked()
{

    job8.clickflag=1;
    UpdateClock8();
      s.clickcounterfunction();
}

void Game::on_Upgrade8_clicked()
{
     upgradejob8();
}
void Game::UpdateClock8()
    {
    if( job8.firsttime>0&&job8.clickflag==1){
        job8.firsttime--;
        ui->Timer8->setText(QString::number(job8.firsttime));
         ui->progressBar8->setValue(100-job8.firsttime*100/job8.secondtime);
       }
    if(job8.firsttime==0){
        money+=job8.firstmoney;
        job8.clickflag=0;
        job8.firsttime=job8.secondtime;
        set();

     }
    save();
    }

void Game::upgradejob8()
            {
    if(job8.upgrademoney<=money){
          money-=job8.upgrademoney;
              job8.firstmoney+=11;
              job8.level++;
              job8.upgrademoney+=13;
              set();
                       ui->Level8->setText(QString::number(job8.level));

    if(job8.level%10==0)
      {
        job8.secondtime-=5;
        job8.firsttime=job8.secondtime;
     }
}}

/*______________________________________________________________________________*/


void Game::on_radioButton7_clicked()
{
    if(job7.oppeningprice<money)
        {
            job7.count++;
            if(job7.count==1)
            {
                money-=job7.oppeningprice;
                   set();
            }
            ui->UpdateClock7->setEnabled(true);
            ui->Upgrade7->setEnabled(true);
             s.unlockcounterfunction();
    }
}

void Game::on_radioButton2_clicked()
{
    if(job2.oppeningprice<money)
       {
           job2.count++;
           if(job2.count==1)
           {
               money-=job2.oppeningprice;
                set();
           }
           ui->UpdateClock2->setEnabled(true);
           ui->Upgrade2->setEnabled(true);
               s.unlockcounterfunction();
    }
}

void Game::on_radioButton3_clicked()
{
    if(job3.oppeningprice<money)
       {
           job3.count++;
           if(job3.count==1)
           {
               money-=job3.oppeningprice;
                set();
           }
           ui->UpdateClock3->setEnabled(true);
           ui->Upgrade3->setEnabled(true);
               s.unlockcounterfunction();
    }
}

void Game::on_radioButton4_clicked()
{
    if(job4.oppeningprice<money)
        {
            job4.count++;
            if(job4.count==1)
            {
                money-=job4.oppeningprice;
                 set();
            }
            ui->UpdateClock4->setEnabled(true);
            ui->Upgrade4->setEnabled(true);
           s.unlockcounterfunction();
    }
}

void Game::on_radioButton5_clicked()
{
    if(job5.oppeningprice<money)
        {
            job5.count++;
            if(job5.count==1)
            {
                money-=job5.oppeningprice;
                 set();
            }
            ui->UpdateClock5->setEnabled(true);
            ui->Upgrade5->setEnabled(true);
               s.unlockcounterfunction();
    }
}

void Game::on_radioButton6_clicked()
{
    if(job6.oppeningprice<money)
        {
            job6.count++;
            if(job6.count==1)
            {
                money-=job6.oppeningprice;
                 set();
            }
            ui->UpdateClock6->setEnabled(true);
            ui->Upgrade6->setEnabled(true);
               s.unlockcounterfunction();
    }
}

void Game::on_radioButton8_clicked()
{
    if(job8.oppeningprice<money)
        {
            job8.count++;
            if(job8.count==1)
            {
                money-=job8.oppeningprice;
                set();
            }
            ui->UpdateClock8->setEnabled(true);
            ui->Upgrade8->setEnabled(true);
               s.unlockcounterfunction();
    }
}
/*_____________________________________________________________________________________________*/
/*QByteArray Game::read()
{
    QByteArray data;
    QFile file("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    // You could use readAll() here, too.
    while (!in.atEnd()) {
        QString line = in.readLine();
        data.append(line);
    }

    file.close();
    return data;
}

void Game::write(QByteArray data)
{
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.write(data);
    file.close();
}*/

void Game::on_gostate_clicked()
{
    s.show();
}

/*void Game::on_home_clicked()
{
   qApp->closeAllWindows();

    m->show();
}*/

void Game::on_home_clicked()
{
    parentWindow->show();
    this->close();
}
