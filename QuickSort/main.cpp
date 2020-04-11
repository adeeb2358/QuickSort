//
//  main.cpp
//  QuickSort
//
//  Created by adeeb mohammed on 05/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
// time complexity o(nlogn) average and best worst o(n2)
// space complexity o(logn) avrg best and worst
// choosing pivot mcechanism


#include <iostream>
#include <vector>

void swap(int fromIdx, int toIdx, std::vector<int> &array){
    int temp = array.at(fromIdx);
    array.at(fromIdx) = array.at(toIdx);
    array.at(toIdx) = temp;
}

void quickSortHelper(int startIdx, int endIdx, std::vector<int> &array){
    if(endIdx <=  startIdx){
        return;
    }
    int pivot = startIdx;
    int leftIdx = startIdx+1;
    int rightIdx = endIdx;
    while (leftIdx <=  rightIdx) {
        if(array.at(leftIdx) > array.at(pivot) && array.at(rightIdx) < array.at(pivot)){
            swap(leftIdx, rightIdx, array);
        }
        if (array.at(leftIdx) <= array.at(pivot)) {
            leftIdx++;
        }
        if (array.at(rightIdx) >= array.at(pivot)) {
            rightIdx--;
        }
    }
    swap(pivot, rightIdx, array);
    bool isLeftArraySmallaer = (rightIdx-1-startIdx) < (endIdx - rightIdx + 1) ? true:false;
    if (isLeftArraySmallaer) {
        quickSortHelper(startIdx, rightIdx - 1, array);
        quickSortHelper(rightIdx + 1 , endIdx, array);
    }else{
        quickSortHelper(rightIdx+1, endIdx, array);
        quickSortHelper(startIdx, rightIdx - 1, array);
    }
}

std::vector<int> quickSort(std::vector<int> array){
    quickSortHelper(0, (int)array.size() - 1, array);
    return array;
}

int main(){
    std::cout << "quickosrt implementation" << std::endl;
    std::vector<int> array = {1223,-1,-0,676,1,-282828,89};
    auto result = quickSort(array);
    for(auto num : result){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
