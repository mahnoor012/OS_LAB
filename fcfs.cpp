
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of process: ";
    cin >> n;

    vector<string> task(n);
    vector<int> time(n);

    cout << "Enter task names:\n";
    for(int i = 0; i < n; i++)
        cin >> task[i];

    cout << "Enter burst times:\n";
    for(int i = 0; i < n; i++)
        cin >> time[i];

    int currentTime = 0;
    int totalWaiting = 0;

    cout << "\nGantt Chart:\n";
    cout << "0 ";

    for(int i = 0; i < n; i++) {
        currentTime += time[i];
        cout << task[i] << " " << currentTime << " ";
    }

    cout << "\n\nWaiting Times:\n";

    currentTime = 0;
    for(int i = 0; i < n; i++) {
        cout << task[i] << " : " << currentTime << endl;
        totalWaiting += currentTime;
        currentTime += time[i];
    }

    float avg = (float)totalWaiting / n;
    cout << "\nAverage Waiting Time = " << avg << " ms\n";

    return 0;
}


