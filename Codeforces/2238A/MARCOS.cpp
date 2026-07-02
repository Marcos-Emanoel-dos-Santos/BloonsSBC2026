#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(){
    int n; cin >> n;
    int c; cin >> c;

    vector<int> vA(n);
    vector<int> vB(n);


    for(int i = 0; i < n; i++){
        cin >> vA[i];
    }
    for(int i = 0; i < n; i++){
        cin >> vB[i];
    }


    int time = 0;
    bool permutate = false;
    for(int i = 0; i < n; i++){
        if(vA[i] < vB[i] && !permutate){
            permutate = true;
            time += c;
        }
    }

    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());
    for(int i = 0; i < n; i++){
        if(vA[i] < vB[i]){
            cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < n; i++){
        time += vA[i] - vB[i];
    }

    cout << time << '\n';
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