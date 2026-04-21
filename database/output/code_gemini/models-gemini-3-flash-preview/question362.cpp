/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<char> teams;
    for (char c = 'A'; c <= 'P'; ++c) {
        teams.push(c);
    }

    int m, n;
    for (int i = 0; i < 15; ++i) {
        if (!(cin >> m >> n)) break;
        char t1 = teams.front();
        teams.pop();
        char t2 = teams.front();
        teams.pop();

        if (m > n) {
            teams.push(t1);
        } else {
            teams.push(t2);
        }
    }

    if (!teams.empty()) {
        cout << teams.front() << endl;
    }

    return 0;
}

