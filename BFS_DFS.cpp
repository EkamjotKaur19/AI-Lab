#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 10

vector <bool> visited(n,false);

//DFS ITERATIVE :- USING STACK
vector<int> dfs_stack(int g[n][n], int w){
    stack <int> st;
    visited[w]=true;
    vector <int> seq;
    st.push(w);
    seq.push_back(w);
    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(visited[node]==false){
            seq.push_back(node);
            visited[node]=true;
        }

        for(int i=0; i<n; i++){
            if(g[node][i]==1 && visited[i]==false){
                st.push(i);
            }
        }
    }
    return seq;
}

//DFS RECURSIVE
vector<int> dfs(int g[n][n], int w){  
    visited[w]=true;
    vector <int> seq;
    cout<<w<<" ";
    seq.push_back(w);
    for(int i=0; i<n; i++){
        if(g[w][i]==1){
            if(visited[i]==false){
                dfs(g,i);
            }
                
        }
    }
    return seq;
}

//DFS for disconnected graph
void dfs_disconnected(int g[n][n], int w, int N){
    vector<int>seq;
    dfs(g,w);
    for(int i=0; i<N; i++){
        if(visited[i]==false){
            dfs(g,i);
        }
    }
    return;
}

/************************/

//BFS ITERATIVE :- USING QUEUE
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

//BFS for Disconnected
void bfs_disconnected(int g[n][n], int w, int N){
    vector<int>seq;
    bfs(g,w);
    for(int i=0; i<N; i++){
        if(visited[i]==false){
            bfs(g,i);
        }
    }
    return;
}

//MAIN FUNCTION
int main(){
    //INPUT Vertices
    int N;
    cout<<"Enter number of vertices"<<endl;
    cin>>N;
    
    //Input Edges
    int  e;
    cout<<"Enter number of edges of the graph"<<endl;
    cin>>e;
    int g[n][n];
    int u, v, w;

    //Create graph adjacency matrix
    cout<<"Enter pair of nodes to draw edges between"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                g[i][i]=0;
            }
            else{
                g[i][j]=0;
            }
        }
    }
    //DIRECTED GRAPH
    for(int i=0; i<e; i++){
        cin>>u>>v;
        g[u][v]=1;
    }

    
    /*cout<<"The adjacency matrix for the input graph is"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    

    //SOURCE VERTEX AS INPUT
    cout<<"Enter the starting vertex for BFS/DFS"<<endl;
    cin>>w;

    //BFS OR DFS
    int inp;
    cout<<"Press 1 for BFS and 2 for DFS"<<endl;
    cin>>inp;
    vector<int> seq;
    
    if(inp==1){
        cout<<"The BFS sequence is"<<endl;
        bfs_disconnected(g,w, N);
        
    }
    else if(inp==2){
        cout<<"The DFS sequence is"<<endl;
        dfs_disconnected(g,w, N);
        for(auto it: seq){
            cout<<seq[it]<<"  ";
        }
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
    
    return 0;
}

/*
Example for Connected Undirected
Verices = 8
Edges = 10
0 2
2 6
6 7
7 5
5 1
1 0
7 3
3 0
7 4
4 1

Example for Disconnected Directed
Vertices = 7
Edges = 5
0 4
4 5
5 6
1 3
2 3
*/
