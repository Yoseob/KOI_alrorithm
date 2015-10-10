#if 0

#include <iostream>
using namespace std;

int main(){
    int a ,b,c;
    long long sum = 0;
    cin >> a >>b >>c ;
    sum = a*b*c;
    
    int table[10] ={0,};
    while (sum) {
        table[sum%10]++;
        sum/=10;
    }
    for(int i = 0; i<=9 ; cout << table[i++] <<endl);
    
    return 0;
    
}

#endif