/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        string target = "vírgula";
        string result = "";
        int n = (int)line.length();
        int m = (int)target.length();

        for (int i = 0; i < n; ++i) {
            bool match = false;
            if (i + m <= n) {
                if (line.compare(i, m, target) == 0) {
                    match = true;
                }
            }

            if (match) {
                if (!result.empty() && result.back() == ' ') {
                    result.back() = ',';
                } else {
                    result += ',';
                }
                i += m - 1;
            } else {
                result += line[i];
            }
        }
        cout << result << "\n";
    }

    return 0;
}