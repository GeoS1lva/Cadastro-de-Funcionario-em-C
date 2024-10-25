#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

typedef struct
{
    int codico;
    char nome[50];
    char endereco[50];
    char cargo[50];
    char dt_admissao[20];
    char telefone[15];
    float salario;
} reg_funcionarios;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem {
    reg_funcionarios conteudo;
    TipoApontador proxima;
} TipoItem;

typedef struct {
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void tela() {
    
    int i;

    gotoxy(2, 1);
    printf("AUTORA : GEOVANA PAULA DA SILVA..");

    gotoxy(2, 2);
    printf("DATA : 09/10/2024..");

    gotoxy(16, 3);
    printf("SISTEMA DE REGISTRO E CADASTRO DE FUNCIONARIO..");

    gotoxy(1, 4);
    printf("%c", 204);

    gotoxy(79, 4);
    printf("%c", 185);

    gotoxy(1, 23);
    printf("%c", 204);

    gotoxy(79, 23);
    printf("%c", 185);

    for(i = 1; i < 4; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(79, i);
        printf("%c", 186);

    }

    for(i = 24; i < 25; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(79, i);
        printf("%c", 186);

    }

    for(i = 5; i < 23; i++){
        gotoxy(1, i);
        printf("%c", 186);

        gotoxy(79, i);
        printf("%c", 186);

    }

    gotoxy(1, 0);
    printf("%c", 201);

    gotoxy(79, 0);
    printf("%c", 187);

    gotoxy(1, 25);
    printf("%c", 200);

    gotoxy(79, 25);
    printf("%c", 188);

    for(i = 2; i < 79; i++){
        gotoxy(i, 0);
        printf("%c", 205);

        gotoxy(i, 25);
        printf("%c", 205);

        gotoxy(i, 4);
        printf("%c", 205);

        gotoxy(i,23);
        printf("%c", 205);

    }
}

void Inicializa(TipoLista *L){
    L->Primeiro = NULL;
    L->Ultimo = NULL;
}

int Contador(TipoLista *L){
    TipoApontador aux;
    int cont = 0;
    aux = L->Primeiro;

    while(aux != NULL){
        cont++;
        aux = aux->proxima;
    }
    return cont;
}

void TelaCadastro(){
    gotoxy(13,7);
    printf("1.Codico.. ");

    gotoxy(13,9);
    printf("2.Nome.. ");

    gotoxy(13,11);
    printf("3.Endereco.. ");

    gotoxy(13,13);
    printf("4.Cargo.. ");

    gotoxy(13,15);
    printf("5.Data de Admissao.. ");

    gotoxy(13,17);
    printf("6.Telefone.. ");

    gotoxy(13,19);
    printf("7.Salario.. ");
}

TipoApontador pesquisa(TipoLista *L, int cod){
    TipoApontador P;
    P = L->Primeiro;

    if(P == NULL){
        return P;
    }

    while(P != NULL){
        if(P->conteudo.codico == cod){
            return P;
        }
        P = P->proxima;
    }

    return NULL;
}

void Cadastro(TipoLista *L, int opc){
    int escolha = 0;
    int d = 0;
    int num = 0;
    do{
    system("cls");
    tela();
    TelaCadastro();
    TipoApontador P;
    TipoApontador R;
    reg_funcionarios reg_func;

    if(opc == 1){
        gotoxy(20, 3);
        printf("                                                ");
        gotoxy(16, 3);
        printf("Cadastro no Final da Lista");
    }
    else if(opc == 2){
        gotoxy(20, 3);
        printf("                                                ");
        gotoxy(16, 3);
        printf("Cadastro no comeco da Lista");
    }
    else {
        gotoxy(20, 3);
        printf("                                                ");
        gotoxy(16, 3);
        printf("Cadastro em uma posicao da Lista");
    }

    gotoxy(2, 24);
    printf("Insira codico 0 para sair..");

    do{
    gotoxy(35,7);
    scanf("%d", &reg_func.codico);
    fflush(stdin);

    if(reg_func.codico == 0){
        return;
    }
    if(pesquisa(L, reg_func.codico) != NULL){
        gotoxy(13,8);
        printf("Esse codico ja existe!");
        gotoxy(36,8);
        getch();
        gotoxy(13,8);
        printf("                      ");
        gotoxy(31,7);
        printf("       ");
    }

  } while (pesquisa(L, reg_func.codico) != NULL);

    gotoxy(35,9);
    fgets(reg_func.nome, 50, stdin);

    gotoxy(35,11);
    fgets(reg_func.endereco, 50, stdin);

    gotoxy(35,13);
    fgets(reg_func.cargo, 50, stdin);

    gotoxy(35,15);
    fgets(reg_func.dt_admissao, 20, stdin);

    gotoxy(35,17);
    fgets(reg_func.telefone, 15, stdin);

    gotoxy(35,19);
    scanf("%f", &reg_func.salario);
    fflush(stdin);

    gotoxy(2, 24);
    printf("Deseja salvar esse cadastro? 1-sim 2-nao... ");
    gotoxy(54, 24);
    scanf("%d", &escolha);

    if(escolha == 1){
       P = (TipoApontador) malloc (sizeof(TipoItem));
       P->conteudo = reg_func;
       P->proxima = NULL;

       if(L->Primeiro == NULL){
        L->Primeiro = P;
        L->Ultimo = P;
        P->proxima = NULL;
       }
       else if(opc == 1){
        L->Ultimo->proxima = P;
        L->Ultimo = P;
        P->proxima = NULL;
       }
       else if (opc == 2){
        P->proxima = L->Primeiro;
        L->Primeiro = P;
        if(L->Ultimo == NULL){
            L->Ultimo = L->Primeiro;
        }
       }
       else if(opc == 3){
        do{
            gotoxy(2, 24);
            printf("                                                  ");
            gotoxy(54, 24);
            printf("     ");
            gotoxy(2, 24);
            printf("Em qual posicao gostaria de inserir o cadastro?.. ");
            gotoxy(53, 24);
            scanf("%d", &num);

            if(num < 1 || num > Contador(L)){
                gotoxy(58, 24);
                printf("| Posicao Invalida!");
                gotoxy(78, 24);
                getch();
                gotoxy(58, 24);
                printf("                   ");
                gotoxy(53, 24);
                printf("       ");
            }

        } while (num < 1 || num > Contador(L));

            int x;
            R = (TipoApontador) malloc (sizeof(TipoItem));
            R->conteudo = reg_func;

            if(num == 1){
                P->proxima = L->Primeiro;
                L->Primeiro = P;
                if(L->Ultimo == NULL){
                    L->Ultimo = L->Primeiro;
                }
            }
            else{
                P = L->Primeiro;
                for(x = 0; x < num - 1; x++){
                    P = P->proxima;
                }
                R->proxima = P->proxima;
                P->proxima = R;
            }
        }
       else {
        gotoxy(2, 24);
        printf("                                              ");
        gotoxy(54, 24);
        printf("       ");
        gotoxy(2, 24);
        printf("ERRO!");
        getch();
       }
       
    }
    
    system("cls");
    tela();
    gotoxy(2, 24);
    printf("                                              ");
    gotoxy(54, 24);
    printf("       ");
    gotoxy(2, 24);
    printf("Deseja realizar mais um cadastro? 1-sim 2-nao... ");
    gotoxy(54, 24);
    scanf("%d", &d);
    } while(d == 1);
}

void Consulta(TipoLista *L){

    tela();
    int opc;
    int cod;
    TipoApontador p;
    p = L->Primeiro;

    if(p == NULL){
    gotoxy(2, 24);
    printf("A Lista esta vazia!");
    getch();
    return;
    }

    gotoxy(13,13);
    printf("1. Consultar Lista");

    gotoxy(13,15);
    printf("2. Consultar Funcionario");

    gotoxy(2, 24);
    printf("Escolha.. ");
    gotoxy(12, 24);
    scanf("%d", &opc);

    system("cls");
    tela();

    if(opc == 1){
        while(p != NULL){
        
            gotoxy(13,7);
            printf("1.Codico.. %d", p->conteudo.codico);

            gotoxy(13,9);
            printf("2.Nome.. %s", p->conteudo.nome);

            gotoxy(13,11);
            printf("3.Endereco.. %s", p->conteudo.endereco);

            gotoxy(13,13);
            printf("4.Cargo.. %s", p->conteudo.cargo);

            gotoxy(13,15);
            printf("5.Data de Admissao.. %s", p->conteudo.dt_admissao);

            gotoxy(13,17);
            printf("6.Telefone.. %s", p->conteudo.telefone);

            gotoxy(13,19);
            printf("7.Salario.. R$%.2f", p->conteudo.salario);

            gotoxy(13, 24);
            getch();
            p = p->proxima;
        }
    }

    if(opc == 2){
    gotoxy(2, 24);
    printf("Insira o Codico que deseja consultar.. ");
    gotoxy(42, 24);
    scanf("%d", &cod);
    gotoxy(2, 24);
    printf("                                        ");
    gotoxy(42, 24);
    printf("        ");

    while(p != NULL){
        
        if(p->conteudo.codico == cod){
            gotoxy(13,7);
            printf("                                                     ");
            gotoxy(13,7);
            printf("1.Codico.. %d", p->conteudo.codico);

            gotoxy(13,9);
            printf("                                                      ");
            gotoxy(13,9);
            printf("2.Nome.. %s", p->conteudo.nome);

            gotoxy(13,11);
            printf("                                                     ");
            gotoxy(13,11);
            printf("3.Endereco.. %s", p->conteudo.endereco);

            gotoxy(13,13);
            printf("                                                     ");
            gotoxy(13,13);
            printf("4.Cargo.. %s", p->conteudo.cargo);

            gotoxy(13,15);
            printf("                                                     ");
            gotoxy(13,15);
            printf("5.Data de Admissao.. %s", p->conteudo.dt_admissao);

            gotoxy(13,17);
            printf("                                                     ");
            gotoxy(13,17);
            printf("6.Telefone.. %s", p->conteudo.telefone);

            gotoxy(13,19);
            printf("                                                     ");
            gotoxy(13,19);
            printf("7.Salario.. R$%.2f", p->conteudo.salario);

            getch();
            return;
        }
        p = p->proxima;
    }

    gotoxy(2, 24);
    printf("Funcionario nao encontrado!");
    getch();
    return;
    }
}

void remover(TipoLista *L, int opc){
    TipoApontador aux;
    TipoApontador aux2;
    int num;
    int resp;
    int g = 6;

    if(opc == 4){
    if (L->Primeiro->proxima == NULL){
        free(L->Primeiro);
        L->Primeiro = NULL;
        L->Ultimo = NULL;
    }
    else {
        aux = L->Primeiro;
        aux2 = aux->proxima;

        while(aux2->proxima != NULL){
            aux2 = aux2->proxima;
            aux = aux->proxima;
        }
        free(aux2);
        aux->proxima = NULL;
        L->Ultimo = aux;
    }
    }

    if(opc == 5){
        if (L->Primeiro->proxima == NULL){
        free(L->Primeiro);
        L->Primeiro = NULL;
        L->Ultimo = NULL;
        }
        else {
            aux2 = L->Primeiro;
            L->Primeiro = aux2->proxima;
            free(aux2);
        }
    }

    if(opc == 6){
        do{
        system("cls");
        tela();
        int x;
        int cont;
        aux2 = L->Primeiro;

        
        if(aux2 == NULL){
            gotoxy(2,24);
            printf("A Lista esta vazia!");
            gotoxy(23,24);
            getch();
            return;
        }

        for(x = 0; x < Contador(L); x++){
            gotoxy(13,g);
            printf("%d. Codico:.. %d, Nome:.. %s", x + 1, aux2->conteudo.codico, aux2->conteudo.nome);
            aux2 = aux2->proxima;
            g++;
        }

        do{
            gotoxy(55,24);
            printf("| Digite 0 para sair");
            gotoxy(2,24);
            printf("Insira a posicao que seja remover.. ");
            gotoxy(38,24);
            scanf("%d", &num);

            if(num == 0){
                return;
            }

            if(num < 1 || num > Contador(L)){
            gotoxy(38, 24);
            printf("       ");
            gotoxy(55, 24);
            printf("                   ");
            gotoxy(58, 24);
            printf("| Posicao Invalida!");
            gotoxy(78, 24);
            getch();
            gotoxy(58, 24);
            printf("                   ");
            gotoxy(53, 24);
            printf("       ");
            }
        } while(num < 1 || num > Contador(L));

        if(num == 1){
             if (L->Primeiro->proxima == NULL){
                free(L->Primeiro);
                L->Primeiro = NULL;
                L->Ultimo = NULL;
            }
            else {
                aux2 = L->Primeiro;
                L->Primeiro = aux2->proxima;
                free(aux2);
            }

        }

        else{
        aux = L->Primeiro;
        aux2 = aux->proxima;
        cont = 1;

        while(cont < num - 1){
            cont = cont + 1;
            aux2 = aux2->proxima;
            aux = aux->proxima;
        }

        aux->proxima = aux2->proxima;
        free(aux2);
        }

        gotoxy(2,24);
        printf("                                                                           ");
        gotoxy(2,24);
        printf("Deseja realizar mais uma exclusao? 1-sim 2-nao...");
        gotoxy(54,24);
        scanf("%d", &resp);
        }while(resp != 2);

    } 

}

void alterar(TipoLista *L){
    TipoApontador aux;
    reg_funcionarios reg_func;
    int resp;
    int opc;
    do{

        do{
            system("cls");
            tela();
            TelaCadastro();
            gotoxy(2,24);
            printf("Digite o Codico do Funcionario..  | Insira 0 para sair");
            gotoxy(31,7);
            scanf("%d", &reg_func.codico);
            if(reg_func.codico == 0){
                return;
            }
            aux = pesquisa(L, reg_func.codico);
            if(aux == NULL && reg_func.codico != 0){
                gotoxy(2,24);
                printf("                                      ");
                gotoxy(2,24);
                printf("Funcionario nao Cadastrado!");
                gotoxy(30,24);
                getch();

            }
        } while(aux == NULL && reg_func.codico != 0);

        if(reg_func.codico != 0){
            reg_func = aux->conteudo;

            gotoxy(35,9);
            printf("%s", reg_func.nome);

            gotoxy(35,11);
            printf("%s", reg_func.endereco);

            gotoxy(35,13);
            printf("%s", reg_func.cargo);

            gotoxy(35,15);
            printf("%s", reg_func.dt_admissao);

            gotoxy(35,17);
            printf("%s", reg_func.telefone);

            gotoxy(35,19);
            printf("R$%.2f", reg_func.salario);
            gotoxy(36,24);

            do{
                do{
                    gotoxy(2, 24);
                    printf("                                                           ");
                    gotoxy(2, 24);
                    printf("Digite o campo que deseja alterar..    | Insira 0 para sair");
                    gotoxy(38, 24);
                    scanf("%d", &opc);

                    if(opc < 0 || opc > 8){
                        gotoxy(2, 24);
                        printf("                                                           ");
                        gotoxy(2, 24);
                        printf("Posicao Invalida!");
                        gotoxy(20, 24);
                        getch();
                    }
                } while(opc < 0 || opc > 8);

                if(opc != 0){
                    switch (opc){
                    case 1: 
                        gotoxy(2, 24);
                        printf("                                                           ");
                        gotoxy(2, 24);
                        printf("O campo 1 nao pode ser alterado!");
                        gotoxy(35, 24);
                        getch();
                        break;
                    case 2:
                        gotoxy(35,9);
                        printf("                                  ");
                        fflush(stdin);
                        gotoxy(35,9);
                        fgets(reg_func.nome, 50, stdin);
                        break;
                    case 3:
                        gotoxy(35,11);
                        printf("                                  ");
                        fflush(stdin);
                        gotoxy(35,11);
                        fgets(reg_func.endereco, 50, stdin);
                        break;
                    case 4:
                        gotoxy(35,13);
                        printf("                                  ");
                        fflush(stdin);
                        gotoxy(35,13);
                        fgets(reg_func.cargo, 50, stdin);
                        break;
                    case 5:
                        gotoxy(35,15);
                        printf("                                  ");
                        fflush(stdin);
                        gotoxy(35,15);
                        fgets(reg_func.dt_admissao, 20, stdin);
                        break;
                    case 6:
                        gotoxy(35,17);
                        printf("                                  ");
                        fflush(stdin);
                        gotoxy(35,17);
                        fgets(reg_func.telefone, 15, stdin);
                        break;
                    case 7:
                        gotoxy(35,19);
                        printf("                                  ");
                        gotoxy(35,19);
                        scanf("%f", &reg_func.salario);
                        break;
                    }
                }
            } while (opc != 0);
            gotoxy(2, 24);
            printf("                                                           ");
            gotoxy(2, 24);
            printf("Salvar alteracao? 1-sim 2-nao... ");
            gotoxy(42,24);
            scanf("%d", &resp);
            if(resp == 1){
                aux->conteudo = reg_func;
            }
        }

        gotoxy(2, 24);
        printf("                                                           ");
        gotoxy(2, 24);
        printf("Deseja alterar outro Funcionario? 1-sim 2-nao... ");
        gotoxy(52,24);
        scanf("%d", &resp);
    } while(resp == 1);
}

void RemoverQuebraDeLinha(char *str)
{
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
    {
        *pos = '\0';
    }
}

void SalvarEmArquivo(TipoLista *L)
{
    TipoApontador p;
    p = L->Primeiro;

    FILE *file = fopen("dados.txt", "w");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (p != NULL)
    {
        RemoverQuebraDeLinha(p->conteudo.nome);
        RemoverQuebraDeLinha(p->conteudo.endereco);
        RemoverQuebraDeLinha(p->conteudo.cargo);
        RemoverQuebraDeLinha(p->conteudo.dt_admissao);
        RemoverQuebraDeLinha(p->conteudo.telefone);
        fprintf(file, "%d;", p->conteudo.codico);
        fprintf(file, "%s;", p->conteudo.nome);
        fprintf(file, "%s;", p->conteudo.endereco);
        fprintf(file, "%s;", p->conteudo.cargo);
        fprintf(file, "%s;", p->conteudo.dt_admissao);
        fprintf(file, "%s;", p->conteudo.telefone);
        fprintf(file, "%.2f;", p->conteudo.salario);
        p = p->proxima;

        if (p != NULL)
        {
            fprintf(file, "\n");
        }
    }

    fclose(file);

    printf("Arquivo salvo");

    return;
}

void CarregarArquivo(TipoLista *lista)
{
    FILE *file = fopen("dados.txt", "r");

    if (file == NULL)
    {
        printf("Nenhum dado foi carregado do arquivo.\n");
        return;
    }

    char linha[300];
    

    while (fgets(linha, sizeof(linha), file))
    {
        TipoApontador funcionario = (TipoApontador)malloc(sizeof(TipoItem));
        int itens;
        itens = sscanf(linha, "%d;%49[^;];%99[^;];%49[^;];%10[^;];%14[^;];%f;",
                           &funcionario->conteudo.codico,
                           funcionario->conteudo.nome,
                           funcionario->conteudo.endereco,
                           funcionario->conteudo.cargo,
                           funcionario->conteudo.dt_admissao,
                           funcionario->conteudo.telefone,
                           &funcionario->conteudo.salario);

        if (itens != 7)
        {
            printf("Erro ao ler a linha do arquivo. Dados incorretos ou incompletos.\n");
            free(funcionario);
            continue;
        }
        if (lista->Primeiro == NULL)
        {

            lista->Primeiro = funcionario;
            lista->Ultimo = funcionario;
        }
        else
        {
            lista->Ultimo->proxima = funcionario;
            lista->Ultimo = funcionario;
        }
        funcionario->proxima = NULL;
    }

    printf("Finalizado");
    fclose(file);
}

int main (){
    int opcao;
    TipoLista lista;
    Inicializa(&lista);
    CarregarArquivo(&lista);
    system("Color 5");

    do{
        system("cls");
        tela();

        gotoxy(13,5);
        printf("1. Cadastrar Funcionario no Final da Lista..");

        gotoxy(13,7);
        printf("2. Cadastrar Funcionario no Inicio da Lista");

        gotoxy(13,9);
        printf("3. Cadastrar Funcionario em uma Posicao da Lista");

        gotoxy(13,11);
        printf("4. Remover Funcionario no Final da Lista");

        gotoxy(13,13);
        printf("5. Remover Funcionario no Inicio da Lista");

        gotoxy(13,15);
        printf("6. Remover Funcionario em uma Posicao da Lista");

        gotoxy(13,17);
        printf("7. Alteracao do Cadastro de Funcionario");

        gotoxy(13,19);
        printf("8. Consultar Funcionarios");

        gotoxy(13,21);
        printf("9. Sair do Programa");

        gotoxy(2, 24);
        printf("Selecione a opcao... ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            system("cls");
            Cadastro(&lista, opcao);


            break;
        case 2:
            system("cls");
            Cadastro(&lista, opcao);

            break;
        
        case 3:
            system("cls");
            Cadastro(&lista, opcao);

            break;

        case 4:
            remover(&lista, opcao);

            break;

        case 5:
            remover(&lista, opcao);

            break;

        case 6:
            remover(&lista, opcao);

            break;

        case 7:
            system("cls");
            alterar(&lista);
            break;
        
        case 8:
            system("cls");
            Consulta(&lista);
            break;
        case 9:
           SalvarEmArquivo(&lista);
           break;
        default:
            gotoxy(2, 24);
            printf("                                              ");
            gotoxy(2, 24);
            printf("Opcao invalida!");
            gotoxy(17, 24);
            getch();
        }
    } while (opcao != 9);
}