#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; cin >> n >> t;
    map<int, int> elements;
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        int comp = t - aux;
        if(elements[comp]){
            cout << elements[comp] << ' ' << i + 1 << '\n';
            return 0;
        }

        elements[aux] = i + 1;
    }


    cout << "IMPOSSIBLE\n";

    return 0;
}