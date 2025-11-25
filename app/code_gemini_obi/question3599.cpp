/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n, curr, count = 1, prev = -1;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> curr;
        if(i > 0 && curr != prev) ++count;
        prev = curr;
    }
    cout << count << endl;
    return 0;
}
