class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<vector<int>> adj(v);

        for(int i=0 ; i<v ; i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
            }
        }
        vector<int> incoming(v,0);
        for(int i=0 ; i<v ; i++)
        {
            for(auto it:adj[i]) incoming[it]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<v ; i++)
        {
            if (!incoming[i]) {
            q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int a = q.front();
            ans.push_back(a);
            q.pop();

            for (auto it : adj[a]) {
            incoming[it]--;
            if(incoming[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
