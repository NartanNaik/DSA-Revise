#include <bits/stdc++.h>
using namespace std;

struct result
{
    int dominantID;
    int canBeBroken;
    int left;
    int right;
};

result Solution(vector<int> &a)
{
    int canditate = -1;
    int cnt = 0;
    for (int x : a)
    {
        if (cnt == 0)
        {
            canditate = x;
            cnt = 1;
        }
        else if (x == canditate)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    int total = 0;
    for (int x : a)
    {
        if (x == canditate)
            total++;
    }
    int needed = total - (a.size() / 2);
    int left = 0;
    int windowCount = 0;
    bool canBeBroken = false;
    int L = -1;
    int R = -1;
    for (int right = 0; right < a.size(); right++)
    {
        if (a[right] == canditate)
        {
            windowCount++;
        }
        while (windowCount >= needed)
        {
            int removedSize = right - left + 1;
            int remainingSize = a.size() - removedSize;
            int remainingDominant = total - windowCount;

            if (remainingDominant * 2 <= remainingSize)
            {
                canBeBroken = true;
                L = left;
                R = right;
                break;
            }

            left++;
        }
        if (canBeBroken)
            break;
    }

    return {canditate, canBeBroken, L, R};
}

int main()
{
    vector<int> a = {1, 2, 1, 1, 3};

    result res = Solution(a);

    cout << "Dominant ID: " << res.dominantID << endl;

    if (res.canBeBroken)
    {
        cout << "Dominance can be broken by removing block ["
             << res.left << ", " << res.right << "]" << endl;
    }
    else
    {
        cout << "Dominance cannot be broken" << endl;
    }
    return 0;
}