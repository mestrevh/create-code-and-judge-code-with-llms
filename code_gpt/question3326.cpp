/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A < 0 || B < 0 || C < 0) {
        cout << "esses dados nao valem" << endl;
        return 0;
    }

    if (A == B && B == C) {
        cout << ":)" << endl;
    } else if (A < B && (B > C || B - C < B - A)) {
        cout << ":(" << endl;
    } else if (A > B && (B < C && B - C <= A - B)) {
        cout << ":(" << endl;
    } else if (A == B && B > C) {
        cout << ":(" << endl;
    } else {
        cout << ":)" << endl;
    }

    return 0;
}
