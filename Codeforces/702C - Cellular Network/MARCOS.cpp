#include <iostream>
#include <vector>

using namespace std;
long long buscaTorreProx(long long cidade, vector<long long>& torres){
    long long left = 0;
    long long right = torres.size() - 1;
    long long mid;
    long long minDist = 1e18;

    while(left <= right){
        mid = (left + right)/2;
        long long distAtual = abs(torres[mid] - cidade);
        if(distAtual < minDist) minDist = distAtual;

        if(torres[mid] < cidade) left = mid + 1;
        else right = mid - 1;
    }

    return minDist;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<long long> cidades(n);
    vector<long long> torres(m);

    for(int i = 0; i < n; i++) cin >> cidades[i];
    for(int i = 0; i < m; i++) cin >> torres[i];

    long long distTorreAnterior = buscaTorreProx(cidades[0], torres);
    for(int i = 1; i < n; i++){
        long long distTorreAtual = buscaTorreProx(cidades[i], torres);
        if(distTorreAnterior < distTorreAtual) distTorreAnterior = distTorreAtual;
    }

    cout << distTorreAnterior << '\n';

    return 0;
}