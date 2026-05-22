#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int d, t;
    cin >> d >> t;
    int tF = t + 10;

    vector<vector<int>> fila;

    for(int i = 0; i < N - 1; i++){
        int nD, nT;
        cin >> nT, nD;
        if(nD == d){
            if(nT < tF) tF += (nT - t);
            t = nT;
        }
        else {
            fila.push_back({t, tF, nD});
        }
    }


    return 0;
}