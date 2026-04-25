#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; int K;

    cin >> N;
    cin >> K;

    cout << (K - N + 1)/N << '\n';

    return 0;
}
