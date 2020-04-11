def fib_gen(limit):
    i,a,b = 0,0,1
    while(i < limit):
        yield a
        a,b = b,a+b
        i += 1

for i in fib_gen(10):
    print(i,end=" ")

class Fruit:
    def __init__(self):
        print('I am fruit')
class Citrus(Fruit):
    "checks inheritance"
    def __init__(self):
        super().__init__()
        print("...and a citrus")

Lemon = Citrus()

print(Lemon.__doc__)

def func(*args):
    for i in args:
        print(i)
func('a','b')
n = [1,2,3]
nn = [x*x for x in n]
print(nn)


