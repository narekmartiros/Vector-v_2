#include "Vector.h"
#include<iostream>


// default ctor
template<class T>
Vector<T>::Vector():m_size{0}, m_cap{10},m_pt{new T [m_cap]}{}


// destructor
template<class T>
Vector<T>::~Vector(){
delete [] m_pt;
}

// copy costructor
template<class T>
Vector<T>::Vector(const Vector<T>& vec): m_size{vec.m_size}, m_cap{vec.m_cap},m_pt{new T [m_cap]}{
    for (int i = 0;i < m_size;++i) {
        m_pt[i] = vec.m_pt[i];
    }
}

// assignement operator
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec){
    if(this==&vec){
        return *this;
    }

    m_cap = vec.m_cap;
    m_size = vec.m_size;
    delete[] m_pt;
    m_pt = new T[m_cap];

    for (int i = 0;i < m_size;++i) {
        m_pt[i] = vec.m_pt[i];
    }
    return *this;
}

// [] asignement operator
template<class T>
T& Vector<T>::operator[](int index){
    return m_pt[index];
}

// [] asignement operator const
template<class T>
const T& Vector<T>::operator[](int index)const{
    return m_pt[index];
}

template<class T>
void Vector<T>::push_back(const T& elem){
    
    if(m_size==m_cap){

        m_cap*=2;
        T* tmp=new T[m_cap];
        for(int i=0;i<m_size; ++i){
            tmp[i]=m_pt[i];
        }

        delete [] m_pt;
        m_pt=tmp;
    }

    m_pt[m_size]=elem;
    ++m_size;
};

template<class T>
void Vector<T>::push_front(const T& elem){

    if(m_size==m_cap){
        m_cap*=2;
        T* tmp=new T[m_cap];

        for(int i=0;i<m_size; ++i){
            tmp[i+1]=m_pt[i];
        }
        delete [] m_pt;
        m_pt=tmp;
        
        m_pt[0]=elem;
        ++m_size;
    }
    else if(m_size<m_cap){

        for(int i=m_size;i>0; --i){
            m_pt[i]=m_pt[i-1];
        }
         m_pt[0]=elem;
         ++m_size;
    }
}

template<class T>
void Vector<T>::remove(int index){
    if(index<m_size){
        T*tmp=new T[m_cap];
        int j=0;
        for(int i=0;i<m_size;++i){
            if(j==index){
                ++j;
            }
            tmp[i]=m_pt[j];
            ++j;
        }
        delete [] m_pt;
        m_pt=tmp;
        --m_size;
    }
    else
        std::cout<<"Out of range"<<std::endl;
}

template<class T>
int Vector<T>::capacity() const{
    return m_cap;
}

template <class T>
int Vector<T>::size() const{
return m_size;
};

