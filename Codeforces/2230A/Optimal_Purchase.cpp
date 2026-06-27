#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, a, b;
    cin >> t;

    for(long long i = 0; i < t; i++){
        cin >> n >> a >> b;
        long long total_cost = 0;
        if(a*3 > b){
            total_cost += (n / 3) * b;
            n %= 3;
        }
        if(a*2 > b){
            total_cost += (n / 2) * b;
            n %= 2;
        }
        if(a > b){
            total_cost += n * b;
            n = 0;
        }
        total_cost += n * a;
        cout << total_cost << '\n';
    }

    return 0;
}