/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isArmstrong(int num) {
    int sum = 0, original = num, digits = 0;

    while (original > 0) {
        original /= 10;
        digits++;
    }
    original = num;

    while (original > 0) {
        int digit = original % 10;
        sum += 1;

        for (int i = 1; i < digits; i++) {
            sum *= digit;
        }
        
        original /= 10;
    }

    return sum == num;
}

int main() {
    int start, end;
    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    
    cout << endl;

    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) count++;
    }
    cout << count << " numeros de Armstrong" << endl;

    return 0;
}
