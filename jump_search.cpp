#include <iostream>
#include <math.h>
using namespace std;
 
int jumpSearch(int arr[], int n, int key)
{
	   // keep track of the previous end 
    int start = 0;

    // a good jump size is square root of the array length
    int end = sqrt(n);
    
    while(arr[end] < key && end < n){
        start = end;
        end = end + sqrt(n);
        if(end > n - 1)
           end = n-1;
    }
    
    //perform linear search in selected subarray/block
	   for(int i = start; i <= end; i++) { 
      if(arr[i] == key)
         return i; //return position of the key
    }
    return -1;
}
 
// Driver code
int main(void)
{
    // arr - array of element
    int arr[] = { 8, 23, 45, 56, 67, 89, 90, 100, 103} ;
  
    // search key
    int key = 100;
  
    // n - size of array (found by dividing size of 
    // entire array by size of single element from the array
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call for jump search
    int result = jumpSearch(arr, n, key);
    if(result == -1){
        cout << "Element is not in the array :-(";
    } else {
        cout << "Element found at position : " << result;
    }
    return 0;
}