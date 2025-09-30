/* Problem Statement

Takahashi has decided to hold fastest-finger-fast quiz games. Kizahashi, who is in charge of making the scoreboard, is struggling to write the program that manages the players' scores in a game, which proceeds as follows.

A game is played by NN players, numbered 11 to NN. At the beginning of a game, each player has KK points.

When a player correctly answers a question, each of the other N−1N−1 players receives minus one (−1−1) point. There is no other factor that affects the players' scores.

At the end of a game, the players with 00 points or lower are eliminated, and the remaining players survive.

In the last game, the players gave a total of QQ correct answers, the ii-th of which was given by Player AiAi​. For Kizahashi, write a program that determines whether each of the NN players survived this game.
Constraints

    All values in input are integers.
    2≤N≤1052≤N≤105
    1≤K≤1091≤K≤109
    1≤Q≤1051≤Q≤105
    1≤Ai≤N (1≤i≤Q)1≤Ai​≤N (1≤i≤Q)
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void ReduzScore(int ganhador, vector<long long> &players){
    if (ganhador - 1 < 0 || ganhador > players.size())
        cout << "Deu ruim" << endl; 

    for (int i = 0; i < players.size(); i++){
        if (i != ganhador - 1)
            players[i]--;
    }
}

void PrintaResposta(vector<long long> &players){
    for (int i = 0; i < players.size(); i++){
        if (players[i] < 1)
            cout << "No" << endl;

        else 
            cout << "Yes" << endl;
    }
}

int main(){
    int N, Q;
    long long K;
    cin >> N >> K >> Q; 

    vector<long long> players(N, K);

    for (int i = 0; i < Q; i++){
        int ganhadorDaRodada;
        cin >> ganhadorDaRodada;

        ReduzScore(ganhadorDaRodada, players);
    }

    PrintaResposta(players);

    return 0;
}