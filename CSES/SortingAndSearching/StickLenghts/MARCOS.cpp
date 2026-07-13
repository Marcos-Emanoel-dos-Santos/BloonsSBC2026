#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> sticks(n);
    
    for(int i = 0; i < n; i++) cin >> sticks[i];

    sort(sticks.begin(), sticks.end());

    long long median = sticks[n / 2];


    long long min_cost = 0;
    for(int i = 0; i < n; i++){
        min_cost += abs(median - sticks[i]);
    }

    cout << min_cost << '\n';

    return 0;
}