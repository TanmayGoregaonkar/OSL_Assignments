#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pi;
    int a_time;
    int b_time;
    int c_time;
};
struct Process Qarray[10];
int qsize=0;
int main()
{

    int n=5;

    struct Process ProArray[n];
    

    // All processor details
    ProArray[0].pi = 1;
    ProArray[1].pi = 2;
    ProArray[2].pi = 3;
    ProArray[3].pi = 4;
    ProArray[4].pi = 5;

    ProArray[0].a_time = 1;
    ProArray[1].a_time = 3;
    ProArray[2].a_time = 2;
    ProArray[3].a_time = 10;
    ProArray[4].a_time = 8;

    ProArray[0].b_time = 7;
    ProArray[1].b_time = 3;
    ProArray[2].b_time = 2;
    ProArray[3].b_time = 10;
    ProArray[4].b_time = 8;

    // finding total time
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_time = ProArray[i].b_time;
    }

    //finding first arrival time
    int firstArrivalTime = ProArray[0].a_time;
    for (int i = 0; i < n; i++)
    {
        firstArrivalTime=(ProArray[i].a_time <  firstArrivalTime) ? ProArray[i].b_time : firstArrivalTime;
    }

    int currentProcess=0;
    for (int i = 0; i < n; i++)
    {
        firstArrivalTime=(ProArray[i].a_time == firstArrivalTime) ? ProArray[i].b_time : firstArrivalTime;
    }
    

    int FinalCompletionTime=firstArrivalTime+total_time;
    int CurrentTime = 0;
    while ( CurrentTime <= FinalCompletionTime)
    {
        for (int i = 0; i < n; i++)
        {
            if (ProArray[i].a_time <= CurrentTime)
            {
                Qarray[qsize].a_time=ProArray[i].a_time;
                Qarray[qsize].b_time=ProArray[i].b_time;
                Qarray[qsize].c_time=ProArray[i].c_time;
                ++qsize;
            }
            
        }

        if (currentProcess==0)
        {
            currentProcess=Qarray[0].pi;
        }
        
        CurrentTime++;
    }

    return 0;
}
