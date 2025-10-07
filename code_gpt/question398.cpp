/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, count = 0;
    cin >> a >> b;
    
    for (int i = 1; i < 50; i++) {
        if (i % a == 0 && i % b == 0) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
