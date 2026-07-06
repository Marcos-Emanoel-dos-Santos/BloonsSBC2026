#include <iostream>
#include <string>

using namespace std;
int d(int y){
    int sum = 0;
    while(y > 0){
        sum += y % 10;
        y /= 10;
    }

    return sum;
}

void solve(){
    int x; cin >> x;

    int contAns = 0;
    for(int i = 0; i < 100; i++){
        if(x+i - d(x+i) == x){
            contAns++;
        }
    }

    cout << contAns << '\n';

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++) solve();

    return 0;
}