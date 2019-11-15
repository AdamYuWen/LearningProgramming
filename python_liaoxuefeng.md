# [liaoxuefeng Python Learning](https://www.liaoxuefeng.com/wiki/1016959663602400)
## Input and Output
1. `print()` accepts more than one strings. `;` will becomes a space.
2. `input()` can display a string. e.g. `input('Please enter your name.')`
## Generator Exercise
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