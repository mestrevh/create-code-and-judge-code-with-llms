/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int total_distance = 0;
    for (int i = 0; i < N; ++i) {
        int T, V;
        cin >> T >> V;
        total_distance += T * V;
    }
    cout << total_distance << endl;
    return 0;
}
