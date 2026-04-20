//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 4 - Salário Bruto
#include <iostream>
using namespace std;

int main (){
    //Variáveis
    int dias;
    float horas;
    float taxahoraria;

    //Capitação de dados
    printf("Ana trabalhou quantos dias no mes? ");
    cin >> dias;
    printf("Por quantas horas ela trabalha diariamente? ");
    cin >> horas;
    printf("Qual a taxa horaria dela? ");
    cin >> taxahoraria;

    //Resultado
    printf("Ana recebera %.2f no final do mes\n",((horas * taxahoraria) * dias));
    return 0;
}