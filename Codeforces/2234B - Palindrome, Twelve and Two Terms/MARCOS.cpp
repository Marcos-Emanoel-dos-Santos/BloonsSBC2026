#include <iostream>
using namespace std;


void solve(){
    long long n; cin >> n;
    if(n == 10){
        cout << -1 << '\n';
        return;
    }

    int MOD = n % 12;
    if(MOD == 10){
        cout << 22 << ' ' << n - 22 << '\n';
    }
    else {
        cout << MOD << ' ' << n - MOD << '\n';
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}