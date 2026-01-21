#include <bits/stdc++.h>
using namespace std;

int OptmialSolution(vector<int> &a)
{
    map<int, int> mpp;
    for (int i = 0; i < a.size(); i++)
    {
        mpp[a[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > a.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 1, 1, 2, 3};
    int maj = OptmialSolution(a);
    cout << "Majority element " << maj;
    return 0;
}