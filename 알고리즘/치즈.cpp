#if 0
#include <iostream>
#include <queue>
#include <string.h>
#define O2 2
#define DEL -1

using namespace std;


int map[101][101] = {0,};
int visit[101][101];
int visitforOx[101][101] = {0,};


class Point{
public:
    int i;
    int j ;
    Point():i(0), j(0){}
    Point(int i , int j):i(i) ,j(j){}
    
};

queue<Point> q , oq;


int n,m;
Point start(-1 , -1);
int dxdy[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int cheeseCount = 0;

void init(){
    cin >> n >>m;
    start.i = -1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j<=m; j ++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                cheeseCount++;
            }
            if(start.i == -1 && map[i][j]== 0){
                start.i = i;
                start.j = j;
            }
        }
    }
}


bool isBoundry(int i , int j){
    return (i>0 && i <= n && j>0 && j <= m);
}


void print(){
    cout <<endl;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j<=m; j ++){
            cout << map[i][j]<<" ";
        }
        cout <<endl;
    }
}
void oxygenLabeling(Point s){
    
    memset(visitforOx, 0, sizeof(visitforOx));
    oq.push(s);
    visitforOx[s.i][s.j] = 1;
    map[start.i][start.j] = O2;
    while (!oq.empty()) {
        Point crnt = oq.front(); oq.pop();
        int di ,dj ;
        for(int i = 0 ; i <4; i ++){
            di = crnt.i+dxdy[i][0];
            dj = crnt.j+dxdy[i][1];
            
            if(visitforOx[di][dj]== 0 && map[di][dj] == 0 && isBoundry(di,dj)){
                map[di][dj] = O2;
                visitforOx[di][dj] = visitforOx[crnt.i][crnt.j] +1;
                oq.push(Point(di,dj));
            }
        }
    }
    
}

void checkDeletePoint(int i , int j){
    visit[i][j] = 1;
    q.push(Point(i,j));
    
    Point crnt;
    int di ,dj, oxCount = 0;
    while (!q.empty()) {
        crnt = q.front(); q.pop();
        oxCount = 0;
        for(int i = 0 ; i <4; i ++){
            di = crnt.i + dxdy[i][0];
            dj = crnt.j + dxdy[i][1];
            if(map[di][dj] == O2){
                oxCount ++;
            }
            
            if(map[di][dj] == 1 && visit[di][dj] == 0 && isBoundry(di, dj)){
                visit[di][dj] = visit[di][dj]+1;
                q.push(Point(di,dj));
            }
        }
        if(oxCount >=2){
            map[crnt.i][crnt.j] = DEL;
            
        }
    }
}


void deletePoint(){
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j<=m; j ++){
            if(map[i][j]== DEL){
                map[i][j] = 0;
                cheeseCount--;
            }
        }
    }
    
}


void findDeletePoint(){
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j<=m; j ++){
            if(map[i][j] == 1 && visit[i][j] == 0){
                checkDeletePoint(i, j);
            }
        }
    }
    
    deletePoint();
    
}

void nextStart(){
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j<=m; j ++){
            if( map[i][j] == O2){
                map[i][j] = 0;
            }
        }
    }
    
    
}

int main(){
    init();
    int count = 0;
    
    while (cheeseCount) {
        count++;
        
        oxygenLabeling(start);
        findDeletePoint();
        nextStart();
        
        
        
        
    }
    cout <<count <<endl;
    
}
#endif