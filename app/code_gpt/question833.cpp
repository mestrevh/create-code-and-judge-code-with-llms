/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> count;
    char ch;

    for (int i = 0; i < 5; ++i) {
        cin >> ch;
        count[ch]++;
    }

    int odd_count = 0;
    for (auto& pair : count) {
        if (pair.second % 2 != 0) {
            odd_count++;
        }
    }

    cout << (odd_count <= 1 ? "sim" : "nao") << endl;
    return 0;
}
