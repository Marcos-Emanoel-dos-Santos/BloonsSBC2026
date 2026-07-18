#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coins;
vector<int> num_dices;

int solve(int target){
    if(target < 0) return 1e9;
    if(target == 0) return 0;

    if(num_dices[target] != -1) return num_dices[target];
    int curr = 1e9;


    for(int i = 0; i < coins.size(); i++) curr = min(curr, solve(target - coins[i]) + 1);
    

    num_dices[target] = curr;

    return curr;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    coins.assign(n, -1);
    num_dices.assign(x + 1, -1);
    for(int i = 0; i < n; i++) cin >> coins[i];

    int ans = solve(x);

    if(ans >= 1e9) ans = -1;
    cout << ans << '\n';

    return 0;
}