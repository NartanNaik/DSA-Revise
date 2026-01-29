// 2. The Archivist’s Corrupted Ledger

// An archivist stores historical event IDs in an array of size N.
// The ledger is supposed to contain unique positive IDs, but corruption has caused:

// Exactly one ID to appear more than half the time

// Several IDs to appear exactly once

// The array order to be completely arbitrary

// The archivist wants to verify the dominant ID, but only after filtering the ledger so that:

// All duplicate entries except one are logically ignored

// No extra memory proportional to N is used

// After verification, the archivist also wants to know whether removing any single contiguous block of entries could result in the dominant ID losing its dominance.

// Return:

// The dominant ID

// true or false based on whether such a block exists

// This problem is a trap for anyone who only memorized solutions instead of understanding why they work.

#include <bits/stdc++.h>
using namespace std;

bool Solution(vector<int>& a, int dom) {
    int N = a.size();
    int F = 0;
    for (int x : a)
        if (x == dom) F++;

    int threshold = 2 * F - N;

    int curr = 0, best = INT_MIN;
    for (int x : a) {
        int val = (x == dom) ? 1 : -1;
        curr = max(val, curr + val);
        best = max(best, curr);
    }

    return best >= threshold;
}


int main()
{
    vector<int> a = {1, 2, 3, 4, 1, 1, 1};
    return 0;
}