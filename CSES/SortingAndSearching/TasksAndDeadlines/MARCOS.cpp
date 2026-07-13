#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> tasks(n);
    for(int i = 0; i < n; i++){
        int duration, deadline; cin >> duration >> deadline;
        tasks[i] = {duration, deadline};
    }
    sort(tasks.begin(), tasks.end());

    long long total_profit = 0;
    long long time = 0;

    for(int i = 0; i < n; i++){
        time += tasks[i].first;
        total_profit += tasks[i].second - time;
    }

    cout << total_profit << '\n';


    return 0;
}