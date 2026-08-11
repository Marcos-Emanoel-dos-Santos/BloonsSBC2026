#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
long long ans[MAXN];


long long DFS(int employee){
    long long ansAux = 0;
    for(int child : graph[employee]) ansAux += DFS(child);
    ans[employee] = ansAux;

    return ansAux + 1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 2; i <= n; i++){
        int aux; cin >> aux;
        graph[aux].push_back(i);
    }

    DFS(1);


    for(int i = 1; i <= n; i++){
        cout << ans[i];
        if(i < n) cout << ' ';
    }
    cout << '\n';

    return 0;
}