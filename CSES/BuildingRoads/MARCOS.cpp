#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
bool visited[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> components;
    vector<int> tmp_comp;

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            tmp_comp.push_back(i);
            q.push(i);


            while(!q.empty()){
                int current = q.front();
                q.pop();

                for(int neighbor : graph[current]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                        tmp_comp.push_back(neighbor);
                    }
                }
            }
            components.push_back(tmp_comp);
            tmp_comp.clear();
        }
    }


    cout << components.size() - 1 << '\n';
    for(int i = 0; i < components.size() - 1; i++){
        cout << components[i][0] << ' ' << components[i+1][0] << '\n';
    }

    return 0;
}