/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double totalExtraCost = 0.0;
    long long totalPeople = 0;

    long long x;
    while (cin >> x) {
        if (x < 0) break;
        long long formingPeople = 1;
        long long allowedGuests = 15;

        long long guests = x;
        if (guests > allowedGuests) guests = allowedGuests;

        totalPeople += formingPeople + guests;

        long long extra = x - allowedGuests;
        if (extra < 0) extra = 0;
        if (extra > 10) extra = 10;

        totalExtraCost += (long double)extra * 42.0;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)totalExtraCost << "\n" << totalPeople << "\n";
    return 0;
}