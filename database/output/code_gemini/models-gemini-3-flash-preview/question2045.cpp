/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
int arr[MAXN];
int aux[MAXN];

ll mergeSort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    ll count = mergeSort(l, mid) + mergeSort(mid + 1, r);
    
    int i = l;
    int j = mid + 1;
    int k = l;
    
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        } else {
            aux[k++] = arr[j++];
            count += (ll)(mid - i + 1);
        }
    }
    
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    while (j <= r) {
        aux[k++] = arr[j++];
    }
    
    for (int x = l; x <= r; x++) {
        arr[x] = aux[x];
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << mergeSort(0, n - 1) << "\n";
    }
    
    return 0;
}