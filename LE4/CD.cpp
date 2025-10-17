#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int numberOfTracks, tapeLength;

    while (cin >> tapeLength  >> numberOfTracks){
        vector<int> tracks;
        vector<int> playedTracks;
        int totalSum = 0;

        for (int i = 0; i < numberOfTracks; i++){
            int value;
            cin >> value; 
            tracks.push_back(value);
        }

        for (int i = 0; i < (1 << tracks.size()); i++){
            vector<int> tempTracks;
            int tempSum = 0;

            for (int j = 0; j < tracks.size(); j++){
                if ((i & (1 << j)) > 0){

                    tempTracks.push_back(tracks[j]);
                    tempSum += tracks[j];
                }     
            }
            if (tempSum > totalSum && tempSum <= tapeLength){
                playedTracks.clear();
                totalSum = tempSum;
                for (int w = 0; w < tempTracks.size(); w++)
                    playedTracks.push_back(tempTracks[w]);
            }
        }

        for (int w = 0; w < playedTracks.size(); w++){
            cout << playedTracks[w] << " ";
        }

        cout << "sum:" << totalSum << endl;
    }

    return 0;
}