#include <bits/stdc++.h>
using namespace std;

// we have to find which number accured only ones in the array

int BruteforceSolution(vector<int> &a)
{
    // TC = O(N^2)
    // SC = O(1)

    // we will iterate through the array and find for each element that how many times it appeared in the array

    int cnt;
    int number;

    // iterate through the aray holding one element at a time
    for (int i = 0; i < a.size(); i++)
    {
        // take that one element in the variable called number
        number = a[i];

        // let intially the count be 0
        cnt = 0;

        // iterate though the array by checking that this one element how many times appeared in the array
        for (int j = 0; j < a.size(); j++)
        {
            // if we find that element in the array increase the count by 1
            if (a[j] == number)
            {
                cnt++;
            }
        }

        // hence if the elements count is 2 that the count also would be 2 but if the cnt is 1 that indicates that only one time that number accured in that array
        if (cnt == 1)
        {
            // return that number which accured only one time
            return number;
        }
    }

    // return -1 for safety purpose if all the elements are there in the array twice
    return -1;
}

int BetterSolution(vector<int> &a)
{
    // TC = O(N logN) where N → number of elements processed and log N → cost of each map operation
    // SC = O(N/2+1) but the big O ignore the constents it would be O(N)

    // we took a map and we keep long long datatype for store the elements from the array we didn't kept a int here to store it to reduce the overflow risk and we kept int for count the frequency of the number (how many times the number accured)
    map<long long, int> mpp;

    // traverse through the array
    for (int i = 0; i < a.size(); i++)
    {
        // record the elements to map with it's frequencies
        mpp[a[i]]++;
    }

    // iterate the map and look for which's frequency is 1
    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            // return that element
            return it.first;
        }
    }

    // return -1 if everything is correct
    return -1;
}

int OptmialSolution(vector<int> &a)
{
    // TC = O(N)
    // SC = O(1)

    // take the xor1 as 0
    int xor1 = 0;

    // traverse the array by making xor operation with all the elements in the array and we know that if one element is single, xor of it will be that element only
    for (int i = 0; i < a.size(); i++)
    {
        xor1 = xor1 ^ a[i];
    }

    // return that element here it would be 0 indicating no number is single or the elemet which appeared ones
    return xor1;
}

int main()
{
    vector<int> a = {1, 1, 2, 3, 3, 4, 4};
    // int solution = BruteforceSolution(a);
    // int solution = BetterSolution(a);
    int solution = OptmialSolution(a);
    cout << "The number which appeared ones is: " << solution;
    return 0;
}