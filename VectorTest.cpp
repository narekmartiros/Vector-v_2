#include "Vector.cpp"
//#include <iostream>
#include <string>

template<class T>
void display_vector(Vector<T> &vec);

int main(){

Vector<int> v;
Vector<std::string> v1;
Vector<int> v2;

for(int i=0;i<10;++i){
    v.push_back(i);
}

v1.push_back("back");
v1.push_front("front");

std::cout<<v1.size()<<std::endl;
std::cout<<v1.capacity()<<std::endl;

Vector<int> v3(v);

v2=v3;

display_vector(v);
display_vector(v1);
display_vector(v2);
display_vector(v3);

v2.push_front(99);
display_vector(v2);

v2.remove(0);
display_vector(v2);

return 0;
}

template<class T>
void display_vector(Vector<T> &vec){
    for(int i=0; i<vec.size();++i){
        std::cout<<vec[i];
        std::cout<<" ";    
    }
    std::cout<<" "<<std::endl;
}
