#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 13
//Nodes are numbered from 0
void dfs(int g[n][n], int w, int d, vector<bool>&visited){  
    if(d==0){
        return;
    }
    else{
        visited[w]=true;
        cout<<w<<" ";
        for(int i=0; i<n; i++){
            if(g[w][i]==1){
                if(visited[i]==false){
                    dfs(g,i,d-1,visited);
                }   
            }
        }
    }
    return;
}
//Nodes are numbered from 0
void dfs_main(int g[n][n], int w){
    for(int i=1; i<=3; i++){
        vector <bool> visited(n,false);
        cout<<"For depth= "<<i<<endl;
        dfs(g,w,i,visited);
        cout<<endl;
    }
}


//MAIN FUNCTION
int main(){
//Nodes are numbered from 0
//                0 1 2 3 4 5 6 7 8 9 0 1 2 
    int g[n][n]={{0,1,1,1,0,0,0,0,0,0,0,0,0},
                 {1,0,0,0,1,1,1,0,0,0,0,0,0},
                 {1,0,0,0,0,0,1,1,0,0,0,0,0},
                 {1,0,0,0,0,0,0,1,1,0,0,0,0},
                 {0,1,0,0,0,0,0,0,0,1,1,0,0},
                 {0,1,0,0,0,0,0,0,0,0,1,0,0},
                 {0,1,1,0,0,0,0,0,0,0,1,1,0},
                 {0,0,1,1,0,0,0,0,0,0,0,1,0},
                 {0,0,0,1,0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,1,0,0,0,0,0,0,0,0},
                 {0,0,0,0,1,1,1,0,0,0,0,1,0},
                 {0,0,0,0,0,0,1,1,1,0,1,0,0},
                 {0,0,0,0,0,0,0,0,1,0,0,0,0}};

    //SOURCE VERTEX AS INPUT
    int w;
    cout<<"Enter the starting vertex"<<endl;
    cin>>w;
    dfs_main(g,w);
    return 0;
}

/*
    Output:
    Enter the starting vertex
    0
    For depth= 1
    0
    For depth= 2
    0 1 2 3
    For depth= 3
    0 1 4 5 6 2 7 3 8
*/
