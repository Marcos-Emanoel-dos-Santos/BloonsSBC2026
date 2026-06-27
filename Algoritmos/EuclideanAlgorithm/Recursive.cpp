#include <iostream>

using namespace std;
int recursive(int a, int b){
    if(b == 0) return a;

    return recursive(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b; cin >> a >> b;
    int res = recursive(a, b);

    cout << res << '\n';

    return 0;
}