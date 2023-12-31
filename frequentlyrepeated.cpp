#include<stdio.h>
#include<stdlib.h>
int findMostFrequentElement(int A[], int n)
{
    for (int i = 0; i < n; i++)    //Sort the array
    {    
        int temp;
        for (int j = i+1; j < n; j++) 
        {     
           if(A[i] > A[j]) 
           {    
               temp = A[i];    
               A[i] = A[j];    
               A[j] = temp;    
           }     
        }     
    }        
    int max_count = 1, res = A[0], count = 1; 
    for (int i = 1; i < n; i++) { 
        if (A[i] ==A[i - 1]) 
            count++; 
        else { 
            if (count > max_count) { 
                max_count = count; 
                res = A[i - 1]; 
            } 
            count = 1; 
        } 
    }   
    if (count > max_count) 
    { 
        max_count = count; 
        res = A[n - 1]; 
    }   
    return res; 
}
int main()
{
    int n;              
    printf("Enter the number of elements ");
    scanf("%d",&n);    
    int array[n];     
    printf("Enter the array elements");
    for(int i=0;i<n;i++)  
    {
        scanf("%d",&array[i]);
    } 
    int maxElement = findMostFrequentElement(array, n);    
    printf("\n Maximum Repeating Element : %d",maxElement);   
    return 0;
}
