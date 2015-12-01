#if 0
#include <iostream>
using namespace std;
int timeTosecond(int h , int m){
    
    return  (3600 * h + 60 * m) - (45*60);
}

void secondToTime(int & h , int & b , int ttime){
    int temph = ttime/3600;
    ttime %= 3600;
    int tempm = ttime/60;
    h = temph;
    b = tempm;
}
int main(){
    int h , m ;
    
    cin >> h >> m;
    
    if(h == 0){
        h= 24;
    }
    int retTime = timeTosecond(h, m);
    int reth = 0 , retm = 0;
    
    secondToTime(reth, retm, retTime);
    cout << reth << " "<< retm <<endl;
    
}
#endif