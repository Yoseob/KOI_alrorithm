#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Label;
int n,m,t,k;
vector<Label> ilabel;
vector<Label> jlabel;


class Point{
public:
    int i ;
    int j ;
    Point(int i , int j) : i(i) , j(j){}
    
};
vector<Point> points;
class Label{
public:
    int value;
    int idx;
    Label():value(0),idx(0){}
    Label(int v , int i) : value(v),idx(i){
    }
    
};
bool isLager(const Label &l1 , const Label & l2){
    return l1.value <l2.value;
}
void init(){
    cin >> n >> m >> t >> k;
    
    int pi , pj ;
    for(int i = 1; i <=t ; i ++){
        cin >> pj >> pi;
        ilabel.push_back(Label(pi , i));
        jlabel.push_back(Label(pj , i));
        points.push_back(Point(pi, pj));
    }
    
    sort(jlabel.begin(), jlabel.end(), isLager);
    sort(ilabel.begin(), ilabel.end(), isLager);
}

void implFind(int i /* <-iter */, int j){
    
    
}

bool isBoudry(int i , int j , Point p){
    return ( p.i >=i && p.i <= i +k && p.j >= j && p.j <=j+k);
}

void findPointInK(){
    
    Label il;
    Label jl;
    Point mp(0,0);
    int maxCount = 0;
    int count = 0;
    for(int i = 0 ; i < ilabel.size(); i ++ ){
        
        for(int j = 0 ; j <= jlabel.size()  ; j ++ ){
            count = 0;
            for(int p = 0; p<= points.size(); p++ ){
                if(isBoudry(i,j,points[p])){
                    count++;
                }
            }
            if(count > maxCount){
                mp = Point(i,j);
                maxCount = count;
            }
        }
        
    }
    cout << mp.j<<" " << mp.i+k <<endl;
    cout <<maxCount<<endl;
    
    
}

int main(){
    
    init();
    findPointInK();
}
#endif