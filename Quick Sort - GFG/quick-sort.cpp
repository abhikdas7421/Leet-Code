//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high) {
            return;
        }
        
        // partition logic
        int p = partition(arr, low, high);
        
        // RE
        // left
        quickSort(arr, low, p-1);
        
        // right
        quickSort(arr, p+1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int i = low-1;
       int j = low;
       int pi = high;
       int pe = arr[pi];
       
       while(j <= high) {
           if(arr[j] < pe) {
               i++;
               swap(arr[j], arr[i]);
           }
           j++;
       }
       i++;
       swap(arr[i], arr[pi]);
       
       return i;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends