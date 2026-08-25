#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
long long distA[MAXN];
long long distB[MAXN];


int DFS(int node, int parent, long long curr_dist, long long dist_array[]){
    dist_array[node] = curr_dist;

    int farthest = node;

    for(int child : tree[node]){
        if(child != parent){
            int candidate = DFS(child, node, curr_dist + 1, dist_array);

            if(dist_array[candidate] > dist_array[farthest]){
                farthest = candidate;
            }
        }
    }

    return farthest;
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

    long long root_dst[MAXN];
    int A = DFS(1, 0, 0, root_dst);
    int B = DFS(A, 0, 0, distA);
    DFS(B, 0, 0, distB);


    for(int i = 1; i <= n; i++){
        cout << max(distA[i], distB[i]) << (i == n ? "" : " ");
    }
    cout << '\n';

    return 0;
}