//Unigranrio Afya, ciências da computação, 1 semestre
//Desafio 5 - Verificação de Idade
#include <iostream>
using namespace std;

int main() {
    //Variáveis
    int anoeleicao;
    int anonascimento;
    int idade;

    //Captação de dados
    printf("Qual o ano da eleicao? ");
    cin >> anoeleicao;
    printf("Qual o ano do nascimento de Joaquim? ");
    cin >> anonascimento;

    //Resultado
    idade = anoeleicao - anonascimento;
    printf("Em %i Joaquim tera %i anos de idade, ",anoeleicao,idade);
        //Condicionais
    if (idade >= 18){
        printf("logo Joaquim podera votar\n");
    }
    else{
        printf("logo Joaquim não podera votar\n");
    }
    return 0;
}