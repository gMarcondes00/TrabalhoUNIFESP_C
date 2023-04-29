#include <stdio.h>
#include <string.h>

//definir estrutura para todos os livros
struct Livro
{
    int disponivel;
    int vendido;
    int id;
    float valor;
    char descricao[200];
};


int main() {
    //Definir Livro de Matematica
    struct Livro Matematica;
    Matematica.disponivel = 5;
    Matematica.vendido = 5;
    Matematica.id = 1;

    FILE *descMat = fopen("matematica.txt", "r");
    fgets(Matematica.descricao, 200, descMat);
    fclose(descMat);



    //Definir Livro de Probabilidade e Estatistica
    struct Livro Probabilidade;
    Probabilidade.disponivel = 5;
    Probabilidade.vendido = 5;
    Probabilidade.id = 1;

    FILE *descProb = fopen("probabilidade.txt", "r");
    fgets(Probabilidade.descricao, 200, descProb);
    fclose(descProb);

    //Definir Livro de Fisica
    struct Livro Fisica;
    Fisica.disponivel = 5;
    Fisica.vendido = 5;
    Fisica.id = 1;

    FILE *descFis = fopen("fisica.txt", "r");
    fgets(Fisica.descricao, 200, descFis);
    fclose(descFis);

    //Definir Livro de Quimica
    struct Livro Quimica;
    Quimica.disponivel = 5;
    Quimica.vendido = 5;
    Quimica.id = 1;

    FILE *descQuim = fopen("quimica.txt", "r");
    fgets(Quimica.descricao, 200, descQuim);
    fclose(descQuim);

    //Definir Livro de Computação
    struct Livro Computacao;
    Computacao.disponivel = 5;
    Computacao.vendido = 5;
    Computacao.id = 1;

    FILE *descComp = fopen("computacao.txt", "r");
    fgets(Computacao.descricao, 200, descComp);
    fclose(descComp);

    return 0;
}