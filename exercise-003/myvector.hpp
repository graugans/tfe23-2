#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>
class MyVector {

public:
    MyVector();
    MyVector(std::size_t size);
    ~MyVector();
    std::size_t size();
    int& at(std::size_t idx);
    void push_back(int& elem);
    void push_back(int* elem);
    void resize(size_t new_size);

private:
    int* m_data;
    std::size_t m_size;
};


#endif /* MY_VECTOR_HPP */