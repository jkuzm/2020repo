def fib_gen(limit):
    i,a,b =0,0,1
    while(i < limit):
        yield a
        a,b = b,a+b
        i += 1

for i in fib_gen(10):
    print(i, end= " ")
print()

#simplest decorator sample from https://medium.com/@dmi3coder/pythons-decorators-vs-java-s-annotations-same-thing-2b1ef12e4dc5

def as_html(func):
    def wrapper():
        result = func()
        return f'<html>{result}</html>'
    return wrapper

@as_html
def say_hello():
    return 'Hello'

print(say_hello())

#now, from there, cached decorator to demonstrate function not called if cached,
#but I'll check what I can't get, if parameter matters, so it's different than sample
import time
cached_items = {}

def cached(func):
    def wrapper(*args, **kwargs):
        global cached_items
        if func.__name__ not in cached_items:
            cached_items[func.__name__] = func(*args,**kwargs)
        return cached_items[func.__name__]
    return wrapper

@cached
def my_task(n):
    time.sleep(1.0)
    return n*2;

start_time = time.time()
res = my_task(10)
print("--- %.8f seconds first execution producing result %d" % ((time.time()-start_time), res))
start_time = time.time()
res = my_task(20) #yes, I was right, cached doesn't count for arg, so result is wrong
print("--- %.8f seconds first execution producing result %d" % ((time.time()-start_time), res))
start_time = time.time()
res = my_task(10)
print("--- %.8f seconds first execution producing result %d" % ((time.time()-start_time), res))

#let's get cleared usage of *args
#* means variable length of args, args becomes iterable
def print_all(*args):
    for i in args:
        print(i,end=' ')
print_all('We','will','survive!')
print()
#key-worded args: ** - a special sign to take them that way
def print_keys_vals(**kwargs):
    for key,val in kwargs.items():
        print("{}:{} ".format(key,val))
print_keys_vals(first = 'We',second = 'will',third = 'survive!')
print()



