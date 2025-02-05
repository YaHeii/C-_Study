#pragma once
#include <iostream>
#include <stdexcept> // 用于 out_of_range 异常
using namespace std;

template<class T>
class myArray {
public:
    // 有参构造
    myArray(int capacity) {
        if (capacity <= 0) {
            throw invalid_argument("容量必须大于0");
        }
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];//需要T类型必须有默认构造函数
    }

    // 拷贝构造函数
    myArray(const myArray& p) {
        this->m_Capacity = p.m_Capacity;
        this->m_Size = p.m_Size;
        this->pAddress = new T[this->m_Capacity];

        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = p.pAddress[i];
        }
    }

    // 赋值运算符重载
    myArray& operator=(const myArray& p) {
        if (this == &p) return *this; // 避免自赋值

        // 释放原有空间
        delete[] this->pAddress;

        // 重新分配空间
        this->m_Capacity = p.m_Capacity;
        this->m_Size = p.m_Size;
        this->pAddress = new T[this->m_Capacity];

        // 复制数据
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = p.pAddress[i];
        }
        return *this;
    }

    // 尾部插入
    void Push_Back(const T& val) {
        if (this->m_Size >= this->m_Capacity) {
            cout << "数组已满" << endl;
            return;
        }
        this->pAddress[this->m_Size++] = val;
    }

    // 删除最后一个元素
    void Pop_Back() {
        if (m_Size == 0) {
            cout << "数组为空" << endl;
            return;
        }
        this->m_Size--; // 伪删除
    }

    // 重载[]运算符
    T& operator[](int index) {
        if (index < 0 || index >= m_Size) {
            throw out_of_range("索引超出范围");
        }
        return this->pAddress[index];
    }

    // 获取容量
    int getCapacity() const {
        return this->m_Capacity;
    }

    // 获取当前大小
    int getSize() const {
        return this->m_Size;
    }

    // 析构函数
    ~myArray() {
        delete[] this->pAddress; // delete[] NULL 是安全的
    }

private:
    T* pAddress; // 指针，指向动态分配的数组
    int m_Capacity; // 数组容量
    int m_Size; // 当前元素个数
};
