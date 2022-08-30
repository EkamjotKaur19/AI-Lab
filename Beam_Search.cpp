#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 12

vector<bool> visited(n,false);
void beam(int g[n][n], int w, int start){
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int i=0; i<n; i++){
            if(g[node][i]==1 && visited[i]==false && q.size()<w){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(int g[n][n], int w){
    queue <int> q;
    vector <int> seq;
    visited[w]=true;
    q.push(w);
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int j=0; j<n; j++){
            if(g[node][j]==1){
                if(visited[j]==false){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
    }
    
}

//MAIN FUNCTION
int main(){
    int w, start;
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
/*
    int g2[n][n]={{0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
         {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, 
         {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
         {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, 
         {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}}
  */   
    //SOURCE VERTEX AS INPUT
    cout<<"Enter the starting vertex for BFS/DFS"<<endl;
    cin>>start;
    cout<<"For queue width=1"<<endl;
    beam(g,1,start);
    cout<<endl;
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    cout<<"For queue width=2"<<endl;
    beam(g,2,start);
    cout<<endl;
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    cout<<"For queue width=3"<<endl;
    beam(g,3,start);
    cout<<endl;
    return 0;
}

/*
Output: For graph with 10 nodes
Enter the starting vertex for BFS/DFS
0
For queue width=1
0 1 2 4 3 6 7
For queue width=2
0 1 2 3 4 6 5 7 9 8
For queue width=3
0 1 2 5 3 4 9 6 8 7

Output: For graph with 12 nodes
Enter the starting vertex for BFS/DFS
0
For queue width=1
0 1 2 5 4 3
For queue width=2
0 1 6 2 5 9 4 8 3 11 10 7
For queue width=3
0 1 6 7 2 10 5 9 11 4 8 3
*/
