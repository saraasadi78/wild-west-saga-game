#ifndef STATE_H
#define STATE_H
#include <QWidget>



namespace Ui {
class State;
}

class State : public QWidget
{
    Q_OBJECT

public:
    explicit State(QWidget *parent = 0);
    ~State();

int clickcounter=0;
void clickcounterfunction();
void earningfunction();
int unlockcounter=0;
void unlockcounterfunction();
//Game m;


private:
    Ui::State *ui;
};

#endif // STATE_H
