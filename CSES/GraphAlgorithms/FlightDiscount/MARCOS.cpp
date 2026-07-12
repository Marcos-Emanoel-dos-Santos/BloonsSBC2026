#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, pair<int, int>> pllpii;
// primeiro valor: preço
//  segundo valor: vértice
// terceiro valor: estado
priority_queue<pllpii, vector<pllpii>, greater<pllpii>> pq;

const int MAXN = 1e5 + 5;
const long long INF = 1e18;

// primeiro valor: vértice
//  segundo valor: peso
vector<pair<int, int>> graph[MAXN];

// primeiro valor: preço
//  segundo valor: estado atual
long long prices[MAXN][2]; // ou usei ou não usei o cupom

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, p; cin >> u >> v >> p;

        graph[u].push_back({v, p});
    }
    for(int i = 1; i <= n; i++){
        prices[i][0] = INF;
        prices[i][1] = INF;
    }


    prices[1][0] = 0;
    prices[1][1] = 0;
    pq.push({0, {1, 0}});

    while(!pq.empty()){
        long long current_price = pq.top().first;
        int current = pq.top().second.first;
        int current_state = pq.top().second.second;
        pq.pop();

        if(current_price > prices[current][current_state]) continue;

        for(pair<int, int> neighbor_info : graph[current]){
            int neighbor = neighbor_info.first;
            int weight = neighbor_info.second;

            if(current_price + weight < prices[neighbor][current_state]){
                prices[neighbor][current_state] = current_price + weight;
                pq.push({prices[neighbor][current_state], {neighbor, current_state}});
            }

            if(current_state == 0){
                long long discount_price = weight / 2;

                if(current_price + discount_price < prices[neighbor][1]){
                    prices[neighbor][1] = current_price + discount_price;
                    pq.push({prices[neighbor][1], {neighbor, 1}});
                }
            }
        }
    }

    cout << prices[n][1] << '\n';

    return 0;
}