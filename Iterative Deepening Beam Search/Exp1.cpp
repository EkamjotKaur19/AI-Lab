#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &matrix, vector<bool> &vis, int curr, int d, int w)
{
    if (d == 0)
        return;
    vis[curr] = true;
    cout << curr + 1 << " ";
    for (int i = 0, cnt = 0; i < matrix.size(); i++)
        if (matrix[curr][i] == 1 && !vis[i] && cnt < w)
            dfs(matrix, vis, i, d - 1, w + 1), cnt++;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x][y] = adj[y][x] = 1;
    }
    for (int d = 1; d <= 3; d++)
    {
        cout << "d=" << d << ", w=" << 1 << " -> ";
        vector<bool> vis(n, false);
        dfs(adj, vis, 0, d, 1);
        cout << endl;
    }
}
