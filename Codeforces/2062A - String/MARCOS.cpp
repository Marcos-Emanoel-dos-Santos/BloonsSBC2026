#include <iostream>
#include <string>

using namespace std;
void solve(){
    string s; cin >> s;

    int count = 0;
    for(int i = 0; i < s.size(); i++) if(s[i] == '1') count++;

    cout << count << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++) solve();

    return 0;
}