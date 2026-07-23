#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> nums(n + 1);
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i++) cin >> nums[i];

    if(nums[0] == 0){
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][nums[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(nums[i] == 0){
            for(int v = 1; v <= m; v++){
                for(int k = -1; k <= 1; k++){
                    int prev_v = v + k;
                    if(prev_v >= 1 && prev_v <= m){
                        dp[i][v] = (dp[i][v] + dp[i-1][prev_v]) % MOD;
                    }
                }
            }
        }
        else {
            int v = nums[i];
            for(int k = -1; k <= 1; k++){
                int prev_v = v + k;
                if(prev_v >= 1 && prev_v <= m){
                    dp[i][v] = (dp[i][v] + dp[i-1][prev_v]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n-1][i]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}