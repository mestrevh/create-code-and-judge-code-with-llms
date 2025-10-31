/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N, P, count = 0;
    cin >> N >> P;
    
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        if (X > 0 && Y > 0 && (X + Y) >= P) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
