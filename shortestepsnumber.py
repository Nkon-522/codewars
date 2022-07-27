def shortest_steps_to_num(num):
    result=0
    while num!=1:
        if num%2==0:
            num/=2
        else:
            num-=1
        result+=1
    return result
