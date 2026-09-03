#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;

void solve(){
    int n; cin >> n;
    vector<int> alice(n + 1);
    vector<int> bob(n + 1);
    for(int i = 1; i <= n; i++) cin >> alice[i];
    for(int i = 1; i <= n; i++) cin >> bob[i];


    dp.assign(n + 1, 0);
    vector<int> nextA(n + 2, n + 1);
    vector<int> nextB(n + 2, n + 1);


    long long num_seg = 0;

    for(int i = n; i >= 1; i--){
        if(alice[i] == bob[i]){
            int ep_atual = alice[i];

            int pos_A = nextA[ep_atual + 1];
            int pos_B = nextB[ep_atual + 1];

            if(pos_A == pos_B){
                if(pos_A == n + 1){
                    dp[i] = n;
                }
                else {
                    dp[i] = dp[pos_A];
                }
            }
            else {
                dp[i] = min(pos_A, pos_B) - 1;
            }
        }

        nextA[alice[i]] = i;
        nextB[bob[i]] = i;

        int pos1_A = nextA[1];
        int pos1_B = nextB[1];
        int R_max = 0;

        if(pos1_A == pos1_B){
            if(pos1_A == n + 1) R_max = n;
            else { R_max = dp[pos1_A]; }
        }
        else {
            R_max = min(pos1_A, pos1_B) - 1;
        }

        num_seg += (R_max - i + 1);
    }


    cout << num_seg << '\n';

    return;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();

    return 0;
}