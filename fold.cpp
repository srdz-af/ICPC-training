#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<vector<ll>> s; 

vector<ll> fold(ll n, vector<ll> vec){
    vector<ll> res;
    if(n == vec.size()){
        res = vec;
        reverse(res.begin(), res.end());
        return res;
    }
    if(n <= vec.size()/2){
        for(int i = vec.size()-1; i >= n*2; i--){
            res.push_back(vec[i]);
        }
        ll l = 0, r = (n*2)-1;
        while(l < r){
            res.push_back(vec[l] + vec[r]);
            l++; r--;
        }
    } else {
        ll l = vec.size()-(vec.size()-n)*2, r = vec.size()-1;
        for(int i = 0; i < l; i++){
            res.push_back(vec[i]);
        }
        while(l < r){
            res.push_back(vec[l] + vec[r]);
            l++; r--;
        }
    }
    return res;
}


void rec(vector<ll> v){
    if (v.size() == 1) {
        s.insert(v); 
        return;
    }
    for (ll i = 1; i<v.size(); i++){
        vector<ll> vrec;
        vrec = fold(i, v);
        s.insert(vrec);
        rec(vrec);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> v1;
    while (n--){
        ll x;
        cin >> x;
        v1.push_back(x);
    }
    ll m;
    cin >> m;
    vector<ll> v2;
    while(m--){
        ll x;
        cin >> x;
        v2.push_back(x);
    }
    s.insert(v1);
    rec(v1);
    reverse(v1.begin(), v1.end());
    s.insert(v1);   

    if (s.count(v2)){
        cout << "S\n";
    }
    else{
        cout << "N\n";
    }

}
