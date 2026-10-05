#Fatorial
def Fatorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * Fatorial(n - 1)

# Exemplos de utilização
print("Fatorial(0)  =", Fatorial(0))
print("Fatorial(1)  =", Fatorial(1))
print("Fatorial(5)  =", Fatorial(5))
print("Fatorial(7)  =", Fatorial(7))
print("Fatorial(10) =", Fatorial(10))

raise SystemExit

#Fibonacci
def F(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return F(n - 1) + F(n - 2)

# Exemplos de utilização
print("F(1)  =", F(1))
print("F(3)  =", F(3))
print("F(6)  =", F(6))
print("F(10)  =", F(10))


#Soma lista
lista = [1,2,3,4,5]

def soma_lista(lista):
    total = 0
    for num in lista:
        total += num
    return total

print(soma_lista(lista))

#Políndromo

def verify_polindromo(palavra):
    palavra_invertida = palavra[::-1]
    if palavra_invertida == palavra:
        return True
    return False

print(verify_polindromo(""))

#Contagem de Ocorrencias

vetor_num = [1,1,1,2,2,3,4,5,6,7,8,]

def contagem_ocorrencias(vetor,valor):
    quantidade = 0
    for x in vetor:
        if x == valor:
            quantidade +=1
    return quantidade

print(contagem_ocorrencias(vetor_num,1))