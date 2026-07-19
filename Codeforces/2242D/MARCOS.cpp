#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
vector<int> PA; vector<int> PB;

void solve(){
    string num_a; cin >> num_a;
    int size_a = num_a.size();
    PA.assign(size_a + 1, 0);
    for(int i = 1; i <= size_a; i++) PA[i] = (PA[i-1] + (num_a[i-1] - '0')) % 10;

    string num_b; cin >> num_b;
    int size_b = num_b.size();
    PB.assign(size_b + 1, 0);
    for(int i = 1; i <= size_b; i++) PB[i] = (PB[i-1] + (num_b[i-1] - '0')) % 10;
    

    if(PA[size_a] != PB[size_b]){
        cout << -1 << '\n';
        return;
    }

    dp.assign(size_a + 1, vector<int>(size_b + 1, 0));


    for(int i = 1; i <= size_a; i++){
        for(int j = 1; j <= size_b; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            if(PA[i] == PB[j]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }

    cout << dp[size_a][size_b] << '\n';

    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}