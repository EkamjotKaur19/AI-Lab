#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

//Steps
/*
1. Initialized empty board
2. Put OX
3. Display func for board
4. Go function
5. make two function
5. Posswin
6. Condition of Draw
7. Move by Computer
8. Move by User

*/

int board[10]={2,2,2,2,2,2,2,2,2,2};
int turn=0;
int flag=0;
int player, comp;
void user_game();

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

void display(){
    for(int i=1; i<=3; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=3){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<"-----------------"<<endl;

    for(int i=4; i<=6; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=6){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<"-----------------"<<endl;

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
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

void Go(int n){
    if(turn%2!=0){
        board[n]=3;
    }
    else{
        board[n]=5;
    }
    turn++;
}

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



bool draw_cond(){
    if(turn>9){
        cout<<"Draw"<<endl;
        exit(0);
    }
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
    display();
    

    if(flag){
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

    cout<<"Your move at position: "<<endl;
    cin>>pos;
    if(board[pos]!=2){
        cout<<"Already occupied position"<<endl;
        user_game();
    }
    if(pos == Posswin(player)){
        Go(pos);
        display();
        cout<<"Player wins"<<endl;
        return;
    }
    Go(pos);
    display();
    comp_game();
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
    return 0;
}
