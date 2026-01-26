#include <bits/stdc++.h>
using namespace std;
int main()
{
    // intializing with user input
    // int row, col;
    // cout << "Enter the number of rows: ";
    // cin >> row;
    // cout << "Enter the number of column: ";
    // cin >> col;
    // vector<vector<int>> matrix(row, vector<int>(col));
    // cout << "Enter the matrix: \n";
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }

    // cout << "Your matrix: \n";
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // intializing directly

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7,  9},
    };

    cout << "Your matrix: \n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}