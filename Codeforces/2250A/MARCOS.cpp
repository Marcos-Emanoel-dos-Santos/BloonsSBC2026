#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


void solve(){
    int n; cin >> n;
    if(n & 1){
        int trash;
        for(int i = 0; i < n; i++) cin >> trash;
        cout << "NO\n";
        return;
    }

    long long minV = INT_MIN; long long maxV = INT_MAX;

    for(int i = 0; i < n; i++){
        long long aux; cin >> aux;
        if(!(i & 1)){
            maxV = min(aux, maxV);
        }
        else {
            minV = max(aux, minV);
        }
    }


    if(maxV - minV > 1) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}