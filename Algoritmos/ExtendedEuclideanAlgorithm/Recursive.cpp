#include <iostream>

using namespace std;
long long extendedGCD(long long a, long long b, long long& x, long long& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long  x1, y1;
    long long g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b; cin >> a >> b;
    long long x, y;

    long long gcd = extendedGCD(a, b, x, y);

    cout << gcd << '\n';

    return 0;
}