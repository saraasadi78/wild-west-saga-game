#include "state.h"
#include "ui_state.h"

State::State(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::State)
{
    ui->setupUi(this);
}

State::~State()
{
    delete ui;
}


void State::clickcounterfunction()
{
    clickcounter++;
    ui->scorelabel->setText(QString::number(clickcounter));
}

void State::earningfunction()
{
    //ui->celabel->setText(QString::number(m.money));
}

void State::unlockcounterfunction()
{
    unlockcounter++;
     ui->unlock->setText(QString::number(unlockcounter));
}
