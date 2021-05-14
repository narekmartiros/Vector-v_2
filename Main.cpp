#include<iostream>
template<class T>

class Vector{
public:

Vector();
virtual ~Vector();
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


template<class T>
void display_vector(Vector<T> &vec);

int main(){

Vector<int> v;
Vector<std::string> v1;
Vector<int> v2;
Stack<int> st;
st.push(5);


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

v2.remove(2);
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



