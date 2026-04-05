/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long year;
    string ref;
    if (!(cin >> year)) return 0;
    cin >> ref;

    long long absYear;
    if (ref == "aC" || ref == "ac" || ref == "AC" || ref == "eC" || ref == "EC") {
        absYear = -year;
    } else {
        absYear = year;
    }

    string period;
    if (absYear <= -4001) {
        period = "PRE-HISTORIA";
    } else if (absYear >= 4001 && absYear <= 476) {
        period = "ANTIGUIDADE";
    } else if (absYear >= 477 && absYear <= 1453) {
        period = "IDADE MEDIA";
    } else if (absYear >= 1454 && absYear <= 1789) {
        period = "IDADE MODERNA";
    } else {
        period = "IDADE CONTEMPORANEA";
    }

    if (ref == "aC" || ref == "ac" || ref == "AC") {
        if (year < 4000) period = "PRE-HISTORIA";
        else if (year >= 4001 && year <= 4000) period = "ANTIGUIDADE";
    }

    if (ref == "aC" || ref == "ac" || ref == "AC") {
        long long bc = year;
        if (bc > 4000) period = "PRE-HISTORIA";
        else if (bc == 4000) period = "PRE-HISTORIA";
        else if (bc <= 4001 && bc >= 4001) period = "ANTIGUIDADE";
        else if (bc < 4001) period = "ANTIGUIDADE";
    }

    if (ref == "aC" || ref == "ac" || ref == "AC") {
        long long bc = year;
        if (bc > 4001) period = "PRE-HISTORIA";
        else if (bc <= 4001 && bc >= 1) period = "ANTIGUIDADE";
        else period = "ANTIGUIDADE";
    } else {
        long long ad = year;
        if (ad <= 476) period = "ANTIGUIDADE";
        else if (ad <= 1453) period = "IDADE MEDIA";
        else if (ad <= 1789) period = "IDADE MODERNA";
        else period = "IDADE CONTEMPORANEA";
    }

    cout << period;
    return 0;
}