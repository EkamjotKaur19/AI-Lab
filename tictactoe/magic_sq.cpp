#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int board[10]={2,2,2,2,2,2,2,2,2,2};
int turn=0;

bool checkWin(){
    int mp[10] = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    int revmp[10] = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    vector<int> comp_moves, user_moves;

    for (int i = 1; i <= 9; i++){
        if (board[i] == 5){
            comp_moves.push_back(mp[i]);
        }
        else if (board[i] == 3){
            user_moves.push_back(mp[i]);
        }
    }

    for (int i = 0; i < comp_moves.size(); i++){
        for (int j = i+1; j < comp_moves.size(); j++){
            for (int k = j+1; k < comp_moves.size(); k++){
                int x = 15-comp_moves[i]-comp_moves[j]-comp_moves[k];
                if (x == 0){
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < user_moves.size(); i++){
        for (int j = i+1; j < user_moves.size(); j++){
            for (int k = j+1; k < user_moves.size(); k++){
                int x = 15-user_moves[i]-user_moves[j]-user_moves[k];
                if (x == 0){
                    return true;
                }
            }
        }
    }
    return false;  
}

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

int make_two()
{
    int pos;

    if (board[5] == 2)
    {
        pos = 5;
    }
    else
    {
        bool done = false;

        for (int i = 2; i <= 8; i += 2)
        {
            if (board[i] == 2) {pos = i; done = true; break;}
        }

        if (!done)
        {
            for (int i = 1; i <= 9; i += 2)
            {
                if (board[i] == 2) {pos = i; break;}
            }            
        }
    }

    return pos;
}

int Poswin(int turn){
    int mp[10] = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    int revmp[10] = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    if (turn%2 == 0){
        vector<int> comp_moves, user_moves;

        for (int i = 1; i <= 9; i++){
            if (board[i] == 5)
            {
                comp_moves.push_back(mp[i]);
            }
            else if (board[i] == 3)
            {
                user_moves.push_back(mp[i]);
            }
        }

        for (int i = 0; i < comp_moves.size(); i++)
        {
            for (int j = i+1; j < comp_moves.size(); j++)
            {
                int x = 15-comp_moves[i]-comp_moves[j];
                if (x > 0 && x < 10 && board[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }

        for (int i = 0; i < user_moves.size(); i++)
        {
            for (int j = i+1; j < user_moves.size(); j++)
            {
                int x = 15-user_moves[i]-user_moves[j];
                if (x > 0 && board[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }
    }
    else
    {
        vector<int> comp_moves, user_moves;

        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 3)
            {
                comp_moves.push_back(mp[i]);
            }
            else if (board[i] == 5)
            {
                user_moves.push_back(mp[i]);
            }
        }

        for (int i = 0; i < comp_moves.size(); i++)
        {
            for (int j = i+1; j < comp_moves.size(); j++)
            {
                int x = 15-comp_moves[i]-comp_moves[j];
                if (x > 0 && x < 10 && board[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }

        for (int i = 0; i < user_moves.size(); i++)
        {
            for (int j = i+1; j < user_moves.size(); j++)
            {
                int x = 15-user_moves[i]-user_moves[j];
                if (x > 0 && board[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }
    }

    return -1;
}

int main()
{
    
    cout<<"Tic Tac Toe - The Game\n";
    cout<<"First turn or Second Turn?\nEnter 1 for first turn, 2 for second turn\n";
    char x;
    int turn;
    if (x == '1'){turn = 2;} else {turn = 1;}


    vector<int> TMP;
    display();
    if (turn == 2)
    {
        cout<<"Input position: \n";
        int x; char C;
        x = C - 48;
        Go(x);
        display();
    }

    while (turn <= 9)
    {
        cout<<"Computer is thinking....\n";
        switch (turn)
        {
            case 1:
                Go(1);
                break;

            case 2:
                if (board[5] == 2)
                {
                    Go(5);                
                }
                else
                {
                    Go(1);
                }
                break;

            case 3:
                if (board[9] == 2)
                {
                    Go(9);                  
                }
                else
                {
                    Go(3);
                }
                break;

            case 4:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    if (( board[1] == 3 || board[4] == 3 ) && board[8] == 3)
                    {
                        Go(9);
                    }
                    else if (( board[3] == 3 || board[6] == 3 ) && board[8] == 3)
                    {
                        Go(7);
                    }
                    else if (board[5] == 3 && board[9] == 3)
                    {
                        Go(7);
                    }
                    else if (( board[4] == 3 || board[6] == 3 ) && board[2] == 3)
                    {
                        Go(1);
                    }
                    else
                    {
                        Go(make_two());
                    }
                }
                break;

            case 5:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    if (board[7] == 2)
                    {
                        Go(7);
                    }
                    else
                    {
                        Go(3);
                    }
                }
                break;

            case 6:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    Go(make_two());
                }
                break;
           
            case 7:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    Go(make_two());
                }
                break;

            case 8:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    Go(make_two());
                }
                break;

            case 9:
                if (Poswin(turn) != -1)
                {
                    Go(Poswin(turn));
                }
                else
                {
                    Go(make_two());
                }  
                break;            
        }

       system("cls");
        display();

        if (checkWin())
        {
            cout<<"\nComputer Won!\n";
            break;
        }

        if (turn != 9)
        {
            cout<<"Enter your move: ";
            int x;
            char C;
            x = C - 48;

            while (board[x] != 2)
            {
                cout<<"Enter valid position ; ";
                cout<<"\n";
                x = C-48;
            }
            Go(x);
           system("cls");
            display();

            if (checkWin())
            {
                cout<<"\nYou Won!\n";
                break;
            }
        }

        turn+=2;
    }

    if (turn > 9)
    {
        cout<<"Game Draw!\n";
    }

    
    system("cls");
}
