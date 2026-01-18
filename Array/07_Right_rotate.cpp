#include <bits/stdc++.h>
using namespace std;

// For single element
void OptmialSolution(vector<int> &a)
{
    int temp = a[a.size() - 1];
    for (int i = a.size() - 1; i >= 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0]=temp;
}

// for d elements
void BruteforceSolution(vector<int> &a, int d)
{
    d = d % a.size();
    reverse(a.end() - d, a.end());
    reverse(a.begin(), a.end() - d);
    reverse(a.begin(), a.end());
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 5, 6, 7};
    int d = 3;
    // BruteforceSolution(a, d);
    OptmialSolution(a);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}