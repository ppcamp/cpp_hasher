#pragma once
namespace hasher
{
    class Copilot
    {
    public:
        Copilot();
        ~Copilot();
        void insert(int key, int value);
        void remove(int key);
        int get(int key);

        // int &operator=(int rhs)
        // {
        //     return m_element[rhs];
        // }
        // int &operator[](const int key)
        // {
        //     return get(key);
        // }

        void print();

    private:
        int size;
        int capacity;
        int *keys;
        int *values;
        int hash(int key);
        void resize();
    };

#define BucketCntBits 3
#define BucketCnt (1 << BucketCntBits)

#define LoadFactorNum 13
#define LoadFactorDen 2

    class HashTable
    {
    private:
    public:
        HashTable();
        ~HashTable();
    };
}
