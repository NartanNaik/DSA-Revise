#include <bits/stdc++.h>
using namespace std;

void BruteforceSolution(vector<int> a)
{
    // First we sort the whole array after that we comapre the second element from the last to the last element and if that is same we come one step back that is third element from the last and comapre it with last element we do the same until we find the element which is not equavalant to the largest and once we got it we return it
    // The time complexity of this will be O(NlogN)+N and SC = O(1)
    if (a.size() < 2)
    {
        cout << "Second largest element does not exist";
        return;
    }
    sort(a.begin(), a.end());
    int largest = a.back();
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] != largest)
        {
            cout << "The largest element is: " << a[i];
            return;
        }
    }

    cout << "Second largest element does not exist";
}

void BetterSolution(vector<int> a)
{
    // here we first find the largest and compare the second largest with it and return the second if that is not equavelent to the largest
    // The time complexity is tc = O(2N) and SC = O(1)
    int largest = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    int secondLargest = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > secondLargest && a[i] != largest)
        {
            secondLargest = a[i];
        }
    }
    cout << "The second largest element is: " << secondLargest;
}

void OptimalSolution(vector<int> a)
{
    // Here when we comparing for largest we also do comapare the things with the secondLargest making the solution optimal
    // so the time complexity will be TC = O(N) SC = O(1)

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    int secondSmallest = INT_MAX;
    int smallest = INT_MAX;

    for (int i = 0; i < a.size(); i++)
    {
        // To find second largest
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }

        // To find second smallest
        if (a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < secondSmallest)
        {
            secondSmallest = a[i];
        }
    }

    if (secondLargest == INT_MIN || secondSmallest == INT_MAX)
    {
        cout << "Second largest/smallest does not exist";
        return;
    }

    cout << "The second largest element is: " << secondLargest;
    cout << "\nThe second smallest element is: " << secondSmallest;
}

int main()
{
    vector<int> a = {1, 2, 5, 4, 8, 8, 9, 9, 9};
    // BruteforceSolution(a);
    // BetterSolution(a);
    OptimalSolution(a);
    return 0;
}