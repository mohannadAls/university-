#include<iostream>
using namespace std;


void Heapify(int t[],int ,int);
void HeapSort(int t[] ,int);


int main()
{
    const int size = 6;
    int arr[size] = {10,8,12,14,6,5};
    HeapSort(arr,size);
    for(int i = 0 ; i <size ; i++)
    {
        cout<<arr[i]<<'\t';
    }

}


void HeapSort(int t[] ,int n)
{
    int parent,last,h;
    parent = n/2;
    last = n-1;

    while(parent >0)
    {
        --parent;
        Heapify(t,parent,last);
    }
    while(last > 0)
    {
        h=t[0];
        t[0]=t[last];
        t[last]=h;
        Heapify(t,0,last);
    }

}

void Heapify(int t[], int parent , int last)
{
int child,h;
child = 2*parent +1;

while(child<= last)
{
    if(child<last)
        if(t[child]>t[child+1])
            ++child;

    if(t[parent]<=t[child])
    {
        child = last +1;
    }
    else{
        h = t[parent];
        t[parent]= t[child];
        t[child]=h;
        child=2*parent +1;
    }      
}
}