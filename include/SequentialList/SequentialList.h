#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H
#include <iostream>

#define MAXSIZE 100
namespace SequentialList {
    template<typename T>
    struct SqList{
        T data[MAXSIZE];
        int length;
    };
    using namespace SequentialList;

    template<typename T>
    void CreateList(SqList<T> **L,T a[],int n){
        int k=0;
        (*L)=(SqList<T>*)malloc(sizeof(SqList<T>));
        for (int i=0;i<n;i++) {
            (*L)->data[i]=a[i];
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
        }
        printf("\n");
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
    void InsertSort(SqList<int>* L) {
        if (L->length==0) {
            printf("Empty\n");
        }
        for (int i=0;i<L->length;i++) {
            //存储要排序的元素
            int temp=L->data[i];
            //从头开始遍历直到下标i-1
            for (int j=i-1;j>=0;j--) {
                //未到插入点,一直往后移
                if (L->data[j]>temp) {
                    L->data[j+1]=L->data[j];
                }else {
                    //元素第一次比它大,即它的上一个待插入的位置
                    L->data[j+1]=temp;
                    break;
                }
                //如果到最后一个元素循环并没有break,则说明它为最小元素,放在首位
                if (j==0) {
                    L->data[j]=temp;
                }
            }
        }
    }
    void BinInsertSort(SqList<int>* L) {
        if (L->length==0) {
            printf("Empty!\n");
        }
        for (int i=0;i<L->length;i++) {
            int left=0,right=i-1,mid,temp=L->data[i];
            //使用拓展的二分查找法,找到最大的小于要temp的数
            while (left<=right) {
                mid=left+(right-left)/2;
                if (L->data[mid]>=temp) {
                    right=mid-1;
                }else {
                    left=mid+1;
                }
            }
            //如果left为i,即说明目前排序的数组中没有数比temp大,不用排序
            if (left==i) {
                continue;
            }
            //left为最后一个比temp大的数的下标
            for (int j=i;j>left;j--) {
                L->data[j]=L->data[j-1];
            }
            L->data[left]=temp;
        }
    }
    void ShellSort(SqList<int>* L) {
        if (L->length==0) {
            printf("Empty!\n");
        }
        //增量为每次除以2
        for (int gap=L->length/2;gap>=1;gap/=2) {
            for (int i=gap;i<L->length;i++) {
                int temp=L->data[i];
                int j=i;
                //不断往前以步长gap判断,如果大于temp就交换顺序,如果不能再跨步长就结束
                while (j>=gap && L->data[j-gap]>temp) {
                    L->data[j]=L->data[j-gap];
                    j-=gap;
                }
                L->data[j]=temp;
            }
        }
    }
    void BubbleSort(SqList<int>* L) {
        //不断把最小的元素往前移动,每次外循环都完成一次最小元素的归位
        for (int i=0;i<L->length;i++) {
            //用来记录一次循环中是否有过交换
            int exchange=0;
            for (int j=L->length-1;j>i;j--) {
                //如果乱序则交换,使得局部顺序
                if (L->data[j-1]>L->data[j]) {
                    int temp=L->data[j];
                    L->data[j]=L->data[j-1];
                    L->data[j-1]=temp;
                    //发生果交换所以置为1;
                    exchange=1;
                }
            }
            //如果在一次循环中没有发生交换,说明已经完成排序,可退出
            if (!exchange) {
                return;
            }
        }
    }
    void QuickSort(SqList<int>* L,int low,int high) {
        //如果左大于由,递归结束
        if (low>=high) {
            return;
        }
        //low与high为下标
        //以最后一个元素为基准值
        //i为比基准值小的最后一个元素下标,j为前驱下标,用来遍历
        int i=low-1,j=low,pivot=L->data[high];
        while (j<high) {
            //如果前驱下标的元素小于基准值,就使i++并交换
            if (L->data[j]<pivot) {
                i++;
                int temp=L->data[j];
                L->data[j]=L->data[i];
                L->data[i]=temp;
            }
            j++;
        }
        //遍历结束,交换基准值与i+1,此时i+1左边全小于它,右边全大于它
        L->data[high]=L->data[i+1];
        L->data[i+1]=pivot;
        //在i+1两侧递归
        QuickSort(L,low,i);
        QuickSort(L,i+2,high);
    }
    void SelectSort(SqList<int>* L) {
        //外循环为顺序的最后值下标
        for (int i=0;i<L->length;i++) {
            int temp=L->data[i];
            int tempMinPov=i;
            //内循环在乱序数组中遍历找到最小值与外循环交换
            for (int j=i;j<L->length;j++) {
                if (L->data[j]<L->data[tempMinPov]) {
                    tempMinPov=j;
                }
            }
            L->data[i]=L->data[tempMinPov];
            L->data[tempMinPov]=temp;
        }
    }
}

#endif //SEQUENTIALLIST_H
