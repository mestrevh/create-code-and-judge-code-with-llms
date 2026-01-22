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
    while (N--) {
        int M;
        cin >> M;
        vector<pair<int, int>> alunos(M);
        for (int i = 0; i < M; ++i) {
            cin >> alunos[i].first;
            alunos[i].second = i;
        }
        
        sort(alunos.begin(), alunos.end(), greater<>());

        int count = 0;
        for (int i = 0; i < M; ++i) {
            if (alunos[i].second == i) count++;
        }
        
        cout << count << endl;
    }
    return 0;
}
