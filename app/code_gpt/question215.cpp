/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int scores[] = {A, B, C};
    sort(scores, scores + 3);
    cout << scores[1] << endl;
    return 0;
}
