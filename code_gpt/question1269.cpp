/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int size = 2 * N - 1;
    for (int i = 0; i < size; ++i) {
        int stars = N - abs(N - 1 - i);
        int dots = size - 2 * stars;
        string line = string(stars, '*') + string(dots, '.') + string(stars, '*');
        cout << line << endl;
    }
    
    return 0;
}
