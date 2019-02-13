#ifndef SORT_H
#define SORT_H
/*
 * Sort.h
 * Name:
 *
 * November 2015
 */

#include <vector>
#include <string.h> 
#include <iostream>
#include <algorithm>


using namespace std;


bool checkInitialSize(vector<int> data){
  if(data.size() <= 1){
    return true;
  }
  return false;
}

bool isSorted(vector<int> data){
  if(checkInitialSize(data)){
    return true;
  }
  
  for (unsigned int i = 0 ; i < data.size() - 1; i++){
    if(data[i]>data[i+1]){
      return false;
    }
  }
  return true;
}

void bubbleSort(vector<int>& data){
  if(isSorted(data)){
    return;
  }
 
  bool is_switched = true;
  while(is_switched){
    is_switched = false;
    for (unsigned int i = 0; i < data.size()-1; i++){
      if (data[i] > data[i+1] ){
        swap(data[i], data[i + 1]);
        is_switched = true;
      }
    }
  }
}


void selectionSort(vector<int>& data){ 
  if(isSorted(data)){
    return;
  }
  
  for (unsigned int i = 0; i < data.size(); i ++){ 
    for (unsigned int j = i +1;  j < data.size(); j ++){// start at the next value and check it
      if(data[i] > data[j]){
        swap(data[i], data[j]);
      }
    }
  }
} 


void mergeSort(vector<int>& data){ // divide into two halfs
  if(isSorted(data)){
    return;
  }
  
  vector<int> fir(data.begin(), data.begin() + data.size()/2);
  vector<int> las(data.begin() + data.size()/2, data.end());
  
  sort(fir.begin(), fir.begin() + fir.size());
  sort(las.begin(), las.begin() + las.size());
  merge(fir.begin(), fir.begin() + fir.size(), las.begin(), las.begin() + las.size(), data.begin());
}

void recursiveQuickSort(int index_begin, int index_end, vector<int>& data){ // passed by reference from quickSort(& data)
  int i = index_begin;
  int j = index_end;
  int middle = data[(index_begin + index_end) / 2];
  while(i <= j){
    while(data[i] < middle){
      i++;
    }
    while (data[j] > middle){
      j--;
    }
    if(i <= j){
      swap(data[i], data[j]);
      i++;
      j--;
    }
  }
  if (index_begin < j){
        recursiveQuickSort(index_begin, j, data); // recall because left side is not done
  }
  if (i < index_end){
        recursiveQuickSort(i, index_end, data); // recall because right side is not done
  }
}

void quickSort(vector<int>& data){
  if(isSorted(data)){
    return;
  }
  recursiveQuickSort(0, data.size() -1, data); // does not work; update, fixed
}

void heapSort(vector<int>& data){
  if(isSorted(data)){
    return;
  }
  make_heap(data.begin(), data.end());
  sort_heap(data.begin(), data.end());
}

int getMax(vector<int> data){
  int max = data[0];
  for (unsigned int i = 0 ; i < data.size(); i ++){
    if(data[i]>= max){
      max = data[i];
    }
  }
  return max;
}


void nonCompareSort(vector<int>& data){
  int max = 0;
  for(unsigned int i = 0; i < data.size(); i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  vector<int>temp(max, 0);
  for(unsigned int i = 0; i < data.size(); i++){
    temp[data[i]]++;
  }
  unsigned int count = 0;
  unsigned int index = 0;
  while(index < data.size()){
    if(temp[count] > 0){
      data[index] = count;
      temp[count]--;
      index++;
    }else{
      count++;
    }
  }
}

void mergeSort2(vector<int>& data){
  if(isSorted(data)){
    return;
  }
  
  vector<int> fir(data.begin(), data.begin() + data.size()/2);
  vector<int> las(data.begin() + data.size()/2, data.end());
  
  sort(fir.begin(), fir.begin() + fir.size());
  sort(las.begin(), las.begin() + las.size());
  merge(fir.begin(), fir.begin() + fir.size(), las.begin(), las.begin() + las.size(), data.begin());
  
}

#endif
