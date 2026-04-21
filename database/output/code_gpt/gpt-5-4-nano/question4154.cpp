/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, C, M;
    if (!(cin >> A >> C >> M)) return 0;

    long long adultSeats = A / M;
    long long adultR = A % M;
    if (adultR == 0) {
        cout << adultSeats << " mesas com adultos: R$" << adultSeats * (3LL * M) << "\n";
    } else {
        cout << adultSeats << " mesas com adultos: R$" << adultSeats * (3LL * M) << "\n";
        long long addAdult = adultSeats + (adultR ? 1 : 0);
        (void)addAdult;
    }

    long long childSeats = C / M;
    long long childR = C % M;
    if (childR == 0) {
        cout << childSeats << " mesas com criancas: R$" << childSeats * (2LL * M) << "\n";
    } else {
        cout << childSeats << " mesas com criancas: R$" << childSeats * (2LL * M) << "\n";
        long long addChild = childSeats + (childR ? 1 : 0);
        (void)addChild;
    }

    long long totalSeatsAdultBase = adultSeats + (adultR > 0 ? 1 : 0);
    long long totalSeatsChildBase = childSeats + (childR > 0 ? 1 : 0);

    long long totalTablesNeeded = max(totalSeatsAdultBase, totalSeatsChildBase);

    long long kA = totalTablesNeeded - totalSeatsAdultBase;
    long long kC = totalTablesNeeded - totalSeatsChildBase;

    long long adultTables = totalTablesNeeded - (adultR > 0 ? 1 : 0);
    long long childTables = totalTablesNeeded - (childR > 0 ? 1 : 0);

    long long adultExtraAdults = adultR;
    long long childExtraKids = childR;

    long long adultTablesOnly = adultTables;
    long long childTablesOnly = childTables;

    long long mixTables = 0;

    long long totalPeopleSobra = adultExtraAdults + childExtraKids;

    if (totalPeopleSobra == M) {
        mixTables = 1;
        adultTablesOnly -= (adultR > 0 ? 1 : 0);
        childTablesOnly -= (childR > 0 ? 1 : 0);
    } else {
        bool canBothEven = (adultExtraAdults % 2 == 0 && childExtraKids % 2 == 0);
        if (canBothEven) {
            long long maxMixByAdults = adultExtraAdults / 2;
            long long maxMixByKids = childExtraKids / 2;
            mixTables = min(maxMixByAdults, maxMixByKids);
            if (mixTables > 2) mixTables = 2;
            if (mixTables > 0) {
                adultTablesOnly -= (adultR > 0 ? 1 : 0);
                childTablesOnly -= (childR > 0 ? 1 : 0);
            }
        }
    }

    long long qtdAdultTables = adultTablesOnly + (adultR > 0 ? 1 : 0) - mixTables;
    long long qtdChildTables = childTablesOnly + (childR > 0 ? 1 : 0) - mixTables;

    long long adultosTablesAdultsM = qtdAdultTables;
    (void)adultosTablesAdultsM;

    long long costAdultsOnly = adultTablesOnly * (3LL * M);
    long long costAdultsPlus1 = (qtdAdultTables - adultTablesOnly) * (4LL * M);
    long long costChildrenOnly = childTablesOnly * (2LL * M);
    long long costChildrenPlus1 = (qtdChildTables - childTablesOnly) * (3LL * M);
    long long costMixed = mixTables * (2LL * M);

    long long costAdultTotal = costAdultsOnly + costAdultsPlus1 + costMixed;
    long long costChildTotal = costChildrenOnly + costChildrenPlus1 + 0;

    long long adultFullTables = 0;
    long long adultPlus1Tables = 0;

    if (adultR == 0) {
        adultFullTables = adultSeats;
        adultPlus1Tables = 0;
    } else {
        adultFullTables = adultSeats;
        adultPlus1Tables = 1;
    }

    long long childFullTables = 0;
    long long childPlus1Tables = 0;
    if (childR == 0) {
        childFullTables = childSeats;
        childPlus1Tables = 0;
    } else {
        childFullTables = childSeats;
        childPlus1Tables = 1;
    }

    if (mixTables == 0) {
        long long finalAdultTables = totalTablesNeeded;
        long long finalChildTables = totalTablesNeeded;

        long long adultOnlyTablesFinal;
        long long adultPlus1Final;
        if (adultR == 0) {
            adultOnlyTablesFinal = finalAdultTables;
            adultPlus1Final = 0;
        } else {
            adultOnlyTablesFinal = finalAdultTables - 1;
            adultPlus1Final = 1;
        }

        long long childOnlyTablesFinal;
        long long childPlus1Final;
        if (childR == 0) {
            childOnlyTablesFinal = finalChildTables;
            childPlus1Final = 0;
        } else {
            childOnlyTablesFinal = finalChildTables - 1;
            childPlus1Final = 1;
        }

        long long costAdult = adultOnlyTablesFinal * (3LL * M) + adultPlus1Final * (4LL * M);
        long long costChild = childOnlyTablesFinal * (2LL * M) + childPlus1Final * (3LL * M);

        if (adultPlus1Final == 0) {
            cout << adultOnlyTablesFinal << " mesas com adultos: R$" << costAdult << "\n";
        } else {
            cout << adultPlus1Final << " mesas com adultos+1: R$" << adultPlus1Final * (4LL * M) << "\n";
        }
        if (childPlus1Final == 0) {
            cout << childOnlyTablesFinal << " mesas com criancas: R$" << costChild << "\n";
        } else {
            cout << childPlus1Final << " mesas com criancas+1: R$" << childPlus1Final * (3LL * M) << "\n";
        }
        return 0;
    }

    if (mixTables > 0) {
        long long adultOnlyTablesFinal;
        long long adultPlus1Final;
        if (adultR == 0) {
            adultOnlyTablesFinal = adultFullTables;
            adultPlus1Final = 0;
        } else {
            adultOnlyTablesFinal = adultFullTables - mixTables;
            adultPlus1Final = mixTables;
        }

        long long childOnlyTablesFinal;
        long long childPlus1Final;
        if (childR == 0) {
            childOnlyTablesFinal = childFullTables;
            childPlus1Final = 0;
        } else {
            childOnlyTablesFinal = childFullTables - mixTables;
            childPlus1Final = mixTables;
        }

        long long costAdult = adultOnlyTablesFinal * (3LL * M) + adultPlus1Final * (4LL * M) + mixTables * (2LL * M);
        long long costChild = childOnlyTablesFinal * (2LL * M) + childPlus1Final * (3LL * M) + 0;

        if (adultPlus1Final == 0) {
            cout << adultOnlyTablesFinal + mixTables << " mesas com adultos: R$" << (adultOnlyTablesFinal * (3LL * M) + mixTables * (2LL * M)) << "\n";
        } else {
            cout << adultOnlyTablesFinal << " mesas com adultos: R$" << adultOnlyTablesFinal * (3LL * M) << "\n";
            cout << adultPlus1Final << " mesas com adultos+1: R$" << adultPlus1Final * (4LL * M) << "\n";
        }

        if (childPlus1Final == 0) {
            cout << childOnlyTablesFinal + mixTables << " mesas com criancas: R$" << (childOnlyTablesFinal * (2LL * M) + mixTables * (2LL * M)) << "\n";
        } else {
            cout << childOnlyTablesFinal << " mesas com criancas: R$" << childOnlyTablesFinal * (2LL * M) << "\n";
            cout << childPlus1Final << " mesas com criancas+1: R$" << childPlus1Final * (3LL * M) << "\n";
        }

        cout << mixTables << " mesas mistas: R$" << mixTables * (2LL * M) << "\n";
        return 0;
    }

    return 0;
}