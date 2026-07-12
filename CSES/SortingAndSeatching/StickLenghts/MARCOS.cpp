#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> sticks(n);
    
    for(int i = 0; i < n; i++) cin >> sticks[i];

    sort(sticks.begin(), sticks.end());

    long long median = sticks[n / 2];


    long long min = 0;
    for(int i = 0; i < n; i++){
        min += abs(median - sticks[i]);
    }

    cout << min << '\n';

    return 0;
}