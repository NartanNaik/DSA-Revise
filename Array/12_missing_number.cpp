#include <bits/stdc++.h>
using namespace std;
// we have to find the the missing number in the array from 1 to N like if the array is 1,2,4 and the N is 4 then the missing number will be 3

int BruteforceSolution(vector<int> &a, int N)
{
    // TC = O(N*N)=>in the worst case where the missing element would be in the last of the array
    // SC = O(1)

    // maintain a flag and turn it as one when you found the element which is matching the index for example the index is 1 and the element also 1 then we mark the flag as 1
    int flag;

    // traversing through out the N so that we get to know which element is lost in the range of N
    for (int i = 1; i <= N; i++)
    {
        // starting our flag is 0 while checking for each element keep the falg 0 again
        flag = 0;

        // traversing the whole array
        for (int j = 0; j < a.size(); j++)
        {
            // if array's element matching the index ex: a[0]=>(1) == i=>(1)
            if (a[j] == i)
            {
                // turn the flag into 1 and break this loop
                flag = 1;
                break;
            }
        }
        // if the flag is still 0 even it traverse the above array that maens this i'th element if missing from the array so return the i
        if (flag == 0)
        {
            return i;
        }
    }

    // if no index found with flag 0 then return -1 indecating all elements are present in the array
    return -1;
}

int BetterSolution(vector<int> &a, int n)
{
    // TC = O(2n)
    // SC = O(n)

    // take an array with all 0's
    int hash[n + 1] = {0};

    // now traverse whole array and mark as 1 for all the elements in the array
    for (int i = 0; i < a.size(); i++)
    {
        // the missing element in the array will not get 1 and that number still remains 0
        hash[a[i]] = 1;
    }

    // now traverse the array from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // if the hash of the perticular element is 0 that means that element is missing becasue we already give the 1 to all the elements if it's 0 here that means that element is missing here
        if (hash[i] == 0)
        {
            // return that number which would be the index
            return i;
        }
    }

    // if nothing found return -1 for safety
    return -1;
}

int OptimalSolutionWithSum(vector<int> &a, int n)
{
    // TC = O(N)
    // SC = O(1)

    // Here how it works: if we take the sum of all elements in the range n and substract it from the sum of all elements from the array then the difference would be the missing number ex: a={1,2,3} and n=4 so sum(n) = 10(1+2+3+4) and sum(a)=6(1+2+3) now sum(n)-sum(a)=>10-6 = 4 this is the missing number in the array a

    // here we are doing sum of all elements from the range n this formula helps to get the sum
    int sum = (n * (n + 1) / 2);

    // taking sum2 as 0 and adding it the elements present in the array
    int s2 = 0;

    // traverse through the whole array
    for (int i = 0; i < a.size(); i++)
    {
        // add the element to the s2 which was initially 0
        s2 += a[i];
    }

    // return the difference of it
    return sum - s2;
}

int OptimalSolutionWithXOR(vector<int> &a, int n)
{
    // How XOR works: this is the symbol of xor: "^", now if you do the xor with the same numbers the xor will be 0 and if you do the xor with the number 0 to the other number then the answer would be that other numeber... example: 1^1=0 and 1^0 = 1 and if 1^1^6^2^2 then the xor would be 0^6^0 = 6

    // TC = O(N)
    // SC = O(1)

    // why is this still better(slightly) than sum method?
    // :- beacuse if the n given as 10^5 and we do the sum of it it would be near 10^10 which cannot be stored in the integer so we have to use bigger data types like long which will take a slightly bigger space than the int but the xor never exceeds the 10^5 which makes it slightly better

    // we took xor1 for xor it with all the numbers in the range of the n we initially kept it as 0 beacase we know that 0^anyNumber = anyNumber
    int xor1 = 0;

    // we did the same thing but we ara gonna use it for array's elements
    int xor2 = 0;

    // traverse through whole array
    for (int i = 0; i < a.size(); i++)
    {
        // doing xor for all the elements from the array (this may includes the missing element)
        xor2 = xor2 ^ a[i];

        // doing xor from 1 to n (this will not includes missing element)
        xor1 = xor1 ^ (i + 1);
    }

    // doing xor with the last element too because the missing element could be the last element too
    xor1 = xor1 ^ n;

    // now when we xor the xor1 and xor2 the elements of both the xor get xor and only the missing element remains
    return xor1 ^ xor2;
}

int main()
{
    int n = 6;
    vector<int> a = {1, 2, 3, 5, 6};
    // int val = BruteforceSolution(a, n);
    // int val = BetterSolution(a, n);
    // int val = OptimalSolutionWithSum(a, n);
    int val = OptimalSolutionWithXOR(a, n);
    cout << "The missing number is: " << val;
    return 0;
}