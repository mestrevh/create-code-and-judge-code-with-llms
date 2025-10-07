/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    string word;
    string result = "";

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            result += ' ';
        } else {
            stack<char> s;
            while (i < line.length() && line[i] != ' ') {
                s.push(line[i]);
                i++;
            }
            i--;
            while (!s.empty()) {
                result += s.top();
                s.pop();
            }
        }
    }

    cout << result << endl;

    return 0;
}
