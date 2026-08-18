#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];
vector<int> dist(MAXN, 0);

void DFS(int node, int parent){
    dist[node] = dist[parent] + 1;

    for(int child : tree[node]){
        if(child != parent) DFS(child, node);
    }

    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1, 0);

    int max_dist = 0; int farthest = 1;
    for(int i = 1; i <= n; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            farthest = i;
        }
    }
    dist.assign(n + 1, 0);

    DFS(farthest, 0);

    max_dist = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > max_dist) max_dist = dist[i];
    }

    cout << max_dist - 1 << '\n';


    return 0;
}