#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> children(n);
    for(int i = 0; i < n; i++) cin >> children[i];

    sort(children.begin(), children.end());
    
    int num_gondola = 0;
    int p1 = 0; int p2 = n - 1;
    
    while(p1 <= p2){
        if(children[p1] + children[p2] <= x){
            p1++;
        }
        p2--;
        num_gondola++;
    }
    

    cout << num_gondola << '\n';

    return 0;
}