#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    int q[n+3]; //increase q array size 3 cause I want to marge head,lower and upper bound
    cout << "Enter disk requests:\n";
    for(int i=0;i<n;i++)
        cin >> q[i];

    int head;
    cout << "Enter head start position: ";
    cin >> head;

    int low, high;
    cout << "Enter lower bound of disk: ";
    cin >> low;
    cout << "Enter upper bound of disk: ";
    cin >> high;

    q[n] = head; //insert head in q
    q[n+1] = low; //insert low in q
    q[n+2] = high; //insert high in q
    n += 3;  //increase n cause I use n in loop

    sort(q, q+n); // sort array


    int init_head_idx;
    //find initial head index
    for(int i=0;i<n;i++)
    {
        if(q[i] == head)
        {
            init_head_idx = i;
            break;
        }
    }

    int total = 0;
    cout << "\nPath: " << head;

    // RIGHT(high) direction first
    for(int i=init_head_idx+1;i<n;i++)
    {
        total += abs(head - q[i]);
        head = q[i];
        cout << " " << head;
    }

    // circular jump: LEFT side of head
    for(int i=0;i<init_head_idx;i++)
    {
        total += abs(head - q[i]);
        head = q[i];
        cout << " " << head;
    }

    cout << "\nTotal distance: " << total << endl;

    return 0;
}

