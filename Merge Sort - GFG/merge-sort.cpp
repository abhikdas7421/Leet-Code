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
    void merge(int arr[], int s, int m, int e)
    {
        // Your code here
        int len1 = m-s+1;
        int len2 = e-m;
        
        int *left = new int[len1];
        int *right = new int[len2];
        
        // copy
        int k = s;
        for(int i = 0; i < len1; i++) {
            left[i] = arr[k];
            k++;
        }
        
        k = m+1;
        for(int i = 0; i < len2; i++) {
            right[i] = arr[k];
            k++;
        }
        
        // merge
        int leftIndex = 0;
        int rightIndex = 0;
        int mainIndex = s;
        
        while(leftIndex < len1 && rightIndex < len2) {
            
            if(left[leftIndex] < right[rightIndex]) {
                arr[mainIndex++] = left[leftIndex++];
            }
            else {
                arr[mainIndex++] = right[rightIndex++];
            }
        }
        
        while(leftIndex < len1) {
            arr[mainIndex++] = left[leftIndex++];
        }
        
        while(rightIndex < len2) {
            arr[mainIndex++] = right[rightIndex++];
        }
        
        delete[] left;
        delete[] right;
        
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        //code here
        // base case
        if(s >= e) return;
        
        int mid = s + (e-s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends