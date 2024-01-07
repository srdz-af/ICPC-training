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



map<char, char> keypad = {{'a', '2'}, {'b', '2'}, {'c', '2'}, {'d', '3'}, {'e', '3'}, {'f', '3'}, {'g', '4'}, {'h', '4'}, {'i', '4'}, {'j', '5'}, {'k', '5'}, {'l', '5'},{'m', '6'},{'n', '6'}, 
{'o', '6'},{'p', '7'},{'q', '7'},{'r', '7'},{'s', '7'},{'t', '8'},{'u', '8'},{'v', '8'}, {'w', '9'},{'x', '9'},{'y', '9'},{'z', '9'}};

string conv(string id){
    string aux = "";
    for(char c: id){
        aux += keypad[c];
    }
    return aux;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    map<string, ll> freq;

    ll n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        freq[conv(s)]++;
    }
    
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        cout << freq[s] << "\n";
    }
    return 0;
}