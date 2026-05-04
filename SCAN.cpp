#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of requests: ";
    cin >> n;

    int q[n+1]; // increase queue size 1 for marge head
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

    q[n] = head;// head merge
    n++; // array size increase 1

    // sort the array
    sort(q, q+n);  //sort(arr, arr + n)

    // head er index ber koro
    int init_head_idx;
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

    // LEFT direction
    for(int i=init_head_idx-1;i>=0;i--)
    {
        total += abs(head - q[i]);
        head = q[i];
        cout << " " << head;
    }

    //go lower bound
    if(head != low)
    {
        total += abs(head - low);
        head = low;
        cout << " " << head;
    }

    // RIGHT direction
    for(int i=init_head_idx+1;i<n;i++)
    {
        total += abs(head - q[i]);
        head = q[i];
        cout << " " << head;
    }

    cout << "\nTotal distance: " << total << endl;

    return 0;
}
