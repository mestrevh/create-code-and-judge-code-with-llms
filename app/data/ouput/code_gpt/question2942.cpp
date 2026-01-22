/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void multiplyMatrices(const vector<vector<long long>>& A, const vector<vector<long long>>& B, vector<vector<long long>>& result, int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k)
                result[i][j] += A[i][k] * B[k][j];
        }
}

vector<vector<long long>> matrixPower(const vector<vector<long long>>& A, int K, int N) {
    vector<vector<long long>> result(N, vector<long long>(N, 0));
    vector<vector<long long>> temp = A;

    for (int i = 0; i < N; ++i)
        result[i][i] = 1;

    while (K) {
        if (K % 2) {
            multiplyMatrices(result, temp, result, N);
        }
        multiplyMatrices(temp, temp, temp, N);
        K /= 2;
    }
    return result;
}

int main() {
    int N, K;
    string P;
    cin >> N;
    
    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
    
    cin >> K >> P;
    
    auto result = matrixPower(A, K, N);

    long long S = 0, D = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            S += result[i][j];
            cout << result[i][j] << " ";
            if (i == j) D += result[i][j];
        }
        cout << endl;
    }

    int R = S % 14;
    string time = (D % 2 == 0) ? "Ru" + to_string(R) + "?" : "Ru" + to_string(R) + "e30?";
    
    cout << time << " ";

    if (S >= 12 * 60) cout << "Aff.. Nem vai dar tempo de cochilar antes da aula de " << P << ".";
    else if (S < (10 * 60 + 30)) cout << "Eita, cedo demais..";
    else cout << "Ainda bem, vai dar tempo de cochilar antes da aula de " << P << ".";

    return 0;
}
