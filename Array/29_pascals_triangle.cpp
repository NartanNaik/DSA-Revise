#include <bits/stdc++.h>
using namespace std;

// if N = 5 then this is the pascal triangle

// 1 ---------------
// 1 1 <-----------| two more 1 for previous 1 <- step 1
// 1 2 1 <---------| step 1 + adding the two elements for the middle element ex: step 1's 1 and 1 = 1+1=2 <- step 2
// 1 3 3 1 <-------| step 2 <- step 3
// 1 4 6 4 1 <-----| step 3 <- step 4

// Q1: return the element which is in Rth row and Cth column
// Q2: return the row of Nth
// Q3: design whole pascal triangle with the size of N

int SolutionForQ1(int row, int col)
{
    // TC = O(r)
    // SC = O(1)

    // to get the element we have to use the formula nCr where n = row -1 and r = col -1; now the formula is =>  n!/r!*(n-r)!, we can use this formula but if we use this in a code it will take lot of time complexity so we will minimize this formula
    // let's take an example of n = 4 and r = 2 now the answer becomes => 4*3*2*1/(2*1)*(2*1)
    // if we carefully absorve these elemets could be canceled --------------->|__________|
    // then the answer becomes 4*3/2*1
    // as we can see the result only goes till the length of the "r" now if we do division by reversing the lower elements like this : 4*3/1*2 => (4/1)*(3/2) now we will get the element we wanted

    // take the res to store the result
    int res = 1;

    // convert row to n
    int n = row - 1;

    // convert col to r
    int r = col - 1;

    // run till the size of r
    for (int i = 0; i < r; i++)
    {
        // here we are doing the upper operation which we descussed in the example this will look like this : res(1) = 1*(4-0) => 4...
        res = res * (n - i);
        // this is the next devide operation which looks like: res(4) = 4/(0+1) = 4/1 = 4...
        res = res / (i + 1);
    }

    // returns the result
    return res;
}

void SolutionForQ2WithBrute(int N)
{
    // TC => O(N*r)
    // SC => O(1)

    // here we are finding the each element of the row (with the help of the previos function) and printing it
    cout << "The row of pascal triangle of " << N << "th number:\n";

    // here the c works like a column and the N works like a row
    for (int c = 1; c <= N; c++)
    {
        // calculating the each element in the row N this looks like if N = 6 => SolutionForQ1(6,1)...
        cout << (SolutionForQ1(N, c)) << " ";
    }
}

void SolutionForQ2WithOptimal(int n)
{
    // TC => O(n)
    // SC => O(1)

    // we did this something same like the function "SolutionForQ1" we will easily get this with the dry run

    cout << "The row of pascal triangle of " << n << "th number:\n";
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
}

vector<vector<int>> SolutionForQ3WithBrute(int n)
{
    // TC => O(n^3) => loops of this function (n^2) and loop of function "SolutionForQ1" (n)
    // SC => O(n^2) => space to store the matrix

    // store the elements in the rows (temp)
    // store the rows in the matrix (ans)
    // return the matrix
    vector<vector<int>> ans;
    for (int row = 1; row <= n; row++)
    {
        vector<int> temp;
        for (int col = 1; col <= row; col++)
        {
            temp.push_back(SolutionForQ1(row, col));
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<int> GenerateRow(int n)
{
    // this is same as the function "SolutionForQ2WithOptimal"
    vector<int> ans_row;
    int ans = 1;
    ans_row.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        ans_row.push_back(ans);
    }

    return ans_row;
}

vector<vector<int>> SolutionForQ3WithOptimal(int n)
{
    // TC => O(N*N)
    // SC => O(1)
    
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(GenerateRow(i));
    }
    return ans;
}

int main()
{
    // int row, col;
    // cout << "Enter the row: ";
    // cin >> row;
    // cout << "Enter the column: ";
    // cin >> col;
    // int ans = SolutionForQ1(row, col);
    // cout << "The element in this row and column is: " << ans;

    int n;
    cout << "Enter the N: ";
    cin >> n;
    // SolutionForQ2WithBrute(n);
    // SolutionForQ2WithOptimal(n);
    // vector<vector<int>> ans = SolutionForQ3WithBrute(n);
    vector<vector<int>> ans = SolutionForQ3WithOptimal(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}