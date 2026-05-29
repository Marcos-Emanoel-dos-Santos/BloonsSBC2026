#include <iostream>
#include <vector>

using namespace std;

// INSERTION SORT ---------------------------------
void InsertionSort(vector<int>& vec){
    int key;
    int j;
    int N = vec.size();
    for(int i = 1; i < N; i++){
        key = vec[i];
        j = i - 1;

        while(j > -1 && vec[j] > key){
            vec[j+1] = vec[j];
            j--;
        }
        
        vec[j+1] = key;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // INPUT DO TAMANHO DA LISTA
    int N;
    cin >> N;
    vector<int> inp(N);
    // INPUT DA LISTA
    for(int i = 0; i < N; i++){
        cin >> inp[i];
    }


    // INSERTION SORT ---------------------------------
    InsertionSort(inp);


    // OUTPUT DO RESULTADO
    for(int i = 0; i < N; i++){
        cout << inp[i] << ' ';
    }
    cout << '\n';

    return 0;
}