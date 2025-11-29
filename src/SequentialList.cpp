#include <iostream>
#include "SequentialList/SequentialList.h"
using namespace SequentialList;

template<typename T>
void CreateList(SqList<T> **L,T a[],int n){
    int k=0;
    (*L)=(SqList<T>*)malloc(sizeof(SqList<T>));
    for (int i=0;i<n;i++) {
        L->data[i]=a[i];
        k++;
    }
    (*L)->length=k;
}

template<typename T>
void InitList(SqList<T> **L) {
    (*L)=(SqList<T>*)malloc(sizeof(SqList<T>));
    (*L)->length=0;
}

template<typename T>
void DestroyList(SqList<T> **L) {
    free(*L);
}

template<typename T>
int ListEmpty(SqList<T> *L) {
    return L->length==0;
}

template<typename T>
int ListLength(SqList<T> *L) {
    return L->length;
}

template<typename T>
void DispList(SqList<T> *L) {
    for (int i=0;i<L->length;i++) {
        std::cout<<L->data[i]<<" ";
        printf("\n");
    }
}

//获取第i个元素的值,不是下标
template<typename T>
int GetElem(SqList<T> *L,int i,T* e) {
    if (i<1 || i>L->length) {
        return 0;
    }
    (*e)=L->data[i-1];
    return 1;
}

template<typename T>
int LocateElem(SqList<T> *L,T e) {
    for (int i=0;i<L->length;i++) {
        if (L->data[i]==e) {
            return i+1;
        }
    }
    return 0;
}

template<typename T>
int ListInsert(SqList<T>** L,int i,T e) {
    //i-1为目标下标
    if (i<1 || i>(*L)->length+1 || (*L)->length>=MAXSIZE) {
        return 0;
    }
    for (int j=(*L)->length-1;j>=i-1;--j) {
        (*L)->data[j+1]=(*L)->data[j];
    }
    (*L)->data[i-1]=e;
    (*L)->length++;
    return 1;
}

template<typename  T>
int ListDelete(SqList<T>** L,int i,T* e) {
    //i-1为目标下标
    if (i-1<0 || i-1>(*L)->length-1 || (*L)->length<=0) {
        return 0;
    }
    (*e)=(*L)->data[i-1];
    for (int j=i-1;j<(*L)->length;j++) {
        (*L)->data[j]=(*L)->data[j+1];
    }
    (*L)->length--;
    return 1;
}



