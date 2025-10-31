/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/de <iostream>
using namespace std;
int main() {
    int n, total = 0;
    cin >> n;
    int curr = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        total += abs(curr - a);
        curr = a;
    }
    total += curr;
    cout << total << endl;
    return 0