#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

int board[10]={2,2,2,2,2,2,2,2,2,2};
int turn=1;
int flag=0;
int player, comp;
void comp_game();
void user_game();
void draw_cond();
void board_state();

bool checkWin(int player){
    vector<int>    mp = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    vector<int> revmp = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    vector<int>comp_moves;
    vector<int>user_moves;

    for(int i=1; i<10; i++){
        if(board[i]==3){
            user_moves.push_back(mp[i]);
        }

        if(board[i]==5){
            comp_moves.push_back(mp[i]);
        }
    }
    if(player==1){
        for(int i=0; i<comp_moves.size(); i++){
            for(int j=i+1; j<comp_moves.size(); j++){
                for(int k=j+1; k<comp_moves.size(); k++){
                    if(comp_moves[i]+comp_moves[j]+comp_moves[k]==15){
                        return true;
                    }
                    else return false;
                }
            }
        }
    }
    if(player==2){
        for(int i=0; i<user_moves.size(); i++){
            for(int j=i+1; j<user_moves.size(); j++){
                for(int k=j+1; k<user_moves.size(); k++){
                    if(user_moves[i]+user_moves[j]+user_moves[k]==15){
                        return true;
                    }
                    else return false;
                }
            }
        }
    }

    
    return false;
}


void gotoxy(short a, short b){
    COORD coordintes;
    coordintes.X=a;
    coordintes.Y=b;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coordintes
    );

}

//First function - Make 2
int make_two(){
    if(board[5]==2){
        return 5;
    }
    else if(board[2]==2){
        return 2;
    }
    else if(board[4]==2){
        return 4;
    }
    else if(board[6]==2){
        return 6;
    }
    else if(board[8]==2){
        return 8;
    }
    return 0;
}

//Second Function - Go(n)
void Go(int n){
    if(turn%2!=0){
        board[n]=3;
    }
    else{
        board[n]=5;
    }
    turn++;
}

int Posswin(int turn){
    vector<int> m_sq = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    vector<int> rev = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    if (turn%2 == 0){
        vector<int> comp_moves;
        vector<int> user_moves;

        for (int i = 1; i <= 9; i++){
            if (board[i] == 5){
                comp_moves.push_back(m_sq[i]);
            }
            else if (board[i] == 3){
                user_moves.push_back(m_sq[i]);
            }
        }

        for (int i = 0; i < comp_moves.size(); i++){
            for (int j = i+1; j < comp_moves.size(); j++){
                int x = 15-comp_moves[i]-comp_moves[j];
                if (x > 0 && x < 10 && board[rev[x]] == 2){
                    return rev[x];
                }
            }
        }

        for (int i = 0; i < user_moves.size(); i++){
            for (int j = i+1; j < user_moves.size(); j++){
                int x = 15-user_moves[i]-user_moves[j];
                if (x > 0 && board[rev[x]] == 2){
                    return rev[x];
                }
            }
        }
    }

    else{
        vector<int> comp_moves;
        vector<int> user_moves;

        for (int i = 1; i <= 9; i++){
            if (board[i] == 3){
                comp_moves.push_back(m_sq[i]);
            }
            else if (board[i] == 5){
                user_moves.push_back(m_sq[i]);
            }
        }

        for (int i = 0; i < comp_moves.size(); i++){
            for (int j = i+1; j < comp_moves.size(); j++)
            {
                int x = 15-comp_moves[i]-comp_moves[j];
                if (x > 0 && x < 10 && board[rev[x]] == 2)
                {
                    return rev[x];
                }
            }
        }

        for (int i = 0; i < user_moves.size(); i++)
        {
            for (int j = i+1; j < user_moves.size(); j++)
            {
                int x = 15-user_moves[i]-user_moves[j];
                if (x > 0 && board[rev[x]] == 2)
                {
                    return rev[x];
                }
            }
        }
    }

    return -1;


}

void comp_game(){
    if(Posswin(turn)){
        Go(Posswin(turn));
        flag=1;
    }
    else{
        if(Posswin(turn)){
            Go(Posswin(turn));
        }
        else{
            Go(make_two());
        }

    }
    board_state();

    if(flag){
        gotoxy(30,20);
        cout<<"Computer Wins"<<endl;
        return;
    }
    else{
        user_game();
    }
}

void user_game(){
    int pos;
    int player=1;
    if(checkWin(player)){
        return;
    }
    board_state();
    gotoxy(30,18);
    cout<<"Your move at position: "<<endl;
    cin>>pos;
    if(board[pos]!=2){
        cout<<"Already occupied position"<<endl;
        user_game();
    }
    if(pos == Posswin(turn)){
        Go(pos);
        board_state();
        gotoxy(30,20);
        cout<<"Player wins"<<endl;
        return;
    }
    Go(pos);
    board_state();
    comp_game();
}

void draw_cond(){
    if(turn>9){
        cout<<"Game Draw"<<endl;
    }
}

void put_X_O(char ch, int pos){
    int m;
    int x=31, y=10;
    m=pos;
    if(m>3){
        while(m>3){
            y=y+3;
            m=m-3;
        }
    }

    if(pos%3 == 0){
        x=x+16;
    }
    else{
        pos = pos%3;
        pos--;
        while(pos){
            x=x+8;
            pos--;
        }
    }
    gotoxy(x,y);
    cout<<ch<<endl;
}

void board_state(){
    int j;
    for(j=9; j<17; j++){
        gotoxy(35,j);
        cout<<"|          |"<<endl;
    }
    gotoxy(28,11);
    cout<<"--------------------------"<<endl;

    gotoxy(28,14);
    cout<<"--------------------------"<<endl;

    for(j=1; j<10; j++){
        if(board[j]==3){
            put_X_O('X', j);
        }
        else{
            if(board[j]==5){
                put_X_O('0', j);
            }
        }
    }
}



int main(){
    
    int choice;

    cout<<"Do You Want To Play?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    cin>>choice;
    turn=1;
    switch(choice){
        case 1:
        player=1;
        comp=0;
        user_game();
        break;

        case 2:
        comp=1;
        player=0;
        comp_game();
        break;
    }
}
