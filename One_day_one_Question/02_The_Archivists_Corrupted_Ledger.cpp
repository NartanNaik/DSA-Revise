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

// A structure is a user-defined data type that groups variables of different types under a single name
struct Result {
    int dominantID;
    bool canBeBroken;
    int left;   
    int right;
};

Result analyzeLedger(const vector<int>& a)
{
    // here after finding the majority element with moores, we see that after removing the part of array whether the majority elements goes or not by comparing the remaining dominant * 2 with the remainig size if it's smaller or equals to it that means it's possible otherwise it's not possible, if it's not possible we increament the left by one and check again all the condition if the while loop is still the true for the present condition

    // TC => O(N)+O(N*N) (almost, because "needed" never be n)
    int candidate = -1, count = 0;

    // Boyer–Moore
    for (int x : a) {
        if (count == 0) {
            candidate = x;
            count = 1;
        } else if (x == candidate) {
            count++;
        } else {
            count--;
        }
    }

    int total = 0;
    for (int x : a)
        if (x == candidate) total++;

    int n = a.size();

    bool canBeBroken = false;
    int L = -1, R = -1;

    int needed = total - (n / 2);

    int windowCount = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (a[right] == candidate)
            windowCount++;

        while (windowCount >= needed) {
            int removedSize = right - left + 1;
            int remainingSize = n - removedSize;
            int remainingDominant = total - windowCount;

            if (remainingDominant * 2 <= remainingSize) {
                canBeBroken = true;
                L = left;
                R = right;
                break;
            }

            // i am still figuring out that why do we need it
            // if (a[left] == candidate)
            //     windowCount--;
            left++;
        }

        if (canBeBroken) break;
    }

    return {candidate, canBeBroken, L, R};
}

int main()
{
    vector<int> a = {1,2,1,1,3};

    Result res = analyzeLedger(a);

    cout << "Dominant ID: " << res.dominantID << endl;

    if (res.canBeBroken) {
        cout << "Dominance can be broken by removing block ["
             << res.left << ", " << res.right << "]" << endl;
    } else {
        cout << "Dominance cannot be broken" << endl;
    }

    return 0;
}

