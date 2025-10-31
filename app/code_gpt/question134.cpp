/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    while (cin >> N, N != -1) {
        unordered_map<int, int> left, right;
        for (int i = 0; i < N; ++i) {
            int M;
            char L;
            cin >> M >> L;
            if (L == 'D') right[M]++;
            else left[M]++;
        }
        
        int pairs = 0;
        for (const auto& [size, count] : left) {
            if (right.count(size)) {
                pairs += min(count, right[size]);
            }
        }
        cout << pairs << endl;
    }
    return 0;
}
