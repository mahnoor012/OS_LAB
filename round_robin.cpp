#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, tq;
    cout<<"num of process\n";
    cin>>n;

    vector<string> task(n);
    vector<int> b_t(n), rem(n);

    cout<<"task:\n";
    for(int i=0;i<n;i++)
        cin>>task[i];

    cout<<"burst time:\n";
    for(int i=0;i<n;i++)
    {
        cin>>b_t[i];
        rem[i] = b_t[i];
    }

    cout<<"quantum :\n";
    cin>>tq;

    int time = 0, wt = 0;
    vector<int> waiting(n,0);

    cout<<"\nGantt Chart:\n";
    cout<<time<<" ";

    while(true)
    {
        bool done = true;

        for(int i=0;i<n;i++)
        {
            if(rem[i] > 0)
            {
                done = false;

                cout<<task[i]<<" ";

                if(rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    time += rem[i];
                    waiting[i] = time - b_t[i];
                    rem[i] = 0;
                }

                cout<<time<<" "; // 🔥 time print
            }
        }

        if(done) break;
    }

    cout<<"\n\nWaiting Time\n";

    for(int i=0;i<n;i++)
    {
        cout<<task[i]<<" wait "<<waiting[i]<<endl;
        wt += waiting[i];
    }

    cout<<"\nAverage Waiting Time = "<<(float)wt/n<<endl;
}
