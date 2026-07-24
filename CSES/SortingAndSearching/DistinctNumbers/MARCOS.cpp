#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int ans = 0;
    map<int, int> nums;
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        if(nums[aux] == 0) ans++;
        
        nums[aux]++;
    }

    cout << ans << '\n';

    return 0;
}