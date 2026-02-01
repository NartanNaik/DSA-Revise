#include <bits/stdc++.h>
using namespace std;

// you have given an array and a value k you have to return the number of subarrays with that sum

int BruteforceSolution(vector<int> &a, int k)
{
    // TC => O(N^3)
    // SC => O(1)

    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += a[k];
            }
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int BetterSolution(vector<int> &a, int k)
{
    // TC => O(N^2)
    // SC => O(1)

    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            if (sum == k)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int OptimalSolution(vector<int> &a, int k)
{
    // TC => O(N logN)
    // SC => O(N)

    // here we store the prefixSum - k into the map and count how many prefixSum - k are in the map which gives us the total subarray with sum k, becuase if the prefixSum is not there which is == prefixSum - k, that means there is not sub array which casue the the sum k

    // for example {1, 2, 3, 4, 5, 6, 7}
    // first the prefix and cnt we keep as 0 and we store 0 in the map with cnt 1 becuase if the k is 3 and the element is 3, 3 - 3(k) becomes 0, so first we add the first element which is 1 check: 1 - 3 (prefix - k) = -2, ask: is this value inside the map? NO, now add the value one to the map, now map = {0 1, 1 1} next prefix sum is 1+2=> 3 now do 3-3(prefix - k) now the answer is 0, ask: is this inside the mapp? yes! how many times? 1 time! increase the cnt by 1 then! and add the prefix "3" into the map, do this untill the array ends and get the count of the array with sum of k

    map<int, int> mpp;

    // add 0 with the count of 1 at the start into the map
    mpp[0] = 1;

    // initially these are 0
    int prefix = 0, cnt = 0;

    // traverse till the end of the array
    for (int i = 0; i < a.size(); i++)
    {
        // add the current value as prefix
        prefix += a[i];

        // get the value which gives us prefix - k
        int remove = prefix - k;

        // count how many times is the number accured in the mpp
        cnt += mpp[remove];

        // add the prefix value into the mpp with increasing the cnt by 1;
        mpp[prefix] += 1;
    }

    // return the cnt
    return cnt;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    // int ans = BruteforceSolution(a, k);
    // int ans = BetterSolution(a, k);
    int ans = OptimalSolution(a, k);
    cout << "The number of subarrays with the sum " << k << " is " << ans;
    return 0;
}