/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L, C, H, l, c, h;
    cin >> L >> C >> H >> l >> c >> h;

    if ((L >= l && C >= c && H >= h) || (L >= l && C >= h && H >= c) || 
        (L >= c && C >= l && H >= h) || (L >= c && C >= h && H >= l) || 
        (L >= h && C >= l && H >= c) || (L >= h && C >= c && H >= l)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
    
    return 0;
}
