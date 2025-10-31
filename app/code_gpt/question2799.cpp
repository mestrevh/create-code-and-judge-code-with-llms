/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        int pontosA = 0, pontosB = 0;
        for (int i = 0; i < N; i++) {
            cin >> A >> B;
            if (A > B) pontosA++;
            else if (B > A) pontosB++;
        }
        cout << pontosA << ' ' << pontosB << endl;
    }
    return 0;
}
