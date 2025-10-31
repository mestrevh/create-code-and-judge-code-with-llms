/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int total = 0, div;
    
    for (int i = 0; i < N; i++) {
        cin >> div;
        total += (div - 1);
    }
    
    cout << total << endl;
    return 0;
}
