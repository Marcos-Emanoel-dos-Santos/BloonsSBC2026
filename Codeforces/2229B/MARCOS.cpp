#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(){
    int n; cin >> n;

    vector<long long> A(n);
    vector<long long> B(n);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    long long sum = 0;
    long long maxA = 0;
    for(int i = 0; i < n; i++){
        if(A[i] > B[i]){
            long long aux; aux = A[i];
            A[i] = B[i];
            B[i] = aux;
        }
        sum += B[i];
        if(maxA < A[i]) maxA = A[i];
    }

    cout << sum + maxA << '\n';

    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++){
        solve();
    }

    return 0;
}