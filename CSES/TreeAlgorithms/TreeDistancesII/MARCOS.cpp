#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
long long sz[MAXN];
long long sum_in[MAXN];
long long ans[MAXN];

int N;

void DFS_in(int node, int parent){
    sz[node] = 1;
    sum_in[node] = 0;

    for(int child : tree[node]){
        if(child != parent){
            DFS_in(child, node);

            sz[node] += sz[child];
            sum_in[node] += sum_in[child] + sz[child];
        }
    }
}


void DFS_out(int node, int parent){
    for(int child : tree[node]){
        if(child != parent){
            ans[child] = ans[node] - sz[child] + (N - sz[child]);

            DFS_out(child, node);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS_in(1, 0);

    ans[1] = sum_in[1];
    DFS_out(1, 0);


    for(int i = 1; i <= N; i++){
        cout << ans[i] << (i == N ? "" : " ");
    }
    cout << '\n';

    return 0;
}