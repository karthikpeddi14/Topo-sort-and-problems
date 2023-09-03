vector<int> topologicalSort(vector<vector<int>> &adj, int v) {

    vector<int> incoming(v,0);
    queue<int> st;
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


string getAlienLanguage(vector<string> &dictionary, int k)
{
    vector<vector<int>> adj(k);
    int n = dictionary.size();

    for(int i=0 ; i<n-1 ;i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int len = min(s1.size(),s2.size());
        for(int ptr=0 ; ptr<len ; ptr++)
        {
            if(s1[ptr]!=s2[ptr])
            {
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
    vector<int> topo = topologicalSort(adj, k);
    string ans="";
    for(auto it:topo)
    {
        ans = ans+char(it+'a');
    }
    return ans;
}
