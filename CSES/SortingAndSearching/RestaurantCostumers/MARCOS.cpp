#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> entradas(n);
    vector<long long> saidas(n);
    for(int i = 0; i < n; i++){
        long long e, s; cin >> e >> s;
        entradas[i] = e;
        saidas[i] = s;
    }

    sort(entradas.begin(), entradas.end());
    sort(saidas.begin(), saidas.end());

    int p1 = 0; int p2 = 0;
    int pessoas = 0;
    int max_pessoas = 0;
    while(p1 < n && p2 < n){
        if(entradas[p1] < saidas[p2]){
            pessoas++;
            p1++;
        }
        else if(entradas[p1] > saidas[p2]) {
            pessoas--;
            p2++;
        }
        else {
            p1++;
            p2++;
        }
        
        if(pessoas > max_pessoas) max_pessoas = pessoas;
    }

    cout << max_pessoas << '\n';

    return 0;
}