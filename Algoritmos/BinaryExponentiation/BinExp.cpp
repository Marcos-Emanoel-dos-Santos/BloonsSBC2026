#include <iostream>

using namespace std;
long long binExp(long long a, long long n){
    if(a == 1 || n == 0) return 1;

    long long res = 1;
    while(n > 0){
        if(n & 1){
            res = res * a;
        }
        a *= a;
        n >>= 1;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, n;
    cin >> a >> n;

    cout << binExp(a, n) << '\n';

    return 0;
}