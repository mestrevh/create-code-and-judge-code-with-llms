/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> habilidades(N);
    for (int i = 0; i < N; ++i) {
        cin >> habilidades[i];
    }

    set<int> habSet;
    long long result = 0;

    for (int i = 0; i < N; ++i) {
        habSet.insert(habilidades[i]);
        for (int j = i + 1; j < N; ++j) {
            if (habilidades[j] > habilidades[i]) {
                result += habSet.size() - 1; 
            }
        }
    }

    cout << result << endl;
    return 0;
}
