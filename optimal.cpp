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

    for(int i=0;i<f;i++)
        frame[i] = -1;

    int fault = 0;

    for(int i=0;i<n;i++)
    {
        int found = 0;

        // check page already in frame
        for(int j=0;j<f;j++)
        {
            if(frame[j] == ref[i])   //hit
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int pos = 0;
            int far = -1;

            for(int j=0;j<f;j++)
            {
                int k;

                for(k=i+1;k<n;k++)
                {
                    if(frame[j] == ref[k])
                        break;
                }

                if(k > far)
                {
                    far = k;
                    pos = j;
                }
            }

            frame[pos] = ref[i];
            fault++;
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

    cout<<"Total Page Faults: "<<fault;

    return 0;
}
