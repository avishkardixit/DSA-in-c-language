//here we are writing these algorithm for linear searching of the array which will perform linear transversal and go through
//eache element
//hence these searching will run until n th element the time comlexity of lenear search is O(n).



#include<stdio.h>
int linear_search(int arr[],int element ,int size )
{
    for(int i = 0 ; i < size ;i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
       
    }
    return -1;
}
int main ()
{
 int arr[100] = {1,23,4,5,6,765,4,6,67,78,766,5,4,3};
 int size = sizeof(arr)/sizeof(int);
 int element = 765;
 int result = linear_search(arr,element,size);
    
    if(result >= 0) 
    {
        printf("element %d found at %d th index",element,result);
    }
    if(result == -1)
    {
         printf("element not found !!!");
    }
 
}