#include <stdio.h>
#include <conio.h>
#include<windows.h>

int vez, d=3;

struct Cadastro{
    char jogador1[50] , jogador2[50];
    int recorde1 , recorde2;
}c;

void Cronometro(){
    int i = 0;

    while(i<10){
        printf("\n\tDuração da Partida: %dh:%dm:%ds\n", hr , min , sec);
        Sleep(1000);
        system("cls");
        sec++;

        if(sec == 60){
            sec = 0;
            min++;
        }
        if(min == 60){
            min = 0;
            hr++;
        }
        if(hr == 24){
            hr = 0;
        }
    }
}

void Placar(){

    printf("\t\t\t     Vitorias do jogador %s  =  %d   \n",c.jogador1 , c.recorde1);
    printf("\t\t\t     Vitorias do jogador %s  =  %d   \n",c.jogador2 , c.recorde2);

}
void Cadastrar(){

    printf("Digite o nome do jogador 1:\n");
    scanf("%s", &c.jogador1);
    printf("Digite o nome do jogador 2:\n");
    scanf("%s", &c.jogador2);

}
int main(){
    system("color fc");
    int tabuleiro[d][d], continuar;

    do{
        vez=1;
        continuar = menu();
        if(continuar == 1){
            jogar(tabuleiro);
        }
        else if(continuar == 4 ){
            Criadores();
        }
        else if (continuar == 3){
            ComoJogar(tabuleiro);
        }
        else if (continuar == 2){
            Cadastrar();
        }
        else if (continuar == 5){
            Placar();
        }

    }while(continuar);

}



int menu(){
    int opcao;
    textcolor(BLACK);
        printf("\t\t\t __________________________________\n\t\t\t|");
        printf("\t\t\t\t   |\n\t\t\t|     *****JOGO DA VELHA*****\t   |\n\t\t\t|\t\t\t\t   |\n");
        printf("\t\t\t|     Jogar                  (1)   |\n");
        printf("\t\t\t|     Cadastrar Jogadores    (2)   |\n");
        printf("\t\t\t|     Como Jogar             (3)   |\n");
        printf("\t\t\t|     Creditos               (4)   |\n");
        printf("\t\t\t|     Placar dos Jogadores   (5)   |\n");
        printf("\t\t\t|     Sair                   (0)   |\n");
        printf("\t\t\t|__________________________________|\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
           case 1:
           case 2:
           case 3:
           case 4:
           case 5:
           case 0:
                break;
           default:

                printf("Opcao invalida. Tente de novo!\n");

        }

    return opcao;
}


void Criadores(){

    printf("\t\t\t __________________________________\n");
    printf("\t\t\t|      *****CRIADORES*****         |\n");
    printf("\t\t\t|                                  |\n");
    printf("\t\t\t|      Victor Hugo Marques         |\n");
    printf("\t\t\t|      Marcus Vinicius Marques     |\n");
    printf("\t\t\t|      Marcio Rodrigues            |\n");
    printf("\t\t\t|__________________________________|\n\n\n");


}
void ComoJogar(){
    textcolor(GREEN);
    printf("Cada posicao corresponde a um numero do Tabuleiro!\n\n");
    int d = 3;
    int m[d][d] , linha , coluna , a = 1;
    for(linha = 0; linha < d; linha ++){
        for(coluna = 0; coluna < d; coluna ++){
            printf(" %d |",a++);
        }
        printf("\n");
    }
    printf("\nGanha o jogador que tiver o seu simbolo ( X ou O ) em 3 posicoes sequenciais!\n\n");
    printf("EXEMPLO 1\n\n");
    for(linha = 0; linha < d; linha ++){
        for(coluna = 0; coluna < d; coluna ++){
            if(linha == coluna){
                printf("X");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("EXEMPLO 2\n\n");
    for(linha = 0; linha < d; linha ++){
        for(coluna = 0; coluna < d; coluna ++){
            if(linha == 0 && coluna == 0){
                printf("X");
            }
            else if(linha == 1 && coluna == 0){
                printf("X");
            }
            else if (linha == 2 && coluna == 0){
                printf("X");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("EXEMPLO 3\n\n");
    for(linha = 0; linha < d; linha ++){
        for(coluna = 0; coluna < d; coluna ++){
            if(linha == 0 && coluna == 0){
                printf("X  ");
            }
            else if(linha == 0 && coluna == 1){
                printf("X  ");
            }
            else if (linha == 0 && coluna == 2){
                printf("X");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }


}

void zeraTabuleiro(int tabuleiro[][d]){
    int linha, coluna;
    for(linha = 0 ; linha < d ; linha++)
        for(coluna = 0 ; coluna < d ; coluna++)
            tabuleiro[linha][coluna] = 0;
}

void exibeTabuleiro(int tabuleiro[][d]){
    int linha, coluna;
    textcolor(BLACK);
    printf("\n");

    for(linha = 0 ; linha < d ; linha++){
        for(coluna = 0 ; coluna < d ; coluna++){
            if(tabuleiro[linha][coluna] == 0){
                printf("    ");

            }
            else if(tabuleiro[linha][coluna] == 1){
                    textcolor(RED);
                    printf("  X ");
                    textcolor(BLACK);
            }
                else{
                    textcolor(BLUE);
                    printf("  O ");
                    textcolor(BLACK);
                }
            if(coluna != (d-1)){
                textcolor(BLACK);
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");

}

void jogar(int tabuleiro[][d]){

    int continua;
    zeraTabuleiro(tabuleiro);

    do{
        system("cls");
        exibeTabuleiro(tabuleiro);
        jogada(tabuleiro);

    }while(checaTermino(tabuleiro, vez) != 1);
}


int checaLocal(int tabuleiro[][d], int linha, int coluna){
    if(linha < 0 || linha > (d-1) || coluna < 0 || coluna > (d-1) || tabuleiro[linha][coluna] != 0){
        return 0;
    }
    else{
        return 1;
    }
}

int checaLinha(int tabuleiro[][d]){
    int linha, coluna,
        soma;

    for(linha = 0 ; linha < d ; linha++){
        soma=0;

        for(coluna = 0 ; coluna < d ; coluna++){
            soma += tabuleiro[linha][coluna];
        }

        if(soma==d || soma == (-1)*d){
            return 1;
        }
    }

    return 0;
}

int checaColuna(int tabuleiro[][d]){
    int linha, coluna,
        soma;


    for(coluna = 0 ; coluna < d ; coluna++){
        soma=0;

        for(linha = 0 ; linha < d ; linha++){
            soma += tabuleiro[linha][coluna];
        }
        if(soma==d || soma == (-1)*d){
            return 1;
        }
    }

    return 0;
}

int checaDiagonal(int tabuleiro[][d]){
    int linha , diagonal_principal=0 , diagonal_secundaria=0;

    for(linha = 0 ; linha < d ; linha++){
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][d-linha-1];
    }

    if(diagonal_principal==d || diagonal_principal==(-1)*d || diagonal_secundaria==d || diagonal_secundaria==(-1)*d){
       return 1;
    }

    return 0;
}

int checaEmpate(int tabuleiro[][d])
{
    int linha, coluna;

    for(linha = 0 ; linha < d ; linha++)
        for(coluna = 0 ; coluna < d ; coluna++){
            if(tabuleiro[linha][coluna] == 0)
                return 0;
        }
    return 1;
}

int checaTermino(int tabuleiro[][d], int vez)

{
    if(checaLinha(tabuleiro))
    {
        textcolor(RED);
      if(((vez % 2) + 1) ==  1){
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador1);

        exibeTabuleiro(tabuleiro);
        c.recorde1++;

      }
    else{
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador2);

        exibeTabuleiro(tabuleiro);
        c.recorde2++;

    }
    return 1;

    }

    if(checaColuna(tabuleiro))
    {
        textcolor(RED);
      if(((vez % 2) + 1) ==  1){
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador1);

        exibeTabuleiro(tabuleiro);
        c.recorde1++;

      }
    else{
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador2);

        exibeTabuleiro(tabuleiro);
        c.recorde2++;

    }
        return 1;
    }

    if(checaDiagonal(tabuleiro))
    {
        textcolor(RED);
      if(((vez % 2) + 1) ==  1){
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador1);

        exibeTabuleiro(tabuleiro);
        c.recorde1++;

      }
    else{
        printf("JOGO ENCERRADO !!! JOGADOR %s VENCEU !!!\n\n", c.jogador2);

        exibeTabuleiro(tabuleiro);
        c.recorde2++;
    }
    return 1;

    }

    if(checaEmpate(tabuleiro))
    {
        textcolor(RED);
        printf("JOGO ENCERRADO !!! OCORREU UM EMPATE !!!\n\n");

        exibeTabuleiro(tabuleiro);

    }

    return 0;
}

void jogada(int tabuleiro[][d])
{
    int linha, coluna, play;
    vez++;
    if(((vez % 2) + 1) ==  1)
    printf("\n--> Jogador %s \n",c.jogador1 );
    else{
        printf("\n--> Jogador %s \n",c.jogador2 );
    }

    do
    {
        printf("Digite a posicao da jogada: ");
        scanf("%d",&play);
            switch(play){
                case 1:
                    linha = 0;
                    coluna = 0;
                    break;
                case 2:
                    linha = 0;
                    coluna = 1;
                    break;
                case 3:
                    linha = 0;
                    coluna = 2;
                    break;
                case 4:
                    linha = 1;
                    coluna = 0;
                    break;
                case 5:
                    linha = 1;
                    coluna = 1;
                    break;
                case 6:
                    linha = 1;
                    coluna = 2;
                    break;
                case 7:
                    linha = 2;
                    coluna = 0;
                    break;
                case 8:
                    linha = 2;
                    coluna = 1;
                    break;
                case 9:
                    linha = 2;
                    coluna = 2;
                    break;

        }

        if(checaLocal(tabuleiro, linha, coluna) == 0){
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
        }
    } while(checaLocal(tabuleiro, linha, coluna) == 0);

    if(vez%2){
        tabuleiro[linha][coluna] = -1;
    }
    else{
        tabuleiro[linha][coluna] = 1;
    }
}
