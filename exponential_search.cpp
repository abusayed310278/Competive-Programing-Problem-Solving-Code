#include <bits/stdc++.h>
using namespace std;
 
int min(int a, int b){
    return (a>b)? a: b;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2; 
 
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
 
        // If x greater, pick right half
        if (arr[mid] < x)
            l = mid + 1;
 
        // If x is smaller, pick left half
        else
            r = mid - 1;
    }
 
    // If search key 'x' is not found in 'arr' then 
    return -1;
}
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;
 
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n-1), x);
}
int main(void)
{
   // An array with elements
   int arr[] = {21, 27, 32, 41, 49, 55, 67, 78, 99};
   // n - size of array
   int n = sizeof(arr)/ sizeof(arr[0]);
   // x - Search key
   int x = 78;
   
   int result = exponentialSearch(arr, n, x);
   
   if (result == -1){
       cout <<"Search key is not present in array";
   } else {
       cout <<"Search key is present at index " << result;
   }
   return 0;
}