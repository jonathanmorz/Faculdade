#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

#ifdef _WIN32
#define OS_nome "Windows"
#elif __linux__
#define OS_nome "LinuxMec"
#else
#define OS_nome "Desconhecido"
#endif
bool continuar = true;
struct Aluno
{
    std::string nome;
    int idade;
    int matricula;
    float nota_final;
};

std::vector<Aluno> vector_alunos;

void menu()
{
    printf("=========================================\n");
    printf("O que deseja fazer?\n");
    printf(" Adicionar aluno [1]\n");
    printf(" Listar alunos cadastrados [2]\n");
    printf(" Buscar informacoes de aluno [3]\n");
    printf(" Mudar nota final e aluno [4]\n");
    printf(" Encerrar programa [0]\n");
}
void limpar_terminal()
{
    if (OS_nome == "Windows")
    {
        system("cls");
    }
    else if (OS_nome == "LinuxMec")
    {
        system("clear");
    }
    else
    {
    }
}

void cadastro()
{
    printf("=========================================\n");
    Aluno aluno_novo;
    printf(" Nome do aluno: ");
    std::cin.ignore();
    std::getline(std::cin, aluno_novo.nome);
    printf(" Idade: ");
    while (true)
    {
        if (std::cin >> aluno_novo.idade)
        {
            break;
        }
        else
        {
            printf("Entrada invalida! Por favor, digite apenas numeros.\n");
            printf(" Idade: ");
            std::cin.clear(); // 1. Limpa o estado de erro (failbit)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    printf(" Matricula: ");
    while (true)
    {
        if (std::cin >> aluno_novo.matricula)
        {
            break;
        }
        else
        {
            printf("Entrada invalida! Por favor, digite apenas numeros.\n");
            printf(" Matricula: ");
            std::cin.clear(); // 1. Limpa o estado de erro (failbit)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    printf(" Nota final: ");
    while (true)
    {
        if (std::cin >> aluno_novo.nota_final)
        {
            break;
        }
        else
        {
            printf("Entrada invalida! Por favor, digite apenas numeros.\n");
            printf(" Nota final: ");
            std::cin.clear(); // 1. Limpa o estado de erro (failbit)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    vector_alunos.push_back(aluno_novo);
}
void listagem()
{
    for (int i = 0; i < vector_alunos.size(); i++)
    {
        printf("=====================\n");
        Aluno aluno_unidade = vector_alunos.at(i);
        printf(" Nome: %s\n Idade: %i\n Matricula: %i\n Nota final: %.2f\n", aluno_unidade.nome.c_str(), aluno_unidade.idade, aluno_unidade.matricula, aluno_unidade.nota_final);
    }
}

int buscar_posicao_aluno(int matricula_buscada)
{
    for (int i = 0; i < vector_alunos.size(); i++)
    {
        Aluno aluno_unidade = vector_alunos.at(i);
        if (aluno_unidade.matricula == matricula_buscada)
        {
            return i;
            break;
        }
        if (i != vector_alunos.size())
        {
            return -1;
            break;
        }
    }
}

void processamento_input(int escolha)
{
    switch (escolha)
    {
    case 1:
        cadastro();
        break;
    case 2:
        if (vector_alunos.size() == 0)
        {
            printf("=========================================\n");
            printf("Nenhum aluno foi registrado ainda\n");
            return;
        }
        listagem();
        break;
    case 3:
    {
        if (vector_alunos.size() == 0)
        {
            printf("=========================================\n");
            printf("Nenhum aluno foi registrado ainda\n");
            return;
        }
        int matricula_buscada;
        printf("Qual a matricula do aluno? ");
        std::cin >> matricula_buscada;
        int posicao_aluno = buscar_posicao_aluno(matricula_buscada);
        printf("%i", posicao_aluno);
        if (posicao_aluno == -1)
        {
            printf("Aluno nao encontrado\n");
        }
        printf("=====================\n");
        Aluno aluno_achado = vector_alunos[posicao_aluno];
        printf(" Nome: %s\n Idade: %i\n Matricula: %i\n Nota final: %.2f\n", aluno_achado.nome.c_str(), aluno_achado.idade, aluno_achado.matricula, aluno_achado.nota_final);
        break;
    }

    case 4:
        if (vector_alunos.size() == 0)
        {
            printf("=========================================\n");
            printf("Nenhum aluno foi registrado ainda\n");
            return;
        }
        break;

    case 0:
        continuar = false;
        break;

    default:
        break;
    }
}

int main()
{
    while (continuar)
    {
        menu();
        int escolha;
        printf("Resposta: ");
        while (true)
        {
            if (std::cin >> escolha && escolha < 5)
            {
                break;
            }
            else
            {
                printf("Entrada invalida! Por favor, digite apenas numeros.\n");
                printf(" Resposta: ");
                std::cin.clear(); // 1. Limpa o estado de erro (failbit)
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        processamento_input(escolha);
    }
}