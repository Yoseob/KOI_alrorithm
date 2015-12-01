#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

class Point{
public:
    int i , j;
    Point(){}
    Point(int i , int j) :i(i),j(j){}
};

int map[30][30]={0,};
int visit[30][30]={0,};
int size ;
int dxdy[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int cc = 0;
vector<int>v;
queue<Point> q;

void init(){
    v.clear();
    
    memset(map, 0, sizeof(map));
    memset(visit,0,sizeof(visit));
    cin >>size;
    
    char input = 0;
    for(int i = 1;  i<=size; i ++){
        for(int j = 1; j<=size; j++){
            cin >> input;
            if(input == '0'){
                map[i][j] = 0;
            }else{
                map[i][j] = 1;
            }
            
            
        }
    }
    
}

bool isBoundry(int i,int j){
    return (i > 0 && i<=size && j>0 && j<=size);
    
}
void impl(Point p){
    
    q.push(p);
    visit[p.i][p.j] = 1;
    Point crt;
    int count = 1;
    while (!q.empty()) {
        
        crt = q.front(); q.pop();
        int di ,dj;
        for(int i = 0 ; i < 4; i++){
            di = crt.i + dxdy[i][0];
            dj = crt.j +dxdy[i][1];
            if(visit[di][dj]==0 && isBoundry(di,dj)&& map[di][dj] == 1){
                visit[di][dj] = visit[crt.i][crt.j] + 1;
                q.push(Point(di,dj));
                count++;
            }
            
        }
    }
    v.push_back(count);
    
}
bool comp(const int a , const int b){
    return a<b;
}
void printAnswer(){
    sort(v.begin(),v.end() ,comp );
    cout <<v.size() <<endl;
    for(int i = 0 ; i <v.size(); i++){
        cout << v[i] <<endl;
    }
}

void find(){
    for(int i = 1;  i<=size; i ++){
        for(int j = 1; j<=size; j++){
            if(visit[i][j] == 0&& map[i][j] == 1){
                impl(Point(i , j));
            }
        }
    }
    
}

int main(){
    
    init();
    find();
    printAnswer();
    
    
}
#endif