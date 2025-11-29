#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H
#define MAXSIZE 100

namespace SequentialList {
    template<typename T>
    struct SqList{
        T data[MAXSIZE];
        int length;
    };
    template<typename T>
    void CreateList(SqList<T> **L,T a[],int n);
    template<typename T>
    void InitList(SqList<T> **L);
    template<typename T>
    void DestroyList(SqList<T> **L);
    template<typename T>
    int ListEmpty(SqList<T> *L);
    template<typename T>
    int ListLength(SqList<T> *L);
    template<typename T>
    void DispList(SqList<T> *L);
    template<typename T>
    int GetElem(SqList<T> *L,int i,T* e);
    template<typename T>
    int LocateElem(SqList<T> *L,T e);
    template<typename T>
    int ListInsert(SqList<T>** L,int i,T e);
    template<typename  T>
    int ListDelete(SqList<T>** L,int i,T* e) ;
}

#endif //SEQUENTIALLIST_H
