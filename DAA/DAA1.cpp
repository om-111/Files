#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void swap(int *a, int *b) {int t = *a;*a = *b;*b = t;}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {swap(arr[i], arr[largest]);heapify(arr, n, largest);};   
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {swap(arr[0], arr[i]);heapify(arr, i, 0);}
}
void merge(int A[],int p, int q,int r)     
{
    int n1=q-p+1,n2=r-q,i,j,k,L[n1],R[n2];
    for(i=0;i<n1;i++) L[i]=A[p+i];
    for(j=0;j<n2;j++) R[j]=A[q+j+1];
    i=0,j=0;
    for(k=p;i<n1&&j<n2;k++)
    L[i]<R[j] ? A[k]=L[i++] : A[k]=R[j++];
    while(i<n1) A[k++]=L[i++];
    while(j<n2) A[k++]=R[j++];
}
void mergeSort(int A[],int p,int r)    
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
auto timing = [](auto && F, auto && ... params)
{
    auto start = std::chrono::steady_clock::now();
    std::forward<decltype(F)>(F)
    (std::forward<decltype(params)>(params)...);
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count()*0.0000001;
};

int main() {
    srand(1);
    int value;
    ofstream file ("numbers.csv");
    int i = 0,size=10000;
    std::vector<int> data,temp1,temp2,temp3;
    while (i < size)
    {
        value = rand();
        file << value%size << ',';
        data.push_back(value%size);
        i++;
    }
    i=50;
    while (i<=size)
    {
    	temp1={data.begin(),data.begin()+i};temp2=temp1;temp3=temp2;
	int* dt1=&temp1[0];int* dt2=&temp2[0];int* dt3=&temp3[0];
	cout<<i<<",";
	cout<<timing(quickSort,dt1,0,i-1)<<",";
	cout<<timing(mergeSort,dt2,0,i-1)<<",";
	cout<<timing(heapSort,dt3,i-1)<<endl;
	i=i+50;
    }
    file.close();
}
