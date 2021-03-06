inp = list(map(int,input().split())) 
def fact(n): 
    a = 1
    for i in range(2, n + 1):  
        a = a * i 
    return a   

n = inp[0]
r = inp[1]
out = fact(n) / (fact(r) * fact(n - r)) 
out = out / (pow(2, n)) 

ff = out.as_integer_ratio() 
print(ff[0],"/",ff[1],sep = "")