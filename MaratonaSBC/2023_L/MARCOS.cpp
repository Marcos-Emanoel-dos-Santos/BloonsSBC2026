#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S; cin >> S;
    int K; cin >> K;

    
    for(int i = S.length()-1; i > -1 - K; i--){
        bool concluido = false; size_t j = i;
        while(!concluido && j < S.length()){
            if(j+K < S.length() && S[j] > S[j+K]){
                char aux = S[j+K];
                S[j+K] = S[j];
                S[j] = aux;
                j += K;

            } else {
                concluido = true;
            }
        }
    }


    cout << S << '\n';

    return 0;
}