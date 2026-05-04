#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter reference string size: ";
    cin>>n;

    int ref[n];
    cout<<"Enter reference string:\n";
    for(int i=0;i<n;i++)
        cin>>ref[i];

    int f;
    cout<<"Enter frame size: ";
    cin>>f;

    int frame[f];

    // frame empty
    for(int i=0;i<f;i++)
        frame[i] = -1;  //for avoid grabage value

    int pageFault = 0;
    int pos = 0;   // replace position of frame in main memory

    for(int i=0;i<n;i++) //reference string check
    {
        int found = 0;

        // check page already in frame
        for(int j=0;j<f;j++)  //this loop is for frame
        {
            if(frame[j] == ref[i])  //frame er index a ref er val check
            {
                found = 1; //hit
                break;
            }
        }

        if(found == 0) // page fault
        {
            frame[pos] = ref[i]; //store current new ref val in frame[pos], here pos can be totally empty or it can swap with other
            pos++;

            if(pos == f)   // frame full go at the 1st index then start
                pos = 0;

            pageFault++;   //increase page fault
        }


        if(found==1)  cout<<"..."<<endl;
        else for(int i=0;i<f;i++)
        {
            //7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
            if(frame[i]==-1) cout<<".";
            else cout<<frame[i]<<" ";
        }
        cout<<endl;

    }

    cout<<"Total Page Faults: "<<pageFault;

    return 0;
}


