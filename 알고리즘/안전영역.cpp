#if 0 

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

int map[101][101] = {0,};
int visit[101][101];
int size, minHeight, maxHeight;

class Point{
public:
    int i;
    int j ;
    Point():i(0), j(0){}
    Point(int i , int j):i(i) ,j(j){}
    
};


int dxdy[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<Point> q;
int maxCount = 0;

void init(){
    
    cin >> size;
    minHeight = 100;
    maxHeight = 0;
    
    
    int input;
    for (int i = 1; i<=size; i++) {
        for(int j = 1; j<=size; j++){
            cin >> input;
            if(input > maxHeight){
                maxHeight = input;
            }else if(input < minHeight){
                minHeight  = input;
            }
            
            map[i][j] = input;
        }
    }
}

void dfs(int i , int j , int height ){
    if(visit[i][j] == 0 && map[i][j] > height &&(i > 0 && i <= size && j>0 && j <=size)){
        visit[i][j] = 1;
        int dx ,dy;
        for(int z = 0 ; z<4; z ++){
            dx = i + dxdy[z][0];
            dy = j + dxdy[z][1];
            dfs(dx, dy, height );
        }
        
    }
}

void bfs(int i , int j , int height){
    
    q.push(Point(i,j));
    
    Point crnt;
    while (!q.empty()) {
        crnt = q.front(); q.pop();
        if(visit[crnt.i][crnt.j] == 0 && map[crnt.i][crnt.j] > height &&(crnt.i > 0 && crnt.i <= size && crnt.j>0 && crnt.j <=size)){
            visit[crnt.i][crnt.j] = 1;
            int dx , dy;
            for(int i = 0 ; i<4; i ++){
                dx = crnt.i + dxdy[i][0];
                dy = crnt.j + dxdy[i][1];
                q.push(Point(dx,dy));
            }
        }
    }
    
}

void findMaxSafeZone(int pivot){
    
    int count = 0;
    for(int i = 1; i <=size; i ++){
        for(int j = 1; j<=size; j ++){
            if(map[i][j] > pivot && visit[i][j] == 0){
                //                bfs(i,j,pivot ,count);
                dfs(i, j, pivot);
                count++;
            }
        }
    }
    
    if(maxCount < count){
        maxCount = count;
    }
    
}

int main(){
    init();
    
    
    for(int i = 0; i <=maxHeight; i++){
        memset(visit, 0, sizeof(visit));
        findMaxSafeZone(i);
    }
    
    cout << maxCount<<endl;
    
}
#endif