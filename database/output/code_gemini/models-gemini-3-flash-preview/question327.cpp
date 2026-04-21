/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; ++i) {
        long long sq = (long long)i * i;
        long long cb = (long long)i * i * i;
        
        cout << i << " " << sq << " " << cb << "\n";
        cout << i << " " << sq + 1 << " " << cb + 1 << "\n";
    }

    return 0;
}