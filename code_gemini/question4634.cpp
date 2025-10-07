/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> alunos;
    int total_alunos = 0;

    for (int i = 0; i < n; ++i) {
        int num_alunos;
        cin >> num_alunos;
        while (num_alunos > 40) {
            cout << "O numero de alunos nao pode ser maior que 40" << endl;
            cin >> num_alunos;
        }
        alunos.push_back(num_alunos);
        total_alunos += num_alunos;
    }

    cout << round((double)total_alunos / n) << endl;

    return 0;
}
