/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    long long a, b, s;
    cin >> a >> b >> s;
    
    long long distance = abs(a) + abs(b);
    
    if (s < distance || (s - distance) % 2 != 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    
    return 0;
}
