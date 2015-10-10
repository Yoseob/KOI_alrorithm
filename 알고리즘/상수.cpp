#if 0
#include <iostream>
using namespace std;

int reverse_number(int num){
    int ret = num%10;
    ret *=10;
    num/=10;
    while (num > 0) {
        ret += num%10;
        num/=10;
        ret *=10;
    }
    ret/=10;
    return ret;
}
int main(){
    
    int a,b ;
    cin >>a>>b;
    
    int tempa = reverse_number(a);
    int tempb = reverse_number(b);
    int ret = tempa > tempb ? tempa : tempb;
    cout << ret <<endl;
}
#endif