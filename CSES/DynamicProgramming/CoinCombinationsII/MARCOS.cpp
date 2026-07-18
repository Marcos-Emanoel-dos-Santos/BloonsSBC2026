#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - coins[i] >= 0){
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';

    return 0;
}