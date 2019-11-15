# [liaoxuefeng Python Learning](https://www.liaoxuefeng.com/wiki/1016959663602400)
## Function
### Use Function Exercise
```python
n1 = 255
n2 = 1000
print(hex(n1))
print(hex(n2))
```
### Define Function Exercise
```python
import math

def quadratic(a, b, c):
    return (-b + math.sqrt(b * b - 4 * a * c)) / (2 * a), \
           (-b - math.sqrt(b * b - 4 * a * c)) / (2 * a)

print('quadratic(2, 3, 1) = ', quadratic(2, 3, 1))
print('quadratic(1, 3, -4) = ', quadratic(1, 3, -4))
```
### Functino Prameter Exercise
```python
def product(*l):
    ret = 1
    for num in l:
        ret = ret * num
    return ret

print('product(5) =', product(5))
print('product(5, 6) =', product(5, 6))
print('product(5, 6, 7) =', product(5, 6, 7))
print('product(5, 6, 7, 9) =', product(5, 6, 7, 9))
```
### Recursion Exercise
```python
def move(n, a, b, c):
    if n == 1:
        print(a, '-->', c)
    else:
        move(n - 1, a, c, b)
        print(a, '-->', c)
        move(n - 1, b, a, c)

move(3, 'A', 'B', 'C')
```
## Advanced Features
### Slice Exercise
```python
def trim(s):
    if len(s) == 0:
        return s
    front_idx, end_idx = 0, len(s) - 1
    while front_idx <= end_idx and s[front_idx] == ' ':
        front_idx = front_idx + 1
    while front_idx <= end_idx and s[end_idx] == ' ':
        end_idx = end_idx - 1
    return s[front_idx:end_idx + 1]

print(trim('hello   '))
print(trim('   hello'))
print(trim('   hello   '))
print(trim('   hello  world   '))
print(trim(''))
print(trim('   '))
```
### Iterable Exercise
```python
def findMinAndMax(L):
    if len(L) == 0:
        return None, None
    else:
        min_num, max_num = L[0], L[0]
        for num in L:
            min_num = min(min_num, num)
            max_num = max(max_num, num)
        return min_num, max_num

print(findMinAndMax([]))
print(findMinAndMax([7]))
print(findMinAndMax([7, 1]))
print(findMinAndMax([7, 1, 3, 9, 5]))
```
### List Comrehensions Exercise
```python
L1 = ['Hello', 'World', 18, 'Apple', None]
L2 = [s.lower() for s in L1 if isinstance(s, str)]
print(L2)
```
### Generator Exercise
```python
def triangles():
    prev = [1]
    yield prev
    while True:
        middle = [x + y for x, y in zip(prev[0:], prev[1:])]
        middle.insert(0, 1)
        middle.append(1)
        prev = middle
        yield middle

n = 0
results = []
for t in triangles():
    results.append(t)
    n = n + 1
    if n == 10:
        break

for t in results:
    print(t)
```
## Functional Programming
### map/reduce Exercise 1
```python
def normalize(name):
    return name[0].upper() + name[1:].lower()

L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)
```
### map/reduce Exercise 2
```python
from functools import reduce
def prod(L):
    def fn(x, y):
        return x * y

    return reduce(fn, L)

print('3 * 5 * 7 * 9 = ', prod([3, 5, 7, 9]))
```