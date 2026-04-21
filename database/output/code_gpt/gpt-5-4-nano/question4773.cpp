/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(int x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int i = 3; 1LL * i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

static bool isLeapPrimeOdd(int q) {
    return (q % 2 == 1) && isPrime(q);
}

static int daysInMonths(int months) {
    return months * 30;
}

static string pad2(int v) {
    ostringstream oss;
    oss << setw(2) << setfill('0') << v;
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dateStr;
    if (!getline(cin, dateStr)) return 0;
    dateStr.erase(remove_if(dateStr.begin(), dateStr.end(), ::isspace), dateStr.end());
    int dd = 0, mm = 0, yyyy = 0;
    char c1, c2;
    {
        istringstream iss(dateStr);
        iss >> dd >> c1 >> mm >> c2 >> yyyy;
    }

    int N;
    cin >> N;

    long long Y = 0;
    for (int i = 0; i < N; i++) {
        int q;
        cin >> q;
        if (isLeapPrimeOdd(q)) Y -= q;
        else Y += q;
    }

    if (Y < 0) {
        cout << "Matheusinho precisa parar AGORA ou vai de F";
        return 0;
    }

    long long totalDaysFromZero = 0;
    totalDaysFromZero += 1LL * (yyyy) * 360;
    totalDaysFromZero += 1LL * (mm - 1) * 30;
    totalDaysFromZero += (dd - 1);
    totalDaysFromZero += Y;

    long long newY = totalDaysFromZero;

    int newYYYY = (int)(newY / 360);
    newY %= 360;
    int newMM = (int)(newY / 30) + 1;
    int newDD = (int)(newY % 30) + 1;

    cout << "Matheusinho ainda tem " << Y << " dias pra se recuperar\n";
    cout << "Se não vai de F em " << pad2(newDD) << "/" << newMM << "/" << newYYYY;
    return 0;
}