
#include <iostream>
using namespace std;

#if 0  //poweofx
long long pow(int x , int y){
    if(y == 1) return x;
    return x * pow(x,y-1);
}
int main(){
    
    int x , y ;
    cin >> x >> y;
    
    cout <<  pow(x, y) << endl;
    return 0;
}
#endif

#if 0  //euclid
int euclid(int a, int b){
    if(b == 0) return a;
    return euclid(b , a%b);
}
int main(){

    long long a ,b ;
    cin >> a >> b;
    long long gcd = euclid(a,b) ;
    cout << gcd << " " << (a*b)/ gcd  << endl;
}
#endif 

#if 0 //upstair
int goal;
int c;


void updstair(int cnt){

    if(cnt == goal) {
        c++;

     return;
    } else if(cnt > goal){
        return;
    }

    updstair(cnt +1);
    updstair(cnt +2);
}
int main(){

    cin >> goal;
    updstair(0);
    cout<< c <<endl;
}

#endif

#if 0 //sfn
int sfn(int a , int t){
    int temp = a%t;
    if( a<t) return  temp;
    return temp +sfn(a/t , t);
    
}

int main(){
    
    
    int a ,b ,c;
    for(int i = 2992; i <=9999; i ++){
        a = sfn(i, 10); b = sfn(i, 12) , c = sfn(i, 16);
        if(a == b && b == c) cout << i << endl;
        
    }

}

#endif

#if 0 //tobin
int tobin(int a , int t){
    int temp = a%t;

    if( a<t) {
        cout << temp;
        return 0;
    }
    
    tobin(a/2, t) ;
    cout << temp;
    return 0;
    
}

int main(){
    int a;
    cin >> a ;
    tobin(a, 2);
    cout <<endl;
}
#endif


#if 0 //mt
void mt(int a){
    if(a == 1) {
        cout << a;
        return ;
    }
    mt(a-1);
    cout << a;


}
void rmt(int a){
    if(a==1)return ;
    cout << a-1;
    rmt(a-1);
    
}
int main(){
    int s ;
    cin >> s;
    mt(s);
    rmt(s);
    
}
#endif

#if 0 // ptp
void mt(int a){
    
    
    if(a == 1) {
        cout << a;
        return ;
    }
    mt(a-1);
    cout << a;
    mt(a-1);
    
}
int main(){
    int s ;
    cin >> s;
    mt(s);

    
}
#endif

#if 0
int n,k;

int arr[31] = {0,};
int buf[31] = {0,};

void pat(int cnt){

    if(cnt == n){

        for(int i = 0; i <n ; cout << buf[i] , i++);
        cout <<endl;
        return ;
    }
    for(int i =1; i<=2; i++){
        if(i == 2) i = 0;
        if(arr[i] != 0){
            arr[i]--;
            
            buf[cnt] = i;
            pat(cnt+1);
            
            arr[i]++;
        }
        if(i == 0) i =2;
    }

    
}
int main(){
    cin >> n >> k;
    arr[0] = n-k;
    arr[1] = k;
    pat(0);
}

#endif
#if 0
char buf[21];
char arr[10];
int mSize = 0 ;
int total = 0;
void athletic(int a , int oc){
    if(  a == (mSize+mSize-1)){
        total++;
        int toc = 0;
        for(int i = 0; i <mSize+mSize; i++){
            if(buf[i]=='o'){
                toc++;
            }
            cout << buf[i];
            if(toc == 3){
                break;
            }

        }
        cout <<endl;
        return ;
    }
    for(int i =0 ; i<10;i ++){
        if(arr[i] != 0){
            arr[i]--;
            char ch;
            if(i == 0){
                ch = 'o';
                oc++;
            }else{
                ch = 'x';
             
            }
            buf[a] = ch;
            
            athletic(a+1 , oc);
            arr[i]++;
        }
    }
}
int main(){
    cin >> mSize;
    
    arr[0] = mSize;
    arr[1] = mSize-1;
    athletic(0, 0);
    cout <<"total " <<total<< " case(s)" << endl;
}
#endif 