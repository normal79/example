#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter no. of processes"<<endl;
    cin>>n;
    vector<int> at(n),bt(n),ct(n),tat(n),wt(n);
 
    for(int i=0; i<n; i++){
        cout << "Enter arrival time and burst time (Space separated) of process "<<i+1<<" : "<<endl;
        cin>>at[i]>>bt[i];
    }

    int currentTime = 0;

    for(int i=0; i<n; i++){
        if(currentTime < at[i]) currentTime = at[i];
        ct[i] = currentTime + bt[i];
        currentTime = ct[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout<<"Answer: "<<endl;
    cout<<"AT BT CT TAT WT"<<endl;
    for(int i=0; i<n; i++){
        cout<<at[i]<<"  "<<bt[i]<<"  "<<ct[i]<<"  "<<tat[i]<<"  "<<wt[i]<<endl;
    }
}
