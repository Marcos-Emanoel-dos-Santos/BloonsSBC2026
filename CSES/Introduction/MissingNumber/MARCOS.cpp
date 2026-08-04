#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> nums(n+1, -1);
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        nums[aux] = 1;
    }

    bool found = false;
    for(int i = 1; i < n; i++){
        if(nums[i] == -1){
            cout << i << '\n';
            found = true;
            break;
        }
    }

    if(!found) cout << n << '\n';

    return 0;
}