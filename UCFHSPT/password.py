def ss(s,L,R):
    cnt=0
    (ss0,ss1,ss2)=(0,0,0)
    for i in range(L,R+1):
        r=int(s[i])%3
        if r==0:
            ss0+=1
        elif r==1:
            (ss0,ss1,ss2)=(ss2,ss0,ss1)
            ss1+=1
        elif r==2:
            (ss0,ss1,ss2)=(ss1,ss2,ss0)
            ss2+=1
        cnt+=ss0
    return(cnt)

n = int(input())
while n - 1 > 0:
    n=n-1
    string = input()
    print(ss(string,0,len(string)))


