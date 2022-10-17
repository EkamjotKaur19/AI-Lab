#include<bits/stdc++.h>
using namespace std;

int d=9;
bool win=0;
int winner;

char put_X_O(int n){
    if(n==3){
        return 'X';
    }
    if(n==5){
        return 'O';
    }
    else{
        return ' ';
    }
}

void display(vector<int>board){
    for(int i=1; i<=3; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=3){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<"----------------"<<endl;

    for(int i=4; i<=6; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=6){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<"----------------"<<endl;

    for(int i=7; i<=9; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=9){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

int updatewin(vector<int>board){
    for(int i=0;i<3;i++){
        if(board[i*3+1]*board[i*3+2]*board[i*3+3]==27){
            winner=1;
            return 1;
        }
        else if(board[i*3+1]*board[i*3+2]*board[i*3+3]==125){
            winner=2;
            return -1;
        }
        if(board[1+i]*board[4+i]*board[7+i]==27){
            winner=1;
            return 1;
        }
        else if(board[1+i]*board[4+i]*board[7+i]==125){
            winner=2;
            return -1;
        }
        if(board[1]*board[5]*board[9]==27){
            winner=1;
            return 1;
        }
        else if(board[1]*board[5]*board[9]==125){
            winner=2;
            return -1;
        }
        if(board[3]*board[5]*board[7]==27){
            winner=1;
            return 1;
        }
        else if(board[3]*board[5]*board[7]==125){
            winner=2;
            return -1;
        }
    }
    return 0;
}


int MiniMax(vector<int>board,int depth,bool maxi, int alpha, int beta){
    int ans = updatewin(board);
    if(d==depth){    
        return ans;
    }
    if (ans != 0){    
        return ans;
    }
    int temp=1,curr=3;
    if(!maxi) temp=-1,curr=5;

    int bestScore = INT_MIN;
    for(int i=1;i<=9;i++){
        if (board[i] == 2){
            board[i]=curr;
            int score = temp*MiniMax(board,depth+1,!maxi, -beta, alpha);
            board[i]=2;
            bestScore = max(score, bestScore);
        }
    }
    if(bestScore==INT_MIN)
        return 0;
    return temp*bestScore;
}

void MoveSelector(vector<int>& board,int &player){
    int curr=3;
    int bestMove;
    int temp = INT_MIN;
    for(int i=1;i<=9;i++){
        if(board[i]==2){
            board[i]=curr;
            int value = MiniMax(board,0,0, INT_MIN, INT_MAX);
            if(value>temp){
                temp=value;
                bestMove=i;
            }
            board[i]=2;
        }
    }
    player=2;
    if(temp==INT_MIN)
        return;
    board[bestMove]=curr;
}

bool turnPossible(vector<int>board){
    for(int i=1;i<=9;i++){
        if(board[i]==2)
            return 1;
    }
    return 0;
}


int main(){
    vector<int>board(10,2);
    
    int choice;

    cout<<"Do You Want To Play?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;

    cin>>choice;

    int player;
    if(choice==1)    player = 2;
    else    player = 1;
    
    while(turnPossible(board)){
        if(player==2){
            while(1){
                cout<<"Your move at position: "<<endl;
                int pos;
                cin>>pos;
                if(board[pos]==2){
                    board[pos]=5;
                    break;
                }
                else
                    cout<<"Position Already Occupied"<<endl; 
            }
            player=1;
        }
        else{
            MoveSelector(board,player);
        }
        win=abs(updatewin(board));
        display(board);
        string winner_name;
        if(winner==1){
            winner_name="computer";
        }
        else{
            winner_name="user";
        }
        if(win){
            cout<<" Player "<<winner<<" wins "<<endl;
            break;
        }
    }
    if(!win && !turnPossible(board))
        cout<<"Draw"<<endl;
}
