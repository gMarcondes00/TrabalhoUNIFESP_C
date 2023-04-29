#include <stdio.h>
#include <string.h>

//Definir estrutura para todos os livros
struct Livro
{
    int disponivel;
    int vendido;
    int id; //Código do Livro
    float valor;
    char descricao[200];
};

struct Livro Matematica;
struct Livro Probabilidade;
struct Livro Fisica;
struct Livro Quimica;
struct Livro Computacao;

//2) Mostrar a descrição da categoria
void desc(id) {
    //Path Matematica
    FILE *descMat = fopen("matematica.txt", "r");
    fgets(Matematica.descricao, 200, descMat);
    fclose(descMat);
    //Path Probabilidade e estatistica
    FILE *descProb = fopen("probabilidade.txt", "r");
    fgets(Probabilidade.descricao, 200, descProb);
    fclose(descProb);
    //Path Fisica
    FILE *descFis = fopen("fisica.txt", "r");
    fgets(Fisica.descricao, 200, descFis);
    fclose(descFis);
    //Path Quimica
    FILE *descQuim = fopen("quimica.txt", "r");
    fgets(Quimica.descricao, 200, descQuim);
    fclose(descQuim);
    //Path Computação
    FILE *descComp = fopen("computacao.txt", "r");
    fgets(Computacao.descricao, 200, descComp);
    fclose(descComp);

    switch (id){
        case 1:
            printf("%s",Matematica.descricao);
            break;
        case 2:
            printf("%s",Probabilidade.descricao);
            break;
        case 3:
            printf("%s",Fisica.descricao);
            break;
        case 4:
            printf("%s",Quimica.descricao);
            break;
        case 5:
            printf("%s",Computacao.descricao);
            break;

        default:
            break;
    }
    //Caso queira outra descrição
    char voltar[4];int idInput2;
    printf("\nGostaria de ver outra descricao?\n");
    scanf("%s",voltar);
    if(!strcmp(voltar, "sim") || !strcmp(voltar, "Sim") || !strcmp(voltar, "SIM")){
        printf("Qual descricao?");
        scanf("%d", &idInput2);
        desc(idInput2);
    } 
}

int main() {
    //Definir Livro de Matematica
    Matematica.disponivel = 5;
    Matematica.vendido = 5;
    Matematica.id = 1;
    Matematica.valor = 150.00;
    
    //Definir Livro de Probabilidade e Estatistica
    Probabilidade.disponivel = 10;
    Probabilidade.vendido = 0;
    Probabilidade.id = 2;
    Probabilidade.valor = 100.00;

    //Definir Livro de Fisica
    Fisica.disponivel = 8;
    Fisica.vendido = 2;
    Fisica.id = 3;
    Fisica.valor = 160.00;

    //Definir Livro de Quimica
    Quimica.disponivel = 7;
    Quimica.vendido = 3;
    Quimica.id = 4;
    Quimica.valor = 160.00;

    //Definir Livro de Computação
    Computacao.disponivel = 1;
    Computacao.vendido = 9;
    Computacao.id = 5;
    Computacao.valor = 200.00;

    //5)Mantenha o programa em loop
    char voltar[4];
    while(strcmp(voltar, "sim") || strcmp(voltar, "Sim") || strcmp(voltar, "SIM")){
        //1) Mostrar total de unidades e valor de cada categoria
        printf("Listagem de livros:\n");
        printf("---------------------------- Disponivel --- Vendido --- Codigo --- Valor\n");

        printf("Matematica:                      %d             %d        %d      R$%.2f\n", Matematica.disponivel, Matematica.vendido, Matematica.id, Matematica.valor);
        printf("Probabilidade e estatistica:     %d            %d        %d      R$%.2f\n", Probabilidade.disponivel, Probabilidade.vendido, Probabilidade.id, Probabilidade.valor);
        printf("Fisica:                          %d             %d        %d      R$%.2f\n", Fisica.disponivel, Fisica.vendido, Fisica.id, Fisica.valor);
        printf("Quimica:                         %d             %d        %d      R$%.2f\n", Quimica.disponivel, Quimica.vendido, Quimica.id, Quimica.valor);
        printf("Computacao:                      %d             %d        %d      R$%.2f\n\n", Computacao.disponivel, Computacao.vendido, Computacao.id, Computacao.valor);

        //Perguntar se quer sair
        printf("\nGostaria de sair das compras?\n");
        scanf("%s",voltar); 

        //Pegar o assunto do livro desejado
        int idInput;
        printf("\nTendo a tabela em vista, selecione a descricao do assunto do livro que gostaria com base no Codigo:\n");
        scanf("%d", &idInput);
        desc(idInput);
        
        //Iniciar processo de compra
        printf("Gostaria de comprar algum livro?");
        //scanf("");
    }

    return 0;
}