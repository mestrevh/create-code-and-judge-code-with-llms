/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Appointment {
    int start;
    int end;
};

bool compareAppointments(const Appointment& a, const Appointment& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<Appointment> appointments(n);
    for (int i = 0; i < n; ++i) {
        cin >> appointments[i].start >> appointments[i].end;
    }

    sort(appointments.begin(), appointments.end(), compareAppointments);

    int count = 0;
    int current_time = -1;

    for (int i = 0; i < n; ++i) {
        if (appointments[i].start >= current_time) {
            count++;
            current_time = appointments[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
