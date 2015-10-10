#if 0
#include <iostream>
#include <queue>

using namespace std;


class Point{
public:
    int i;
    int j ;
    int h;
    Point():i(0), j(0), h(0){}
    Point(int i , int j , int h):i(i) ,j(j),h(h){}
    
};
queue<Point> q;
int dxdy[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int dhs[2] = {1,-1};
int box[101][101][101] = {0,};
int visit[101][101][101] = {0,};
int m,n,h;
int resultMix =0;

int init(){
    cin >> m >> n >> h;
    
    
    int check = 1;
    int temp;
    for(int k = 1; k<=h;k++){
        for(int i = 1 ; i<=n; i ++){
            for(int j = 1; j<=m; j++){
                cin >> temp;
                if(temp == 0){
                    check = 0;
                }else if(temp == 1){
                    q.push(Point(i,j,k));
                }
                box[k][i][j] = temp;
            }
        }
    }
    
    return check;
}

bool validateBoudry(int i , int j , int k){
    return (i > 0 && i <=n && j >0 && j<= m && k > 0 && k<= h);
}

void bfs(){
    
    int depth = 0;
    while (!q.empty()) {
        
        int di , dj ,dh;
        Point crnt = q.front(); q.pop();
        
        for(int itr = 0; itr < 4; itr ++){
            di = crnt.i + dxdy[itr][0];
            dj = crnt.j + dxdy[itr][1];
            dh = crnt.h;
            if(validateBoudry(di,dj,dh)&&visit[dh][di][dj] == 0 && box[dh][di][dj] == 0 ){
                visit[dh][di][dj] = visit[crnt.h][crnt.i][crnt.j]+1;
                q.push(Point(di, dj, dh));
                
                if(visit[dh][di][dj] >depth){
                    depth = visit[dh][di][dj];
                }
            }
        }
        
        for(int itr = 0; itr < 2; itr ++){
            dh = crnt.h+dhs[itr];
            di = crnt.i;
            dj = crnt.j;
            
            if(validateBoudry(di,dj,dh) && visit[dh][di][dj] == 0 && box[dh][di][dj] == 0 ){
                visit[dh][di][dj] =visit[crnt.h][crnt.i][crnt.j]+1;
                q.push(Point(di, dj, dh));
                if(visit[dh][di][dj] >depth){
                    depth = visit[dh][di][dj];
                }
            }
        }
        
    }
    
    if(resultMix < depth){
        resultMix = depth;
    }
    
}

bool isRemainUnTomato(){
    
    bool ret = false;
    for(int k = 1; k<=h;k++){
        for(int i = 1 ; i<=n; i ++){
            for(int j = 1; j<=m; j++){
                if(box[k][i][j] == 0 && visit[k][i][j] == 0){
                    ret = true;
                    break;
                }
            }
        }
    }
    
    return ret;
    
}



int main(){
    
    if(init()){
        cout << 0 <<endl;
    }else{
        
        bfs();
        
        if(isRemainUnTomato()){
            cout << -1<<endl;
            return 0 ;
        }
        cout << resultMix << endl;
        
    }
    
    
}

/*
 
 
 
 6 6 5
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 -1 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 -1 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 -1 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 -1 -1 -1 -1 -1 -1
 
 
 
 
 */
#endif