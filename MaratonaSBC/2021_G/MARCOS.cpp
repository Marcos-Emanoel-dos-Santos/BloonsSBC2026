#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<long long> fibo(92, -1);
vector<string> possibilidades;

string geraResp(int idx){
    string resp = "";
    for(int i = 0; i < idx - 1; i++){
        resp.push_back('A');
    }
    resp.push_back('B');

    return resp;
}


void encontraFatorFibo(long long n, string parcial){
    if(n == 1){
        possibilidades.push_back(parcial);
        return;
    }

    for(int i = 2; i < 92; i++){
        if(n % fibo[i] == 0){
            string bloco = geraResp(i);

            encontraFatorFibo(n / fibo[i], parcial + bloco);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fibo[0] = 1; fibo[1] = 1;
    for(int i = 2; i < 92; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }


    long long n; cin >> n;
    encontraFatorFibo(n, "");

    if(possibilidades.empty()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    else {
        sort(possibilidades.begin(), possibilidades.end());
    }


    cout << possibilidades[0] << '\n';

    return 0;
}