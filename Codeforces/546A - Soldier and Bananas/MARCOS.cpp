#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n, w;
    cin >> k >> n >> w;

    int totalPrice = w*(k + k*w)/2;

    if(totalPrice > n){
        cout << totalPrice - n << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}