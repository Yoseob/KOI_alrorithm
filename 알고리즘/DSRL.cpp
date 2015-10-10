#if 0
#include <iostream>
#include <math.h>
#include <queue>
#include <map>
#include <string>
#include <string.h>

using namespace std;
class PathNumber{
public:
    int a;
    string s;
    
    PathNumber(int a , string s) : a(a), s(s){}
    PathNumber(int a ) : a(a){
        s= "";
    }
    PathNumber():a(0){}
    
};
map<int,char> oper;
queue<PathNumber> q;
int cache[100000] = {0,};
void  init( int & a , int & b){
    
    
    memset(cache, 0, sizeof(cache));
    while (!q.empty()) {
        q.pop();
    }
    cin >> a>>b;
    
}



int D(int  a){
    a = (a*2) % 10000;
    return a;
}
int S(int a){
    a = a-1;
    if(a < 0){
        a = 9999;
    }
    return a;
}
int L(int num){
    int temp ;
    temp = num / 1000;
    num = (num - temp * 1000) * 10 + temp;
    return num;
}
int R(int num){
    
    int temp;
    temp = num % 10;
    num = (num / 10) + temp * 1000;
    return num;
}

int (*arr[])(int) = {D,S,L,R};

void aTob(int start, int end){
    
    
    q.push(PathNumber(start ,""));
    
    
    cache[start] = 1;
    
    PathNumber crnt;
    string ts;
    while (!q.empty()) {
        crnt = q.front(); q.pop();
        if(crnt.a == end){
            cout << crnt.s <<endl;
            return;
            
        }
        for(int i = 0 ; i < 4; i++){
            
            int next  =(*arr[i])(crnt.a);
            if(cache[next] ==0){
                cache[next] = 1;
                ts = crnt.s;
                ts.append(&oper[i]);
                PathNumber nextPath(next ,ts);
                q.push(nextPath);
            }
        }
        
    }
    
}

int main(){
    int tc;
    cin >> tc;
    
    oper[0] = 'D';
    oper[1] = 'S';
    oper[2] = 'L';
    oper[3] = 'R';
    
    while (tc--) {
        int a ,b;
        init(a,b);
        aTob(a,b);
    }
    
}


#endif
