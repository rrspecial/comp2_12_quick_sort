#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* a, item* b)
{
    item tmp = *a;
    *a = *b;
    *b = tmp;
}
// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

	if (!begin || !end)
		return false;
	if (!begin || !end || begin >= end)
		return false;

    item* left = begin;
    item* right = (item*)end - 1;
    int pivot = begin[(end - begin) / 2].key;

    while (left <= right)
    {
        while (left->key < pivot) left++;
        while (right->key > pivot) right--;

        if (left <= right)
        {
            swap(left, right);
            left++;
            right--;
        }
    }
    if (begin < right + 1)
        quick_sort(begin, right + 1);

    if (left < end)
        quick_sort(left, end);

    return true;
}
