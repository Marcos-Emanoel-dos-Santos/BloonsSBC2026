#include <iostream>
#include <vector>

using namespace std;
int main(){
    size_t N;
    cin >> N;

    vector<int> inp(N);
    vector<int> cBit(30, 0);
    vector<int> resposta(N, 0);

    for(size_t i = 0; i < N; i++){
        cin >> inp[i];

        for(size_t j = 0; j < 30; j++){
            if((inp[i] >> j) & 1) cBit[j]++;
        }
    }

    for(size_t i = 0; i < N; i++){
        for(size_t j = 0; j < 30; j++){
            if(cBit[j] > 0){
                resposta[i] |= (1 << j);
                cBit[j]--;
            }
        }
    }

    for(size_t i = 0; i < N; i++){
        cout << resposta[i] << " ";
    }

    cout << '\n';

    return 0;
}