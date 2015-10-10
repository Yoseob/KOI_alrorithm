#if 0

#include <iostream>
using namespace std;


class Man{
public:
    int weight;
    int height;
    Man(int w , int h): weight(w),height(h){}
    Man(){}
};

Man man[50];
int main(){
    
    int size;
    cin >> size;
    int count = 1;
    
    int w,h;
    for(int i = 0; i<size;i ++ ){
        cin >> w >> h;
        man[i] = Man(w, h);
    }
    
    Man me, you;
    for(int i = 0 ; i<size; i ++){
        me = man[i];
        count = 1;
        for(int j = 0; j<size; j++){
            you  = man[j];
            if(me.height < you.height && me.weight < you.weight){
                count++;
            }
        }
        cout<< count<< " " ;
    }
    
}
#endif