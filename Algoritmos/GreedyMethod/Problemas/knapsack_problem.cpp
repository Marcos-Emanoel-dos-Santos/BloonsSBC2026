#include <iostream>
#include <vector>

using namespace std;
void insertion_sort(vector<vector<double>>& vec){
    vector<double> key;
    int j;
    int N = vec.size();
    for(int i = 1; i < N; i++){
        key = vec[i];
        j = i-1;
        
        while(j > -1 && vec[j][3] < key[3]){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int max; cin >> max;
    vector<vector<double>> items;

    for(int i = 0; i < N; i++){
        double id, p, w;
        cin >> id >> p >> w;
        vector<double> aux = {id, p, w, p/w};
        items.push_back(aux);
    }

    insertion_sort(items);

    double qtd = 0; double profit = 0;
    int idx = 0;
    while(qtd < max && idx < items.size()){
        vector<double> item = items[idx];
        if(qtd + item[2] <= max){
            profit += item[1];
            qtd += item[2];
        }
        else {
            profit += item[1] * ((max - qtd) / item[2]);
            qtd += (max - qtd);
        }
        idx++;
    }

    cout << profit << ' ' << qtd << '\n';

    return 0;
}
