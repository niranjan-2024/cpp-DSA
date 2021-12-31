#include<bits/stdc++.h>
using namespace std;

void bubblesort(int array[], int size){
   for(int i = 0; i < size; i++){
      for(int j =  0; j <size-i;j++){
         if(array[j]>array[j+1]){
            int temp = array[j];
            array[j]=array[j+1];
            array[j + 1]= temp;
         }
      }
   }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9, -1, -105, 99, 657};
  int size = sizeof(data) / sizeof(data[0]);
  bubblesort(data, size);
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}
