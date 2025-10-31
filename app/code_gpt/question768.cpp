/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> num1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> num1[i];
    }
    
    cin >> n2;
    vector<int> num2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> num2[i];
    }
    
    int maxSize = max(n1, n2);
    vector<int> result(maxSize + 1, 0);
    
    int carry = 0;
    for (int i = 0; i < maxSize; ++i) {
        int digit1 = (i < n1) ? num1[n1 - 1 - i] : 0;
        int digit2 = (i < n2) ? num2[n2 - 1 - i] : 0;
        int sum = digit1 + digit2 + carry;
        result[maxSize - i] = sum % 10;
        carry = sum / 10;
    }
    result[0] = carry;

    for (int i = (result[0] ? 0 : 1); i <= maxSize; ++i) {
        cout << result[i];
    }
    return 0;
}
