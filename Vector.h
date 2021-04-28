
#include<iostream>
template<class T>
class Vector{

public:

Vector();
~Vector();
Vector(const Vector<T>& vec);
Vector& operator=(const Vector<T>& vec);
const T& operator[](int index)const;
T& operator[](int index);
void push_back(const T& elem);
void push_front(const T& elem);
void remove(int index);
int capacity() const;
int size() const;

private:
int m_size;
int m_cap;
T* m_pt;

};
