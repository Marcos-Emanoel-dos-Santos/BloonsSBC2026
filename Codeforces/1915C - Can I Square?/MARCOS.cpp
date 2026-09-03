#include <iostream>
#include <cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;
        
        long long num = 0;
        for(int i = 0; i < n; i++){
            long long aux; cin >> aux;
            num += aux;
        }

        if(sqrt(num) == floor(sqrt(num))) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}