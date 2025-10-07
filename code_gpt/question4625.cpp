/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int numbers[10], x, count = 0;
    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }
    cin >> x;
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == x) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
