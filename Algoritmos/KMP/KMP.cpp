#include <iostream>
#include <vector>
#include <string>

using namespace std;

// BUSCA KMP --------------------------------------
vector<size_t> KMP_search(string& s, string& p){
    vector<size_t> LPS(p.size(), 0);
    vector<size_t> matches;

    // PREPARANDO O LPS
    size_t i = 1;
    size_t len = 0;
    while(i < p.size()){
        if(p[i] == p[len]){
            len++;
            LPS[i] = len;
            i++;
        }
        else if(len != 0){
            len = LPS[len-1];
        }
        else {
            i++;
        }
    }

    // ALGORITMO KMP
    i = 0;
    int j = 0;
    while(i < s.size()){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        if(j == p.size()){
            matches.push_back(i - j);
            j = LPS[j-1];
        }
        else if(i < s.size() && s[i] != p[j]){
            if(LPS[j] == 0){
                i++;
            }
            else {
                j = LPS[j] - 1;
            }
        }
    }

    return matches;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    string p; cin >> p;

    vector<size_t> matches = KMP_search(s, p);

    for(size_t i = 0; i < matches.size(); i++){
        cout << matches[i] << ' ';
    }

    return 0;
}