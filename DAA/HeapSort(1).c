#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Decalaration of Heap
void Display(int A[],int);
struct Heap
{
 int *array;
 int capacity;
 int count;
 int Heap_Type;
};

//Creating Heap
struct Heap* CreateHeap(int capacity,int Heap_type)
{
 struct Heap *h;
 h = malloc(sizeof(struct Heap));
 if(!h)
  return 0;
 h->Heap_Type = Heap_type;
 h->capacity = capacity;
 h->count = 0;
 h->array = malloc(sizeof(int)*capacity);
 if(!h->array)
  return 0;
 return h;
}

// Parent Node 

int Parent(struct Heap *h, int i)
{
  if(i<=0 || i>=h->count)
    return -1;
  return (i-1)/2;
}

// Children Node

int Left(struct Heap *h,int i)
{
  int left = 2*i + 1;
  if(left >= h->count)
   return -1;
  return left;
}

int Right(struct Heap *h, int i)
{
  int right = 2*i+2;
  if(right>=h->count)
     return -1;
  return right;
}

// Getting the Maximum Element
int GetMaximum(struct Heap *h)
{
 if(h->count ==0)
  return -1;
 return h->array[0];
}

//Heapifying the element

void Percolate(struct Heap *h , int i)
{
 int l,r,max = i,temp;
 l = Left(h,i);
 r = Right(h,i);
 if(l!=-1 && h->array[l]>h->array[i])
   max = l;
 else 
   max = i;
 if(r!=-1 && h->array[r]>h->array[max])
   max = r;
 if(max !=i)
 {
   temp = h->array[i];
   h->array[i] = h->array[max];
   h->array[max] = temp;
   Percolate(h,max);
 }
}

// Build MaxHeap

/*int Build_Heap(struct Heap *h, int A[],int n)
{
 if(h==NULL)
  return 0;
 for(int i=0;i<n;i++)
  h->array[i] = A[i];
 h->count = n;
 for(int i = (n-1)/2 ; i>=0;i--)
  Percolate(h,i);
}*/

void HeapSort(int A[],int n)
{
 int temp,old_size;
 struct Heap *h = CreateHeap(n,1);
 //Building Heap Array
 for(int i=(n-1)/2 ; i>=0;i++)
  Percolate(h,i);
 for(int i=n-1;i>=0 ; i++)
  {
    int temp = h->array[0];
    h->array[0] = h->array[i];
    h->array[i] = temp;
    Percolate(h,i);
  }
}
void Display(int A[],int size)
{
 for(int i=0;i<size ; i++)
  printf("%d  ",A[i]);
 printf("\n\n\n");
}
int main(void)
{
 int *A,size;
 printf("\n Enter Size : ");
 scanf("%d",&size);
 A = malloc(sizeof(int)*size);
 for(int i=0;i<size;i++)
 {
  int r =rand()%size;
  A[i]=r;
 }
 Display(A,size);
 HeapSort(A,size);
 Display(A,size);
 return 0;
}
