#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree_graph;
long long guild = 0;


int DFS(int node){
    int max1 = -1; int max2 = -1;

    for(int i = 0; i < tree_graph[node].size(); i++){
        int child_h = DFS(tree_graph[node][i]);

        if(child_h > max1){
            max2 = max1;
            max1 = child_h;
        }
        else if(child_h > max2){
            max2 = child_h;
        }
    }

    guild += 1;
    if(max2 != -1) guild += max2 + 1;

    return max1 + 1;
}



void solve(){
    int n; cin >> n;
    tree_graph.assign(n + 1, vector<int>());
    guild = 0;

    for(int i = 2; i <= n; i++){
        int pai; cin >> pai;

        tree_graph[pai].push_back(i);
    }

    DFS(1);

    cout << guild << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++) solve();


    return 0;
}