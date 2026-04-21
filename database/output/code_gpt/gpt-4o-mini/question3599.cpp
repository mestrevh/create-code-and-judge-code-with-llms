/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    
    int count = 0, current = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] == 2) {
            count += current;
        } else {
            current++;
        }
    }
    
    cout << count << endl;
    return 0;
}