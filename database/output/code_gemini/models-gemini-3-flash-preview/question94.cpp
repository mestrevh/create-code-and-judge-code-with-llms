/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Entry {
    char letter;
    int count;
};

bool compareEntries(const Entry& a, const Entry& b) {
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.letter < b.letter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int testCaseCount = 1;

    while (cin >> n && n != 0) {
        string dummy;
        getline(cin, dummy); // Consume the newline after n

        int frequency[26] = {0};

        for (int i = 0; i < n; ++i) {
            string line;
            if (!getline(cin, line)) break;
            for (char c : line) {
                if (c >= 'a' && c <= 'z') {
                    frequency[c - 'a']++;
                } else if (c >= 'A' && c <= 'Z') {
                    frequency[c - 'A']++;
                }
            }
        }

        vector<Entry> results;
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] > 0) {
                results.push_back({(char)('A' + i), frequency[i]});
            }
        }

        sort(results.begin(), results.end(), compareEntries);

        cout << "TESTE " << testCaseCount++ << "\n";
        for (const auto& entry : results) {
            cout << entry.letter << " " << entry.count << "\n";
        }
    }

    return 0;
}