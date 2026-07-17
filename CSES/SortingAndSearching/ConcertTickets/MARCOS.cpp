#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    multiset<long long> prices;
    for(int i = 0; i < n; i++){
        long long price; cin >> price;
        prices.insert(price);
    }

    vector<long long> costumers(m);
    for(int i = 0; i < m; i++) cin >> costumers[i];

    for(int i = 0; i < m; i++){
        long long max_price = costumers[i];

        auto it = prices.upper_bound(max_price);
        
        if(it == prices.begin()){
            cout << -1 << '\n';
        }
        else {
            --it;
            cout << *it << '\n';
            prices.erase(it);
        }
    }

    return 0;
}