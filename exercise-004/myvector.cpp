#include "myvector.hpp"
#include <fmt/format.h>


#include <algorithm>
#include <iterator>

MyVector::MyVector() : m_size(0){
    fmt::println("[MyVector] welcome to the CTOR!");
    m_data = nullptr;
}

MyVector::MyVector(size_t size) : m_size(size) {
    fmt::println("[MyVector] welcome to the size CTOR!");
    m_data = new int[size];
}


MyVector::~MyVector() {
    fmt::println("[MyVector] welcome to the DTOR!");
    if(m_data != nullptr) {
        delete [] m_data;
    }
    
}

size_t MyVector::size() {
    //fmt::println("[MyVector] welcome to the size method");
    return m_size;
}

void MyVector::push_back(int& elem) {
   resize(m_size+1);
   m_data[m_size-1] = elem;
}

void MyVector::push_back(int* elem) {
    push_back(*elem);
}

int& MyVector::at(size_t idx) {
    if( idx  >= m_size )
    {
        throw std::out_of_range ("Invalid idx");
    }
    return m_data[idx];
}

void MyVector::resize(size_t new_size) {
    int* tmp = nullptr;
    size_t to_copy = 0;
    if(new_size == m_size) {
        return;
    } else if(new_size < m_size) {
        tmp = new int[new_size];
        to_copy = new_size;
    } else {
        tmp = new int[new_size];
        to_copy = m_size;
        for (int i = 0; i < new_size; i++){
            int a;
            tmp[i] = a;
        }
    }
    if( m_data == nullptr) {
        m_data = tmp;
        m_size = new_size;
        return;
    }
    std::copy(m_data,m_data+to_copy,tmp);
    delete [] m_data;
    m_data = tmp;
    m_size = new_size;
}