#include <bits/stdc++.h>
using namespace std;

void SortedOrNot(vector<int> &a)
{
    // Takes O(N) TC and O(1) SC
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] >= a[i - 1])
        {
        }
        else
        {
            cout << "Array is not sorted";
            return;
        }
    }
    cout << "Array is sorted";
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    SortedOrNot(a);
    return 0;
}