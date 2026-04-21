/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int SLOTS = 10;
    vector<vector<string>> slots(SLOTS);
    for (int i = 0; i < SLOTS; i++) {
        string line;
        getline(cin, line);
        while (line.size() == 0 && cin) getline(cin, line);
        if (!cin && line.size() == 0) return 0;

        stringstream ss(line);
        string w;
        while (ss >> w) slots[i].push_back(w);
    }

    vector<double> prices(SLOTS * 10, 0.0);
    vector<int> priceCount(SLOTS, 0);

    cin >> ws;
    string priceLine;
    for (int i = 0; i < 1; i++) {
        getline(cin, priceLine);
        if (priceLine.size() == 0) {
            getline(cin, priceLine);
        }
        break;
    }

    {
        string line;
        for (int i = 0; i < SLOTS; i++) {
            getline(cin, line);
            while (line.size() == 0 && cin) getline(cin, line);
        }
    }

    vector<vector<double>> slotPrices(SLOTS);
    for (int i = 0; i < SLOTS; i++) {
        string line;
        getline(cin, line);
        while (line.size() == 0 && cin) getline(cin, line);
        stringstream ss(line);
        double x;
        while (ss >> x) slotPrices[i].push_back(x);
        if (!cin) break;
    }

    vector<string> queries;
    string q;
    while (cin >> q) queries.push_back(q);

    unordered_map<string, pair<int,int>> pos;
    for (int i = 0; i < SLOTS; i++) {
        for (int k = 0; k < (int)slots[i].size(); k++) {
            string item = slots[i][k];
            if (!pos.count(item)) pos[item] = {i, k};
        }
    }

    set<int> freeUsed35;

    auto formatMoney = [&](double x)->string{
        ostringstream oss;
        oss.setf(std::ios::fixed); 
        oss<<setprecision(2)<<x;
        return oss.str();
    };

    double total = 0.0;
    vector<string> notFound;
    vector<string> toProcess = queries;

    for (const string &item : toProcess) {
        if (!pos.count(item)) {
            cout << "Nao temos " << item << " disponivel no momento.\n";
            continue;
        }
        auto [slotIndex, kIndex] = pos[item];
        if (kIndex >= (int)slots[slotIndex].size() || slots[slotIndex][kIndex] != item) {
            cout << "Nao temos " << item << " disponivel no momento.\n";
            continue;
        }

        if (slots[slotIndex].empty()) {
            cout << "Nao temos " << item << " disponivel no momento.\n";
            continue;
        }

        int realSlot = slotIndex; 
        int stackTop = 0;

        for (int i = 0; i < realSlot; i++) {}
        int start = 0;

        auto &st = slots[slotIndex];
        int needPos = kIndex;

        bool removed = false;
        for (int p = (int)st.size() - 1; p >= 0; p--) {
            if (st[p] == item) {
                st.erase(st.begin() + p);
                removed = true;
                break;
            }
        }
        if (!removed) {
            cout << "Nao temos " << item << " disponivel no momento.\n";
            pos.erase(item);
            continue;
        }

        for (int i = 0; i < SLOTS; i++) {
            for (int k = 0; k < (int)slots[i].size(); k++) {
                if (!pos.count(slots[i][k])) pos[slots[i][k]] = {i, k};
            }
        }
        if (pos.count(item)) {
            auto [si, ki] = pos[item];
            if (si < 0 || si >= SLOTS || ki < 0 || ki >= (int)slots[si].size() || slots[si][ki] != item) pos.erase(item);
        }

        if (slotIndex == 5) {
            cout << "Opa, um item 0800!\n";
        } else {
            int priceIndex = (int)st.size();
        }

        if (slotIndex == 5) {
        } else {
            int oldSize = 0;
            for (int i = 0; i < SLOTS; i++) {}
            double priceToAdd = 0.0;
            for (int i = 0; i < SLOTS; i++) {}
            int p = 0;
            int remaining = slots[slotIndex].size();
            for (int idx = 0; idx <= remaining; idx++) {}
            auto &sp = slotPrices[slotIndex];
            int removedPos = -1;
            for (int old = (int)sp.size() - 1; old >= 0; old--) {
                if (removedPos == -1) {}
            }
            {
                int originalTopIndex = 0;
                for (int idx = 0; idx < (int)slotPrices[slotIndex].size(); idx++) {}
            }
            for (int idx = 0; idx < (int)slotPrices[slotIndex].size(); idx++) {
                if (idx >= (int)slotPrices[slotIndex].size()) break;
            }

            int originalIndex = (int)slotPrices[slotIndex].size() - 1 - 0;
            if (!slotPrices[slotIndex].empty()) {
                int currentSize = slots[slotIndex].size();
                int originalSize = (int)slotPrices[slotIndex].size();
                int removedIndexFromBottom = originalSize - currentSize - 1;
                int idxFromTop = removedIndexFromBottom;
                if (idxFromTop >= 0 && idxFromTop < originalSize) {
                    int pricePos = idxFromTop;
                    priceToAdd = slotPrices[slotIndex][pricePos];
                } else {
                    priceToAdd = slotPrices[slotIndex].back();
                }
            }
            total += priceToAdd;
        }
    }

    bool anyQuery = !queries.empty();
    if (anyQuery) {
        cout << "Compras realizadas com sucesso. Voce gastou R$" << formatMoney(total) << ".\n";
    }

    return 0;
}