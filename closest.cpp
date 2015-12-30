// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <string.h>

using namespace std;
int partition(int* array, int p, int q)
{
    int x = array[p];
    int i = p - 1;
    int j = q + 1;
    int temp;
    do
    {
        do
        {
            j--;
        }while (x >array[j]);
        do
        {
            i++;
        } while (x <array[i]);
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }while (i < j);
    return j;
}

void Quicksort(int* num, int p, int q)
{
    int i;
    if (p < q)
    {
        i = partition(num, p, q);
        Quicksort(num, p, i);
        Quicksort(num, i+1, q);
    }
    return;
}

int main(){
    int n;
    int a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Quicksort(a,0,n-1);
    int min=1000000000;
    for(int i =0;i<n-1;i++){
        if(a[i]-a[i+1]<min){
            min=a[i]-a[i+1];
        }
    }
    cout<<min<<endl;
}
