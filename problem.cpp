#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
ll mov[4] = {0, 0, 1, -1};
ll mat[1005][1005];
ll vis[1005][1005];
ll dis[1005][1005];

bool check(ll x, ll y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}
void bfs(pair<ll, ll> o){
    queue<pair<ll, ll>> trav;
    trav.push(o);
    vis[o.first][o.second] = 0;
    while(!trav.empty()){
        ll x = trav.front().first;
        ll y = trav.front().second;
        trav.pop();
        for(int i = 0; i < 4; i++){
            ll nextx, nexty;
            nextx = x + mov[i];
            nexty = y + mov[3-i];
            if(check(nextx, nexty) && vis[nextx][nexty] == -1 && mat[nextx][nexty] != -1){
                if(mat[nextx][nexty]){
                    dis[mat[nextx][nexty]][mat[o.first][o.second]] = vis[x][y]+1;
                    dis[mat[o.first][o.second]][mat[nextx][nexty]] = vis[x][y]+1;
                }
                vis[nextx][nexty] = vis[x][y]+1;
                trav.push({nextx, nexty});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    vector<pair<ll, ll>> tes;
    tes.push_back({0, 0});
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];

            if(mat[i][j] > 0){
                tes.push_back({i, j});
            }

        }
    }

    ll q;
    cin >> q;

    for(auto it: tes){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = -1;
            }
        }

        bfs(it);
    }

    while(q--){
        bool f = true;
        ll r, ans = 0;
        cin >> r;
        ll ant = 0;
        for(int i = 0; i < r; i++){
            ll a; 
            cin >> a;
            ans += dis[a][ant];
            if(!dis[a][ant]) f = false;
            ant = a;
        }
        if(f) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}

/* 
5 5
0 0 0 0 0
0 6 -1 -1 0
0 0 -1 3 0
-1 -1 -1 -1 0
4 -1 0 0 0
7
3
6 3 4
3
4 3 6
1
6
1
3
1
4
2
6 3
2
3 6

*/