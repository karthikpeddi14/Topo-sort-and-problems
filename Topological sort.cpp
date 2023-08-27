#include <bits/stdc++.h>
void dfs(vector<int> adj[], vector<int>& visited, stack<int>& st , int i)
{
    visited[i] = 1;
    for(auto it:adj[i])
    {
        if(visited[it]==0) dfs(adj,visited,st,it);
    }
    st.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];
    vector<int> visited(nodes,0);
    stack<int> st;
    for(auto it:graph)
    {
        adj[it[0]].push_back(it[1]);
    }

    for(int i=0 ; i<nodes ; i++)
    {
        if(visited[i]==0)
        {
            dfs(adj,visited,st,i);
        }
    }
    
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}
