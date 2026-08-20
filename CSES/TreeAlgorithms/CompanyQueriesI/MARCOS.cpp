#include <iostream>
#include <vector>
using namespace std;

const int LOG = 20;
const int MAXN = 200005;
vector<int> tree[MAXN];
int up[MAXN][LOG];
int depth[MAXN];


void preprocessing(int node, int parent){
    up[node][0] = parent;

    for(int i = 1; i < LOG; i++){
        up[node][i] = up[ up[node][i-1] ][i-1];
    }

    for(int child : tree[node]){
        if(child != parent){
            depth[child] = depth[node] + 1;
            preprocessing(child, node);
        }
    }
}

int find_k_ancestor(int node, int k){
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }

    if(node == 0) return -1;

    return node;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int u; cin >> u;

        tree[i].push_back(u);
        tree[u].push_back(i);
    }


    preprocessing(1, 0);


    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;

        cout << find_k_ancestor(x, k) << '\n';
    }


    return 0;
}