
#ifndef STACK_H
#define STACK_H
#include "Vector.hpp"
template<class T>
class Stack: private Vector<T>{
    public:
        void push(const T& t);
        void pop();
        bool is_empty();
        /*T& operator[](std::size_t index);
        const T& operator[](std::size_t index)const;*/
    
    private:
        int m_sp{0};
};

#endif //Vector