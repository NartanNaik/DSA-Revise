#include <bits/stdc++.h>
using namespace std;

// you have to choose 2 elements "in order" and when you "subtract them" and have to return the maximum output

int maximumProfit(vector<int> &a)
{
    // TC = O(N)
    // SC = O(1)

    // keep the first element as mini
    int mini = a[0];

    // initially take maximum profit as 0
    int mxProfit = 0;

    // traverse throught the array
    for (int i = 1; i < a.size(); i++)
    {
        // and take the cost as substraction of present element and it's past element
        int cost = a[i] - mini;

        // and if the cost is minimum then the previous cost the maxProfit wont update
        mxProfit = max(mxProfit, cost);

        // after each iteration update the min as the next element
        mini = min(mini, a[i]);
    }

    // return the maximum profit
    return mxProfit;
}

int main()
{
    vector<int> a = {5, 1, 4, 2, 8, 1};
    int profit = maximumProfit(a);
    cout << "The maximum profit is: " << profit;
    return 0;
}