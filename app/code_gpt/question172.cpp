/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void invert(vector<int>& memory, int x, int y) {
    while (x < y) {
        swap(memory[x - 1], memory[y - 1]);
        x++;
        y--;
    }
}

long long sum(const vector<int>& memory, int x, int y) {
    long long total = 0;
    for (int i = x - 1; i < y; ++i) {
        total += memory[i];
    }
    return total;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> memory(N);
    for (int i = 0; i < N; i++) memory[i] = i + 1;

    cin.ignore();
    string command;
    while (M--) {
        getline(cin, command);
        stringstream ss(command);
        char op;
        int x, y;
        ss >> op >> x >> y;
        if (op == 'I') {
            invert(memory, x, y);
        } else if (op == 'S') {
            cout << sum(memory, x, y) << endl;
        }
    }
    return 0;
}
