/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

using namespace std;

int tree[100005];
int n;

void update(int i, int delta) {
    for (; i <= n; i += i & -i) {
        tree[i] += delta;
    }
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
        sum += tree[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n != 0) {
        memset(tree, 0, (n + 1) * sizeof(int));
        long long inv_count = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            inv_count += (i - 1) - query(x);
            update(x, 1);
        }
        if (inv_count % 2 != 0) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }

    return 0;
}