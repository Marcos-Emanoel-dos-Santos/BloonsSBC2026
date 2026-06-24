#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<long long> dist(N-1);
    long long x1, y1;
    cin >> x1 >> y1;

    long long x2, y2;
    for(int i = 0; i < N-1; i++){
        cin >> x2 >> y2;
        long long distX = abs(x2 - x1);
        long long distY = abs(y2 - y1);
        dist[i] = max(distX, distY);
        x1 = x2; y1 = y2;
    }

    long long min_R1 = 1;
    long long max_R1 = 1e18; // zero necessidade de um número tão grande, mas eu não sabia que número por.

    long long S = 0;
    int sinal = 1;

    for(int i = 0; i < dist.size(); i++){
        S = dist[i] - S;
        sinal = -sinal;

        if(sinal == 1){
            min_R1 = max(min_R1, 1 - S);
        }
        else {
            max_R1 = min(max_R1, S - 1);
        }
    }

    if(min_R1 <= max_R1){
        cout << max_R1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}