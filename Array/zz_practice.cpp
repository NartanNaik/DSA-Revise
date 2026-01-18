#include <bits/stdc++.h>
using namespace std;

vector<int> OptmialSolution(vector<int> &a1, vector<int> &a2)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    int n1 = a1.size();
    int n2 = a2.size();
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            i++;
        }
        else if (a1[i] > a2[j])
        {
            j++;
        }
        else
        {
            if (ans.empty() || ans.back() != a1[i])
            {
                ans.push_back(a1[i]);
            }
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{
    vector<int> a1 = {1, 2, 3, 4, 5, 6};
    vector<int> a2 = {5, 6, 7, 8};
    vector<int> ans = OptmialSolution(a1, a2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}