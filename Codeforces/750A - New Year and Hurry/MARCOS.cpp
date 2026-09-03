// Eu ainda tinha conseguido errar na primeira tentativa. 
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    int numProblems = floor((-5 + sqrt(25 + 40*(240 - k)))/10);

    if(numProblems > n) numProblems = n;

    cout << numProblems << '\n';

    return 0;
}