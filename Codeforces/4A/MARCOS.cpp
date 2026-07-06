#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w; cin >> w;

    if(w & 1 || w == 2){
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    return 0;
}