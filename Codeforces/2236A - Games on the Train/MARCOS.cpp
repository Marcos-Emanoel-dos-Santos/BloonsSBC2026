#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> heights(n);

    int minimum = 100; int maximum = 1;
    for(int i = 0; i < n; i++){
        cin >> heights[i];
        minimum = min(minimum, heights[i]);
        maximum = max(maximum, heights[i] + 1);
    }

    int ans = max(1, maximum - minimum);

    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}