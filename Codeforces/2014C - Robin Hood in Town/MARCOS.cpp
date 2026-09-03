#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;

        if(n < 3){
            for(int i = 0; i < n; i++){
                int trs; cin >> trs;
            }
            cout << -1 << '\n';
        }
        else {
            long long totalWealth = 0;
            
            vector<int> wealth(n, 0);

            for(int j = 0; j < n; j++){
                cin >> wealth[j];
                totalWealth += wealth[j];
            }
            double halfAvg = totalWealth/(n*2);
            sort(wealth.begin(), wealth.end());
            
            long long targetWealth = wealth[n/2];

            long long neededWealth = 2LL * n * targetWealth - totalWealth + 1;

            if(neededWealth < 0) neededWealth = 0;

            cout << neededWealth << '\n';
        }
        
    }

    return 0;
}