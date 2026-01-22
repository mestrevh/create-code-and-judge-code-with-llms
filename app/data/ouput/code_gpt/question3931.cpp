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
    vector<int> A(N), C(101, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    
    for (int i = 0; i <= 100; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    
    vector<int> output;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < C[i]; j++) {
            output.push_back(i);
        }
    }
    
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    
    return 0;
}
