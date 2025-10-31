/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        map<string, string> substitutes;
        string line;

        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            size_t pos = line.find(" -> ");
            if (pos != string::npos) {
                string key = line.substr(0, pos);
                string value = line.substr(pos + 4);
                substitutes[key] = value;
            }
        }

        vector<string> text(m);
        for (int i = 0; i < m; ++i) {
            getline(cin, text[i]);
            for (auto& pair : substitutes) {
                size_t pos = 0;
                while ((pos = text[i].find(pair.first, pos)) != string::npos) {
                    text[i].replace(pos, pair.first.length(), pair.second);
                    pos += pair.second.length();
                }
            }
        }

        for (const auto& t : text) {
            cout << t << endl;
        }
    }
    return 0;
}
