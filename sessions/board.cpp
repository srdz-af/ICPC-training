#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool diagpos[20];
bool diagneg[20];
bool colum[8];
bool row[8];
bool board[8][8];

ll ans = 0;

void rec(ll cq, ll c){
    if (cq == 8){
        ans++;
        return;
    }

    for (ll j = 0; j<8; j++){
        for (ll i=c; i<8; i++){
            if(board[j][i] || diagpos[j+i] || colum[i] || row[j] || diagneg[i-j+7]){
                continue;
            }

            diagpos[j+i] = colum[i] = row[j] = diagneg[i-j+7] = true;

            rec(cq+1, c);

            diagpos[j+i] = colum[i] = row[j] = diagneg[i-j+7] = false;
            
            

        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0); 

    for(ll i = 0; i<8; i++){
        for(ll j = 0; j<8; j++){
            char c;
            cin >> c;
            if (c == '*'){
                board[i][j] = true;
            }

        }
    }

    rec(0, 0);
    cout << ans << '\n';
    return 0

}
