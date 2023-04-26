//
// Created by liulei on 2023/4/1.
//

#ifndef CPPTHING_MY_STRING_H
#define CPPTHING_MY_STRING_H

#include <cstddef>

namespace my{
    class string{
    public:
        typedef char *iterator;
    public:
        string(const char *s = "");
        string(const string &str);
        string &operator=(const string &str);
        ~string();

        iterator begin();
        iterator end();

        size_t size() const;
        size_t capacity() const;
        bool empty() const;
        void resize(size_t n,char c = '\0');
        void reserve(size_t n);

        char &operator[](size_t index);
        const char &operator[](size_t index) const;
        friend std::ostream &operator<<(std::ostream &_cout,const string &s);

        void push_back(char c);
        string &operator+=(char c);
        void append(const char* str);
        string &operator+=(const char * str);
        void clear();
        void swap(string &s);
        const char * c_str() const;

        size_t find(char c,size_t pos = 0) const;
        size_t find(const char *s,size_t pos = 0) const;
        string &insert(size_t pos,char c);
        string &insert(size_t pos,const char *str);

        string &erase(size_t pos,size_t len);
    private:
        char *_str;
        size_t _size;
        size_t _capacity;
    };
}

#endif //CPPTHING_MY_STRING_H
