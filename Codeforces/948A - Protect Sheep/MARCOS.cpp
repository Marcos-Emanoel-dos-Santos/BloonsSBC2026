#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int r, c; cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'W'){
                for(int k = 0; k < 4; k++){
                    int new_row = i + dr[k];
                    int new_col = j + dc[k];

                    if(new_row < 0 || new_row > r-1) new_row = i;
                    if(new_col < 0 || new_col > c-1) new_col = j;

                    if(grid[new_row][new_col] != 'S'){
                        if(grid[new_row][new_col] != 'W') grid[new_row][new_col] = 'D';
                    }
                    else{
                        cout << "No\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }


    return 0;
}