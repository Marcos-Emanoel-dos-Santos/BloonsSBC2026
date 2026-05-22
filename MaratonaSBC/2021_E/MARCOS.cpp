#include <iostream>
#include <queue>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    queue<int> dir0;
    queue<int> dir1;

    int d; int t;

    for(int i = 0; i < N; i++){
        cin >> t >> d;

        if(d == 0) dir0.push(t);
        else dir1.push(t);
    }

    int tF = 0;
    while(dir0.size() > 0 || dir1.size() > 0){
        bool escolha0 = false;
        if(dir1.size() == 0){
            escolha0 = true;
        } else if(dir0.size() > 0 && dir0.front() < dir1.front()){
            escolha0 = true;
        }

        if(escolha0){
            tF = max(tF, dir0.front()) + 10;
            dir0.pop();
            while(dir0.size() > 0 && dir0.front() < tF){
                tF = dir0.front() + 10;
                dir0.pop();
            }
        }
        else {
            tF = max(tF, dir1.front()) + 10;
            dir1.pop();
            while(dir1.size() > 0 && dir1.front() <= tF){
                tF = dir0.front() + 10;
                dir1.pop();
            }
        }
    }

    cout << tF << '\n';

    return 0;
}