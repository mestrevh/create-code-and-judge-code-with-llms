/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Obj {
    string name;
    int peso;
    double preco;
};

static inline long long floorll(double x) {
    return (long long)floor(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    while ( (cin >> N >> P) ) {
        vector<Obj> objs(N);
        for (int i = 0; i < N; i++) {
            cin >> objs[i].name >> objs[i].peso >> objs[i].preco;
        }

        vector<int> serial_to_idx(N, -1);
        vector<char> used(N, 0);

        int k = 0;
        for (int idx = 0; idx < N; idx++) {
            (void)k;
        }

        vector<int> order(N);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return objs[a].name < objs[b].name;
        });

        for (int pos = 0; pos < N; pos++) {
            int i = order[pos];
            double price = objs[i].preco;
            int peso = objs[i].peso;
            int ceil_price = (int)ceil(price - 1e-12);
            int kk = 0;
            int serial;
            while (true) {
                long long val = (long long)ceil_price + pos + peso + kk;
                serial = (int)( (val % N + N) % N );
                if (!used[serial]) break;
                kk++;
            }
            used[serial] = 1;
            serial_to_idx[serial] = i;
        }

        int cur;
        vector<int> vehicle_pos_type(N, -1);
        for (int s = 0; s < N; s++) {
            if (serial_to_idx[s] == -1) continue;
        }

        vector<pair<double,double>> depot(P);
        vector<pair<double,double>> veh(P);
        vector<double> totalMoney(1,0.0);

        for (int v = 0; v < P; v++) {
            veh[v] = {0.0, 0.0};
        }

        vector<int> center_of_serial(N, -1);
        int per = N / P;
        int rem = N % P;

        for (int serial = 0; serial < N; serial++) {
            int center;
            if (rem == 0) {
                center = serial / per;
            } else {
                int base = N / P;
                int extra = N % P;
                if (serial < (base + 1) * extra) center = serial / (base + 1);
                else center = extra + (serial - (base + 1) * extra) / base;
            }
            if (center >= P) center = P - 1;
            center_of_serial[serial] = center;
        }

        vector<double> x(P), y(P);
        for (int v = 0; v < P; v++) {
            x[v] = 0.0; y[v] = 0.0;
        }

        int serialReq;
        double total = 0.0;
        while (cin >> serialReq) {
            if (serialReq == -1) break;
            double xreq, yreq;
            cin >> xreq >> yreq;

            int center = center_of_serial[serialReq];
            if (center < 0) continue;

            int chosen_vehicle = -1;
            double bestDist = numeric_limits<double>::infinity();

            for (int v = 0; v < P; v++) {
                double vx = veh[v].first;
                double vy = veh[v].second;
                double dx = vx - xreq;
                double dy = vy - yreq;
                double dist2 = dx*dx + dy*dy;
                if (dist2 + 1e-12 < bestDist) {
                    bestDist = dist2;
                    chosen_vehicle = v;
                } else if (fabs(dist2 - bestDist) <= 1e-12) {
                    if (v < chosen_vehicle) chosen_vehicle = v;
                }
            }

            int objIdx = serial_to_idx[serialReq];
            string prodName = objs[objIdx].name;
            double price = objs[objIdx].preco;

            long long ceil_price = (long long)ceil(price - 1e-12);
            total += price;

            cout << "delivered " << prodName << " s. " << serialReq << " by vehicle " << (chosen_vehicle + 1) << "\n";
            veh[chosen_vehicle] = {xreq, yreq};
        }

        cout << "Thank you for using this service. Bye!" << "\n";
    }
    return 0;
}