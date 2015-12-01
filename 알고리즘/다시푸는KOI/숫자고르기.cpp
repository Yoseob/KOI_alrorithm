#if 0
//
//  숫자고르기.cpp
//  알고리즘
//
//  Created by LeeYoseob on 2015. 10. 14..
//  Copyright © 2015년 LeeYoseob. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int list[101] = {0,};
int size;
void init(){
    memset(list, 0, sizeof(list));
    
    cin >> size;
    for(int i = 1; i<=size; i++){
        cin>>list[i];
    }
    
}

int find(int i){
    int depth = 0;
    int temp = i;
    int begin = i;
    
    while (depth<size) {
        temp = list[temp];
        if(temp == begin){
            return begin;
        }
        depth++;
    }
    
    return  0;
}

void findSameResultNumbers(){
    vector<int> v;
    for(int i = 1; i <=size; i++){
        if(int ret = find(i)){
            v.push_back(ret);
        }
    }
    
    cout << v.size() <<endl;
    for(int i = 0; i < v.size(); i ++){
        cout << v[i] <<endl;
    }
}

int main(){
    init();
    findSameResultNumbers();
}



#endif