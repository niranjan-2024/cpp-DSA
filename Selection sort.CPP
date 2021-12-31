#include<iostream>
using namespace std;

void swap(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

void printArray(int array[], int size){
   for(int i = 0; i<size;i++){
      cout << array[i]<<" ";
   }
   cout<< endl;
}

void selectionsort(int array[], int size){
   for(int i = 0;i<size-1;i++){
      int min= i;
      for(int j=i+1;j<size;j++){
         if(array[j]<array[min]){
            min = j;
         }
         
      }
      swap(&array[min],&array[i]);
   }
}
int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionsort(data, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);
}




