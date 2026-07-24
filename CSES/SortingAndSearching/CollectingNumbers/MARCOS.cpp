#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int ans = 1;
    vector<int> nums(n + 1);
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        nums[aux] = i;
    }

    for(int i = 1; i < n; i++){
        if(nums[i + 1] < nums[i]) ans++;
    }
    
    cout << ans << '\n';

    return 0;
}