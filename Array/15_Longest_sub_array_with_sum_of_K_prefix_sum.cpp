#include <bits/stdc++.h>
using namespace std;

// You have to return the length of the longest sub array with the sum of k in the given array

int BruteforceSolution(vector<int> &a, int k)
{
    // TC => O(N*N*N) (not exactly but somewhere around)
    // SC => O(1)

    int length = 0;

    // keep i at beginnig of the array and traverse to whole array
    for (int i = 0; i < a.size(); i++)
    {
        // s as 0 so that we can record the sum of the array in future
        int sum = 0;

        // keep it where the i is there and also traverse till end this works like if the i is on 1 this will run till 1 to size of array and if it's on 3 it will run till 3 to size of the array
        for (int j = i; j < a.size(); j++)
        {
            // and sum the subarray and store it in the s
            sum += a[j];

            // is the s == k
            if (sum == k)
            {
                // check that it's length is greater or lesser than previous one and if it's greater keep it as longest
                length = max(length, (j - i + 1));
            }
        }
    }
    // return the longest
    return length;
}

int BetterSolution(vector<int> a, long long k)
{
    // TC = O(N*longN)=> if we use oredered map and in worst case it would be O(N*N) if we use unordered map
    // SC = O(N)
    // This will works for the array containg the elements positives and negatives if the array contains only positives and 0s we go for optimal one which we discussed

    // max length as 0
    int maxLen = 0;

    // sum as 0 ans we took long long because the k also could long long
    long long sum = 0;

    // a map with long long contents and int index
    map<long long, int> prefixSumMap;

    // iterate through the array
    for (int i = 0; i < a.size(); i++)
    {
        // sum the the i'th element of the array to the sum
        sum += a[i];

        // if that sum == k
        if (sum == k)
        {
            // take the max of maxLen and i+1 as maxLen
            maxLen = max(maxLen, i + 1);
        }

        // getting the rem with subtracting the sum and k
        long long rem = sum - k;

        // if the rem IS in the map
        if (prefixSumMap.find(rem) != prefixSumMap.end())
        {
            // take the len as this where prefixSumMap[rem] is the index of the rem in that map
            int len = i - prefixSumMap[rem];

            // and consider the map
            maxLen = max(maxLen, len);
        }

        // if the sum is not there inside the map
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            // then add it into the map with the index of i
            prefixSumMap[sum] = i;
        }
    }

    // return the maxLen
    return maxLen;
}

int OptimalSolution(vector<int> a, int k)
{
    // TC = O(N)
    // SC = O(1)
    // Here we are using two pointer approach and this will only works where there is not negative elements in the array, and here we are using the concept of prefix sum

    int maxLen = 0;
    int i = 0;
    int sum = 0;

// traverse array from starting to the end
    for (int j = 0; j < a.size(); j++)
    {
        // add the elemets 
        sum += a[j];

        // if the sum is exceeds the k
        if (sum > k)
        {
            // then remove the first elemnt from the sub array
            sum -= a[i];
            // and move the i pointer one step ahead
            i++;
        }

        // if the sum == k
        if (sum == k)
        {
            // then take the maxLen from the max of maxLen and j-i+1
            maxLen = max(maxLen, j - i + 1);
        }
    }

    // return the maxLen
    return maxLen;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    long long k = 9;
    // long long sol = BruteforceSolution(a, k);
    // long long sol = BetterSolution(a, k);
    long long sol = OptimalSolution(a, k);
    cout << "Length of the longest sub array with the sum " << k << " is " << sol;
    return 0;
}