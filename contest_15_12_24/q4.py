import copy

t=int(input())
for i in range(t):
    already_done=[]
    n=int(input())
    value=1
    input_string = input()
    a= list(map(int, input_string.split()))
    a_set = set(a)
    for j in range(n):
        if a[j] in already_done:
            combined_set=a_set | set(already_done)
            for k in range(value, n + 1):
                if k in combined_set:
                    continue
                else:
                    value = k
                    already_done.append(copy.deepcopy(value))
                    break
            print(value,end=" ")
        else:
            already_done.append(a[j])
            print(a[j],end=" ")
    print()

