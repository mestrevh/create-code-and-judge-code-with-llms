/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long int N;
    cin >> N;

    long long int last_odd_number = 2 * (N * (N + 1)) - 1;
    long long int sum = last_odd_number + (last_odd_number - 2) + (last_odd_number - 4);

    cout << sum << endl;
    return 0;
}
