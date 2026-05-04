#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of requests: ";
    cin>>n;

    int q[n+1];  //increase q size 1 for head marge

    cout<<"Enter disk requests:\n";
    for(int i=0;i<n;i++)
        cin>>q[i];

    int head;
    cout<<"Enter head start position: ";
    cin>>head;

    q[n] = head;  // head merge
    n++;

    sort(q, q+n);  // sort

    int init_head_idx;  //initial head index
    //find head index
    for(int i=0;i<n;i++)
    {
        if(q[i]==head)
        {
            init_head_idx=i;
            break;
        }
    }

    int total=0;
    cout<<"\nPath: "<<head;

    // RIGHT side
    for(int i=init_head_idx+1;i<n;i++)
    {
        total += abs(head-q[i]);
        head=q[i];
        cout<<" "<<head;
    }

    // circular jump to first request
    for(int i=0;i<init_head_idx;i++)
    {
        total += abs(head-q[i]);
        head=q[i];
        cout<<" "<<head;
    }

    cout<<"\nTotal distance: "<<total;

    return 0;
}

