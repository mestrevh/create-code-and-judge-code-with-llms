/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

bool isLuckyTicket(const string& ticket) {
    int n = ticket.length();
    if (n % 2 != 0) return false; // ticket must have an even number of digits

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; ++i) {
        sum1 += ticket[i] - '0';
        sum2 += ticket[n - 1 - i] - '0';
    }
    return sum1 == sum2;
}

int main() {
    string ticket;
    cin >> ticket;
    cout << (isLuckyTicket(ticket) ? "True" : "False") << endl;
    return 0;
}
