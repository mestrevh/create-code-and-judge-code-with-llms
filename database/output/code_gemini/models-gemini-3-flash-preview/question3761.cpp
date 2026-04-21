/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Problem: The Elevator (O Prédio)
 * Persona: Grandmaster in Competitive Programming
 * Logic:
 * The elevator starts at the ground floor (floor 0) and moves to collect people 
 * from various floors as requested in the input. The elevator has a capacity of N.
 * It follows the requests in the order they are given. For each trip, it picks up 
 * as many people as it can until it reaches capacity or exhausts the current requests.
 * Each trip consists of moving up from floor 0 to all floors visited in that trip 
 * and then returning to floor 0. The total distance is the sum of all floors traveled.
 */

struct Request {
    int floor;
    int people;
};

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Z, N, X;
    // Reading floor count Z, elevator capacity N, and solicitation count X
    if (!(cin >> Z >> N >> X)) return 0;

    // Reading all solicitations in the order they were provided
    vector<Request> requests(X);
    for (int i = 0; i < X; ++i) {
        cin >> requests[i].floor >> requests[i].people;
    }

    long long total_dist = 0;

    // Simulation loop: continue while there are people left on any floor
    while (true) {
        bool anyone_left = false;
        for (int i = 0; i < X; ++i) {
            if (requests[i].people > 0) {
                anyone_left = true;
                break;
            }
        }

        // If no one is waiting, the job is done
        if (!anyone_left) break;

        int current_capacity = 0;
        int current_floor = 0;

        // One trip logic
        for (int i = 0; i < X; ++i) {
            if (requests[i].people > 0) {
                // Determine how many people can be picked from this floor in this trip
                int can_take = min(requests[i].people, N - current_capacity);
                
                if (can_take > 0) {
                    // Update the distance traveled to reach this floor from the previous stop
                    total_dist += abs(requests[i].floor - current_floor);
                    current_floor = requests[i].floor;
                    
                    // Update state
                    requests[i].people -= can_take;
                    current_capacity += can_take;
                }
                
                // If capacity is hit, the elevator must return to the ground
                if (current_capacity == N) break;
            }
        }
        
        // After picking up as many as possible (or finishing requests), return to floor 0
        total_dist += current_floor;
    }

    // Output the final accumulated distance
    cout << total_dist << endl;

    return 0;
}