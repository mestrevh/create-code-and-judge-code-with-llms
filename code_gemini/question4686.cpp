/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    queue<int> q;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "push") {
            int value;
            ss >> value;
            q.push(value);
        } else if (command == "pop") {
            if (!q.empty()) {
                q.pop();
            }
        } else if (command == "sum") {
            long long sum = 0;
            queue<int> temp = q;
            while (!temp.empty()) {
                sum += temp.front();
                temp.pop();
            }
            cout << sum << endl;
        } else if (command == "print") {
            queue<int> temp = q;
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        } else if (command == "exit") {
            break;
        }
    }

    return 0;
}
`