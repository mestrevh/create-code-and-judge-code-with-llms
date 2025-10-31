/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int L;
        cin >> L;
        int totalHash = 0;
        for (int i = 0; i < L; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); ++j) {
                int position = s[j] - 'A';
                totalHash += position + i + j;
            }
        }
        cout << totalHash << endl;
    }
    return 0;
}
