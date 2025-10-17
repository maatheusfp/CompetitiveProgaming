#include <iostream>
#include <stdlib.h>
#include <queue>
#include <math.h>  
using namespace std;

int main(){
    int testCases; 
    cin >> testCases;
    bool first = true;

    while (testCases--){
        if (!first) cout << endl;
        first = false;

        int numBF, numGreen, numBlue;
        cin >> numBF >> numGreen >> numBlue;

        priority_queue<int> greenArmy;
        priority_queue<int> blueArmy;

        for (int i = 0; i < numGreen; i++){
            int value; 
            cin >> value;
            greenArmy.push(value);
        }

        for (int i = 0; i < numBlue; i++){
            int value; 
            cin >> value; 
            blueArmy.push(value);
        }

        while(greenArmy.size() > 0 && blueArmy.size() > 0){
            vector<int> roundGreenArmy;
            vector<int> roundBlueArmy;

            for (int k = 0; k < numBF; k++){
                if (greenArmy.size() < 1 || blueArmy.size() < 1) break;

                int greenSoldier, blueSoldier, battleResult;

                greenSoldier = greenArmy.top();
                greenArmy.pop();

                blueSoldier = blueArmy.top();
                blueArmy.pop();

                battleResult = greenSoldier - blueSoldier;

                if (battleResult > 0) 
                    roundGreenArmy.push_back(battleResult);

                else if (battleResult < 0){
                    roundBlueArmy.push_back(sqrt(pow(battleResult, 2)));
                }
            }

            for (int count = 0; count < roundGreenArmy.size(); count++)
                greenArmy.push(roundGreenArmy[count]);


            for (int count = 0; count < roundBlueArmy.size(); count++)
                blueArmy.push(roundBlueArmy[count]);
            
        }

        if (greenArmy.size() > 0){
            cout << "green wins" << endl;
            int size = greenArmy.size();

            for (int j = 0; j < size; j++){
                cout << greenArmy.top() << endl;
                greenArmy.pop();
            }
        }
        else if (blueArmy.size() > 0){
            cout << "blue wins" << endl;
            int size = blueArmy.size();

            for (int j = 0; j < size; j++){
                cout << blueArmy.top() << endl;
                blueArmy.pop();
            }
        }
        else {
            cout << "green and blue died" << endl;
        }

    }

    return 0;
}