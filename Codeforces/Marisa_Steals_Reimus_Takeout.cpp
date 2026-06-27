// https://codeforces.com/problemset/problem/2228/A
// SOLUÇÃO DO MARCOS
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n;
        
        int operations = 0;
        int input1 = 0; int input2 = 0;

        for(int j = 0; j < n; j++){
            int w;
            cin >> w;
            if(w == 0) operations++;
            else if(w == 1) input1++;
            else input2++;
        }

        int minOp = min(input1, input2);
        input1 -= minOp;
        input2 -= minOp;
        operations += minOp;

        operations += input1 / 3;
        operations += input2 / 3;

        cout << operations << '\n';
    }

    return 0;
}