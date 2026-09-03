#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;
vector<int> tree[MAXN];
int sz[MAXN];
int depth[MAXN];
int up[MAXN][LOG];

void preprocess(int node, int parent){
    up[node][0] = parent;
    sz[node] = 1;

    for(int i = 1; i < LOG; i++){
        up[node][i] = up[ up[node][i-1] ][i-1];
    }

    for(int child : tree[node]){
        if(child != parent){
            depth[child] = depth[node] + 1;
            preprocess(child, node);
            sz[node] += sz[child];
        }
    }
}

int find_k_ancestor(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }

    return node;
}

int find_lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    a = find_k_ancestor(a, k);

    if(a == b) return a;

    for(int i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    preprocess(1, 0);

    int m; cin >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;

        if(u == v){
            cout << n << '\n';
            continue;
        }

        int lca = find_lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[lca];

        if(dist & 1){
            cout << 0 << '\n';
            continue;
        }

        if(depth[u] < depth[v]) swap(u, v);

        int mid = find_k_ancestor(u, dist / 2);
        int child_u = find_k_ancestor(u, (dist / 2) - 1);

        if(depth[u] == depth[v]){
            int child_v = find_k_ancestor(v, (dist / 2) - 1);
            cout << n - sz[child_u] - sz[child_v] << '\n';
        }
        else {
            cout << sz[mid] - sz[child_u] << '\n';
        }
    }


    return 0;
}
