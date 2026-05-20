#include <iostream>
#include <vector>

using namespace std;
int valorCarta(int c){
    if(c > 10) c = 10;
    return c;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> comuns(N);
    int cartas[14] = {0};

    int joao = 0;
    for(int i = 0; i < 2; i++){
        int aux;
        cin >> aux;
        if(aux > 10) joao += 10; else joao += aux;
        cartas[aux]++;
    }

    int maria = 0;
    for(int i = 0; i < 2; i++){
        int aux;
        cin >> aux;
        if(aux > 10) maria += 10; else maria += aux;
        cartas[aux]++;
    }

    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        if(c > 10){
            joao += 10; maria += 10;
        }
        else {
            joao += c; maria += c;
        }
        cartas[c]++;
    }

    int resp = -1;
    for(int i = 1; i <= 13; i++){
        if(cartas[i] == 4) continue;

        int v = valorCarta(i);

        if((maria + v == 23) || (maria + v < 23 && joao + v > 23)){
            resp = i;
            break;
        }
    }

    cout << resp << '\n';

    return 0;
}