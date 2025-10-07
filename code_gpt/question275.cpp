/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int totalMinutesStart = (h1 % 12) * 60 + m1;
    int totalMinutesEnd = (h2 % 12) * 60 + m2;
    if (totalMinutesStart > totalMinutesEnd) totalMinutesEnd += 12 * 60;

    int count = 0;
    for (int t = totalMinutesStart; t < totalMinutesEnd; ++t) {
        if ((t % 60) > (t / 60 % 12) * 5) count++;
    }

    cout << count << endl;
    return 0;
}
