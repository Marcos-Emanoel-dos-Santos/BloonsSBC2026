#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int D, C, R;
    cin >> D; cin >> C; cin >> R;

    vector<int> cansativas(C);

    for(int i = 0; i < C; i++){
        cin >> cansativas[i];
    }

    int r = 0;
    int qtd = 0;
    for(int i = 0; i < R; i++){
        cin >> r;
        D += r;
        qtd++;
    }

    int c = 0;
    while(D > cansativas[c] && c < C){
        D -= cansativas[c];
        c++;
        qtd++;
    }

    cout << qtd << '\n';

    return 0;
}