#include <bits/stdc++.h>
using namespace std;

int BruteforceSolution(vector<int> &a, int f)
{
    // TC = O(N) SC = O(1)
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == f)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int f = 8;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int val = BruteforceSolution(a, f);
    cout << "The number " << f << " exist in " << val << " index.";
    return 0;
}