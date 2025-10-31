/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool isFibonacci(int number) {
    int a = 0, b = 1, next = 0;
    while (next < number) {
        next = a + b;
        a = b;
        b = next;
    }
    return next == number;
}

int sumOfDigits(int N) {
    int sum = 0;
    while (N > 0) {
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    int sum = sumOfDigits(N);
    if (isFibonacci(sum)) {
        cout << "Sim" << endl;
    } else {
        cout << "Nao" << endl;
    }
    return 0;
}
