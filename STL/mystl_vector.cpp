//
// Created by liulei on 2023/5/4.
//
#include <iostream>
#include <stdexcept>

template<typename T>
class vector {
public:
    vector() : m_size(0), m_capacity(4), m_data(new T[m_capacity]) {}
    ~vector() { delete[] m_data; }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            resize();
        }
        m_data[m_size++] = value;
    }

    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    size_t size() const { return m_size; }

private:
    void resize() {
        m_capacity *= 2;
        T* temp = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            temp[i] = m_data[i];
        }
        delete[] m_data;
        m_data = temp;
    }

    size_t m_size;
    size_t m_capacity;
    T* m_data;
};

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
