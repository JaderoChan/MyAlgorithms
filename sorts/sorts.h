#ifndef JCALGO_SORTS_H
#define JCALGO_SORTS_H

#include <stddef.h>

#define JCALGO_DEFAULT_LESS_THAN(a, b) ((a) < (b))

/** @brief 冒泡排序 */
#define JCALGO_DEFINE_BUBBLE_SORT(T, COMP)                                      \
void jcalgo_bubble_sort_##T(T *arr, size_t n)                                   \
{                                                                               \
    if (n < 2)                                                                  \
        return;                                                                 \
                                                                                \
    n -= 1;                                                                     \
    int has_swap = 1;                                                           \
    while (has_swap)                                                            \
    {                                                                           \
        has_swap = 0;                                                           \
        for (size_t i = 0; i < n; ++i)                                          \
        {                                                                       \
            if (COMP(arr[i + 1], arr[i]))                                       \
            {                                                                   \
                const T tmp = arr[i];                                           \
                arr[i]      = arr[i + 1];                                       \
                arr[i + 1]  = tmp;                                              \
                has_swap    = 1;                                                \
            }                                                                   \
        }                                                                       \
    }                                                                           \
}

/** @brief 选择排序 */
#define JCALGO_DEFINE_SELECT_SORT(T, COMP)                                      \
void jcalgo_select_sort_##T(T *arr, size_t n)                                   \
{                                                                               \
    if (n < 2)                                                                  \
        return;                                                                 \
                                                                                \
    for (size_t i = 0; i < n; ++i)                                              \
    {                                                                           \
        size_t flag = i;                                                        \
        for (size_t j = i + 1; j < n; ++j)                                      \
        {                                                                       \
            if (COMP(arr[j], arr[flag]))                                        \
                flag = j;                                                       \
        }                                                                       \
                                                                                \
        const T tmp = arr[i];                                                   \
        arr[i]      = arr[flag];                                                \
        arr[flag]   = tmp;                                                      \
    }                                                                           \
}

/** @brief 插入排序 */
#define JCALGO_DEFINE_INSERT_SORT(T, COMP)                                      \
void jcalgo_insert_sort_##T(T *arr, size_t n)                                   \
{                                                                               \
    if (n < 2)                                                                  \
        return;                                                                 \
                                                                                \
    for (size_t i = 1; i < n; ++i)                                              \
    {                                                                           \
        size_t flag = i;                                                        \
        for (size_t j = i - 1; j >= 0;)                                         \
        {                                                                       \
            if (!COMP(arr[flag], arr[j]))                                       \
                break;                                                          \
                                                                                \
            const T tmp = arr[flag];                                            \
            arr[flag]   = arr[j];                                               \
            arr[j]      = tmp;                                                  \
            --flag;                                                             \
                                                                                \
            if (j == 0) break;                                                  \
            else        --j;                                                    \
        }                                                                       \
    }                                                                           \
}

/** @brief 希尔排序 */
#define JCALGO_DEFINE_SHELL_SORT(T, COMP)                                       \
void jcalgo_shell_sort_##T(T *arr, size_t n)                                    \
{                                                                               \
    if (n < 2)                                                                  \
        return;                                                                 \
                                                                                \
    size_t gap = n / 2;                                                         \
    while (gap)                                                                 \
    {                                                                           \
        for (size_t g = 0; g < gap; ++g)                                        \
        {                                                                       \
            for (size_t i = g + gap; i < n; i += gap)                           \
            {                                                                   \
                size_t flag = i;                                                \
                for (size_t j = i - gap; j >= 0;)                               \
                {                                                               \
                    if (!COMP(arr[flag], arr[j]))                               \
                        break;                                                  \
                                                                                \
                    const T tmp = arr[flag];                                    \
                    arr[flag]   = arr[j];                                       \
                    arr[j]      = tmp;                                          \
                    flag -= gap;                                                \
                                                                                \
                    if (j == g) break;                                          \
                    else        j -= gap;                                       \
                }                                                               \
            }                                                                   \
        }                                                                       \
                                                                                \
        gap /= 2;                                                               \
    }                                                                           \
}

/** @brief 归并排序 */

/** @brief 快速排序 */
#define JCALGO_DEFINE_QUICK_SORT(T, COMP)                                       \
void jcalgo_quick_sort_##T(T *arr, size_t n)                                    \
{                                                                               \
    if (n < 2)                                                                  \
        return;                                                                 \
                                                                                \
    T pivot = arr[n / 2];                                                       \
    size_t i = 0, j = n - 1;                                                    \
                                                                                \
    while (i <= j)                                                              \
    {                                                                           \
        while (i < n && COMP(arr[i], pivot)) ++i;                               \
        while (j > 0 && COMP(pivot, arr[j])) --j;                               \
        if (i <= j)                                                             \
        {                                                                       \
            const T tmp = arr[i];                                               \
            arr[i]      = arr[j];                                               \
            arr[j]      = tmp;                                                  \
            ++i;                                                                \
            if (j > 0) --j;                                                     \
            else       break;                                                   \
        }                                                                       \
    }                                                                           \
                                                                                \
    if (i < n) jcalgo_quick_sort_##T(arr + i, n - i);                           \
    if (j > 0) jcalgo_quick_sort_##T(arr,     j + 1);                           \
}

/** @brief 堆排序 */

/** @brief 计数排序 */

/** @brief 桶排序 */

/** @brief 基数排序 */

#endif // !JCALGO_SORTS_H
