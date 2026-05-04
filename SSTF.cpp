#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of requests: ";
    cin>>n;

    int q[n];
    int head;
    int total;

    cout<<"Enter requests:\n";
    for(int i=0;i<n;i++)
        cin>>q[i];


    cout<<"Enter head position: ";
    cin>>head;   // disk head er starting position


    total = 0;   // total store cylinder movement means distance,initially 0
    cout<<"\nPath: "<<head;   // In output path the !st point must be head

    for(int i=0;i<n;i++)   // sob request serve korbo
    {
        int min = 10000;   // take a big value for compare
        int idx = -1;    // nearest request er index rakhar jonno

        for(int j=0;j<n;j++)   // sob request check korbo
        {
            int d = abs(head - q[j]);   // distance between current head with other point

            if(d < min)
            {
                min = d;      // min update if distance is less than d
                idx = j;     // For which point I get the min distance,store that point's index in idx for initialize our new head
            }
        }

        total = total + abs(head - q[idx]);
        // total distance er sathe movement add korlam

        head = q[idx]; //new head

        cout<<" "<<head; // if we print new head we will get the path automatically

        q[idx] = 10000; // serve done for idx index, and it act like it removed from from Queue
    }

    cout<<"\nTotal distance: "<<total; // total cylinder movement print

    return 0;
}

