# range можно применять по-разному:
print("Числа на полуинтервале [0, 10):")
for i in range(10):
  print(i, end=' ')
print()

print("Числа на полуинтервале [5, 10):")
for i in range(5, 10):
  print(i, end=' ')
print()

print("Нечётные числа на полуинтервале [0, 10):")
for i in range(1, 10, 2):
  print(i, end=' ')
print()

print("Числа на полуинтервале [10, -1):")
for i in range(10, 0, -1):
  print(i, end=' ')
print()

a = input("Введите строку: ")
print("Длина строки равна", len(a))

# Элементы в списке нумеруются с нуля.
# К конкретному элементу можно обратиться,
# написав его индекс в квадратных скобках:
print("Числа в массиве:")
#       0    1   2   3   <=  индексы
arr = [4000, 1, 300, 20]
for i in range(4):
  print(arr[i], end=' ')
print()

# К строкам тоже можно обращаться по индексу:
s = input("Введите строку: ")
for i in range(len(s)):
  print(s[i], end=' ')
print()

# Можно написать так и отсортировать массив:
print("Сортирую массив")
arr.sort()
# Можно написать так и вывести массив без скобок и цикла:
print(*arr)
# Без * будет с квадратными скобками и запятыми:
print(arr)

# Можно добавлять элементы в конец массива и удалять:
print("Добавляю 123 в конец массива")
arr.append(123)
print(*arr)
print("Удаляю два элемента с конца массива")
arr.pop()
arr.pop()
print(*arr)

# В массиве могут быть числа, строки и другие массивы:
arr = [123, "ham", [1, 2, 3]]
print(*arr)

# В частности, можно прочитать массив из 3 массивов вот так:
print("Введите три строки чисел через пробел:")
mat = [[int(num) for num in input().split()] for i in range(3)]
print("Вывожу обратно:")
for row in mat:
  print(*row)

# Чтобы сделать пустую матрицу (прямоугольный массив) пишите:
mat = [[0 for j in range(5)] for i in range(3)]
print("Матрица 3*5 из нулей:")
for row in mat:
  print(*row)
