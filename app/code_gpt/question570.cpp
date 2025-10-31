/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    
    int d1 = num / 100;
    int d2 = (num / 10) % 10;
    int d3 = num % 10;
    
    cout << d1 << " " << d2 << " " << d3 << endl;
    return 0;
}
