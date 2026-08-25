#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;
vector<int> tree[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void preprocess(int node, int parent){
    up[node][0] = parent;

    for(int i = 1; i < LOG; i++){
        up[node][i] = up[ up[node][i-1] ][i-1];
    }

    for(int child : tree[node]){
        if(child != parent){
            depth[child] = depth[node] + 1;
            preprocess(child, node);
        }
    }

    return;
}

int find_k_ancestor(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }

    return node;
}

int find_distance(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int k = depth[u] - depth[v];
    int new_u = find_k_ancestor(u, k);
    int new_v = v;

    if(new_u == new_v) return k;

    for(int i = LOG - 1; i >= 0; i--){
        if(up[new_u][i] != up[new_v][i]){
            new_u = up[new_u][i];
            new_v = up[new_v][i];
        }
    }

    int LCA = up[new_v][0];

    int dist_u_v = depth[u] + depth[v] - 2 * depth[LCA];

    return dist_u_v;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    preprocess(1, 0);

    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;

        cout << find_distance(u, v) << '\n';
    }

    return 0;
}