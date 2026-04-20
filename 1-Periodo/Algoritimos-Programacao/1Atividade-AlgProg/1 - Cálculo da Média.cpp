//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 1 - Cálculo da Média
#include <iostream>
using namespace std;

int main () {
    //Variáveis
    float notamatematica;
    float notaportugues;
    float notaciencias;

    //Captação de dados
    printf("Qual a nota de pedro em matematica? ");
    cin >> notamatematica;
    printf("Qual a nota de pedro em portugues? ");
    cin >> notaportugues;
    printf("Qual a nota de pedro em ciencias? ");
    cin >> notaciencias;
    
    //Resultado
    printf("A media de Pedro e: %.2f\n", (notamatematica+notaportugues+notaciencias)/3);
    return 0;
}