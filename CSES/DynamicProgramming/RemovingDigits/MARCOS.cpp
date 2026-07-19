#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int tmp = i;
        while(tmp > 0){
            int digit = tmp % 10;

            dp[i] = min(dp[i], dp[i - digit] + 1);

            tmp /= 10;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}