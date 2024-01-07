#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, div;
    cin >> x;
    div = 3000/x;
    if(x*div < 3000) div++;
    if(div > 15){
        cout << "15\n";
    } else {
        cout << div << "\n";
    }
    return 0;
}