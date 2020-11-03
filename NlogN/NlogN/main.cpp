// Autumn Ossello
// Last modified: 11/3/2020

#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

long long int binarySearch(long long int t) {
    long long int high = t, low = 1;
    long long int mid = -1;
    long long int n = -1;
    long long int old_n = n;

    while (low <= high)
    {
        mid = (high + low) / 2;
        long long int n = floor(mid * log2(mid));
        if (n == old_n)
        {
            return mid;
        }
        old_n = n;

        if (t == n)
            return mid;
        else if (t > n)
        {
            //cout << "T: " << t << "  Result was too small: " << n << endl;
            low = mid;
            mid = (low + high) / 2;
        }
        else if (t < n)
        {
            high = mid;
            mid = (low + high) / 2;
        }
    }

    return mid;
}

void intHandler()
{
    long long int x = 2592000000000;
    long long int result = binarySearch(x);
    cout << "A result was found: " << result << endl;
}

int main()
{
    intHandler();

    return 0;
}

// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
/*
long long int binarySearch(long long int arr[], long long int low, long long int high, long long int t)
{
    int ran = 0;
    long long int old_m = -1;
    while (low <= high) {
        long long int m = low + (high - low) / 2;
        if (old_m == m)
            return m;
        old_m = m;
        // double re = log2(arr[m]);
        long long int result = floor(arr[m] * log2(arr[m]));

        // Check if x is present at mid
        if (t == result)
        {
            return m;
        }

        // If x greater, ignore left half
        if (t < result)
        {
            cout << "T was smaller: " << t << "  Should be: " << result << endl;
            high = m;
        }

        // If x is smaller, ignore right half
        else
        {
            cout << "T was bigger: " << t << "  Should be: " << result << endl;
            low = m;
        }
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main(void)
{
    long long int t = 1000000;
    long long int arr[1000001];
    for (long long int i = 0; i <= t; i++)
    {
        arr[i] = i;
    }
    long long int result = binarySearch(arr, 1, t, t);
    (result == -1) ? cout << "Element is not present in array"
        : cout << "Result: " << result;
    return 0;
}
*/