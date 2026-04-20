// Bibliotecas
#include <iostream>  // Entrada e saída padrão (cin, cout)
#include <vector>    // Uso de vetor
#include <string>    // Manipulação de strings
#include <limits> // Usada na limpagem do buffer de entrada
#include <cstdlib>   // Uso da função system()

// Identifica o sistema operacional
#ifdef _WIN32
#define OS_nome "Windows"
#elif __linux__
#define OS_nome "LinuxMac"
#else
#define OS_nome "Desconhecido"
#endif

// Variável global de controle do loop principal
bool continuar = true;

// Definição da struct Aluno
struct Aluno
{
    std::string nome;
    int idade;
    int matricula;
    float nota_final;
};

// Vetor global que armazena todos os alunos cadastrados
std::vector<Aluno> vector_alunos;

// Exibe as opções disponíveis para o usuário
void menu()
{
    printf("=========================================\n");
    printf("         O que deseja fazer?\n");
    printf("=========================================\n");
    printf(" Adicionar aluno [1]\n");
    printf(" Listar alunos cadastrados [2]\n");
    printf(" Buscar informacoes de aluno [3]\n");
    printf(" Mudar nota final de aluno [4]\n");
    printf(" Encerrar programa [0]\n");
    printf("=========================================\n");
}

// Limpar a tela do terminal dependendo do sistema operacional
void limpar_terminal()
{
    if (OS_nome == std::string("Windows"))
    {
        system("cls"); // comando do Windows
    }
    else if (OS_nome == std::string("LinuxMac"))
    {
        system("clear"); // comando do Linux e no Mac
    }
}

// Percorrer o vetor de alunos e encontrar a posição de um aluno com base na matrícula
int buscar_posicao_aluno(int matricula_buscada)
{
    // Percorre o vetor
    for (int i = 0; i <= vector_alunos.size(); i++)
    {
        // Se chegou ao final sem encontrar
        if (i == vector_alunos.size())
        {
            return -1;
        }

        // Acessa o elemento na posição i
        Aluno aluno_unidade = vector_alunos.at(i);

        // Verifica se a matrícula coincide
        if (aluno_unidade.matricula == matricula_buscada)
        {
            return i;
        }
    }

    return -1; // Segurança adicional (boa prática)
}

// Cadastra um novo aluno no vetor
void cadastro()
{
    printf("=========================================\n");

    Aluno aluno_novo;

    // Entrada do nome (usa getline para permitir espaços)
    printf(" Nome do aluno: ");
    std::cin.ignore();
    std::getline(std::cin, aluno_novo.nome);

    // Entrada da idade com validação
    printf(" Idade: ");
    while (true)
    {
        if (std::cin >> aluno_novo.idade)
        {
            break; // entrada válida
        }
        else
        {
            printf("{Entrada invalida!(character ou numero muito extenso)}\n");
            printf(" Idade: ");
            std::cin.clear(); // limpa erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Entrada da matrícula com verificação de unicidade
    printf(" Matricula: ");
    while (true)
    {
        if (std::cin >> aluno_novo.matricula &&
            buscar_posicao_aluno(aluno_novo.matricula) == -1)
        {
            break; // matrícula válida e não duplicada
        }
        else if (buscar_posicao_aluno(aluno_novo.matricula) != -1)
        {
            printf("{Matricula ja registrada!}\n");
            printf(" Matricula: ");
        }
        else
        {
            printf("{Entrada invalida!(character ou numero muito extenso)}\n");
            printf(" Matricula: ");
        }

        std::cin.clear(); // limpa erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpar o buffer de entrada(remove todos os caracteres remanescentes)
    }

    // Entrada da nota final
    printf(" Nota final: ");
    while (true)
    {
        if (std::cin >> aluno_novo.nota_final)
        {
            break;
        }
        else
        {
            printf("Entrada invalida!(character ou numero muito extenso!)\n");
            printf(" Nota final: ");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Inserção no vetor
    vector_alunos.push_back(aluno_novo);
}

// Exibe todos os alunos cadastrados
void listagem()
{
    for (int i = 0; i < vector_alunos.size(); i++)
    {
        printf("=========================================\n");

        // Acesso ao aluno
        Aluno aluno_unidade = vector_alunos.at(i);

        // Impressão do aluno
        printf(" Nome: %s\n Idade: %i\n Matricula: %i\n Nota final: %.2f\n",
               aluno_unidade.nome.c_str(),
               aluno_unidade.idade,
               aluno_unidade.matricula,
               aluno_unidade.nota_final);
    }
}

// Exibe um aluno específico
bool visualizar_aluno()
{
    int matricula_buscada;

    printf("Qual a matricula do aluno? ");

    // Validação de entrada
    if (!(std::cin >> matricula_buscada))
    {
        printf("=========================================\n");
        printf("Valor invalido!\n");
        printf("=========================================\n");
        printf("Aperte [Enter] para continuar");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        limpar_terminal();
        return false;
    }

    int posicao_aluno = buscar_posicao_aluno(matricula_buscada);

    printf("=========================================\n");

    if (posicao_aluno == -1)
    {
        printf("Aluno nao cadastrado!\n");
        printf("=========================================\n");
        printf("Aperte [Enter] para continuar");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        limpar_terminal();
        return false;
    }

    // Exibição dos dados
    Aluno aluno_achado = vector_alunos[posicao_aluno];

    printf(" Nome: %s\n Idade: %i\n Matricula: %i\n Nota final: %.2f\n",
           aluno_achado.nome.c_str(),
           aluno_achado.idade,
           aluno_achado.matricula,
           aluno_achado.nota_final);

    return true;
}

// Altera a nota final de um aluno existente
bool mudar_nota()
{
    float nova_nota;
    int matricula;

    printf("Qual a matricula do aluno? ");

    if (!(std::cin >> matricula))
    {
        printf("=========================================\n");
        printf("Valor invalido!\n");
        printf("=========================================\n");
        printf("Aperte [Enter] para continuar");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        std::cin.clear();
        return false;
    }

    int posicao = buscar_posicao_aluno(matricula);
    printf("=========================================\n");

    if (posicao == -1)
    {
        printf("Aluno nao cadastrado!\n");
        printf("=========================================\n");
        printf("Aperte [Enter] para continuar");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        limpar_terminal();
        return false;
    }

    printf("Aluno %s encontrado. Nota atual: %.2f\n",
           vector_alunos.at(posicao).nome.c_str(),
           vector_alunos.at(posicao).nota_final);

    printf("Nova nota: ");
    while (true)
    {
        if(std::cin >> nova_nota){
            break;
        }
        else{
            printf("{Entrada invalida!(character ou numero muito extenso)}\n");
            printf("Nova nota: ");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    

    // Atualização no vetor
    vector_alunos.at(posicao).nota_final = nova_nota;

    return true;
}

// Executa a ação escolhida no menu
void processamento_input(int escolha)
{
    limpar_terminal();

    switch (escolha)
    {
    case 1:
        cadastro();
        break;

    case 2:
        if (vector_alunos.empty())
        {
            printf("=========================================\n");
            printf("Nenhum aluno registrado\n");
            printf("=========================================\n");
            printf("Aperte [Enter] para continuar");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            limpar_terminal();
            return;
        }
        listagem();
        break;

    case 3:
        if (vector_alunos.empty())
        {
            printf("=========================================\n");
            printf("Nenhum aluno registrado\n");
            printf("=========================================\n");
            printf("Aperte [Enter] para continuar");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            limpar_terminal();
            return;
        }
        if (!visualizar_aluno())
        {
            return;
        }
        break;

    case 4:
        if (vector_alunos.empty())
        {
            printf("=========================================\n");
            printf("Nenhum aluno registrado\n");
            printf("=========================================\n");
            printf("Aperte [Enter] para continuar");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            limpar_terminal();
            return;
        }
        if (!mudar_nota())
        {
            return;
        }
        break;

    case 0:
        continuar = false;
        return;
    }
    printf("=========================================\n");
    printf("Aperte [Enter] para continuar");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cin.clear();
    limpar_terminal();
}

// Função principal; Controla o fluxo geral do programa
int main()
{
    limpar_terminal();

    // Loop principal do programa
    while (continuar)
    {
        menu();

        int escolha;

        printf("Resposta: ");

        // Validação da escolha do menu
        while (true)
        {
            if (std::cin >> escolha && escolha < 5 && escolha >= 0)
            {
                break;
            }
            else
            {
                limpar_terminal();
                printf("Entrada invalida!\n");
                menu();
                printf("Resposta: ");
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        processamento_input(escolha);
    }
    printf("=========================================\n");
    printf("         Fim do programa\n");
    printf("=========================================\n");
    return 0;
}