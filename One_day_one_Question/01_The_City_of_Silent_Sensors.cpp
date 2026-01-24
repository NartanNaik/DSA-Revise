// 1. The City of Silent Sensors

// A city deploys N sensors in a straight line, each reporting an integer value every minute. Due to a firmware defect, inactive sensors report 0, while active sensors report positive or negative values depending on signal drift.
// The city controller wants to reorganize the data stream in-place so that all inactive sensors are pushed to the end, while preserving the relative order of all active sensors.

// However, after reorganization, the controller must also determine the maximum cumulative signal strength that can be obtained by choosing one continuous block of sensors before the inactive zone begins.

// If all sensors are inactive, return 0.

// You are not allowed to:

// Use extra arrays

// Traverse the array more than once meaningfully

// Reorder active sensors

// Return only the maximum cumulative signal strength.

// This problem looks simple until you realize the second requirement depends on the first in a non-trivial way.

#include <bits/stdc++.h>
using namespace std;

// ######################################################################################################

// why this solution won't meat the requirement?

int Solution(vector<int> &a)
{
    int j;
    int sum = 0;

    // we are breaking the kadane's algorithm
    // we are assuming there defenately will be 0 this cause the trouble if there is no 0 which leads the i as undefined value where the i = j+1
    // we are not getting the answer with one parse, even though we are travelling from the different element this loops concludes as two parse because of the loop conditions
    // in first loop we are not swapping
    // we are using the swap in second loop which is unstable becuase the swap is unstable

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum < 0)
        {
            sum = 0;
        }
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    int i = j + 1;
    while (i < a.size())
    {
        if (a[i] == 0)
        {
            i++;
        }
        if (a[i] != 0)
        {
            sum += a[i];
            if (sum < 0)
            {
                sum = 0;
            }
            swap(a[j], a[i]);
            i++;
            j++;
        }
    }
    return sum;
}

// in one sentence the code works from this example but it's unstable and not meeting the questions conditions

//######################################################################################################


// #####################################################################################################

// why is this good?

// meeting all conditions and also the solution is guarrenteed (stable) because we are not using the swap here insteed we using copy forward method

int CorrectFunction(vector<int> &a)
{
    int write = 0;
    int sum = 0;
    int maxSum = 0;
    bool hasActive = false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            hasActive = true;
            a[write] = a[i];
            write++;

            sum += a[i];
            if (a[i] < 0)
            {
                sum = 0;
            }
            maxSum = max(maxSum, sum);
        }
    }

    // this is not parsing twice !
    while (write < a.size())
    {
        a[write++] = 0;
    }

    if (!hasActive)
    {
        return 0;
    }

    return maxSum;
}

// #####################################################################################################

int main()
{
    vector<int> a = {1, 0, -2, 0, 0, 0, 3, -4, 5};
    int ans = CorrectFunction(a);
    cout << "Tha maximum sum is: " << ans;
    return 0;
}