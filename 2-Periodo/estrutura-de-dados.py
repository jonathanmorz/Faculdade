
#Fatorial
def fatorial(n):
    if n < 0:
        raise ValueError("Não existe fatorial de número negativo")
    if n == 0 or n == 1:
        return 1
    return n * fatorial(n - 1)

print(fatorial(5))

#Fibonacci
def fibonacci_personalizado(inicio, quantidade):
    sequencia = [inicio, inicio]
    for x in range(quantidade - 2):
        proximo = sequencia[-1] + sequencia[-2]
        sequencia.append(proximo)
    return sequencia

print(fibonacci_personalizado(1,10))

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
    