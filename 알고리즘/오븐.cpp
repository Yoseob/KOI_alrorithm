#if 0

#include <iostream>
using namespace std;

int main(){
    
    int h,m;
    int time;
    
    cin >> h >> m;
    cin >> time;
    
    int tempm = time%60;
    int temph = time/60;
    
    
    h+=temph;
    m+=tempm;
    
    h +=(m/60);
    m = (m%60);
    
    h = h%24;
    cout << h<<" " << m;
    
}
#endif