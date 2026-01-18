#include <bits/stdc++.h>
using namespace std;

// here we have to find the maximum sum of the subarray
// this problem makes sense when there is also negative elements in the array

int BruteforceSolution(vector<int> &a)
{
    // TC =O(N*N*N)
    // SC = O(1)

    int mx = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            mx = max(mx, sum);
        }
    }
    return mx;
}

int BetterSolution(vector<int> &a)
{
    // TC = O(N*N)
    // SC = O(1)

    int mx = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < a.size(); j++)
        {
            sum += a[j];
        }
        mx = max(mx, sum);
    }

    return mx;
}

int OptmimalSolution(vector<int> &a)
{
    // here we just add the elements and if the addition gives negative we convert back sum to 0 and do this same process till the arrays end and at last return the sum as max if it's greater than it
    // TC = O(N)
    // SC = O(1)

    // if we asked for find the subarray of the max element we have to add these steps (line 62 to 65 and 70 and 71)

    int sum = 0;
    int mx = INT_MIN;
    int start;
    int ansStart = -1;
    int ansEnd = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (sum == 0)
        {
            // if the sum is 0 that means it it's the first element or the previous elements got the negative values which changed as 0 in our future logic
            start = i;
        }

        // add the elements
        sum += a[i];
        if (sum > mx)
        {
            mx = sum;
            // we get the start of the sub array when the sum was 0
            ansStart = start;

            // the end of the subarray we decides when we get the largest sum (that index)
            ansEnd = i;
        }

        // make the negative values as 0
        if (sum < 0)
        {
            sum = 0;
        }
    }
    // return the max element
    return mx;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    // int mx = BruteforceSolution(a);
    // int mx = BetterSolution(a);
    int mx = OptmimalSolution(a);
    cout << "the maximum sum of the subarrays is " << mx;
    return 0;
}