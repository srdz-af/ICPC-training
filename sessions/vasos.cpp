#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0); 

    ll n;
    cin >> n;
    bool f = false;
    unordered_map<ll> m;
    ll acum = 0;

    for (ll i = 0; i<n; i++){
        ll x;
        cin >> x;
        if(i%2){
            acum += x;
        }
        else{
            acum -= x;
        }
        m[x]++;

        if (acum == 0 || m[x] == 2){
            f = true;
        }
    }

    if (f) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}