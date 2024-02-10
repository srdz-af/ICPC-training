#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll ar[25];
ll n;

ll rec(ll i, ll a, ll b){
    if(i == n) return abs(a-b);
    return min(rec(i+1, a+ar[i], b), rec(i+1, a, b+ar[i]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }

    cout << rec(0, 0, 0) << "\n";
    return 0;
}
