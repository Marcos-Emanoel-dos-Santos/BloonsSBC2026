#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> tree[MAXN];
bool cats[MAXN];
int restaurants = 0;

void search_restaurants(int vertex, int parent, int curr_cats, int& max_cats){
    if(cats[vertex] == 1) curr_cats--;
    else curr_cats = max_cats;
    if(curr_cats < 0) return;

    if(tree[vertex].size() == 1 && tree[vertex][0] == parent) restaurants++;

    for(int neighbor : tree[vertex]){
        if(neighbor == parent) continue;
        search_restaurants(neighbor, vertex, curr_cats, max_cats);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> cats[i];
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int curr_cats = m;
    search_restaurants(1, 0, curr_cats, m);

    cout << restaurants << '\n';

    return 0;
}