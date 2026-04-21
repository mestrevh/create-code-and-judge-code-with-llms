/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            int x;
            if (cin >> x) {
                freq[x]++;
            }
        }

        for (auto const& [val, count] : freq) {
            cout << val << " " << count << "\n";
        }
    }

    return 0;
}