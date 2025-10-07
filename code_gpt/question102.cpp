/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N, pos = 0;
    cin >> N;
    vector<int> roleta(N);
    for (int i = 0; i < N; ++i) {
        cin >> roleta[i];
    }
    string comando;
    while (true) {
        cin >> comando;
        if (comando == "S") break;
        int V;
        cin >> V;
        if (comando == "D") {
            pos = (pos + V) % N;
        } else if (comando == "E") {
            pos = (pos - V + N) % N;
        }
        for (int i = 0; i < N; ++i) {
            cout << roleta[(pos + i) % N] << (i == N - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
