#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2001;
vector<int> graph[MAXN];
bool visited[MAXN];
int max_depth = -1;

void DFS(int vertex, int curr_depth){
    if(visited[vertex] || vertex == 0) return;
    visited[vertex] = true;
    curr_depth++;

    for(int neighbor : graph[vertex]){
        DFS(neighbor, curr_depth);
    }
    if(curr_depth > max_depth) max_depth = curr_depth;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        if(u == -1)u = 0;
        graph[u].push_back(i);
    }

    int depth = 0;
    for(int root : graph[0]){
        DFS(root, depth);
    }

    cout << max_depth << '\n';

    return 0;
}