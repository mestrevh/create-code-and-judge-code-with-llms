/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string date;
    getline(cin, date);
    int n;
    cin >> n;
    vector<int> qs(n);
    for (int i = 0; i < n; i++) {
        cin >> qs[i];
    }
    
    int totalDays = 0;
    for (int q : qs) {
        if (q % 2 == 1 && isPrime(q)) {
            totalDays -= q;
        } else {
            totalDays += q;
        }
    }

    if (totalDays < 0) {
        cout << "Matheusinho precisa parar AGORA ou vai de F" << endl;
    } else {
        cout << "Matheusinho ainda tem " << totalDays << " dias para se recuperar" << endl;
        
        stringstream ss(date);
        int day, month, year;
        char sep;
        ss >> day >> sep >> month >> sep >> year;
        
        day += totalDays;
        while (day > 30) {
            day -= 30;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        
        cout << "Se não vai de F em " << setfill('0') << setw(2) << day << "/" 
             << setfill('0') << setw(2) << month << "/" << year << endl;
    }

    return 0;
}
