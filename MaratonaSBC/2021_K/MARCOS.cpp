#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, D, M;
    cin >> T >> D >> M;

    char d = 'N';
    int ultimaRef;
    cin >> ultimaRef;
    for(int i = 0; i < M-1; i++){
        int ref;
        cin >> ref;
        if(ref - ultimaRef >= T) d = 'Y';
        ultimaRef = ref;
    }
    if(D - ultimaRef >= T) d = 'Y';

    cout << d << '\n';

    return 0;
}