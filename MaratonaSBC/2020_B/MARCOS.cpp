#include <iostream>
#include <unordered_map>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; int D; int L; int R; int C;
    int posHash;
    cin >> N;
    unordered_map<int, int> pos;

    for(int i = 0; i < N; i++){
        cin >> D;
        cin >> L;
        cin >> R;
        cin >> C;

        if(D == 0){
            if(C + L - 1 > 10){
                cout << "N\n";
                return 0;
            }
            for(int j = 0; j < L; j++){
                posHash = 11 * R + C;
                if(pos[posHash] == 0){
                    pos[posHash] = 1;
                    C++;
                } else {
                    cout << "N\n";
                    return 0;
                }
            }
            
        } else {
            if(R + L - 1 > 10){
                cout << "N\n";
                return 0;
            }
            for(int j = 0; j < L; j++){
                posHash = 11 * R + C;
                if(pos[posHash] == 0){
                    pos[posHash] = 1;
                    R++;
                } else {
                    cout << "N\n";
                    return 0;
                }
            }
        }
    }

    cout << "Y\n";

    return 0;
}