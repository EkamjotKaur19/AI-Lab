#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<utility>
using namespace std;

set<pair<int,int>>open;
set<int>close;
vector<int>f(100000),g(100000),h(100000),parent(100000);

void dfs(int i,int bestnode,vector<vector<int> >&matrix){
    
    int gnew=g[bestnode]+matrix[bestnode][i];
    
    if(open.find({i,f[i]})!=open.end()){
        int fnew=gnew+h[i];
        if(fnew>f[i])
            return;
        else{
            open.erase({f[i],i});
            parent[i]=bestnode;
            f[i]=fnew;
            g[i]=gnew;
            open.insert({f[i],i});
        }
    }
    else if(close.find(i)!=close.end()){
        int fnew=gnew+h[i];
        if(fnew>f[i])
            return;
        else{
            open.erase({f[i],i});
            parent[i]=bestnode;
            f[i]=fnew;
            g[i]=gnew;
            open.insert({f[i],i});
        }
        for(int j=0;matrix.size();j++){
            if(matrix[i][j])
                dfs(j,bestnode,matrix);
        }
    }
}

vector<int> A_star(vector<vector<int> >&matrix){
    int n=(int)matrix.size();
    g[0]=0;
    f[0]=g[0]+h[0];
    open.insert({f[0],0});
    close.insert(0);
    parent[0]=-1;
    
    while(!open.empty()){
        int bestnode= open.begin()->second;
        cout<<bestnode<<" ";
        close.insert(bestnode);
        open.erase({bestnode,f[bestnode]});
        
        if(bestnode==n-1)
            break;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[bestnode][i]){
                if(open.find({i,f[i]})!=open.end()||close.find(i)!=close.end())
                    dfs(i,bestnode,matrix);
                else{
                    f[i]=g[i]+h[i];
                }
            }
        }
    }
    if(open.empty())
        return {-1};
    return {};
 }

int main(){
    vector<int> H={150,10,10,0};
    for(int i=0;i<H.size();i++)
        h[i]=H[i];
    vector<vector<int> > G={
        {0,1,0,100},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0}
    };

    vector<int>ans=A_star(G);
    parent[0]=-1;
    int n=H.size()-1;
    while(n!=-1){
        cout<<n<<" ";
        n=parent[n];
    }
}
