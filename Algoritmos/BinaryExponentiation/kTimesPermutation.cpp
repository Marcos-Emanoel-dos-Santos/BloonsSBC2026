#include <iostream>
#include <vector>


using namespace std;
vector<int> aplicarPermuta(vector<int>& vNum, vector<int>& vPerm){
    vector<int> newVNum(vNum.size());

    for(int i = 0; i < vNum.size(); i++){
        newVNum[i] = vNum[vPerm[i]];
    }

    return newVNum;
}

void permutar(vector<int>& vNum, vector<int>& vPerm, long long& qtdPerm){
    while(qtdPerm > 0){
        if(qtdPerm & 1){
            vNum = aplicarPermuta(vNum, vPerm);
        }

        vPerm = aplicarPermuta(vPerm, vPerm);
        qtdPerm >>= 1;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> vetorNumeros(N);
    int aux;
    for(int i = 0; i < N; i++){
        cin >> aux;
        vetorNumeros[i] = aux;
    }

    vector<int> vetorPermutacao(N);
    for(int i = 0; i < N; i++){
        cin >> aux;
        vetorPermutacao[i] = aux - 1;
    }

    long long qtdPermutacao; cin >> qtdPermutacao;

    permutar(vetorNumeros, vetorPermutacao, qtdPermutacao);

    for(int i = 0; i < vetorNumeros.size(); i++)
        cout << vetorNumeros[i] << ' ';
    cout << '\n';
    return 0;
}