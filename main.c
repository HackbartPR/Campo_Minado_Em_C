#include <stdio.h>
#include <stdlib.h>

void setBomb(char matriz[][10]);
void setValues(char campo[][10]);
void setSquare(char campo[][10]);
void showTheGame(char campo[][10]);
void fillNewCampo(char newCampo[][10]);
int showItens(char campo[][10], char newCampo[][10],int posLin,int posCol);
void gameOver(char campo[][10], char newCampo[][10]);

int main()
{
    char campo[10][10];
    char newCampo[10][10];

    //INSERINDO AS MARGENS E CAMPO DE JOGO
    setSquare(campo);
    //INSERINDO BOMBAS
    setBomb(campo);
    //MARCA OS NUMEROS ADJACENTES AS BOMBAS
    setValues(campo);
    //CRIAR NOVO TABULEIRO
    fillNewCampo(newCampo);

    int posLin = 0;
    int posCol = 0;
    int isContinue = 0;
    int count = 0;
    do{
        //MOSTRAR O TABULEIRO
        showTheGame(newCampo);

        printf("DIGITE UMA POSICAO: VALORES COMECAM A PARTIR DO NUMERO 1:\n");
        printf("LINHA: ");
        scanf("%d", &posLin);
        printf("COLUNA: ");
        scanf("%d", &posCol);

        if(posLin < 1 || posLin > 8 || posCol < 1 || posCol > 8)
            break;

        isContinue = showItens(campo, newCampo,posLin,posCol);
        system("clear || cls");

        if(!isContinue){
            gameOver(campo, newCampo);
            showTheGame(newCampo);
            printf("\n ######## GAME OVER ######## \n");
        }

        count++;

        if(count >= 54){
            showTheGame(newCampo);
            printf("\n ######## PARABENS, VOCE VENCEU! ######## \n");
        }

    }while(posLin != 0 && posCol != 0 && isContinue && count < 54);

    return 0;
}

void setBomb(char matriz[][10]){
    int count = 0;

    time_t t;
    srand((unsigned) time(&t));

    do{
        int lin = (rand() % 8) + 1;
        int col = (rand() % 8) + 1;

        if(matriz[lin][col] == 48){
            matriz[lin][col] = 207;
            count++;
        }

    }while(count < 10);
}

void setValues(char campo[][10]){

    for(int lin=1; lin < 10; lin++){
        for(int col=1; col < 10; col++){
           if(campo[lin][col] == -49){

                //AJUSTANDO OS CANTOS
                if(lin == 1 && col == 1){
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col+1] != -49)
                        campo[lin+1][col+1] += 1;
                }

                if(lin == 1 && col == 8){
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col-1] != -49)
                        campo[lin+1][col-1] += 1;
                }

                if(lin == 8 && col == 1){
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin-1][col+1] != -49)
                        campo[lin-1][col+1] += 1;
                }

                if(lin == 8 && col == 8){
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin-1][col-1] != -49)
                        campo[lin-1][col-1] += 1;
                }

                //AJUSTANDO A PRIMEIRAS E ULTIMA LINHA
                if(lin == 1 && col > 1 && col < 8){
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin+1][col-1] != -49)
                        campo[lin+1][col-1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col+1] != -49)
                        campo[lin+1][col+1] += 1;
                }

                if(lin == 8 && col > 1 && col < 8){
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin-1][col-1] != -49)
                        campo[lin-1][col-1] += 1;
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin-1][col+1] != -49)
                        campo[lin-1][col+1] += 1;
                }

                //AJUSTANDO A PRIMEIRAS E ULTIMA COLUNA
                if(col == 1 && lin > 1 && lin < 8){
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin-1][col+1] != -49)
                        campo[lin-1][col+1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col+1] != -49)
                        campo[lin+1][col+1] += 1;
                }

                if(col == 8 && lin > 1 && lin < 8){
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin-1][col-1] != -49)
                        campo[lin-1][col-1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col-1] != -49)
                        campo[lin+1][col-1] += 1;
                }


                if(lin > 1 && lin < 8 && col > 1 && col < 8){
                    if(campo[lin][col-1] != -49)
                        campo[lin][col-1] += 1;
                    if(campo[lin][col+1] != -49)
                        campo[lin][col+1] += 1;
                    if(campo[lin-1][col-1] != -49)
                        campo[lin-1][col-1] += 1;
                    if(campo[lin-1][col] != -49)
                        campo[lin-1][col] += 1;
                    if(campo[lin-1][col+1] != -49)
                        campo[lin-1][col+1] += 1;
                    if(campo[lin+1][col-1] != -49)
                        campo[lin+1][col-1] += 1;
                    if(campo[lin+1][col] != -49)
                        campo[lin+1][col] += 1;
                    if(campo[lin+1][col+1] != -49)
                        campo[lin+1][col+1] += 1;
                }
           }
        }
    }
}

void setSquare(char campo[][10]){
    //MARCA OS LIMITES DO CAMPO COM 1 E O RESTANTO COM ZERO
    for(int lin=0; lin < 10; lin++){
        for(int col=0; col < 10; col++){
           if(lin == 0 || lin == 9 || col == 0 || col == 9)
                campo[lin][col] = ' ';
            else
                campo[lin][col] = 48;
        }
    }
}

void showTheGame(char campo[][10]){
    //MOSTRAR CAMPO MINADO
    for(int lin=0; lin < 10; lin++){
        for(int col=0; col < 10; col++){
          printf("%c ", campo[lin][col]);
        }
        printf("\n");
    }
}

int showItens(char campo[][10], char newCampo[][10],int posLin,int posCol){
    int isContinue = 1;


        newCampo[posLin][posCol] = campo[posLin][posCol];

    if(newCampo[posLin][posCol] == -49)
        isContinue = 0;

    return isContinue;
}

void fillNewCampo(char newCampo[][10]){
    //MARCA OS LIMITES DO CAMPO COM 1 E O RESTANTO COM ZERO
    for(int lin=0; lin < 10; lin++){
        for(int col=0; col < 10; col++){
           if(lin == 0 || lin == 9 || col == 0 || col == 9)
                newCampo[lin][col] = ' ';
            else
                newCampo[lin][col] = 43;
        }
    }
}

void gameOver(char campo[][10], char newCampo[][10]){
    for(int lin=0; lin < 10; lin++){
        for(int col=0; col < 10; col++){
           newCampo[lin][col] = campo[lin][col];
        }
    }
}

