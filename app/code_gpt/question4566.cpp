/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char decodeChar(char base, int shift) {
    int new_char = base + shift;
    if (new_char > 'z' || new_char < 'a') return '.';
    return new_char;
}

int main() {
    int n, m;
    cin >> n;
    
    vector<char> chars(n);
    for (int i = 0; i < n; ++i) cin >> chars[i];

    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) cin >> nums[i];

    vector<char> result;
    for (int i = 0; i < max(n, m); ++i) {
        if (i < n && i < m) {
            result.push_back(decodeChar(chars[i], nums[i]));
        } else if (i < n) {
            result.push_back(chars[i]);
        } else {
            result.push_back(decodeChar('a', nums[i]));
        }
    }

    for (char c : result) cout << c << ' ';
    cout << endl;

    return 0;
}
