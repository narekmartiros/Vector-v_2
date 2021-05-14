#include "Stack.h"

template<class T>
void Stack<T>::push(T){   
    this[sp]=T;
    ++m_sp;
    }

template<class T>
void Stack<T>::pop(){
    --m_sp;
    }

template<class T>
bool is_empty(const Stack<T> &){
    return (m_sp==0)?true:false;
}

