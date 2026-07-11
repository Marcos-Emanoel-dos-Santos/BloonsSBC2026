#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int MAXN = 1005;
string maze[MAXN];
int dist[MAXN][MAXN];
int p_dist[MAXN][MAXN];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

char path[MAXN][MAXN];
char dir[] = {'U', 'D', 'L', 'R'};


bool isValid(int row, int col, int n, int m){
    if(row < 0 || col < 0 || row >= n || col >= m) return false;
    if(maze[row][col] == '#') return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> monsters;

    int start_r = -1; int start_c = -1;

    for(int i = 0; i < n; i++){
        cin >> maze[i];
        
        for(int j = 0; j < m; j++){
            dist[i][j] = -1;
            p_dist[i][j] = -1;

            if(maze[i][j] == 'A'){
                start_r = i; start_c = j;
            }
            else if(maze[i][j] == 'M') monsters.push_back({i, j});
        }
    }


    queue<pair<int, int>> q;

    for(int i = 0; i < monsters.size(); i++){
        int mRow = monsters[i].first; int mCol = monsters[i].second;
        q.push({mRow, mCol});
        dist[mRow][mCol] = 0;

    }

    while(!q.empty()){
        int row = q.front().first; int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int new_r = row + dr[i];
            int new_c = col + dc[i];
            if(isValid(new_r, new_c, n, m) && dist[new_r][new_c] == -1){
                dist[new_r][new_c] = dist[row][col] + 1;
                q.push({new_r, new_c});
            }
        }
    }


    q.push({start_r, start_c});
    bool leave = false;
    vector<char> final_path;
    int end_r, end_c;
    path[start_r][start_c] = 0;
    p_dist[start_r][start_c] = 0;

    while(!q.empty() && !leave){
        int row = q.front().first; int col = q.front().second;
        q.pop();

        if(row == 0 || col == 0 || row == n - 1 || col == m - 1){
            leave = true;
            end_r = row; end_c = col;
            break;
        }


        for(int i = 0; i < 4; i++){
            int new_r = row + dr[i];
            int new_c = col + dc[i];
            if(isValid(new_r, new_c, n, m) && p_dist[new_r][new_c] == -1 &&
            (p_dist[row][col] + 1 < dist[new_r][new_c] || dist[new_r][new_c] == -1)){
                path[new_r][new_c] = dir[i];
                p_dist[new_r][new_c] = p_dist[row][col] + 1;
                q.push({new_r, new_c});
            }
        }
    }
    if(!leave){
        cout << "NO\n";
        return 0;
    }

    while(end_r != start_r || end_c != start_c){
        final_path.push_back(path[end_r][end_c]);

        if(path[end_r][end_c] == 'U') end_r++;
        else if(path[end_r][end_c] == 'D') end_r--;
        else if(path[end_r][end_c] == 'L') end_c++;
        else if(path[end_r][end_c] == 'R') end_c--;
    }

    cout << "YES\n" << final_path.size() << '\n';
    for(int i = final_path.size() - 1; i > -1 ; i--){
        cout << final_path[i];
    }
    cout << '\n';


    return 0;
}