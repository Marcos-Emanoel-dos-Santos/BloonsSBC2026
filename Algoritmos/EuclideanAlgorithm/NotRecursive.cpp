#include <iostream>

using namespace std;
int notRecursive(int a, int b){
    while(b){
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b; cin >> a >> b;
    int res = notRecursive(a, b);

    cout << res << '\n';

    return 0;
}