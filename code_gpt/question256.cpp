/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array1(n);
    vector<int> array2(n);
    
    for (int i = 0; i < n; ++i) cin >> array1[i];
    for (int i = 0; i < n; ++i) cin >> array2[i];
    
    for (int i = 0; i < n; ++i) {
        cout << array1[i] << endl;
        cout << array2[i] << endl;
    }
    
    return 0;
}
