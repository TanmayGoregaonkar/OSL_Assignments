#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

// to store process information like arrival time, burst time ...
struct node{
    int pr, at, bt, ct, wt, tat, vis = 0, bt1;
};

// compare fuction to sort in asc order of arrival time
bool cmp(node &p1, node &p2){
    return p1.at < p2.at;
}

void display_menu(){
    cout << "*********************************\n";
    cout << "1. SJF NON PRIMPTION\n";
    cout << "2. SJF PRIMPTION\n";
    cout << "3. ROUND ROBIN\n";
    cout << "4. EXIT\n";
    cout << "*********************************\n";
    cout<<"Select from above options : ";
}

void sjf_non_prim(){
    cout<<"Enter Number Of Processes : ";
    int num_process;
    cin>>num_process;
    
    vector<node>vec(num_process);
    
    for(int i = 0;i<num_process;i++){
        vec[i].pr = i + 1;
    	cout<<"Enter Arrival Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].at;
    	cout<<"Enter Burst Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].bt;
    	vec[i].bt1 = vec[i].bt;
    }
    	
    vector<int>gant_chart;

    sort(vec.begin(), vec.end(), cmp);
    int curtime = 0;
    int mini = INT32_MAX;
    int index = 0;
    int count = num_process;
    cout<<"--------------------------------GANTT CHART------------------------------------------\n";
    while(count){
        // take minimum burst time process.
        for(int i = 0;i<num_process;i++){
            if(vec[i].vis == 0 && vec[i].at <= curtime && vec[i].bt < mini){
                mini = vec[i].bt;
                index = i;
                
            }
        }
        curtime += vec[index].bt;   // add burst time to current time.
        vec[index].bt = 0;  // make burst time of that process 0.
        vec[index].vis = 1; // mark it as visited.
        vec[index].ct = curtime;    // mark completion time.
        count--;    // reduce process count.
        mini = INT_MAX;     
        gant_chart.push_back(vec[index].pr);    // store process number for gant chart.
        cout<<"| "<<vec[index].pr<<" "; // print gant chart.

    }
    cout<<endl;
    cout<<"----------------------------------CALCULATIONS-----------------------------------------------\n";
    for(int i = 0;i<vec.size();i++){
        vec[i].tat = vec[i].ct - vec[i].at;
        vec[i].wt = vec[i].tat - vec[i].bt1;
    }
    int wi = 10;
    cout<<"PROC"<<setw(wi)<<"AT"<<setw(wi)<<"CT"<<setw(wi)<<"TAT"<<setw(wi)<<"WT"<<"\n";
    wi += 1;
    int total1 = 0, total2 = 0;
    for(int i =0;i<vec.size();i++){
	total1 += vec[i].tat;
	total2 += vec[i].ct;
        cout<<vec[i].pr<<setw(wi)<<vec[i].at<<setw(wi)<<vec[i].ct<<setw(wi)<<vec[i].tat<<setw(wi)<<vec[i].wt<<"\n";
    }
    cout<<"-----------------------OPTIMIZED GANTT CHART---------------------------------------\n";
    int prev = gant_chart[0];
    cout<<"| "<<prev<<" ";
    for(int i = 1;i<gant_chart.size(); i++){
        if(gant_chart[i] != prev){
            cout<<"| "<<gant_chart[i]<<" ";
            prev = gant_chart[i];
        }
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
	double temp1 = total1/(double)num_process;
	double temp2 = total2/(double)num_process;
    cout<<"Average TURN AROUND Time is : "<<temp1<<"\n";
    cout<<"Average WAITING Time is : "<<temp2<<"\n";

}

void sjf_prim(){
    cout<<"Enter Number Of Processes : ";
    int num_process;
    cin>>num_process;
    
    vector<node>vec(num_process);
    
    for(int i = 0;i<num_process;i++){
    vec[i].pr = i + 1;
    	cout<<"Enter Arrival Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].at;
    	cout<<"Enter Burst Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].bt;
    	vec[i].bt1 = vec[i].bt;
    }
    	
    vector<int>gant_chart;

    sort(vec.begin(), vec.end(), cmp);
    int curtime = 0;
    int mini = INT32_MAX;
    int index = 0;
    int count = num_process;
    cout<<"--------------------------------GANTT CHART------------------------------------------\n";
    while(count){
        
        for(int i = 0;i<num_process;i++){
            if(vec[i].vis == 0 && vec[i].at <= curtime && vec[i].bt < mini){
                mini = vec[i].bt;
                index = i;
                
            }
        }
        curtime += 1;
        vec[index].bt--;
        if(vec[index].bt == 0){
            vec[index].vis = 1;
            count--;
            vec[index].ct = curtime;
        }
        mini = INT_MAX;
        gant_chart.push_back(vec[index].pr);
        cout<<"| "<<vec[index].pr<<" ";

    }
    cout<<endl;
    cout<<"----------------------------------CALCULATIONS-----------------------------------------------\n";
    for(int i = 0;i<vec.size();i++){
        vec[i].tat = vec[i].ct - vec[i].at;
        vec[i].wt = vec[i].tat - vec[i].bt1;
    }
    int wi = 10;
    cout<<"PROC"<<setw(wi)<<"AT"<<setw(wi)<<"CT"<<setw(wi)<<"TAT"<<setw(wi)<<"WT"<<"\n";
    wi += 1;
    int total1 = 0, total2 = 0;
    for(int i =0;i<vec.size();i++){
	total1 += vec[i].tat;
	total2 += vec[i].ct;
        cout<<vec[i].pr<<setw(wi)<<vec[i].at<<setw(wi)<<vec[i].ct<<setw(wi)<<vec[i].tat<<setw(wi)<<vec[i].wt<<"\n";
    }
    cout<<"-----------------------OPTIMIZED GANTT CHART---------------------------------------\n";
    int prev = gant_chart[0];
    cout<<"| "<<prev<<" ";
    for(int i = 1;i<gant_chart.size(); i++){
        if(gant_chart[i] != prev){
            cout<<"| "<<gant_chart[i]<<" ";
            prev = gant_chart[i];
        }
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
	double temp1 = total1/(double)num_process;
	double temp2 = total2/(double)num_process;
    cout<<"Average TURN AROUND Time is : "<<temp1<<"\n";
    cout<<"Average WAITING Time is : "<<temp2<<"\n";
}

void round_robin(){
    cout<<"Enter Number Of Processes : ";
    int num_process;
    cin>>num_process;

    vector<node>vec(num_process);
    vector<bool> inside_queue(num_process + 1, 0);

    for(int i = 0;i<num_process;i++){
        vec[i].pr = i + 1;
    	cout<<"Enter Arrival Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].at;
    	cout<<"Enter Burst Time For Process : "<<i + 1<<"\n";
    	cin>>vec[i].bt;
    	vec[i].bt1 = vec[i].bt;
    }
    int time_quantum = 4;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].bt1 = vec[i].bt;
    }
    sort(vec.begin(),vec.end(), cmp);
    int cur_time = 0;
    queue<node> q1;
    q1.push(vec[0]);
    inside_queue[vec[0].pr] = 1;
    while (!q1.empty())
    {
        node obj = q1.front();
        q1.pop();
        for (int i = 0;i<vec.size();i++){
            if(vec[i].pr == obj.pr){
                if(time_quantum < vec[i].bt){
                    vec[i].bt -= time_quantum;
                    cur_time += time_quantum;
                }else{
                    cur_time += vec[i].bt;
                    vec[i].ct = cur_time;
                    vec[i].bt = 0;
                    vec[i].vis = 1;
                }
                break;
            }
        }
        int cur_pro = obj.pr;
        cout << "| " << cur_pro << " ";
        for (int i = 0; i < vec.size(); i++)
        {
            if(vec[i].pr != cur_pro && inside_queue[vec[i].pr] == 0) {
                if(vec[i].vis != 1 && vec[i].at <= cur_time){
                    q1.push(vec[i]);
                    inside_queue[vec[i].pr] = 1;
                }
            }
        }
        for (int i = 0; i < vec.size(); i++){
            if(vec[i].pr == cur_pro){
                if(vec[i].vis != 1){
                    q1.push(vec[i]);
                }
                break;
            }
        }
    }
    cout << "----------------------------------CALCULATIONS-----------------------------------------------\n";
    for(int i = 0;i<vec.size();i++){
        vec[i].tat = vec[i].ct - vec[i].at;
        vec[i].wt = vec[i].tat - vec[i].bt1;
    }
    int wi = 10;
    cout<<"PROC"<<setw(wi)<<"AT"<<setw(wi)<<"CT"<<setw(wi)<<"TAT"<<setw(wi)<<"WT"<<"\n";
    wi += 1;
    int total1 = 0, total2 = 0;
    for(int i =0;i<vec.size();i++){
	    total1 += vec[i].tat;
	    total2 += vec[i].ct;
        cout<<vec[i].pr<<setw(wi)<<vec[i].at<<setw(wi)<<vec[i].ct<<setw(wi)<<vec[i].tat<<setw(wi)<<vec[i].wt<<"\n";
    }
    cout<<"-------------------------------------------------------------------------------------"<<endl;
	double temp1 = total1/(double)num_process;
	double temp2 = total2/(double)num_process;
    cout<<"Average TURN AROUND Time is : "<<temp1<<"\n";
    cout<<"Average WAITING Time is : "<<temp2<<"\n";
}

int main(){
    int option = 0;
    do
    {
        display_menu();
        cin >> option;
        switch(option){
            case 1 : sjf_non_prim(); break;
            case 2: sjf_prim(); break;
            case 3: round_robin();break;
            default: break;
        }
    } while (option != 4);
}