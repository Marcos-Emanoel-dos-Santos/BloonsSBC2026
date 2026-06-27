#include <iostream>
#include <vector>

using namespace std;
void insertion_sort(vector<vector<int>>& vec){
    int N = vec.size();
    int j;
    vector<int> key;
    for(int i = 1; i < N; i++){
        key = vec[i];
        j = i - 1;

        while(j > -1 && key[1] > vec[j][1]){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

int main(){
    int N; cin >> N;
    int K; cin >> K;

    vector<vector<int>> jobs;
    vector<vector<int>> final_jobs(K, {-1});

    for(int i = 0; i < N; i++){
        int id, p, d;
        cin >> id >> p >> d;
        jobs.push_back({id, p, d});
    }

    insertion_sort(jobs);

    
    for(int i = 0; i < N; i++){
        int j;
        if(jobs[i][2] > K-1) j = K-1;
        else j = jobs[i][2] - 1;
        
        while(j >= 0 && final_jobs[j][0] != -1){
            j--;
        }
        if(j >= 0) final_jobs[j] = jobs[i];
    }

    int max_profit = 0;
    for(int i = 0; i < final_jobs.size(); i++){
        if(final_jobs[i][0] != -1) max_profit += final_jobs[i][1];
    }

    cout << max_profit << '\n';
    return 0;
}