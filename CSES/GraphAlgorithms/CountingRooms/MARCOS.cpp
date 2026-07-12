#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int MAXN = 1001;
vector<string> building(MAXN);
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN));
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int row, int col, int n, int m){
    if(row >= n || row < 0 || col >= m || col < 0) return false;
    if(visited[row][col]) return false;
    if(building[row][col] == '#') return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> building[i];
    }


    int rooms = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                if(building[i][j] == '#') continue;

                rooms++;

                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int new_r = r + dr[k];
                        int new_c = c + dc[k];

                        if(isValid(new_r, new_c, n, m)){
                            visited[new_r][new_c] = true;
                            q.push({new_r, new_c});
                        }
                    }
                }
            }
        }
    }

    
    cout << rooms << '\n';

    return 0;
}