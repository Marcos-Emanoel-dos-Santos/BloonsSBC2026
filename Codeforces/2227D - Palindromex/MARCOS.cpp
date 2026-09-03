#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;

        vector<int> input(n*2);

        int p1 = -1; int p2 = -1;
        for(int j = 0; j < n*2; j++){
            cin >> input[j];
            if(!input[j] && p1 == -1) p1 = j;
            else if(!input[j]) p2 = j;
        }

        int l, r;
        int mexGlobal = 1;
        if(p1){
            l = p1-1; r = p1+1;
            vector<bool> numVisto(n+1, false);
            int mexLocal = 1;

            while(l > -1 && r < input.size() && input[l] == input[r]){
                numVisto[input[l]] = true;
                l--; r++;
            }
            while(numVisto[mexLocal]){ mexLocal++; }

            if(mexLocal > mexGlobal) mexGlobal = mexLocal;
        }

        if(p2){
            l = p2-1; r = p2+1;
            vector<bool> numVisto(n+1, false);
            int mexLocal = 1;

            while(l > -1 && r < input.size() && input[l] == input[r]){
                numVisto[input[l]] = true;
                l--; r++;
            }
            while(numVisto[mexLocal]){ mexLocal++; }

            if(mexLocal > mexGlobal) mexGlobal = mexLocal;
        }

        l = p1+1; r = p2-1;
        vector<bool> numVisto(n+1, false);
        int mexLocal = 1;

        bool isPalindrome = true;
        while(l <= r && isPalindrome){
            numVisto[input[l]] = true;
            isPalindrome = input[l] == input[r];
            l++; r--;
        }
        if(isPalindrome){
            l = p1-1; r = p2+1;

            while(l > -1 && r < input.size() && input[l] == input[r]){
                numVisto[input[l]] = true;
                l--; r++;
            }
            while(numVisto[mexLocal]){ mexLocal++; }

            if(mexLocal > mexGlobal) mexGlobal = mexLocal;
        }


        cout << mexGlobal << '\n';
    }

    return 0;
}