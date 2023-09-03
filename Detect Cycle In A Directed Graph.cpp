#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    queue<int> q;
    vector<int> in_count(n+1,0);
    int cnt = 0;
    vector<vector<int>> adj(n+1);

    for(int i=0 ; i<edges.size() ; i++)
    {
      int a = edges[i].first;
      int b = edges[i].second;
      adj[a].push_back(b);
    }

    for(int i=1 ; i<=n ; i++)
    {
      for(auto it:adj[i])
      {
        in_count[it]++;
      }
    }

    for(int i=1 ; i<=n ; i++)
    {
      if(in_count[i]==0) q.push(i);
    }

    while(!q.empty())
    {
      int a = q.front();
      q.pop();
      cnt++;
      for(auto it:adj[a])
      {
        in_count[it]--;
        if(in_count[it]==0) q.push(it);
      }
    }
    if(cnt==n) return false;
    return true;

}
