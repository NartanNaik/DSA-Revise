#include <bits/stdc++.h>
using namespace std;

void reversed(vector<int> &a, int begin, int end)
{
    int i = begin;
    int j = end;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    reversed(a, 0, a.size() - 1);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}