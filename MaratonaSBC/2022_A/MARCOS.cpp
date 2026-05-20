#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string s; cin >> s;

    int qtd_a = 0; int c = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a') c++;
        else {
            if(c > 1) qtd_a += c;
            c = 0;
        }

        if(i == s.size()-1) qtd_a += c;
    }

    cout << qtd_a << '\n';

    return 0;
}