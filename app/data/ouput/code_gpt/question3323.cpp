/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int A, B, C;
    char X, Y;
    cin >> A >> X >> B >> Y >> C;
    
    int result = (X == '^') ? (A & B) : (A | B);
    result = (Y == '^') ? (result & C) : (result | C);
    
    cout << result << endl;
    return 0;
}
