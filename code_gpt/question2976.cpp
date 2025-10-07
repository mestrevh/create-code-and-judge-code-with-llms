/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int hailstone(int n) {
    int sum = 0;
    while (n != 1) {
        sum += n;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    sum += 1; // add the last number 1
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << hailstone(n) << endl;
    return 0;
}
