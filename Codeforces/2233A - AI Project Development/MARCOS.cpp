#include <iostream>
#include <cmath>

using namespace std;
void solve(){
    double n, x, y, z;
    cin >> n >> x >> y >> z;

    double time1 = ceil(n / (x+y));
    double time2 = z + ceil((n - x*z) / (10*y + x));
    
    if(time1 < time2) cout << time1 << '\n';
    else cout << time2 << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}