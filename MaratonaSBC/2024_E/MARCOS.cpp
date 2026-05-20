#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int idx0, idx1, idx2;

    cin >> idx0 >> idx1;
    
    int trs;
    for(int i = 0; i < N-2; i++){
        cin >> trs;
    }

    cin >> idx2;

    bool xAlign = false;
    bool yAlign = false;
    if(idx0 < idx1){ xAlign = true; }
    if(idx0 < idx2){ yAlign = true; }

    if(xAlign && yAlign) {cout << 0;}
    else if(xAlign && !yAlign) {cout << 3;}
    else if(!xAlign && !yAlign) {cout << 2;}
    else {cout << 1;}

    return 0;
}