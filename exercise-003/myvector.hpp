#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

class MyVector {

public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    int size();

private:
    int* m_data;
};


#endif /* MY_VECTOR_HPP */