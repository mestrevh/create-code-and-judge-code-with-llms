/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void generateBinary(int k, string current) {
    if (current.size() == k) {
        cout << current << endl;
        return;
    }
    generateBinary(k, current + "0");
    if (current.empty() || current.back() != '1') {
        generateBinary(k, current + "1");
    }
}

int main() {
    int k;
    cin >> k;
    generateBinary(k, "");
    return 0;
}
