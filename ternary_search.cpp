#include <iostream>
using namespace std;

int ternarySearch(int l, int r, int key, int ar[])

{
    while (r >= l)
    {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid1
        if (ar[mid1] == key)
        {
            return mid1;
        }
        // Check if key is present at any mid2
        if (ar[mid2] == key)
        {
            return mid2;
        }

        // Check if key is there in all three partitions of the array
        if (key < ar[mid1])
        {

            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (key > ar[mid2])
        {

            // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else
        {

            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // Key not found
    return -1;
}

// Driver code
int main()
{
    // An array with sorted elements
    int arr[] = {9, 23, 35, 41, 58, 61, 70, 84, 92, 109};

    // Search key -to be found in the array
    int key = 70;

    // Find size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = ternarySearch(0, n, key, arr);

    // Printing the result
    if (result == -1)
    {
        cout << "Search key is not present in array";
    }
    else
    {
        cout << "Search key is present at index " << result;
    }
}