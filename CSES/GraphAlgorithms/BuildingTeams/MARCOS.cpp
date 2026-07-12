#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
int team[MAXN];

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
    bool possible = true;

    for(int i = 1; i <= n; i++){
        if(team[i] == 0){
            team[i] = 1;
            q.push(i);

            while(!q.empty() && possible){
                int current = q.front();
                q.pop();
                

                for(int neighbor : graph[current]){
                    if(team[neighbor] == 0){
                        q.push(neighbor);
                        if(team[current] == 1) team[neighbor] = 2;
                        else team[neighbor] = 1;
                    }
                    else if(team[neighbor] == team[current]){
                        possible = false;
                    }
                }
            }
        }
    }

    if(!possible) cout << "IMPOSSIBLE\n";
    else {
        for(int i = 1; i <= n; i++){
            cout << team[i];
            if(i < n) cout << " ";
        }
        cout << '\n';
    }


    return 0;
}