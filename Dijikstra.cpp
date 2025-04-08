#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector<list<pp>> grf;

void add_edge(int v, int u, int wt, bool Bidr = true){
    grf[u].push_back({v,wt});
    if(Bidr)
    grf[v].push_back({u,wt});
}

unordered_map<int,int> dijikstra(int src , int n){
    priority_queue<pp, vector<pp> , greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int,int> mp;
     for(int i=1;i<=n;i++){
        mp[i] = INT_MAX;
     }
     pq.push({0,src});
     mp[src] = 0;
     

     while( !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        
            vis.insert(curr.second);
            pq.pop();
        for(auto neighbr : grf[curr.second]){
            if(!vis.count(neighbr.first) && mp[neighbr.first]>mp[curr.second]+neighbr.second){
                pq.push({mp[curr.second]+neighbr.second,neighbr.first});
                par[neighbr.first] = curr.second;
                mp[neighbr.first] = mp[curr.second]+neighbr.second;
            }
        }

     }
     return mp;
}


int main(){
    int m,n;
    cin>>m>>n;
    grf.resize(n+1, list<pp> ());
    while(m--){
        int v,u,wt;
        cin>>v>>u>>wt;
        add_edge(v,u,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int> ans = dijikstra(src,n);
    for(auto p : ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    int dest;
    cin>>dest;
    cout<<ans[dest]<<endl;

    return 0;
}