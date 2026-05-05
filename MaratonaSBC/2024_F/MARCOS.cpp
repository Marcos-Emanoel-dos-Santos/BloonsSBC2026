#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int l2 = 0; int l1 = 1; int n = 1; int aux = 0;

    if(N < 2){ cout << 1; return 0; }

    for(int i = 0; i < N-1; i++){
        n += l1;
        aux = l1;
        l1 += l2;
        l2 = aux;
    }

    cout << n;

    return 0;
}