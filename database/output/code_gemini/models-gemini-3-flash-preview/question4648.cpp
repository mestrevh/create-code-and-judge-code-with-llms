/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words(10);
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> words[i])) break;
    }

    string target;
    if (!(cin >> target)) return 0;

    vector<string> result;
    for (int i = 0; i < 10; ++i) {
        if (words[i].size() >= target.size()) {
            if (words[i].compare(0, target.size(), target) == 0) {
                result.push_back(words[i]);
            }
        }
    }

    cout << result.size() << "\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}