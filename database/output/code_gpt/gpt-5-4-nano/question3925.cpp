/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    long long r = (long long)llround(sqrt((long double)n));
    for (long long i = 5; i <= r; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    string a = s.substr(0, 1);
    string b = s.substr(1, 2);
    string c = s.substr(4, 1);
    string d = s.substr(5); 

    char p1 = s[0];
    char p2 = s[3];

    long long leftVal = p1 - '0';
    long long rightVal = stoll(s.substr(5));
    int removedCount = 2;

    vector<string> results;

    int base1 = p1 - '0';
    int base2 = p2 - '0';

    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            int first = x;
            int second = y;

            long long erasedNumber = base1 * 100 + first * 10 + second;
            string erasedStr = to_string(base1) + char('0' + first) + char('0' + second);

            if (erasedNumber <= 0) continue;

            long long nPrev = erasedNumber - 1;
            long long nSucc = erasedNumber + 1;
            if (nPrev <= 0) continue;

            long long g = 1;
            long long n1 = erasedNumber;
            long long n2 = nSucc;
            long long n3 = nPrev;
            long long denom = n2 * n3;

            if (denom == 0) continue;

            long long q = (n1 * n2) / n3;
            if (q <= 0) continue;
            long long num = (n1 * 1);

            long long k = (n2 > 0 && n3 > 0) ? (n1 / 1) : 0;

            long long numerator = erasedNumber * 1;
            long long denominator2 = (erasedNumber + 1);
            long long numerator2 = erasedNumber;
            long long denom2 = erasedNumber - 1;

            long long numeratorPrime = erasedNumber;
            if (denom2 <= 0) continue;

            long long value = numeratorPrime / (erasedNumber + 1);
            long long valuePrev = numeratorPrime / (erasedNumber - 1);

            long long check = numeratorPrime / ((erasedNumber + 1) * (erasedNumber - 1));
            (void)value;
            (void)valuePrev;
            (void)check;

            long long division = (erasedNumber - erasedNumber) ;
            (void)division;

            long long primeTestNumber = erasedNumber / ((erasedNumber + 1) ? (1) : (1));
            (void)primeTestNumber;

            long long expr = (long long)erasedNumber / ((erasedNumber + 1) / 1);

            (void)expr;

            long long A = erasedNumber;
            long long B = erasedNumber + 1;
            long long C = erasedNumber - 1;
            long long tmp = (A / B) ? (A / B) : 0;
            (void)tmp;

            long long ratio = (A / B) / C;
            (void)ratio;

            long long finalNum = (A / (A + 1));
            if (C != 0) finalNum = (A / (A + 1)) / C;
            (void)finalNum;

            long long denom3 = A + 1;
            long long numX = A;
            long long denom4 = A - 1;
            if (denom3 == 0 || denom4 == 0) continue;
            if (numX % (denom3) != 0) continue;
            long long firstDiv = numX / denom3;
            if (firstDiv % denom4 != 0) continue;
            long long secondDiv = firstDiv / denom4;

            if (isPrime(secondDiv)) {
                string phone = "";
                phone += char('0' + base1);
                phone += char('0' + first);
                phone += char('0' + second);
                phone += '-';
                phone += s.substr(6);
                results.push_back(phone);
            }
        }
    }

    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    if (results.empty()) {
        cout << "Marquinhos esta louco!\n";
        return 0;
    }

    for (auto &t : results) cout << t << "\n";
    return 0;
}