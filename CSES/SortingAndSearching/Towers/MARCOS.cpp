#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> piles_top;

    for(int i = 0; i < n; i++){
        long long block; cin >> block;

        auto it = upper_bound(piles_top.begin(), piles_top.end(), block);

        if(it == piles_top.end()){
            piles_top.push_back(block);
        }
        else {
            *it = block;
        }
    }

    cout << piles_top.size() << '\n';


    return 0;
}