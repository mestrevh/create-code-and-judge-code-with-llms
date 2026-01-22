/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((A > B && (B <= C)) || (A < B && B < C && C - B >= B - A) || 
        (A > B && B > C && B - C < A - B) || (A == B && B < C)) {
        cout << ":)" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}
