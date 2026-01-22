/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> sections(N);
    int totalSum = 0;

    for (int i = 0; i < N; ++i) {
        cin >> sections[i];
        totalSum += sections[i];
    }

    int leftSum = 0;
    for (int k = 0; k < N; ++k) {
        leftSum += sections[k];
        if (leftSum == totalSum - leftSum) {
            cout << k + 1 << endl;
            break;
        }
    }
    
    return 0;
}
