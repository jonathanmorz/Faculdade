#Fatorial
def Fatorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * Fatorial(n - 1)

# Exemplos de utilização Fatorial(n)
print("Fatorial(0)  =", Fatorial(0))
print("Fatorial(1)  =", Fatorial(1))
print("Fatorial(5)  =", Fatorial(5))
print("Fatorial(7)  =", Fatorial(7))
print("Fatorial(10) =", Fatorial(10))

#Fibonacci
def F(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return F(n - 1) + F(n - 2)

# Exemplos de utilização F(n)
print("F(1)  =", F(1))
print("F(3)  =", F(3))
print("F(6)  =", F(6))
print("F(10)  =", F(10))

#Soma lista
def SomaLista(lista):
    if len(lista) == 0:
        return 0
    return lista[0] + SomaLista(lista[1:])

# Exemplos de utilização SomaLista(lista)
print("Soma da lista[1,3,5,7,9]: ",SomaLista([1, 3, 5, 7, 9]))
print("Soma da lista[10,20,30]: ",SomaLista([10, 20, 30]))
print("Soma da lista[-2,4,-6,8]: ",SomaLista([-2, 4, -6, 8]))

#Palíndromo
def Palindromo(palavra):
    palavra_invertida = palavra[::-1]
    if palavra_invertida == palavra:
        return True
    return False

# Exemplos de utilização Palindromo(palavra)
print("urubu é um Palíndromo? ",Palindromo("urubu"))
print("arara é um Palíndromo? ",Palindromo("arara"))
print("radar é um Palíndromo? ",Palindromo("radar"))

#Contagem de ocorrências
def ContaOcorrencia(vet, elemento):
    if len(vet) == 0:
        return 0
    if vet[0] == elemento:
        return 1 + ContaOcorrencia(vet[1:], elemento)
    else:
        return ContaOcorrencia(vet[1:], elemento)

# Exemplos de utilização ContaOcorrencia(vet, elemento)
print("Ocorrencias do 2:", ContaOcorrencia([1, 2, 3, 2, 2, 5], 2))
print("Ocorrencias do 'a':", ContaOcorrencia(["a", "b", "a", "c"], "a"))
print("Ocorrencias do 4:", ContaOcorrencia([4, 4, 4, 4], 4))
print("Ocorrencias do 5:", ContaOcorrencia([3, 2, 3, 2], 5))