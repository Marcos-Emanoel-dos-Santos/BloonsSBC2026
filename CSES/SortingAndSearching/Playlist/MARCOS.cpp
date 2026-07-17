#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    set<long long> songs;

    int L = 0; int R = 0;
    int max_len = 0;

    while(R < n){
        if(songs.count(nums[R]) == 0){
            songs.insert(nums[R]);
            if(max_len < R - L + 1) max_len = R - L + 1;
            R++;
        }
        else {
            songs.erase(nums[L]);
            L++;
        }
    }
    
    cout << max_len << '\n';


    return 0;
}