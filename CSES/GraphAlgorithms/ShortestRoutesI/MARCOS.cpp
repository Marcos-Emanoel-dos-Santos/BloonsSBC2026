#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> plli;
priority_queue<plli, vector<plli>, greater<plli>> pq;


const int MAXN = 1e5 + 5;
const long long INF = 1e18;
vector<pair<int, int>> graph[MAXN];
long long dist[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, peso; cin >> u >> v >> peso;

        graph[u].push_back({v, peso});
    }
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }


    dist[1] = 0;
    pq.push({0, 1});


    while(!pq.empty()){
        long long dist_atual = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if(dist_atual > dist[current]) continue;

        for(pair<int, int> neighbor_info : graph[current]){
            int neighbor = neighbor_info.first;
            int peso = neighbor_info.second;

            if(dist_atual + peso < dist[neighbor]){
                dist[neighbor] = dist_atual + peso;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << dist[i];
        if(i < n) cout << ' ';
    }
    cout << '\n';
    

    return 0;
}