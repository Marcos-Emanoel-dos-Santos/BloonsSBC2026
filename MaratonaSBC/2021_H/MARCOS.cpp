#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int K; cin >> K;
    vector<int> cores_init(N);
    vector<int> cores_end(N);

    for(int i = 0; i < N; i++){
        int b;int c;
        cin >> b >> c;
        cores_init[i] = c;
        cores_end[b-1] = c;
    }

    char resp = 'Y';
    for(int i = 0; i < N; i++){
        if(cores_init[i] != cores_end[i]) resp = 'N';
    }

    cout << resp << '\n';

    return 0;
}