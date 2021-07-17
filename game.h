#ifndef GAME_H
#define GAME_H
#include<job.h>
#include <QWidget>
#include<QTimer>
 #include <QJsonObject>
#include <QJsonDocument>
#include<QFile>
#include<QMovie>
#include<QLabel>
#include<QSize>
#include<QMediaPlayer>
#include<state.h>
#include<QApplication>


namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    Job job1,job2,job3,job4,job5,job6,job7,job8;
   QTimer *timer;
   State s;
   void save();
   void load();
   void setup();
   void playsound();

   QWidget *parentWindow;

   //MainWindow *m;
//QMediaPlayer *music= new QMediaPlayer();
QMovie *movie=new QMovie("C:\\Users\\Sara-PC\\Desktop\\ax\\IMG_9903.MOV");
QLabel *prolabel=new QLabel(this);

  // Q_INVOKABLE QByteArray read();
  // QByteArray data() const;

   void check();
   int money=0;
   void set();
   void upgradejob1();
   void upgradejob2();
   void upgradejob3();
   void upgradejob4();
   void upgradejob5();
   void upgradejob6();
   void upgradejob7();
   void upgradejob8();

//public slots:
  // void write(QByteArray data) const;
   //void saveToFile();
  // void loadFromFile();

private slots:
   void UpdateClock1();
   void UpdateClock2();
   void UpdateClock3();
   void UpdateClock4();
   void UpdateClock5();
   void UpdateClock6();
   void UpdateClock7();
   void UpdateClock8();


   void on_UpdateClock1_clicked();

   void on_Upgrade1_clicked();

   void on_UpdateClock2_clicked();

   void on_Upgrade2_clicked();

   void on_UpdateClock3_clicked();

   void on_Upgrade3_clicked();

   void on_UpdateClock4_clicked();

   void on_Upgrade4_clicked();

   void on_UpdateClock5_clicked();

   void on_Upgrade5_clicked();

   void on_UpdateClock6_clicked();

   void on_Upgrade6_clicked();

   void on_UpdateClock7_clicked();

   void on_Upgrade7_clicked();

   void on_UpdateClock8_clicked();

   void on_Upgrade8_clicked();

   void on_radioButton7_clicked();

   void on_radioButton2_clicked();

   void on_radioButton3_clicked();

   void on_radioButton4_clicked();

   void on_radioButton5_clicked();

   void on_radioButton6_clicked();

   void on_radioButton8_clicked();

   //void on_Save_clicked();

   void on_gostate_clicked();


   void on_home_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
