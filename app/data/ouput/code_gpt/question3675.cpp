/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void fibonacciRec(int n, vector<int>& fibs) {
    if (n == 0) return;
    if (n == 1) {
        fibs.push_back(1);
        return;
    }
    fibonacciRec(n - 1, fibs);
    fibs.push_back(fibs[n - 2] + fibs[n - 1]);
}

void printInReverse(const vector<int>& fibs, int index) {
    if (index < 0) return;
    cout << fibs[index] << " ";
    printInReverse(fibs, index - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> fibs;
    fibonacciRec(n, fibs);
    printInReverse(fibs, n - 1);
    return 0;
}
