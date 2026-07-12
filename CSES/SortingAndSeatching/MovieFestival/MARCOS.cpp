#include <iostream>
#include <vector>
#include <algorithms>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> movies;
    for(int i = 0; i < n; i++){
        int s, f; cin >> s >> f;
        movies.push_back({f, s});
    }

    sort(movies.begin(), movies.end());

    int last_movie_finish = 0;
    int num_movies = 0;

    for(int i = 0; i < n; i++){
        int start = movies[i].second;
        int end = movies[i].first;

        if(start >= last_movie_finish){
            num_movies++;
            last_movie_finish = end;
        }
        movies.pop();
    }

    cout << num_movies << '\n';


    return 0;
}