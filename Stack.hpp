#include "Stack.h"
//#include "Vector.h"
//#include "Vector.cpp"


template<class T>
void Stack<T>::push(const T& t){   
    Vector<T>::push_back(t);
    ++m_sp;
    }

template<class T>
void Stack<T>::pop(){
    --m_sp;
    }

template<class T>
bool Stack<T>::is_empty(){
    return (this.m_sp==0)?true:false;
}

/*template<class T>
T& Stack<T>::operator[](std::size_t index){
    return this[index];
}

template<class T>
const T& Stack<T>::operator[](std::size_t index)const{
    return this[index];
}
*/