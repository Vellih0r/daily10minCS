import time

start = time.time()
list(map(lambda x: x*x, range(1, 10001)))
print("map:", time.time() - start)

start = time.time()
[x*x for x in range(1, 10001)]
print("list comp:", time.time() - start)