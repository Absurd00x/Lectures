# def название функции(от чего зависит функция)
#                     (аргументы функции)
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(1, n):
            if arr[j - 1] > arr[j]:
                arr[j - 1], arr[j] = arr[j], arr[j - 1]

