#do reversion of string
#do sum of list elements in one line
#from his requirements: pandas, dask(parallel computing),
# pep 8 (clean python code style)

import numpy as np

myarr = np.zeros(4)
print(myarr)
for i in myarr:
    print(i)
ll = [1,3,3,4,5,6]
print(ll[3:0])
print(ll[:-3])


ll = [1,2,3,4,5]
sum1 = 0
for i in ll:
    sum1 = i + sum1
mysum = sum(ll)

mysum1line = lambda x:
print(mysum)
sum2 = 0
sum2 = [sum2+x for x in ll]
#print(sum2) wrong



