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

//Third Function - Posswin(p);
int Posswin(int p){
    int i;
    int target, pos;
    if(p==1){
        target=18;
    }
    else{
        target=50;
    }
    i=1;
    //checkimg rows;
    while(i<=9){
        if(board[i]*board[i+1]*board[i+2] == target){
            if(board[i]==2){
                return i;
            }
            if(board[i+1]==2){
                return i+1;
            }
            if(board[i+2]==2){
                return i+2;
            }
        }
        i=i+3;
    }
    i=1;
    //checking columns
    while(i<=3){
        if(board[i]*board[i+3]*board[i+6] == target){
            if(board[i]==2){
                return i;
            }
            if(board[i+3]==2){
                return i+3;
            }
            if(board[i+6]==2){
                return i+6;
            }
        }
        i=i+1;
    }

    //First Diagonal
    if(board[1]*board[5]*board[9] == target){
        if(board[1]==2){
            return 1;
        }
        if(board[5]==2){
            return 5;
        }
        if(board[9]==2){
            return 9;
        }
    }

    //Second Diagonal
    if(board[3]*board[5]*board[7] == target){
        if(board[3]==2){
            return 3;
        }
        if(board[5]==2){
            return 5;
        }
        if(board[7]==2){
            return 7;
        }
    }
    return 0;
}

void comp_game(){
    if(Posswin(comp)){
        Go(Posswin(comp));
        flag=1;
    }
    else{
        if(Posswin(player)){
            Go(Posswin(player));
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
    draw_cond();
    board_state();
    gotoxy(30,18);
    cout<<"Your move at position: "<<endl;
    cin>>pos;
    if(board[pos]!=2){
        cout<<"Already occupied position"<<endl;
        user_game();
    }
    if(pos == Posswin(player)){
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
