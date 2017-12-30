#include<iostream>
#include<string.h>
using namespace std;
//int max(int x,int y){
  //  return x>y ? x :y; if x>y return x else return y
//}
//float max(float x,float y){
  //  return x>y ? x :y;
//}

template<typename T>
T Max(T x,T y){
    cout<<"tipo:"<<typeid(T).name()<<endl;
    return x>y ? x :y;
}
//instancia explicia
//template char Max(char x,char y);

template<> const char * Max<const char*>(const char *x,const char *y) {
    return (strcmp(x,y)>0) ? x : y ;
}
int main(){
    const char *b={"B"};
    const char *a={"A"};
    auto s=max(b,a);
    cout<<"max: "<<s<<endl;
    return  0;
}