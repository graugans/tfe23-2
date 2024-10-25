#include "myvector.hpp"
#include <fmt/format.h>

MyVector::MyVector() {
    fmt::println("[MyVector] welcome to the CTOR!");
    m_data = nullptr;
}

MyVector::MyVector(unsigned int size) {
    fmt::println("[MyVector] welcome to the size CTOR!");
    m_data = new int[size];
}


MyVector::~MyVector() {
    fmt::println("[MyVector] welcome to the DTOR!");
    if(m_data != nullptr) {
        delete m_data;
    }
    
}

int MyVector::size() {
    fmt::println("[MyVector] welcome to the size method");
    return 0;
}