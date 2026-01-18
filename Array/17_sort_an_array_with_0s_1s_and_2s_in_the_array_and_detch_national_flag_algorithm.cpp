#include <bits/stdc++.h>
using namespace std;

void BruteforceSolution(vector<int> &a)
{
    // TC = O(nlogn)
    // SC = O(logn)
    sort(a.begin(), a.end());
}

void BruteforceWithSelectionSort(vector<int> &a)
{
    // here we take the first element as min for intitial and check through the array finding any min is available in the array if we find it we take that element as min and swap it with first element doing the same thing untill we get the sorted array

    // TC = O(N*N)
    // Sc = O(1)
    int n = a.size();

    // keep the i at the first element
    for (int i = 0; i < n - 1; i++)
    {
        // keep the min at the i (it's initially 0)
        int min = i;

        // take another pointer j which traverse from i to n
        for (int j = i; j < n; j++)
        {
            // if the j'th element is smaller than the min element (initially it's first element)
            if (a[j] <= a[min])
            {
                // we take the min as j and when we go out of this loop we take the i as min again
                min = j;
            }
        }
        // hence we found the real min we swap it with i (initally it's first element)
        swap(a[min], a[i]);
    }
}

void BruteforceWithBubbleSort(vector<int> &a)
{
    // we just keep the i at the last and keep decrement in every iteration until the array ends and also keep the j as first element and keep compare it with it's next element if the current j is greater than the next j we swap them and maintain a flag called didSwap by making it 1 if they swap and keep the process in the j loop untill the i comes to inital position of the array at last if the didSwap is still the 0 that indicates there is now swap accured that means the array id already sorted so we break the loop

    // TC = O(N*N) in worst case
    // SC = O(1)

    int n = a.size();

    // i at the last of the array and traverse backwords
    for (int i = n - 1; i >= 0; i--)
    {
        // keep the didSwap as 0 before entering the j loop
        int didSwap = 0;

        // j moves from staring of the array to i
        for (int j = 0; j < i; j++)
        {
            // if the j'th element is greater than it's next element
            if (a[j] > a[j + 1])
            {
                // swap them and update the flag by 1
                swap(a[j], a[j + 1]);
                didSwap = 1;
            }
        }

        // if the didSwap is still the 0 after it complete the loop break it because the array is already sorted :)
        if (didSwap == 0)
        {
            break;
        }
    }
}

void BruteforceWithInsertionsort(vector<int> &a)
{
    // first we keep a pointer i in the starting of the array and and keep a pinter j which will be with the pointer i and we check whether the j is smaller than it's previous element or not if it's smaller we swap it with it's previos element and we decrement j by one and again comapare and swap operations accures untill the j is one step ahead from the 0'th element because we need j-1 element for compare with j we do the same process untill the array ends

    // TC = O(N*N) in worst case
    // SC = O(1)

    // keep the i in the starting of the array
    for (int i = 0; i < a.size(); i++)
    {
        // keep the j where i is
        int j = i;

        // while the j one step ahead from the first element and also the previos element is greater then it
        while (j > 0 && a[j - 1] > a[j])
        {
            // swap them and devrement j by 1
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}

void merge(vector<int> &a, int low, int mid, int high)
{
    // we just take two pointers left will be on low and right will be on mid+1 and left traverse until it crosses the mid and also the right crosses the high by traversing we compare the left and right element and add the smallest element in the temp array we do the procedure untill we complete the whole array now we after that we rearrange the element back to the original array from the temp array

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void BruteforceWithMergesort(vector<int> &a, int low, int high)
{
    // here the recursion takes place and in the very movement the low crosses the high the array return with the sorted part

    // nlogn
    // O(n)
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    BruteforceWithMergesort(a, low, mid);
    BruteforceWithMergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int partician(vector<int> &a, int low, int high)
{
    // here we make a element which we selected as pivot (normally first element but we can take any element from the array) such that the smaller elements comes to it's left and greater elements comes to it's right and return the pivot elment's poistion after getting done by these

    int pivot = a[low];
    int i = low;
    int j = high;

    // while the i won't cross the j
    while (i < j)
    {
        // while the i'th element is smaller or equals to pivot and also it won't crossing the high increment the i (at the end we reach the array end or get the greater element from the pivot)
        while (a[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        // this same works as i but viceversa we get the lower element then the pivot after the loop completes and here j decrements
        while (a[j] > pivot && j >= low + 1)
        {
            j--;
        }

        // int the movement when the i cross the j we swap them then meanse we place the right elements at the right place
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    // after this loop we will have the smaller element and larger elements we swap them (do on the book for better understanding) swap them
    swap(a[low], a[j]);

    // now we have j which's left have smaller and right have bigger elemts
    return j;
}

void BruteforceWithQuicksort(vector<int> &a, int low, int high)
{
    // recursion takes place
    // O(nlogn)
    // O(1)

    // this means the low crossed the high
    if (low < high)
    {
        int part = partician(a, low, high);
        BruteforceWithQuicksort(a, low, part - 1);
        BruteforceWithQuicksort(a, part + 1, high);
    }
}

void BetterSolution(vector<int> &a)
{
    // just take some counts for number 0,1,2 and increment them when that number visible in the array and just add the 0s,1s and 2s when in the aray how much there is a count
    // TC = O(2N)
    // SC = O(1)

    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 1)
        {
            cnt1++;
        }
        else if (a[i] == 2)
        {
            cnt2++;
        }
        else
        {
            cnt0++;
        }
    }
    for (int i = 0; i < cnt0; i++)
    {
        a[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        a[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < a.size(); i++)
    {
        a[i] = 2;
    }
}

void OptimalSolution(vector<int> &a)
{
    // TC = O(N)
    // SC = O(1)

    /*
    Detch national Flag Aglorithm
    imagine this like this:
    0   low-1 low  mid-1 mid   high high+1   n-1
    |     |    |     |    |      |    |       |
    v     v    v     v    v      v    v       v
    0 0 0 0    1 1 1 1    uNsoRteD    2 2 2 2 2
    now what we do here is first we check for mid if it's 0 we swap it with low that is swap(mid,low) now the hence the rule is 0 to low-1 should 0 now it's reaching upto low, we increment the low by one now the now the rule satisfied that 0 is in the range of 0 to low-1 now if the mid will have 1 we wont swap it and move the mid by one becase the low to mid-1 should be 1 we don't need to swap it... now if the mid have the 2 we have swao(mid,high) and decrement the high by one because the rule says high+1 to n-1 should be 2.. by continuing the same we sort the whole array
    */
    int low = 0;
    int mid = 0;
    int high = a.size() - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> a = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    // BruteforceSolution(a);
    // BruteforceWithSelectionSort(a);
    // BruteforceWithBubbleSort(a);
    // BruteforceWithInsertionsort(a);
    // BruteforceWithMergesort(a, 0, a.size() - 1);
    // BruteforceWithQuicksort(a, 0, a.size() - 1);
    // BetterSolution(a);
    OptimalSolution(a);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}