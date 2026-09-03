#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;
    string aux = s;

    int scores[2] = {0};

    for(int i = 1; i <= 2*n; i++){
        int curr = i - 1;
        int next = i;

        if(s[curr % (2*n)] == '1' && s[next % (2*n)] == '0'){
            aux[curr % (2*n)] = '0';
            aux[next % (2*n)] = '1';
        }

    }


    for(int i = 1; i <= 2*n; i++){
        int curr = i - 1;
        int next = i;
        if(aux[curr % (2*n)] == '1') scores[i % 2]++;
    }
    
    cout << scores[0] << ' ' << scores[1] << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}