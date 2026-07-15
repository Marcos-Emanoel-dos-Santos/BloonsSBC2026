#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;

    vector<long long> applicants(n);
    for(int i = 0; i < n; i++) cin >> applicants[i];
    sort(applicants.begin(), applicants.end());

    vector<long long> apartments(m);
    for(int i = 0; i < m; i++) cin >> apartments[i];
    sort(apartments.begin(), apartments.end());

    long long num = 0;
    int p1 = 0; int p2 = 0;
    while(p1 < m && p2 < n){
        if(apartments[p1] >= applicants[p2] - k  && apartments[p1] <= applicants[p2] + k){
            num++;
            p1++; p2++;
        }
        else if(apartments[p1] < applicants[p2] - k){
            p1++;
        }
        else {
            p2++;
        }
    }

    cout << num << '\n';


    return 0;
}