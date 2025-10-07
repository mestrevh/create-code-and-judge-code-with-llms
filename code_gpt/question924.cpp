/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> domino(N);
    vector<int> result(N);
    
    for (int i = 0; i < N; i++) {
        cin >> domino[i];
    }
    
    for (int i = 0; i < N; i++) {
        int current = i + 1;
        int max_domino = current;
        while (domino[current - 1] != current) {
            max_domino = max(max_domino, domino[current - 1]);
            current = domino[current - 1];
        }
        result[i] = max_domino;
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
