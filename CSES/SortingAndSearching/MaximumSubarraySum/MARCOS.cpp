#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    long long max_sum = -1e18;
    long long curr_sum = 0;

    for(int i = 0; i < n; i++){
        curr_sum += nums[i];
        if(curr_sum > max_sum) max_sum = curr_sum;

        if(curr_sum < 0){
            curr_sum = 0;
        }
    }

    
    cout << max_sum << '\n';

    return 0;
}