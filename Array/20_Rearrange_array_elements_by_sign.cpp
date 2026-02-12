#include <bits/stdc++.h>
using namespace std;

// you have given an array with count of positive numbers = count of negative numbers, your task is to re-arrange them in such way that while mantaining the order the numbers should arrange like this : + - + - + - ex: for below input the out put will be 1, -3, 2, -4, 5, -6

// in second question there is not confirmation that the array have no.of.positive == no.of.negative to solve this we did the soltuion after the OptimalSolution (BruteForSecond)

void BruteforceSolution(vector<int> &a)
{
    // TC = O(2N)
    // SC = O(N)

    vector<int> pos;
    vector<int> neg;

    // traverse through the array
    for (int i = 0; i < a.size(); i++)
    {
        // if it's negative store it in the neg array
        if (a[i] < 0)
        {
            neg.push_back(a[i]);
        }
        // if it's positive store it in the pos array
        else
        {
            pos.push_back(a[i]);
        }
    }

    // put all the positive numbers in the even position of the array and negative numbers in odd postion
    for (int i = 0; i < a.size() / 2; i++)
    {
        a[2 * i] = pos[i];
        a[2 * i + 1] = neg[i];
    }
}

vector<int> OptimalSolution(vector<int> &a)
{
    // TC = O(N)
    // SC = O(N)

    // we know that the postive numbers should be at even indexus and negaive should be in odd indexes so first we took 2 integers pointing intital even(0) and initial odd(1) and then if we get the negative we store it in the extra array (ans) and move the pointer by 2 by doing this we arrange the negative value in odd position and positive in even

    vector<int> ans(a.size());
    int pos = 0;
    int neg = 1;

    for (int i = 0; i < a.size(); i++)
    {
        // if it's negative
        if (a[i] < 0)
        {
            // store it in negative position and move 2 step ahead
            ans[neg] = a[i];
            neg += 2;
        }
        // else it must be the positive, add it and move 2 step ahead
        else
        {
            ans[pos] = a[i];
            pos += 2;
        }
    }

    // return the arranged array
    return ans;
}

void BruteForSecond(vector<int> &a)
{
    // here we do the same step as the brute force approach which have taken before and if add the leftover elements at the last

    // TC = O(2N)
    // SC = O(1)

    vector<int> neg, pos;

    // traverse through the array amd collect positive and negative elements seperately
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < 0)
        {
            neg.push_back(a[i]);
        }
        else
        {
            pos.push_back(a[i]);
        }
    }

    // if the size of the pos is greater than neg
    if (pos.size() > neg.size())
    {
        // add the elements in the correct order unntil the negative ends, the arranged array is in the size of neg.size()*2 now!
        for (int i = 0; i < neg.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }

        // we have to collect next leftover elements from this index
        int index = neg.size() * 2;

        // the remaining elements in the "positive array" we took neg.size. because the neg.size elements are already added into the array from the pos array
        for (int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    // just did the oposite
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            a[2 * i] = pos[i];
            a[2 * i + 1] = neg[i];
        }
        int index1 = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            a[index1] = neg[i];
            index1++;
        }
    }
}

int main()
{
    vector<int> a = {1, 2, -3, -4, 5, -6};
    // BruteforceSolution(a);
    // vector<int> newArray = OptimalSolution(a);
    BruteForSecond(a);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}