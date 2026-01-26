#include <bits/stdc++.h>
using namespace std;

// you have given a matrix with including the zeros... your task is to make the the rows and colums where the the 0s exist have to make 0s.. example for the matrix {1, 2, 0},                      {0, 0, 0},
// {1, 0, 3},               ->     {0, 0, 0},
// {1, 2, 3},               |      {1, 0, 0},
//  the output will be -----

void MarkRow(vector<vector<int>> &m, int row)
{
    int col = m[0].size();
    for (int j = 0; j < col; j++)
    {
        if (m[row][j] != 0)
        {
            m[row][j] = -1;
        }
    }
}

void MarkCol(vector<vector<int>> &m, int col)
{
    int row = m.size();
    for (int i = 0; i < row; i++)
    {
        if (m[i][col] != 0)
        {
            m[i][col] = -1;
        }
    }
}

void BruteforceSolution(vector<vector<int>> &mt)
{
    // TC = O(N^3) => O(N*M) from the step where we are converting it to the -1 O(n+m) from the MarkRow and MarkCol O(N*M) from the step where we are convertig back it to the the 0 so this becomes => O(n*m)*O(n+m)+O(n*m) which gives us O(N^3)
    // SC = O(1)

    // in this solution we get the element 0 and make it's row and col as -1 and in next step make it as 0, because if we make it 0 at the first time only all will be 0s

    int n = mt.size();
    int m = mt[0].size();

    // convert to -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mt[i][j] == 0)
            {
                MarkRow(mt, i);
                MarkCol(mt, j);
            }
        }
    }

    // convert to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mt[i][j] == -1)
            {
                mt[i][j] = 0;
            }
        }
    }
}

void BetterSolution(vector<vector<int>> &mt)
{
    // TC = O(n*m)+O(n*m)
    // SC = O(n+m)

    // here we carry two array arrays in the size of row and col, when if find a element 0 in the matrix we mark that col and row as one and we do it for whole matrix and at last we turn the whole row and column into zero if the row or col anyone is 1... it's like marking the row and col of the 0 element and make the whole row and col as 0s

    int n = mt.size();
    int m = mt[0].size();
    int row[n];
    int col[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mt[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                mt[i][j] = 0;
            }
        }
    }
}

void OptimalSolution(vector<vector<int>> &mt)
{
    // TC = O(n*m)+O(n*m)
    // SC = O(1)

    // here we insteed of keeping a seperate track array for the row and col we do that inside the matrix only

    // we keep this outside the matrix because inside the matrix the corners colides.. so we keep the column's 0th position outside the col
    int col0 = 1;
    int n = mt.size();
    int m = mt[0].size();

    // traverse through the matrix and convert the first row and col as 0 when we get the 0 inside the matrix if that is not a 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mt[i][j] == 0)
            {
                mt[i][0] = 0;
                if (j != 0)
                {
                    mt[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    // we convert the rows and columns as 0s but the only element's which are inside the 1st row and 1st column
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mt[i][j] != 0)
            {
                if (mt[0][j] == 0 || mt[i][0] == 0)
                {
                    mt[i][j] = 0;
                }
            }
        }
    }

    // after that we do it for first row
    if (mt[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            mt[0][j] = 0;
        }
    }

    // and first columnf
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            mt[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 0},
        {1, 0, 3},
        {1, 2, 3},
    };
    // BruteforceSolution(m);
    // BetterSolution(m);
    OptimalSolution(m);
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}