//abstracted data type :
//                      so in thise topic we are making our custom array wich can easily
//                      perform our requred operations it is a simple array but with differnt 
//                      capabilities 

// so for that we use a structure to create array which will store total size , used size and 
// base address of our array

#include<stdio.h>
#include<stdlib.h>

struct myarray//these the structure  for getting the array
{
int total_size;
int used_size;
int *ptr;
};

// now below we hafd created the function to create the array when it called in main it will
// give the total size , used size and base address as input .
int CreateArray( struct myarray *a ,int T_size,int U_size)
{
   (*a).total_size = T_size;
   (*a).used_size = U_size;
   (*a).ptr = (int *)malloc(T_size * sizeof(int) );
}

//these function will fill the values in array
int fill_array(struct myarray *a)
{   int n;
    for(int i = 0 ; i < (*a).used_size ; i++)
    {
            printf("%d) enter number :",i+1);
            scanf("%d",&n);
            (*a).ptr[i]= n;
    }
}

//these function will show the array 
int show_array(struct myarray *a)
{
    for(int i = 0 ; i < (*a).used_size ; i++)
    {
        printf("%d\n",(*a).ptr[i]);
    }

}

//these function will increase the size of array
int addmore(struct myarray *a)
{
    int n;
    for(int i = (*a).used_size ; i < (*a).total_size ; i++)
    {
        printf("%d) enter number :",i+1);
        scanf("%d",&n);
         (*a).ptr[i]= n;
    }
}

//these function will print full array with increased size 
int showfullarray(struct myarray *a)
{
     for(int i = 0 ; i < (*a).total_size ; i++)
    {
        printf("%d\n",(*a).ptr[i]);
    }
}


int main()
{
    struct myarray f_arr;
    CreateArray(&f_arr,10,3);
    fill_array(&f_arr);
    show_array(&f_arr);
    addmore(&f_arr);
    showfullarray(&f_arr);

}