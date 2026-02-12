#include <bits/stdc++.h>
using namespace std;

// consequtive numbers meant the sequence numbers withought breaking the order example in the array a = {45, 46, 42, 1, 2, 3, 5, 4}; the consiqutives will be 1,2,3,4,5 and 42 and 45,46. so in this question you have to find longest consequtive which in 1,2,3,4,5 in our case and return the length of it

// this will search whether the perticular element is there or not in the array
bool LenearSearch(vector<int> &a, int num)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == num)
        {
            return true;
        }
    }
    return false;
}

int BruteforceSolution(vector<int> &a)
{
    // TC = O(2N)
    // SC = O(1)

    // atleast one element exist in the array so we take the longest as 1
    int longest = 1;

    // traverse through the array
    for (int i = 0; i < a.size(); i++)
    {
        // take one element
        int x = a[i];

        // keep count as one becuase atleast one element exist in the array
        int cnt = 1;

        // while it's next element don't appear in the array check for the whole array and check whether it's next element exist or not
        while (LenearSearch(a, x + 1) == true)
        {
            // upgrading presenet element to it's next element this will updated to the x of the while loop condition whenever the condition turns true
            x = x + 1;

            // increase the count if you get it's next element
            cnt++;
        }

        // update the longest based on what you got
        longest = max(longest, cnt);
    }

    // return the longest
    return longest;
}

int BetterSolution(vector<int> &a)
{
    // TC = O(NlogN) + O(N)
    // SC = O(1)

    // sort the array first
    sort(a.begin(), a.end());
    int logest = 1;
    int cnt = 0;

    // take a number to compare with the element in the array whether it's previuos exist or not because if it's preious exist that means the the numbers are in sequence
    int lastSmaller = INT_MIN;

    // traverse through the entire array
    for (int i = 0; i < a.size(); i++)
    {
        // if the previous of this element is exist already
        if (a[i] - 1 == lastSmaller)
        {
            // increase the count
            cnt++;
            // and now keep this item as the previous
            lastSmaller = a[i];
        }

        // if the previos of it's not there
        else if (lastSmaller != a[i])
        {
            // keep the the cnt as 1
            cnt = 1;
            // and keep it as the previous number of it
            lastSmaller = a[i];
        }

        // choose the longest
        logest = max(logest, cnt);
    }

    // return the longest
    return logest;
}

// My code (Better approach)
int Solution(vector<int> &a)
{
    sort(a.begin(), a.end());
    int cnt = 1, longest = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i + 1] == a[i] + 1)
        {
            cnt++;
        }
        else
        {
            longest = max(longest, cnt);
            cnt = 1;
        }
    }
    longest = max(longest, cnt);
    return longest;
}

int OptimalSolution(vector<int> &a)
{
    // TC = O(2N+N) => O(3N) where O(2N) for while loop because we are nearly iterating twice for each element, like when we get first element we chack for whether it's next elements are present or not in the array and O(N) for forLoop
    // SC = O(N) because we are storing the element

    // return the array if the array size is 0
    if (a.size() == 0)
    {
        return 0;
    }
    int longest = 1;

    // this will store the all the elements as it is
    unordered_set<int> st;    
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    // iterate in the elements stack which we stored
    for (auto it : st)
    {
        // and if the element's preious not present in the stack (that means this is the first element for the consequtives)
        if (st.find(it - 1) == st.end())
        {
            // make count as 1 and keep that item as x
            int cnt = 1;
            int x = it;

            // now while the next elements for x exist in the stack
            while (st.find(x + 1) != st.end())
            {
                // make the x as x's next element
                x = x + 1;
                // increase the count
                cnt++;
            }

            // get the longest
            longest = max(longest, cnt);
        }
    }

    // return the longest
    return longest;
}

int main()
{
    vector<int> a = {45, 46, 42, 1, 2, 5, 4};
    // int length = BruteforceSolution(a);
    int length = BetterSolution(a);
    // int length = OptimalSolution(a);
    cout << "The longest consequtive array's length is: " << length;
    return 0;
}