/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        vector<string> guests(n);
        string dummy;
        getline(cin, dummy); 
        for (int i = 0; i < n; ++i) {
            getline(cin, guests[i]);
        }
        sort(guests.begin(), guests.end());
        for (int i = 0; i < n; ++i) {
            cout << guests[i] << "\n";
        }
    }
    return 0;
}