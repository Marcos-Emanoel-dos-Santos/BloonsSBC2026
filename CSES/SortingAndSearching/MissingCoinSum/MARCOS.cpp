#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    sort(coins.begin(), coins.end());

    bool found_missing = false;
    long long target = 1;
    int idx = 0;

    while(!found_missing && idx < n){
        if(coins[idx] <= target){
            target += coins[idx];
            idx++;
        }
        else {
            found_missing = true;
        }
    }
    cout << target << '\n';


    return 0;
}