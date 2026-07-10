#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5001;
vector<int> planes(MAXN);
int visitedState[MAXN];
bool found = false;

void DFS(int vertex){
    if(visitedState[vertex] == 2) return;
    if(visitedState[vertex] == 1){
        int aux = 0;
        int current = planes[vertex];
        while(aux < 2){
            current = planes[current];
            aux++;
        }
        if(current == vertex) found = true;
        return;
    }
    visitedState[vertex] = 1;

    DFS(planes[vertex]);
    visitedState[vertex] = 2;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> planes[i];
    }

    for(int i = 1; i <= n; i++){
        DFS(i);
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}