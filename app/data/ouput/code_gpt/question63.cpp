/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        for (int i = 0; i < N; ++i) {
            vector<int> answers(5);
            for (int j = 0; j < 5; ++j) {
                cin >> answers[j];
            }
            int count = 0, marked = -1;
            for (int j = 0; j < 5; ++j) {
                if (answers[j] <= 127) {
                    count++;
                    marked = j;
                }
            }
            if (count == 1) {
                cout << char('A' + marked) << endl;
            } else {
                cout << '*' << endl;
            }
        }
    }
    return 0;
}
