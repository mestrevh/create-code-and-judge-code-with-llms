/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the minimum cost to adjust intervals [li, ri] of 2^N teams such that a 
 * tournament can be carried out. A match between two teams (or winners of previous matches) 
 * can occur if their current availability intervals have a non-empty intersection. 
 * "Guaranteeing the functioning" means that at each node of the tournament tree, there 
 * must exist at least one survivor from each branch that can play each other at some day.
 * 
 * For each match node (L, R) in the tournament tree, the set of potential winners from the 
 * left subtree and the right subtree must have at least one pair of teams that can share 
 * a common day. This translates to ensuring that the union of available intervals from 
 * the left branch and the right branch have a non-empty intersection. Since intervals 
 * are adjusted at each level to ensure they intersect, the union of intervals in any 
 * subtree will effectively form a single continuous interval [min_l, max_r].
 * 
 * Complexity: O(2^N) time and space.
 */

struct Interval {
    long long l, r;
};

long long total_cost = 0;

Interval solve(const vector<Interval>& intervals, int l, int r) {
    // Base case: leaf node (single team)
    if (l == r) {
        return intervals[l];
    }

    // Divide and Conquer
    int mid = l + (r - l) / 2;
    Interval left_union = solve(intervals, l, mid);
    Interval right_union = solve(intervals, mid + 1, r);

    // Calculate distance between the two unions.
    // If they don't intersect, the cost to make them intersect is the gap.
    long long dist = 0;
    if (left_union.l > right_union.r) {
        dist = left_union.l - right_union.r;
    } else if (right_union.l > left_union.r) {
        dist = right_union.l - left_union.r;
    }

    // Add the adjustment cost for this match level
    total_cost += dist;

    // The resulting union for this subtree, after adjusting to bridge the gap.
    // Because we ensure the sub-unions intersect, their new union will be [min_l, max_r].
    Interval combined;
    combined.l = min(left_union.l, right_union.l);
    combined.r = max(left_union.r, right_union.r);
    return combined;
}

int main() {
    // Standard CP optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int num_teams = 1 << N;
    vector<Interval> intervals(num_teams);
    for (int i = 0; i < num_teams; ++i) {
        cin >> intervals[i].l >> intervals[i].r;
    }

    // Solve the problem starting from the root of the tournament tree
    solve(intervals, 0, num_teams - 1);

    cout << total_cost << endl;

    return 0;
}