/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Ambrosino Airlines - Flight Reservation System
 * 
 * Optimized solution using a hash map for O(1) average lookup.
 * Handles 37 fixed flights and processes reservation requests until sentinel 9999.
 */

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Initial flights configuration
    // Using unordered_map for O(1) average time complexity for lookups and updates
    unordered_map<int, int> flight_inventory;

    cout << "Digite o numero do voo e a quantidade de lugares disponiveis:\n";

    // Read exactly 37 flights as specified
    for (int i = 0; i < 37; ++i) {
        int flight_id, seats;
        if (!(cin >> flight_id >> seats)) break;
        flight_inventory[flight_id] = seats;
    }

    // Process reservation requests
    int request_id;
    while (true) {
        cout << "Digite o pedido de reserva:\n";
        
        // Break if reading fails or sentinel value 9999 is encountered
        if (!(cin >> request_id) || request_id == 9999) {
            break;
        }

        // Check flight existence and seat availability
        auto it = flight_inventory.find(request_id);
        if (it != flight_inventory.end() && it->second > 0) {
            // Flight found and has seats
            cout << "Voo " << request_id << " DISPONIVEL\n";
            // Reduce availability upon successful reservation
            it->second--;
        } else {
            // Flight either does not exist or is full
            cout << "Voo " << request_id << " INDISPONIVEL\n";
        }
    }

    return 0;
}