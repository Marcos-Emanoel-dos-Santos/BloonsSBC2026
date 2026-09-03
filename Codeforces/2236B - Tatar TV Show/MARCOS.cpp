#include <iostream>
#include <string>
#include <vector>

using namespace std;
void solve(){
    int n; cin >> n;
    int k; cin >> k;

    string str; cin >> str;
    vector<int> count(k);
    for(int i = 0; i < n; i++){
        if(str[i] == '1') count[i % k]++;
    }

    for(int i = 0; i < k; i++){
        if(count[i] & 1){
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}