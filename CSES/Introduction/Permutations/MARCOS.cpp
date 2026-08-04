#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    if(n <= 3 && n != 1){
        cout <<  "NO SOLUTION\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(!(i & 1)) cout << i << ' ';
    }
    for(int i = 1; i <= n; i++){
        if(i & 1) cout << i << ' ';
    }

    cout << '\n';

    return 0;
}