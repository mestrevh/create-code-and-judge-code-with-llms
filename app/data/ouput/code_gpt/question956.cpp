/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int num, minNum = INT_MAX, maxNum = INT_MIN;
    
    while (true) {
        cin >> num;
        if (num == 0) break;
        if (num < minNum) minNum = num;
        if (num > maxNum) maxNum = num;
    }
    
    cout << minNum << " " << maxNum << endl;
    return 0;
}
