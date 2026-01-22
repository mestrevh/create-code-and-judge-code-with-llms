/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int B, E, K, C, F;
    cin >> B >> E >> K >> C >> F;
    
    int total = 0;
    for (int round = 1; B <= E; round++) {
        for (int worker = 0; worker < F; worker++) {
            if (total >= C) {
                continue;
            }
            int start = B + worker * (C + K);
            int end = start + C - 1;
            if (end <= E) {
                cout << "distribution " << round << " to worker " << worker << ": " << start << "-" << end << ": ";
                for (int i = 0; i < C; i++) {
                    cout << start + i * (K + 1);
                    if (i < C - 1) cout << ", ";
                }
                cout << ", \n";
                total++;
            }
        }
        B += C * (F + K);
    }
    return 0;
}
