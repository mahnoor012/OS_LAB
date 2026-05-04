#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Number of request: ";
    cin >> n;

    int que[n];
    cout << "Queue:\n";
    for(int i=0; i<n; i++)
        cin >> que[i];

    int head;
    cout << "Head start: ";
    cin >> head;

    int path[n+1];  // here I add headstart so 1+n
    path[0] = head; // initially start with head
    int total_distance = 0; //initially distense is 0
    int res=0;
    // FCFS processing
    for(int i=0; i<n; i++){
        path[i+1] = que[i];
        res=abs(path[i+1] - path[i]); //calculate difference between 2 point then
        total_distance = total_distance+res ; //sum up
        res=0;
    }

    // Output path print
    cout << "\nPath: ";
    for(int i=0; i<=n; i++)
        cout << path[i] << " ";

    //calculate Total distance
    cout << "\nTotal distance: " << total_distance << endl;

    return 0;
}

