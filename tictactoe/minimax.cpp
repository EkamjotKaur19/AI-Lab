/*Minimax Algorithm*/
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

*/

vector<int>board(10,2);
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
    cout<<"-------------------"<<endl;

    for(int i=4; i<=6; i++){
        cout<<put_X_O(board[i])<<" ";
        if(i!=6){
            cout<<" | ";
        }
    }
    cout<<endl;
    cout<<"-------------------"<<endl;

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

vector<vector<int>>move_gen(){
    vector<vector<int>>ans;
    for(int i=0; i<9; i++){
        if(board[i]==2){
            board[i]=3;
            ans.push_back(board);
            board[i]=2;
        }
    }
    return ans;
}

int evaluate(int player){
    int comp_third, comp_sec, comp_first;
    int opp_third, opp_sec, opp_first;

    if(player==0){
        comp_third=27;
        comp_sec=18;
        comp_first=12;
    }
    else{
        opp_third=125;
        opp_sec=50;
        opp_first=20;
    }

    for(int i=1;i<=9; i=i+3){
        if(board[i]*board[i+1]*board[i+2]==comp_third){
            return 10;
        }
        if(board[i]*board[i+1]*board[i+2]==opp_third){
            return -10;
        }
    }

    for(int i=1;i<=9; i=i++){
        if(board[i]*board[i+3]*board[i+6]==comp_third){
            return 10;
        }
        if(board[i]*board[i+3]*board[i+6]==opp_third){
            return -10;
        }
    }

    if(board[1]*board[5]*board[9] == comp_third){
        return 10;
    }
    if(board[3]*board[5]*board[7] == opp_third){
        return -10
    }


    for(int i=1;i<=9; i=i+3){
        if(board[i]*board[i+1]*board[i+2]==comp_two){
            return 5;
        }
        if(board[i]*board[i+1]*board[i+2]==opp_two){
            return -5;
        }
    }

    for(int i=1;i<=9; i=i++){
        if(board[i]*board[i+3]*board[i+6]==comp_two){
            return 5;
        }
        if(board[i]*board[i+3]*board[i+6]==opp_two){
            return -5;
        }
    }

    if(board[1]*board[5]*board[9] == comp_two){
        return 5;
    }
    if(board[3]*board[5]*board[7] == opp_two){
        return -5
    }
    return 0;
}

bool draw_cond(){
    if(turn>9){
        cout<<"Draw"<<endl;
        exit(0);
    }
}



int main(){
    
    int choice;

    cout<<"Do You Want To Play?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    
    return 0;
}
