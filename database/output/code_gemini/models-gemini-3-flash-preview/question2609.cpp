/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    int pos, val;
    cin >> pos >> val;

    cout << "[ ";
    for (int i = 0; i < N; ++i) {
        cout << vec[i] << " ";
    }
    cout << "]" << endl;

    if (pos < 0 || pos > N) {
        cout << "A posicao " << pos << " estah fora do intervalo" << endl;
    } else {
        cout << "[ ";
        for (int i = 0; i < pos; ++i) {
            cout << vec[i] << " ";
        }
        cout << val << " ";
        for (int i = pos; i < N; ++i) {
            cout << vec[i] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}