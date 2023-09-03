#include<bits/stdc++.h>
vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites)
{
    int n = numCourses;
    vector<vector<int>> adj(n+1);
    
    for(int i=0 ; i<prerequisites.size() ; i++)
    {
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            adj[b].push_back(a);
    }

    vector<int> in_ward(n+1,0);
    for(int i=1 ; i<=n ; i++)
    {
        for(auto it:adj[i])
        {
            in_ward[it]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for(int i=1 ;i<=n ; i++)
    {
        if(in_ward[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int a = q.front();
        ans.push_back(a);
        q.pop();

        for(auto it:adj[a])
        {
            in_ward[it]--;
            if(in_ward[it]==0) q.push(it);
        }
    }

    if(ans.size()==n) return ans;
    return {};

}
