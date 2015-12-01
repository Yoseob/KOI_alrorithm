//
//  숫자카드.cpp
//  알고리즘
//
//  Created by LeeYoseob on 2015. 10. 15..
//  Copyright © 2015년 LeeYoseob. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Point{
public:
    int i, j;
    Point(){}
    Point(int i , int j): i(i) , j(j){}
};
int pos[5];
vector<Point> shops;
int map[101][101];
int visited[101][101];
int w, h;
int numberOfShop;
vector<int> result;
Point myPoint;

int dxdy[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
void setMap(){
    for (int i = 0; i <= w; i++) map[0][i] = -1;
    for (int i = 0; i <= h; i++) map[i][0] = -1;
    for (int i = 0; i <= w; i++) map[h][i] = -1;
    for (int i = 0; i <= h; i++) map[i][w] = -1;
    
}
void init(){
    cin >> w >> h;
    cin >> numberOfShop;
    pos[1] = pos[3] = 0;
    pos[2] = h;
    pos[4] = w;
    memset(map, 0, sizeof(map));
    memset(visited , 0 ,sizeof(visited));
    
    for (int i = 0; i < 100; i++){
        result.push_back(999);
    }
    
    setMap();
    
    int ti, tj;
    for (int i = 0; i <=numberOfShop; i++){
        cin >> ti >> tj;
        
        
        if (ti == 1 || ti == 2 ){
            shops.push_back(Point(pos[ti] ,tj));
//            		map[pos[ti]][tj] = i + 1;
        }
        else if(ti == 3 || ti == 4){
            shops.push_back(Point(tj , pos[ti]));
//            	map[tj][pos[ti]] = i + 1;
        }
        
        if (i == numberOfShop){
            myPoint = shops.back();

//            		map[myPoint.i][myPoint.j] = 9;
        }
        
    }
    

    for (int i = 0; i <= h; i++){
        for (int j = 0; j <= w; j++){
//            cout << map[i][j];
        }
//        cout << endl;
    }
}

void dfs(Point p , Point dest , int depth , int len){
    if (p.i == dest.i && p.j == dest.j){
        
        if (result[len] > depth){
            result[len] = depth;
        }

        return;
    }
    int ap = 1;
    if ((p.i == 0 && p.j == 0) || (p.i == h && p.j == w) || (p.i == h && p.j == 0) || (p.i == 0 && p.j == w)){
//        ap = 2;
    }
    visited[p.i][p.j] = 1;
    int di, dj;
    for (int i = 0; i < 4; i++){
        di = dxdy[i][0] + p.i;
        dj = dxdy[i][1] + p.j;
        if (map[di][dj] == -1 && visited[di][dj] == 0){
            dfs(Point(di, dj), dest, depth + ap, len );
        }
    }
}

void find(){
    Point shop;
    for (int i = 0; i < shops.size()-1; i++){
        shop = shops[i];
        
        dfs(myPoint ,shop , 0,i+1);
        memset(visited, 0, sizeof(visited));
    }
    int ret = 0;
    for (int i = 1; i <shops.size(); i++){
        ret += result[i];
    }
    cout << ret << endl;
}
int main(){
    init();
    find();
    
    
}
/*
 
 10 5
	3
	1 4
	3 2
	2 8
	2 3
 */
#if 0
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int input;
int numbers[100];

vector<string> abled;
vector<int> v;
int intSize(int a){
    int c = 0;
    while (a) {
        a/=10;
        c++;
    }
    return  c;
}

void init(){
    memset(numbers, 0, sizeof(numbers));
    input = 0;
    

    cin >> input;

    
    int size = intSize(input);
    int temp =0;
    int t = pow(10, size-1);
    v.push_back(0);


    while (input) {
        temp = input/t;
        input%=t;
        t/=10;
        v.push_back(temp);
    }
    

    
    
}

bool isValidate(int str){
    return (str <=34);
    
}

bool iToa(int i , int j){
    if(i == 0){
        return false;
    }
    int ret = i * 10;
    ret+=j;
    if(isValidate(ret)){
        return true;
    }
    return  false;

}




void findAbleCase(){
    //1개의 셋트를 찾는경우
    
    int table[100];
    int cache[100];


    int n = 0;
   for(int i = 1 ; i <=v.size(); i ++ , n++){
       if(v[i] == 0){
           numbers[n] = 0;
       }else{
           numbers[n] =1;
       }
        if(iToa(v[i-1], v[i])){
            table[n] = 1;
        }else{
            table[n] = 0;
        }
    }

    cache[0] = 1;
    cache[1] = 1;



    

    
    for(int i = 1 ; i<n; i ++){
        cout <<numbers[i] <<endl;
        cache[i] = ((cache[i-2] * table[i]) +  (numbers[i] *cache[i-1]));

    }
    
    for(int j = 0 ; j<n; j ++){
//        cout << cache[j] << " " << table[j] <<" " <<numbers[j] <<endl;
        
    }
    n--;
    cout << cache[n-1] <<endl;
}


int main(){
    init();
    findAbleCase();

}
#endif