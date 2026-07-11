#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> path(MAXN);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    vector<int> final_path;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        visited[current] = true;

        if(current == n) break;

        for(int neighbor : graph[current]){
            if(visited[neighbor] == false){
                visited[neighbor] = true;
                path[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int idx = n;
    final_path.push_back(n);
    while(idx != 1){
        final_path.push_back(path[idx]);
        idx = path[idx];
    }

    cout << final_path.size() << '\n';
    for(int i = final_path.size() - 1; i > -1; i--){
        cout << final_path[i];
        if(i != 0) cout << " ";
    }
    cout << '\n';


    return 0;
}