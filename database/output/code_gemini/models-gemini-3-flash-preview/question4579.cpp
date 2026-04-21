/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Room {
    int id;
    int approved_count;
    int original_pos;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Room> rooms;
    rooms.reserve(n);

    for (int i = 0; i < n; ++i) {
        int id, q;
        if (!(cin >> id >> q)) break;
        
        int approved_in_room = 0;
        for (int j = 0; j < q; ++j) {
            string name;
            double presence;
            cin >> name >> presence;
            
            int math_sum = 0;
            for (int k = 0; k < 3; ++k) {
                int val;
                cin >> val;
                math_sum += val;
            }
            
            int port_sum = 0;
            for (int k = 0; k < 3; ++k) {
                int val;
                cin >> val;
                port_sum += val;
            }
            
            int hist_sum = 0;
            for (int k = 0; k < 3; ++k) {
                int val;
                cin >> val;
                hist_sum += val;
            }
            
            bool is_approved = true;
            if (presence < 0.75 - 1e-9) is_approved = false;
            if (math_sum < 21) is_approved = false;
            if (port_sum < 21) is_approved = false;
            if (hist_sum < 21) is_approved = false;
            
            if (is_approved) {
                approved_in_room++;
            }
        }
        rooms.push_back({id, approved_in_room, i});
    }

    sort(rooms.begin(), rooms.end(), [](const Room& a, const Room& b) {
        if (a.approved_count != b.approved_count) {
            return a.approved_count > b.approved_count;
        }
        return a.original_pos < b.original_pos;
    });

    for (int i = 0; i < (int)rooms.size(); ++i) {
        cout << i + 1 << ". [SALA #" << rooms[i].id << "] APROVADOS: " << rooms[i].approved_count << "\n";
    }

    return 0;
}