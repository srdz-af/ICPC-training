#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mat[10000][10000];
ll mat_vis[10000][10000];
ll mat_char[10000][10000];

void bfs_mat(pair<ll, ll> o, ll n, ll m){
	queue<pair<ll, ll>> cola;
	cola.push(o);
	ll curr_num = mat[o.first][o.second];

	while(!cola.empty()){
		pair<ll, ll> curr = cola.front();
		cola.pop();
		ll x = curr.first;
		ll y = curr.second;
		
		if (x-1 >= 0){
			if (mat[x-1][y] != -1 && mat_vis[x-1][y] != 0){
				mat_vis[x-1][y] = mat_vis[x][y] + 1;
				if (mat[x-1][y] > 0){
					mat_char[curr_num][mat[x-1][y]] = mat_vis[x-1][y];
				}
				cola.push({x-1, y});
			}
		}
		if (x+1 <= m){
			if (mat[x+1][y] != -1 && mat_vis[x+1][y] != 0){
				mat_vis[x+1][y] = mat_vis[x][y] + 1;
				if (mat[x+1][y] > 0){
					mat_char[curr_num][mat[x+1][y]] = mat_vis[x+1][y];
				}
				cola.push({x+1, y});
			}
		}
		if (y-1 <= n){
			if (mat[x][y-1] != -1 && mat_vis[x][y-1] != 0){
				mat_vis[x][y-1] = mat_vis[x][y] + 1;
				if (mat[x][y-1] > 0){
					mat_char[curr_num][mat[x][y-1]] = mat_vis[x][y-1];
				}
				cola.push({x, y-1});
			}
		}
		if (y+1 >= 0){
			if (mat[x][y+1] != -1 && mat_vis[x][y+1] != 0){
				mat_vis[x][y+1] = mat_vis[x][y] + 1;
				if (mat[x][y+1] > 0){
					mat_char[curr_num][mat[x][y+1]] = mat_vis[x][y+1];
				}
				cola.push({x, y+1});
			}
		}
	}
}

// void bfs(ll o, unordered_map<ll,vector<ll>> &adj, vector<ll> &vis){
// 	queue<ll> cola;
// 	cola.push(o);
// 	vis[o] = 1;

// 	while(!cola.empty()){
// 		ll curr = cola.front();
// 		cola.pop();

// 		for (auto it: adj[curr]){
// 			if (vis[it] == -1){
// 				cola.push(it);
// 				vis[it] = !vis[curr];
// 			}
// 		}
// 	}
// 	return true;
// }

// void dfs(ll o, unordered_map<ll, vector<ll>> &adj, vector<ll> &vis){
// 	vis[it] = 1;
// 	for(auto it: adj[o]){
// 		if(!vis[it]){
// 			dfs(it, adj, vis);
// 		}
// 	}
// }

int main(){
	unordered_map<ll,pair<ll, ll>> tesoros;
	tesoros[0] = {0, 0};
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			if (mat[i][j]>0){
				tesoros[mat[i][j]] = {i, j};
			}
		}
	}

	ll q;
	cin >> q;

	while(q--){
		ll t; 
		cin >> t;
		vector<ll> v;
		v.push_back(0);
		bfs_mat({0, 0}, n, m);
		while(t--){
			ll x;
			cin >> x;
			pair<ll,ll> ubtes = tesoros[x];
			bfs_mat(ubtes, n, m);
			v.push_back(x);
		}
		

		ll dis = 0;
		for (ll i=0; i<v.size()-1; i++){
			dis = mat_char[v[i]][v[i+1]];
		}

		cout << dis << '\n';

	}

	cout << "\n";

}


0 	-1 	 1 	 -1 	 0
0 	-1 	 0 	 -1 	-1
3 	 0 	 0 	  0 	 4
-1 	-1 	 0 	 -1 	-1
0 	-1 	 2 	 -1 	 0