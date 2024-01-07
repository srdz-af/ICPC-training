#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

ll arr[MAXN];
ll pre[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n, m, t, acc = 0;
    cin >> n >> m;
    t = m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++){
        acc += arr[i];
        pre[i] = acc;
    }

    while(t--){
        ll s;
        cin >> s;

        ll l, r, mid;
        l = 0;
        r = n-1;

        while(l < r){
            mid = (l+r)/2;
            if(arr[mid] > s){
                r = mid;
            } else {
                l = mid+1;
            }
        }

        if (arr[r] < s){
            cout << pre[r] << "\n";
        }
        else{
            cout << pre[r] - (arr[r]-s) + (n-r-1)*s << "\n";
        }        
    }


    return 0;
}