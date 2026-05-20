#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; int H;
    cin >> N; cin >> H;

    int qtd = 0;
    int n;
    for(int i = 0; i < N; i++){
        cin >> n;
        if(n <= H) qtd++;
    }

    cout << qtd << '\n';

    return 0;
}