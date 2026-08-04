#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool ehPossivel(vector<long long>& m, long long h, int K){
    int min_P = 0; int max_P = m.size() - 1;


    for(int i = 0; i < m.size(); i++){
        if(m[i] >= h) continue;


        int dist_h = h - m[i];

        min_P = max(min_P, i);
        max_P = min(max_P, i + K - dist_h);
    }

    return min_P <= max_P;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K; cin >> N >> K;
    vector<long long> muralha(N);
    long long min_value = 10000000000LL; long long max_value;
    for(int i = 0; i < N; i++){
        cin >> muralha[i];
        if(muralha[i] < min_value) min_value = muralha[i];
    }


    max_value = min_value + K;
    long long mid_value;
    long long ans;

    while(min_value <= max_value){
        mid_value = (max_value + min_value) / 2;

        if(ehPossivel(muralha, mid_value, K)){
            min_value = mid_value + 1;
            ans = mid_value;
        }
        else max_value = mid_value - 1;
    }

    cout << ans << '\n';

    return 0;
}