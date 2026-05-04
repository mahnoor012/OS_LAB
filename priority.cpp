#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"num of process"<<endl;
    cin>>n;

    vector<string>task(n);
    vector<int>b_t(n);
    vector<int>prt(n);
    cout<<"task :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>task[i];
    }
    cout<<"burst time :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>b_t[i];
    }
    cout<<"priority :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>prt[i];
    }


    //sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(prt[i]>prt[j])
            {
                swap(task[i],task[j]);
                swap(b_t[i],b_t[j]);
                swap(prt[i],prt[j]);
            }
        }
    }

    int ct=0;
    int wt=0;
    cout<<"Gantt chart"<<endl;
    cout<<"0 ";
    for(int i=0;i<n;i++)
    {
        ct=ct+b_t[i];
        cout<<task[i]<<" "<<ct<<" ";
    }

    ct=0;
    cout<<endl;


    cout<<"Wating time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<task[i]<<" wait "<<ct<<endl;
        wt=wt+ct;
        ct=ct+b_t[i];
    }

    float avg=(float)wt/n;
    cout<<"Avg wating time "<<avg<<endl;
}
