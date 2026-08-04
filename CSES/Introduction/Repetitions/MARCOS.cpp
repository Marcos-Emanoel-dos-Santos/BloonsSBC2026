#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;
    char prev = s[0];
    int max = 1; int curr_max = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == prev) curr_max++;
        else {
            prev = s[i];
            curr_max = 1;
        }

        if(curr_max > max) max = curr_max;
    }
    
    cout << max << '\n';

    return 0;
}