#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    unsigned long long p = 0;

    int coef;
    for(size_t i = 0; i <= N; i++){
        cin >> coef;
        if(coef) p |= 1ULL << (N - i);
    }

    int c = 0;
    while(p != 1){
        if(p % 2 == 0){
            p >>= 1;
        } else {
            p = (p << 1) ^ p;
            p ^= 1ULL;
        }
        c++;
    }
    cout << c;

    return 0;
}