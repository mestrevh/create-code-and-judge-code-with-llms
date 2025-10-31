/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

using namespace std;

set<int> fibSet;

void generateFibonacci(int n) {
    int a = 1, b = 1;
    fibSet.insert(a);
    while (b <= n) {
        fibSet.insert(b);
        int temp = b;
        b = a + b;
        a = temp;
    }
}

int main() {
    int n;
    cin >> n;
    
    generateFibonacci(n);
    
    string name;
    for (int i = 1; i <= n; ++i) {
        if (fibSet.count(i)) {
            name += 'O';
        } else {
            name += 'o';
        }
    }
    
    cout << name << endl;
    return 0;
}
