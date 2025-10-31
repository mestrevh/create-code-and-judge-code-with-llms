/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int n, test_case = 1;
    while (cin >> n, n) {
        cin.ignore();
        map<char, int> frequency;
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            for (char ch : line) {
                if (isalpha(ch)) {
                    frequency[toupper(ch)]++;
                }
            }
        }
        
        vector<pair<char, int>> freq_vec(frequency.begin(), frequency.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        cout << "TESTE " << test_case++ << endl;
        for (const auto& p : freq_vec) {
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}
