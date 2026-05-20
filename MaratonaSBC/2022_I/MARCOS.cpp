#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t a;
    for(int i = 0; i < 8; i++){
        cin >> a;
        if(a == 9){
            cout << 'F' << '\n';
            return 0;
        }
    }

    cout << 'S' << '\n';

    return 0;
}