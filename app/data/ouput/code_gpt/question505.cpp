/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    vector<int> arr(n);
    for (int j = 0; j < n; j++) {
        cin >> arr[j];
    }
    cin >> i;
    i = i % n; 
    for (int j = 0; j < n; j++) {
        cout << arr[(j + i) % n] << endl;
    }
    return 0;
}
