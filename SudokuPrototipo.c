#include <stdio.h>
#include <stdlib.h>
#include <time.h> //necessário para usar localtime() e struct tm

#define ENTRADA "entrada.csv"
#define SAIDA "saida.csv"
#define TAM_VETOR 10
#define LINHAS 9
#define COLUNAS 9

typedef struct {
    char nome[50];
    int idade;
    float altura;
    char sexo;
} Pessoa;

void printSudoku(int sudoku[LINHAS][COLUNAS]);
void resolverSudoku(int sudoku[LINHAS][COLUNAS]);
void zerarSudoku(int sudoku[LINHAS][COLUNAS]);
int resolucaoSudoku (int sudoku[LINHAS][COLUNAS]);
    int comparador(void * a, void * b);

    


int sudoku[LINHAS][COLUNAS]=
{
        5,3,4,6,7,8,9,1,2,
        6,7,2,1,9,5,3,4,8,
        1,9,8,3,4,2,5,6,7,
        8,5,9,7,6,1,4,2,3,
        4,2,6,8,5,3,7,9,1,
        7,1,3,9,2,4,8,5,6,
        9,6,1,5,3,7,2,8,4,
        2,8,7,4,1,9,6,3,5,
        3,4,5,2,8,6,1,0,0
};



int main()
{


            int opcao;


        printf("Jogo sudoku: \n");
        printf("0 - Finalizar\n");
        printf("1 - Jogar\n");
        printf("2 - Intrucoes\n");
        printf("opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        

        if(opcao == 0){
            exit(0);
        }



    time_t start, end;

        if(opcao == 1)
        {
                    
    time(&start);
  

            do
            {

                printSudoku(sudoku);
                resolverSudoku(sudoku);
                zerarSudoku(sudoku);
           }
            while(resolucaoSudoku(sudoku) == 0);
            
    time(&end);
            
    double time_taken = (end - start);
    printf("%f sec", time_taken);

        }


        if(opcao == 2)
        {
            printf("1� Regra - Cada linha deve conter os numeros de 1 a 9, sem repeticoes \n O jogador deve preencher cada linha da tabela com cuidado para que nao existam duplicados nestas no final. A ordem numerica e irrelevante. \nCada puzzle, independentemente do seu nivel de dificuldade, inicia com numeros pre-colocados na tabela. O jogador deve utilizar estes digitos como pistas para encontrar quais os numeros em falta em cada linha e as suas posioes.\n2� Regra - Os numeros de 1 a 9 apenas podem estar presentes uma vez por coluna\nAs regras do Sudoku para as colunas sao exatamente as mesmas que para as linhas. Tambem para estas o jogador deve preencher as quadriculas com os numeros de 1 a 9, sem repeti��es por coluna.\nOs numeros oferecidos ao inicio do puzzle funcionam como pistas para descobrir quais sao os digitos em falta em cada coluna.\n3� Regra - Cada digito apenas pode estar presente uma vez por grupo\nUma tabela de Sudoku tradicional de 9 x 9 esta dividida em 9 grupos mais pequenos de 3 x3. Os numeros de 1 a 9 apenas podem estar presentes uma vez em cada um destes grupos.\nNa pratica, isto significa que o processo de preencher as colunas e linhas sem duplicados encontra dentro de cada grupo restri�oes ao posicionamento dos numeros.\n4� Regra - O valor da soma de cada linha, coluna e grupo e de 45\nPara descobrir quais os numeros em falta em cada linha, coluna ou grupo, o jogador pode simplesmente conta-los ou praticar os seus dotes matematicos e soma-los.\nQuando nao existem digitos duplicados a soma individual de cada linha, coluna e grupo e sempre de 45:\n1+2+3+4+5+6+7+8+9= 45");
            printf("\nDigite 1 para retornar ao inicio do jogo: ");
            scanf("%d", &opcao);
        }

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
            if(i == 2 && j == 8 || i == 5 && j == 8 )  //se chegar ao final da terceira linha ou da sexta, ele vai printar uma linha de tra�o e seguir a vida
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
        printf("Espero que voce tenha lido as instrucoes senao tera serios problemas durante o jogo hahahaha \n");
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
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 2)
            {
                verificar2++;
                if(verificar2 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 3)
            {
                verificar3++;
                if(verificar3 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 4)
            {
                verificar4++;
                if(verificar4 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 5)
            {
                verificar5++;
                if(verificar5 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 6)
            {
                verificar6++;
                if(verificar6 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 7)
            {
                verificar7++;
                if(verificar7 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 8)
            {
                verificar8++;
                if(verificar8 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }
            else if(sudoku[i][j] == 9)
            {
                verificar9++;
                if(verificar9 > 9)
                {
                    printf("Pense de novo...\n");
                    sleep(2);
                }
            }

        }
    }
    return;
}

int resolucaoSudoku (int sudoku[LINHAS][COLUNAS])
{
     int acertos=0;
                   

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

    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            if(sudoku[i][j] == sudoku2[i][j]){
                acertos++;
            }
        }
    }

    if(acertos==81){
        printf("Parabens voce ganhou!!!!");


            Pessoa p[TAM_VETOR];
    int i = 0;

    // Abre o arquivo entrada.csv como leitura.
    FILE * entrada = fopen(ENTRADA, "r");

    // Se conseguiu abrir o arquivo de entrada ...
    if (entrada == NULL) {
        printf("ERRO: nao foi possivel abrir o arquivo %s.\n", ENTRADA);
        return 1;
    }

    /* Consome a primeira linha do arquivo de entrada, sem armazenar em vari�vel.
        O * (aster�sco) serve para suprimir a entrada (consumir sem armazenar).
    */
    fscanf(entrada, "%*[^\n] ");

    // Enquanto n�o chegou ao fim do arquivo ...
    while (! feof(entrada)) {
        // L� o nome, a idade e altura da linha atual, pulando para pr�xima linha.
        int r = fscanf(entrada, "%[^,] , %d",
                       &p[i].nome, &p[i].idade);

        // Se leu 3 valores no fscanf() anterior...
        if (r < 3) {
            printf("ERRO: arquivo mal formatado na linha %d.\n");
            return 2;
        }

        // Imprime os dados na tela.


        // Avan�a na posi��o do vetor.
        i++;
    }

    // Fecha o arquivo de entrada.
    fclose(entrada);

    // captura o tamanho l�gico do vetor.
    int tam = i;

    // Ordena o vetor p utilizando a fun��o comparador para comparar as pessoas.
    qsort(p, tam, sizeof(Pessoa), comparador );

    FILE * saida = fopen(SAIDA, "w");
    // Se conseguiu abrir o arquivo de saida ...
    if (saida == NULL) {
        printf("ERRO: nao foi possivel abrir o arquivo %s.\n", SAIDA);
        return 1;
    }

    fprintf(saida, "IDADE,NOME\n");


    for(i=0; i<tam; i++) {
        fprintf(saida, "%d,%s\n", p[i].idade, p[i].nome);

    }

    // fecha o arquivo de sa�da.
    fclose(saida);

    return 1;
    }
    return 0;
}

int comparador(void * a, void * b) {
    Pessoa * pa = (Pessoa *) a;
    Pessoa * pb = (Pessoa *) b;

    // retorna a diferen�a de idade entre ambos.
    return pa->idade - pb->idade;
}


