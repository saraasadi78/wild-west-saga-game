#ifndef JOB_H
#define JOB_H


class Job
{
public:
    bool clickflag=0;
    int firstmoney=0;
    int  firsttime;
    int upgrademoney=0;
    int level=0;
    int jobmoney=0;
    int secondtime;
    int oppeningprice;
    int count=0;

    void setFirstmoney(int fm);
    int getFirstmoney();

    void setFirsttime(int ft);
    int getFirsttime();

    void setUpgrademoney(int um);
    int getUpgrademoney();

    void setSecondtime(int st);
    int getSecondtime();

    void setOppeningprice(int op);
    int getOppeningprice();

    Job();
};

#endif // JOB_H
