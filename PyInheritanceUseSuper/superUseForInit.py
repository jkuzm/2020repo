import numpy as np
import pandas as pd
import requests
import io

class Fruit:
    def __init__(self):
        print('I am a fruit')

class Citrus(Fruit):
    def __init__(self):
        super().__init__()
        print(" and I am a citrus")

Lemon = Citrus()
print(Citrus.__mro__) #not Lemon.__mro__ should be called on class, not object

a = np.array([1,2,3])
b = np.zeros((5,5))
print(b)
x = np.array([2,3,100,4,68])
print(x[np.argsort(x)[-2:][::-1]])

l1 = [1,2,3,4,5]
data1 = pd.DataFrame(l1)
print(data1)
dict1 = {'fruit name':['apple','mango'],'count':[12,24] }
data2 = pd.DataFrame(dict1)
print(data2)
my_csv_link = "https://github.com/jkuzm/2020repo/blob/master/test.csv"
my_url_data = requests.get(my_csv_link).text
#following produces errors will end playing with this
#c=pd.read_csv(io.StringIO(my_url_data))
#print(c)
x=lambda a: a+10
print(x(5))
#replace all odd numbers of array with -1
arr = np.arange(1,11)
print(arr)
arr[arr%2==1]=-1
print(arr)
#print common elements of 2 arrays
a=np.array([1,2,3,4])
b = np.array([2,4,6,8])
c = np.intersect1d(a,b)
print(c)
#capitalize all words, make "mary had an apple" into "Mary Had An Apple"
ll = "mary had an apple".split()
ser=pd.Series(ll)
print(ser)
nnn=ser.map(lambda x: x.title())
print(nnn)
#calculate number of characters of each word in a series
lenofwords=ser.map(lambda a: len(a))
print(lenofwords)
my_csv = pd.read_csv("C:\\Users\\liza\\source\\repos\\2020repo\\test.csv")
my_csv.head()
#not sure it starts here or higher, going through this class:
#https://www.youtube.com/watch?v=yrEmaJS5MpM
def multiplier():
    return [lambda x,i=i:i*x for i in range(1,5)]
print('use of multiplier,for m(1) m(10) m(2)')
print([m(1) for m in multiplier()])
print([m(10) for m in multiplier()])
print([m(2) for m in multiplier()])
#n=n in lambda parameter means a lambda parameter can be nitialized with
# i a default value: the parameter n takes the outer n as a default value
numbers = ['one','two', 'three']
funcs = []
for n in numbers:
    print('func for n=',n)
    #funcs.append(lambda x=n:print(x))
    funcs.append(lambda x=n: print(x))
for f in funcs:
    f()
#get rid of duplicates in a list
mylist = ['a','b','a','c','c']
myset = set(mylist)
mylist = list(dict.fromkeys(mylist))
print('mylist after fromkeys:',mylist)
print('myset:',myset)

#using lambda as filters
def even_fn(x):
    if x % 2 == 0:
        return True
    else:
        return False
print(list(filter(even_fn,[1,2,3,4,6,7,5,8])))


def reverseStr(str):
    if len(str) == 0:
        return str
    return reverseStr(str[1:])+str[0]
mystr = 'andwhat?'
print(reverseStr(mystr))

def isPalindrome(str,l,r):
    if(r <= l):
        return True
    if(str[r] != str[l]):
        return False
    else:
        return isPalindrome(str,l+1,r-1)
mypal = '!arosaupalanalapuasora!'
if isPalindrome(mypal,0,len(mypal)-1):
    print('str ',mypal,' is palindrome')
else:
    print('str ', mypal, ' is NOT palindrome')

