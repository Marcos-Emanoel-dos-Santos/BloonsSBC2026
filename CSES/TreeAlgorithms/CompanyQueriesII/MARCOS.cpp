#include <iostream>
#include <vector>
using namespace std;

const int LOG = 20;
const int MAXN = 200005;
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
}

int find_k_ancestor(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)) node = up[node][i];
    }

    return node;
}

int find_lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int k = depth[u] - depth[v];

    // subir na árvore
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)) u = up[u][i];
    }

    if(u == v) return u;

    for(int i = LOG - 1; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int e; cin >> e;

        tree[i].push_back(e);
        tree[e].push_back(i);
    }

    preprocess(1, 0);

    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;

        cout << find_lca(a, b) << '\n';
    }


    return 0;
}