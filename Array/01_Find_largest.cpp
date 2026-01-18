#include <bits/stdc++.h>
using namespace std;

void BruteSollution(vector<int> a)
{
    // First we sort the array and take the last element which is array of a.size()-1 and that will be the largest element
    // The Time complexity of this will be O(NlogN) because this is the tc which taken by sorting and space complexity is O(1)
    sort(a.begin(), a.end());
    cout << "The largest element is: " << (a[a.size() - 1]);
}

void OptimalSolution(vector<int> a)
{
    // Here what we are gonna do is first we take the minimum number in the integers (0) as the largest and compare it in every iteration with other elements in the array and if the element is will larger than the largest which we declared we make it as largest and continue the cycle until the array ends
    // The time complexity for this will be O(N) and SC is O(1)
    int largest = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
    }
    cout << "The largest element is: " << largest;
}

int main()
{
    vector<int> a = {1, 5, 4, 6, 8, 1};
    // BruteSollution(a);
    OptimalSolution(a);
    return 0;
}