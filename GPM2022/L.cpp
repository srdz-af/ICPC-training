#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<ll, ll, custom_hash> safemap;
typedef gp_hash_table<ll, ll, custom_hash> safehash;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordset; 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multiset; 

ll ojo, x;

void bfs(ll o, vector<vector<ll>>& adj, vector<bool>& vis ,vector<ll>& dis){
    queue<ll> trav;
    trav.push(o);
    dis[o] = 0;

    while(!trav.empty()){
        ll curr = trav.front();
        trav.pop();
        for(auto it: adj[curr]){
            if(!vis[it]){
                if(it == x) ojo = curr;
                trav.push(it);
                dis[it] = dis[curr] + 1;
            }
        }
        vis[curr] = true;
    }
    return;
}

ll dfs(ll o, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& desc){
    ll aux = 1;
    vis[o] = true;
    for(auto it: adj[o]){
        if(!vis[it]) aux += dfs(it, adj, vis, desc);
    }
    desc[o] = aux;
    return aux;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    ll n;
    cin >> n >> x;
    x--;

    vector<vector<ll>> adj(n);
    vector<ll> dis(n);
    vector<ll> desc(n);
    vector<bool> vis(n, false);
    vector<bool> vis2(n, false);

    for(int i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0, adj, vis, dis);
    dfs(0, adj, vis2, desc);

    cout << 2*(n-1-desc[ojo]-(dis[x]-2)) + dis[x] << "\n";

    return 0;
}
