#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 10
//Nodes are numbered from 0
void dfs(int g[n][n], int w, int d, vector<bool>&visited, int m){ 
    queue<int>q; 
    if(d==0){
        return;
    }
    else{
        visited[w]=true;
        cout<<w<<" ";
        q.push(w);
        for(int i=0; i<n; i++){
            if(q.size()<m){
                if(g[w][i]==1){
                    if(visited[i]==false){
                        dfs(g,i,d-1,visited,m);
                    }   
                }
            }
        }
    }
    return;
}
//Nodes are numbered from 0
void dfs_main(int g[n][n], int w){
    int m = 3;
    for(int i=1; i<=3; i++){
        vector <bool> visited(n,false);
        cout<<"For depth = "<<i<<endl;
        dfs(g,w,i,visited,2);
        cout<<endl;
    }
}


//MAIN FUNCTION
int main(){
//Nodes are numbered from 0
//                
    int g[n][n]={{0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, 
                {1, 0, 1, 1, 0, 0, 0, 0, 0, 0}, 
                {1, 1, 0, 0, 1, 0, 0, 1, 0, 0}, 
                {0, 1, 0, 0, 1, 0, 1, 0, 1, 0}, 
                {0, 0, 1, 1, 0, 1, 1, 0, 0, 0}, 
                {1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, 
                {0, 0, 0, 1, 1, 0, 0, 1, 0, 0}, 
                {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
                {0, 0, 0, 1, 0, 0, 0, 0, 0, 1}, 
                {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

    //SOURCE VERTEX AS INPUT
    int w;
    cout<<"Enter the starting vertex"<<endl;
    cin>>w;
    dfs_main(g,w);
    return 0;
}

