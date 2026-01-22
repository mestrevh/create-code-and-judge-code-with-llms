/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int d1, m1, a1, d2, m2, a2;
    cin >> d1 >> m1 >> a1;
    cin >> d2 >> m2 >> a2;

    struct tm start = {0}, end = {0};
    start.tm_mday = d1; start.tm_mon = m1 - 1; start.tm_year = a1 - 1900;
    end.tm_mday = d2; end.tm_mon = m2 - 1; end.tm_year = a2 - 1900;

    time_t start_time = mktime(&start);
    time_t end_time = mktime(&end);

    double seconds = difftime(end_time, start_time);
    int days = seconds / (60 * 60 * 24);

    cout << days << endl;
    return 0;
}
