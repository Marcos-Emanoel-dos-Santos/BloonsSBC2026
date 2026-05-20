#include <iostream>
#include <set>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<size_t> s;

    for(size_t i = 0; i < 10; i++){
        size_t n;
        cin >> n;
        s.insert(n);
    }

    cout << 4 - s.size() << '\n';

    return 0;
}