#include<bits/stdc++.h>
using namespace std;
const int N=100;

class snacksNladders{

    vector<bool> snakes; // index as snakes position in board aand value equals final position downwards after snake bite
    vector<bool> ladders; // index as ladder starting position and value as its final position upwards
    vector<int> board[N+1];  
    public:
        snacksNladders(){
            snakes.resize(101, -1);
            ladders.resize(101, -1);

            // snakes initializations
            snakes[17] = 7;
            snakes[54] = 34;
            snakes[62] = 19;
            snakes[64] = 60;
            snakes[87] = 36;
            snakes[93] = 73;
            snakes[95] = 75;
            snakes[98] = 79;

            // ladders initialization
            ladders[1] = 38;
            ladders[4] = 14;
            ladders[9] = 31;
            ladders[21] = 42;
            ladders[28] = 84;
            ladders[51] = 67;
            ladders[72] = 91;
            ladders[80] = 99;


            // constructing the game board with snakes and ladders placed
            for(int i=0; i<100; i++){
                if(snakes[i] != -1)
                    board[i].push_back(snakes[i]);
                else if(ladders[i] != -1)
                    board[i].push_back(ladders[i]);
                else{
                    if(snakes[i+1] != -1 or ladders[i+1] != -1)
                        board[i].push_back(i+2);
                    else
                        board[i].push_back(i+1);
                }
            }
        }

        void printBoard(){
            cout << "position    can go to\n";
            int i=0;
            for(int i=0; i<=100; i++){
                cout << i << " :\t    ";
                for(auto v: board[i]) 
                    cout << v << " ";
                cout << "\n";
            }
        }
};



int main(){
    vector<int> snakes; // index as snakes position in board aand value equals final position downwards after snake bite
    vector<int> ladders; // index as ladder starting position and value as its final position upwards
    vector<int> board[N+1]; 
    snakes.resize(101, -1);
    ladders.resize(101, -1);

            // snakes initializations
            snakes[17] = 7;
            snakes[54] = 34;
            snakes[62] = 19;
            snakes[64] = 60;
            snakes[87] = 36;
            snakes[93] = 73;
            snakes[95] = 75;
            snakes[98] = 79;

            // ladders initialization
            ladders[1] = 38;
            ladders[4] = 14;
            ladders[9] = 31;
            ladders[21] = 42;
            ladders[28] = 84;
            ladders[51] = 67;
            ladders[72] = 91;
            ladders[80] = 99;


            // constructing the game board with snakes and ladders placed
            for(int i=0; i<100; i++){
                if(snakes[i] != -1)
                    board[i].push_back(snakes[i]);
                else if(ladders[i] != -1)
                    board[i].push_back(ladders[i]);
                else{
                    // if(snakes[i+1] != -1 or ladders[i+1] != -1)
                    //     board[i].push_back(i+2);
                    // else
                        board[i].push_back(i+1);
                }
            }
            cout << "position    can go to\n";
            int i=0;
            for(int i=0; i<=100; i++){
                cout << i << " :\t    ";
                for(auto v: board[i]) 
                    cout << v << " ";
                cout << "\n";
            }
        

            
    // snacksNladders K;
    // K.printBoard();
}