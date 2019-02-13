/*
        Sort Speed
        Paul Talaga
        November 2015
*/
 
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "unistd.h"
#include <cstdlib>
#include <sys/timeb.h>
 
 
#include "MySort.h"
 
using namespace std;
 
 
 
int randomRange(int begin, int end) {
    return (rand() % end) + begin;
}
 
int main(int argc, char* argv[]){
    time_t timer;
    srand (time(NULL));
 
    vector<int> data;
    for (unsigned int i = 0; i < 2000; i += 2) {
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        clock_t start = clock();
        selectionSort(data);
        clock_t end = clock();
        int selectTime = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        bubbleSort(data);
        end = clock();
        int bubbleTime = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        mergeSort(data);
        end = clock();
        int mergeTime = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        mergeSort2(data);
        end = clock();
        int mergeTime2 = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        quickSort(data);
        end = clock();
        int quickTime = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        heapSort(data);
        end = clock();
        int heapTime = end - start;
 
        data.clear();
        for (unsigned int k = 0; k < i; k++) {
            data.push_back(randomRange(0, 700000));
        }
 
        start = clock();
        nonCompareSort(data);
        end = clock();
        int nonTime = end - start;
 
        cout << data.size() << '\t' << selectTime << '\t' << bubbleTime << '\t' << mergeTime << '\t' << mergeTime2 << '\t' << quickTime << '\t' << heapTime << '\t' << nonTime << '\n';
    }
 
}
