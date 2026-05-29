#include <iostream>

using namespace std;

int main() {
    int n, count = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        char last_char, last_last_char;
        cin >> c;

        if (last_char == 'a' && c == 'a' && last_last_char != 'a') {
            count += 2;
        } else if (last_char == 'a' && c == 'a') {
            count++;
        }
        last_last_char = last_char;
        last_char = c;
    }
    cout << count;
    return 0;
}