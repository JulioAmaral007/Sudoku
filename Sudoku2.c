#include <stdio.h>


#define LINHAS 9
#define COLUNAS 9

void printSudoku(int sudoku[LINHAS][COLUNAS]);
void resolverSudoku(int sudoku[LINHAS][COLUNAS]);
void zerarSudoku(int sudoku[LINHAS][COLUNAS]);
//void resolucaoSudoku (int sudoku[LINHAS][COLUNAS]);


int main()
{
    int sudoku[LINHAS][COLUNAS]=
    {
        5,3,0,0,7,0,0,1,0,
        6,0,0,1,0,5,0,0,8,
        0,0,8,0,0,0,0,6,0,
        8,0,0,0,6,0,0,0,3,
        4,0,0,8,0,3,0,0,1,
        7,0,0,0,2,0,0,0,6,
        0,6,0,0,0,0,2,8,0,
        0,0,0,4,1,9,0,0,5,
        0,0,0,0,8,0,0,7,9
    };
    int opcao;

    do
    {
        printf("Jogo sudoku: \n");
        printf("0 - Finalizar\n");
        printf("1 - Jogar\n");
        printf("2 - Intrucoes\n");
        printf("opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        if(opcao == 1)
        {
            do
            {

                printSudoku(sudoku);
                resolverSudoku(sudoku);
                zerarSudoku(sudoku);
                // resolucaoSudoku(sudoku);

            }
            while(opcao !=0);
        } // mudar while

        if(opcao == 2)
        {
            printf("1ª Regra - Cada linha deve conter os numeros de 1 a 9, sem repetições \n O jogador deve preencher cada linha da tabela com cuidado para que não existam duplicados nestas no final. A ordem numérica é irrelevante. \nCada puzzle, independentemente do seu nível de dificuldade, inicia com números pré-colocados na tabela. O jogador deve utilizar estes dígitos como pistas para encontrar quais os números em falta em cada linha e as suas posições.\n2ª Regra - Os números de 1 a 9 apenas podem estar presentes uma vez por coluna\nAs regras do Sudoku para as colunas são exatamente as mesmas que para as linhas. Também para estas o jogador deve preencher as quadrículas com os números de 1 a 9, sem repetições por coluna.\nOs números oferecidos ao início do puzzle funcionam como pistas para descobrir quais são os dígitos em falta em cada coluna.\n3ª Regra - Cada dígito apenas pode estar presente uma vez por grupo\nUma tabela de Sudoku tradicional de 9 x 9 está dividida em 9 grupos mais pequenos de 3 x3. Os números de 1 a 9 apenas podem estar presentes uma vez em cada um destes grupos.\nNa prática, isto significa que o processo de preencher as colunas e linhas sem duplicados encontra dentro de cada grupo restrições ao posicionamento dos números.\n4ª Regra - O valor da soma de cada linha, coluna e grupo é de 45\nPara descobrir quais os números em falta em cada linha, coluna ou grupo, o jogador pode simplesmente contá-los ou praticar os seus dotes matemáticos e somá-los.\nQuando não existem dígitos duplicados a soma individual de cada linha, coluna e grupo é sempre de 45:\n1+2+3+4+5+6+7+8+9= 45");
            printf("\nDigite 1 para retornar ao inicio do jogo: ");
            scanf("%d", &opcao);
        }

    }
    while(opcao != 0);
}

void printSudoku(int sudoku[LINHAS][COLUNAS])
{

    system("cls");
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if(j == 3 || j == 6)  //caso seja coluna 4 ou 7, ele vai printar um divisor vertical
            {
                printf("| ");
            }
            printf("%d ", sudoku[i][j]); // printa o valor do sudoku
            if(i == 2 && j == 8 || i == 5 && j == 8 )  //se chegar ao final da terceira linha ou da sexta, ele vai printar uma linha de traço e seguir a vida
            {
                printf("\n");
                for(int traco = 0; traco < 21; traco++)
                {
                    printf("-");
                }
            }
        }
        printf("\n");
    }
}


void resolverSudoku(int sudoku[LINHAS][COLUNAS])
{

    int x,y;

    do
    {
        printf("Espero que voce tenha lido as intrucoes senao tera serios problemas durante o jogo hahahaha \n");
        printf("Digite as coordenadas X (Linha) - Y (Coluna): ");
        printf("\nAs coordenadas sao de 0-0 ate 8-8. \nEx: 0-8, 5-6.\n");
        printf("X-Y: ");
        scanf("%d-%d",&x,&y);
    }
    while((x<0 || x>9) || (y<0 || y>9));

    do
    {
        printf("Valor: ");
        scanf("%d", &sudoku[x][y]);
    }
    while((sudoku[x][y]<1) || (sudoku[x][y]>9) );

    return;
}

void zerarSudoku(int sudoku[LINHAS][COLUNAS])
{
    int verificar = 0;
    int verificar2 = 0;
    int verificar3 = 0;
    int verificar4 = 0;
    int verificar5 = 0;
    int verificar6 = 0;
    int verificar7 = 0;
    int verificar8 = 0;
    int verificar9 = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(sudoku[i][j] == 1)
            {
                verificar++;
                if(verificar > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 2)
            {
                verificar2++;
                if(verificar2 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 3)
            {
                verificar3++;
                if(verificar3 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 4)
            {
                verificar4++;
                if(verificar4 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 5)
            {
                verificar5++;
                if(verificar5 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 6)
            {
                verificar6++;
                if(verificar6 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 7)
            {
                verificar7++;
                if(verificar7 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 8)
            {
                verificar8++;
                if(verificar8 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 9)
            {
                verificar9++;
                if(verificar9 > 9)
                {
                    printf("errou\n");
                    sleep(2);
                }
            }

        }
    }

    /*for (int valor = 1; valor < 10; valor++)
    {
        int verificar = 0;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(sudoku[i][j] == valor)
                {
                    verificar++;
                    printf("%d", &sudoku[i]);

                }
            }



        }

        printf("\n%d", &verificar);
    }*/
    return;
}

/* void resolucaoSudoku (int sudoku[LINHAS][COLUNAS])
 {

     int valor = 0;
     int verificar = 0;
     int sudoku2[LINHAS][COLUNAS]=
     {
         5,3,4,6,7,8,9,1,2,
         6,7,2,1,9,5,3,4,8,
         1,9,8,3,4,2,5,6,7,
         8,5,9,7,6,1,4,2,3,
         4,2,6,8,5,3,7,9,1,
         7,1,3,9,2,4,8,5,6,
         9,6,1,5,3,7,2,8,4,
         2,8,7,4,1,9,6,3,5,
         3,4,5,2,8,6,1,7,9
     };

     for (int i = 0; i < LINHAS; i++)
     {
         for (int j = 0; j < COLUNAS; j++)
         {
             if(sudoku == sudoku2)
             {
                 printf("Parabéns voce ganhou!!");
                 sleep(10);
             }
             else
             {
                 return;
             }
         }
     }
 }*/

