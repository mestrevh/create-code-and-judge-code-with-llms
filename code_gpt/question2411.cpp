/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int digitalRoot(int n) {
    return n < 10 ? n : digitalRoot(n / 10 + n % 10);
}

int findKthNumber(int k, int x) {
    int count = 0;
    for (int i = 1; ; ++i) {
        if (digitalRoot(i) == x) {
            count++;
            if (count == k) return i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, x;
        cin >> k >> x;
        cout << findKthNumber(k, x) << endl;
    }
    return 0;
}
