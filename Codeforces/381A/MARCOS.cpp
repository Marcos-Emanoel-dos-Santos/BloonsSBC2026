#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> cartas(n);

    for(int i = 0; i < n; i++){
        cin >> cartas[i];
    }

    int p1 = 0; int p2 = n-1;
    int pontos[] = {0, 0};
    int turn = 0;
    while(p1 <= p2){
        if(cartas[p1] > cartas[p2]){
            pontos[turn] += cartas[p1];
            p1++;
        }
        else {
            pontos[turn] += cartas[p2];
            p2--;
        }
        
        turn = 1 - turn;
    }

    cout << pontos[0] << ' ' << pontos[1] << '\n';

    return 0;
}