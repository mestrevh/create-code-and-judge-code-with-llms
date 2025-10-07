/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    stack<char> s;
    bool balanced = true;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        for (char ch : line) {
            if (ch == '{') {
                s.push(ch);
            } else if (ch == '}') {
                if (s.empty()) {
                    balanced = false;
                    break;
                }
                s.pop();
            }
        }
        if (!balanced) break;
    }

    if (balanced && s.empty()) 
        cout << "S" << endl;
    else 
        cout << "N" << endl;

    return 0;
}
