#include <bits/stdc++.h>
using namespace std;

// you have given a matrix you have to traverse it in the spiral way

vector<int> OptimalSolution(vector<vector<int>> &mt)
{
    // TC = O(n*m)
    // SC = O(n*m)

    // here we traversing it in the spriral form
    // iterate it in the book for better understanding
    
    vector<int> ans;
    int n = mt.size();
    int m = mt[0].size();
    int top = 0, bottom = n - 1, right = m - 1, left = 0;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mt[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mt[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mt[bottom][i]);
            }
        }
        bottom--;

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mt[i][left]);
            }
        }
        left++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<int> ans = OptimalSolution(m);
    cout<<"Traversing the matrix in spiral";
    for (auto it : ans)
    {
        cout << it << " -> ";
    }
    return 0;
}