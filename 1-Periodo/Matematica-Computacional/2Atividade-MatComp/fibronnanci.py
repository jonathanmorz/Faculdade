num = []

def fibronacci(firstnum, howmuch):
    for i in range(howmuch):
        num.append(firstnum)
        if i > 0:
            firstnum = firstnum + num[i-1]
        else:
            firstnum +=1
fibronacci(int(input("Número inicial: ")),int(input("Rodar o processo quantas vezes? ")))

print(num)
        