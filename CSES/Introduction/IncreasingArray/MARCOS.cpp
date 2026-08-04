#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;

    int prev; cin >> prev;
    long long ans = 0;
    for(int i = 1; i < n; i++){
        int aux; cin >> aux;

        if(aux < prev){
            ans += abs(aux - prev);
        }

        prev = max(aux, prev);
    }

    cout << ans << '\n';

    return 0;
}