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
    bool opening = true;
    while (getline(cin, line)) {
        if (line == "_") {
            break;
        }
        
        string result = "";
        for (char c : line) {
            if (c == '+') {
                if (opening) {
                    result += '*';
                } else {
                    result += '#';
                }
                opening = !opening;
            } else {
                result += c;
            }
        }
        cout << result << "\n";
    }

    return 0;
}