#include <iostream>
#include <algorithm>
using namespace std;


void solve(){
    long long nums[3] = {};
    long long sums[3] = {};
    cin >> nums[0] >> nums[1] >> nums[2];

    long long min_value = 1e12;
    long long max_value_pos = 0;

    for(int i = 0; i < 3; i++){
        sums[i] = nums[i % 3] + nums[(i+1) % 3];
        if(nums[i] < min_value) min_value = nums[i];
        if(nums[i] > nums[max_value_pos]) max_value_pos = i;
    }

    for(long long s : sums) if(s < nums[max_value_pos]) nums[max_value_pos] = s;

    cout << nums[max_value_pos] - min_value << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();


    return 0;
}