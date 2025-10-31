/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    char C;
    getline(cin, S);
    cin >> C;
    int pos = S.find(C);
    cout << (pos != string::npos ? pos : -1) << endl;
    return 0;
}
