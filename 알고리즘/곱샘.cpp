#if 0


#include <iostream>
using namespace std;
int calc[6][10]= {0,};
int main(){
    int a,b,temp;
    cin >> a>>b;
    temp = b;
    while (temp) {
        int c = temp%10;
        temp/=10;
        cout <<a *c <<endl;
    }
    cout << a*b <<endl;
    
}

#endif