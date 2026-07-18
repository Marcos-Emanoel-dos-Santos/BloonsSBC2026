#include <iostream>
#include <vector>
using namespace std;

vector<long long> combinations;
const int MOD = 1e9 + 7;

long long solve(int num){
    if(num < 0) return 0;
    if(num == 0) return 1;

    long long cur = 0;

    if(combinations[num] != -1) return combinations[num];

    for(int i = 1; i <= 6; i++){
        cur = (cur + solve(num - i)) % MOD;
    }
    
    combinations[num] = cur;
    return cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    combinations.assign(n + 1, -1);
    
    long long ans = solve(n);

    cout << ans << '\n';

    return 0;
}