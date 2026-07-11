#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAXN = 1001;

string grid[MAXN];
char path[MAXN][MAXN];
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN));
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};


bool isValid(int r, int c, int n, int m){
    if(r < 0 || c < 0 || r >= n || c >= m) return false;
    if(visited[r][c]) return false;
    if(grid[r][c] == '#') return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    int start_r = -1; int start_c = -1;
    int end_r = -1; int end_c = -1;

    for(int i = 0; i < n; i++){
        cin >> grid[i];

        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                start_r = i; start_c = j;
            }
            else if(grid[i][j] == 'B'){
                end_r = i; end_c = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    vector<char> final_path;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        visited[r][c] = true;
        q.pop();
        if(grid[r][c] == '#') continue;

        if(grid[r][c] == 'B') break;

        for(int i = 0; i < 4; i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if(isValid(new_r, new_c, n, m)){
                visited[new_r][new_c] = true;
                path[new_r][new_c] = dir[i];
                q.push({new_r, new_c});
            }
        }
    }
    if(!visited[end_r][end_c]){
        cout << "NO" << '\n';
        return 0;
    }

    int x = end_r; int y = end_c;
    while(x != start_r || y != start_c){
        final_path.push_back(path[x][y]);

        if(path[x][y] == 'U') x++;
        else if(path[x][y] == 'D') x--;
        else if(path[x][y] == 'L') y++;
        else if(path[x][y] == 'R') y--;
    }

    cout << "YES" << '\n';
    cout << final_path.size() << '\n';
    for(int i = final_path.size()-1; i >= 0; i--){
        cout << final_path[i];
    }
    cout << '\n';


    return 0;
}