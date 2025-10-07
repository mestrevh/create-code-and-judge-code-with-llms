/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int numDigits(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int power(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

bool isArmstrong(int n) {
    int num_digits = numDigits(n);
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += power(digit, num_digits);
        temp /= 10;
    }
    return sum == n;
}

int main() {
    int start, end;
    cin >> start >> end;

    vector<int> armstrong_numbers;
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            armstrong_numbers.push_back(i);
        }
    }

    for (int i = 0; i < armstrong_numbers.size(); i++) {
        cout << armstrong_numbers[i] << (i == armstrong_numbers.size() - 1 ? "" : " ");
    }
    cout << endl;
    cout << armstrong_numbers.size() << " numeros de Armstrong" << endl;

    return 0;
}
