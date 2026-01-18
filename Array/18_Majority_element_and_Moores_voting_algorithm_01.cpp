#include <bits/stdc++.h>
using namespace std;

// majority element in the sense the element which appeared in the array more than a.size()/2 time not >= but >

int BruteforceSolution(vector<int> &a)
{
    // TC = O(N*N)
    // SC = O(1)

    // keep a pointer i in the first element
    for (int i = 0; i < a.size(); i++)
    {
        // before entering the j loop make the count as 0
        int cnt = 0;

        // keep the j also in first element
        for (int j = 0; j < a.size(); j++)
        {
            // if element of j == element of i (first the j compare with first element next it compare with second element watching that is this same as i'th element or not same goes through the array checking of all elements)
            if (a[j] == a[i])
            {
                // then increment count by one by saying this element occured "count" times
                cnt++;
            }
        }
        // if we found the majority element return it
        if (cnt > (a.size() / 2))
        {
            return a[i];
        }
    }

    // if we won't find majority return -1
    return -1;
}

int BetterSolution(vector<int> &a)
{
    // TC = O(nlogn) + O(n)=>we are traversing the map
    // SC = O(n)
    map<int, int> mpp;

    // traverse an array and keep the count of how many times the elemets accured in the array
    for (int i = 0; i < a.size(); i++)
    {
        mpp[a[i]]++;
    }

    // if the element's count is majority in size return it
    for (auto it : mpp)
    {
        if (it.second > (a.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

int OptimalSolution(vector<int> &a)
{
    // TC = O(N)=> only if in there is a chance that there will be the majority O(2N) => there could or couldn't be the majority (our case)
    // SC = 0

    // we choose one element which we consider as majority element and count it's counter if the next element of it's same as the element and if the next element of it's not same we decrement it and if the element's count becomes 0 there will be chance that the element may not be the majority and we take the element next after the count becomes 0 and consider it as new majority element and check it with the same process at last we check whether the element which get the count as non 0 is appeared a.size()/2 times or not we take this step only if we unsure that there is a majority or not

    int cnt = 0;
    int el;

    // be in first element and traverse through the array
    for (int i = 0; i < a.size(); i++)
    {
        // if the count is 0 that means if it's first element or it's element after the count became 0 (choosing the next element after we get 0 for the element which we meant as majority)
        if (cnt == 0)
        {
            cnt = 1;
            el = a[i];
        }

        // if the same element which took as the majority accures next also increment the count
        else if (a[i] == el)
        {
            cnt++;
        }

        // if it's not decrement the count
        else
        {
            cnt--;
        }
    }

    // this step is totally for checking that is there is majority element or not
    int cnt1 = 0;

    // we are traversing and counting and cheking whether it's majority or not
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == el)
        {
            cnt1++;
        }
    }
    if (cnt1 > (a.size() / 2))
    {
        return el;
    }

    // return -1 for safety it there is not majority
    return -1;
}

int main()
{
    vector<int> a = {1, 1, 1, 1, 1, 2, 3, 4, 5};
    // int majority = BruteforceSolution(a);
    // int majority = BetterSolution(a);
    int majority = OptimalSolution(a);
    cout << "The majority element in the array is: " << majority;
    return 0;
}