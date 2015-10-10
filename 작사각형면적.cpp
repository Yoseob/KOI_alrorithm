#if 0
//
//  main.cpp
//  algorism
//
//  Created by LeeYoseob on 2014. 11. 3..
//  Copyright (c) 2014&#65533;&#65533; LeeYoseob. All rights reserved.
//



#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;
int arr[5] = {6,3,2,8,5};
int heigh , row;

void mSwap(int a , int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int mpartition(int left , int right){
    int pivot = arr[left];
    int cursor = left;
    for(int i = left+1; i<=right; i++ ){
        if(arr[i] < pivot){
            
            mSwap(i, ++cursor);
        }else{
            
        }
    }
    mSwap(left, cursor);
    return cursor;
}
void mqsort(int a , int b){
    if(a<b){
        int pivot = mpartition(a, b);
        mqsort(a,pivot-1);
        mqsort(pivot+1, b);
    }
}


int vs(int len , int data){
    
    heigh = len;
    row = 0;
    int mid =0;
    while (row <= heigh) {
        mid = (heigh + row)/2;
        if(data > arr[mid]){
            row = mid+1;
        }else if (data<arr[mid]) {
            heigh =mid-1;
        }else{
            return mid;
        }
    }
    
    
    return mid;
}
int smap[10] = {1,2,3,4,5,6,7,8,9,10};
void removemm(int s , int end){
    
    
    for(int i = s ; i < end; i ++){
        smap[i] = -1;
    }
}

int main(){
    
    for(int i = 0; i < 5; cout << arr[i++]);
    mqsort(0, 4);
    cout << endl;
    for(int i = 0; i < 5; cout << arr[i++]);
    
}
#endif