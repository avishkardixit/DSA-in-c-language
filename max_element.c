 #include<stdio.h>
 int main()
 {

int arr[] ={1,2,5678};
int size = 3;
 int max_element = 0;
 int i,j;
    for( i = 0 ; i < size ; i++)
    {
        if(arr[i]>max_element)
        {
           max_element = arr[i];
        }
    }
    
    printf("%d",max_element);
}