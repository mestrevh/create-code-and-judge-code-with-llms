/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    int current_capacity = 0;
    bool exceeded = false;

    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;

        current_capacity -= S;
        current_capacity += E;

        if (current_capacity > C) {
            exceeded = true;
        }
    }

    cout << (exceeded ? 'S' : 'N') << endl;
    return 0;
}
