#include <bits/stdc++.h>
using namespace std;

// you have given a matrix you to rotate it by 90 degree

vector<vector<int>> BruteforceSolution(vector<vector<int>> &mt)
{
    // TC = O(N^2)
    // SC = O(N^2)

    // here we are figuring out what should be the correct position of the element in the matrix and keeping that in that position in the answer matrix.

    // this work like [0][0] = [0][n-1] in the same way next will be => [0][1]=[1][n-1], [0][2]=[2][n-1] this is for the first row.. and those numbers are the position of the elements in the array

    int n = mt.size();
    int m = mt[0].size();

    vector<vector<int>> ans(n, vector<int>(m));

    // traverse through the matrix and arrange the elements in the correct order
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // this is the correct order
            ans[j][(n - 1) - i] = mt[i][j];
        }
    }
    return ans;
}

vector<vector<int>> OptimalSolution(vector<vector<int>> &mt)
{
    // TC = O(N/2*N/2)(becuase we traverse the half of the matrix) + O(N*N/2)(because we traverse each row and the reverse function take n/2 tc)
    // SC = O(1)

    // for this solution i solved it in the book where, we just swap the adjecenet elements and reverse the the each row after we get swapped the elements, this gives us the correct matrix

    int n = mt.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mt[i][j], mt[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(mt[i].begin(), mt[i].end());
    }

    return mt;
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    // vector<vector<int>> ans = BruteforceSolution(m);
    vector<vector<int>> ans = OptimalSolution(m);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}