#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int v) {
    
    vector<int> adj[v];
    queue<int> st;
    for(auto it:graph) adj[it[0]].push_back(it[1]);

    vector<int> incoming(v,0);
    for(int i=0 ; i<v ; i++)
    {
        for(auto it:adj[i]) incoming[it]++;
    }
    
    for(int i=0 ; i<v ; i++)
    {
        if (!incoming[i]) {
          st.push(i);
        }
    }
    vector<int> ans;
    while(!st.empty())
    {
        int a = st.front();
        ans.push_back(a);
        st.pop();

        for (auto it : adj[a]) {
          incoming[it]--;
          if(incoming[it]==0) st.push(it);
        }
    }
    return ans;
}
