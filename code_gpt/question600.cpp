/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int countDifferentBits(int A, int B) {
    int diff = A ^ B;
    int count = 0;
    while (diff) {
        count += diff & 1;
        diff >>= 1;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << countDifferentBits(A, B) << endl;
    }
    return 0;
}
