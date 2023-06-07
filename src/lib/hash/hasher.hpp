#pragma once
namespace hasher
{
#define CAPACITY 5000

    class Basic
    {
    public:
        Basic();
        ~Basic();
        void print();

        int &operator=(int rhs)
        {
            return m_element[rhs];
        }
        int &operator[](const int index)
        {
            return m_element[index];
        }

    private:
        unsigned long hash_function(char *str);
        int m_element[10];
    };
}
