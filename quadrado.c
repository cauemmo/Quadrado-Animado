/*Programa: quadrado animado.
  Descrição: Esse programa realiza a animação de um quadrado.Dessa forma,é também possível alterar a área,cor,velocidade,dentre outros parâmetros.
  Programador: Cauê Mendonça Magela do Ó.
  RGM: 43558.
  Data da ultima modificação: 25/04/2023*/

/*instruções para Compilação: Utilize a linha de comândo a seguir para compilar o programa 
 gcc -o main.exe quadrado.c graphics_v1.1.c conio_v3.2.4.c -lgdi32 -Wall -pedantic -Wextra -Werror */

#include "conio_v3.2.4.h"  /* textbackground(), window(), gotoxy(), getch(), constantes BLACK, BLUE, LIGHTGRAY */
#include "graphics_v1.1.h" /* Sleep() */
#include <locale.h>        /* setlocale() */
#include <stdio.h>         /* printf() */
#include <stdlib.h>        /* strlen() */
#include <time.h>          /*srand() */
#include <windows.h>


#define TAMANHO_QUADRADO 0x3
#define ALTURA_MAXIMA_JANELA 0x96
#define LARGURA_MAXIMA_JANELA 0x50
#define CIMA 0x48
#define BAIXO 0x50
#define ESQUERDA 0x4B
#define DIREITA 0x4D
#define F1 0x3B
#define F2 0x3C
#define F3 0x3D
#define F4 0x3E
#define F5 0x3F
#define F6 0x40
#define F7 0x41
#define F8 0x42
#define F9 0x43
#define TAB 0x09
#define F10 0x44
#define ESPACO 0x20
#define TAB 0x09
#define SPACE 0X20
#define ESC 27
#define CTRL 0

/*Retorna o número correspondente a direção que o quadrado de asteristicos irá começar*/
int movimento_aleatorio(void)
{
    int direcao;
    direcao = rand() % 2;
    if (direcao == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int muda_cor(void)
{
    int cor_;

    srand(time(NULL));
    cor_ = rand() % 15 + 1;

    return cor_;
}

/*Imprime no canto inferior esquerdo informações*/
int imprime(float x, float y, int cor, float velocidade, int corast, int dir_horinzontal, int dir_vertical)
{
	
    gotoxy(x, y);
    printf("V:%.0f", velocidade);
    gotoxy(x + 12, y);
    switch (cor)
    {
    case 15:
        printf("Borda:Branco");
        break;
    case 1:
        printf("Borda:Azul");
        break;
    case 2:
        printf("Borda:Verde");
        break;
    case 3:
        printf("Borda:Ciano");
        break;
    case 4:
        printf("Borda:Vermelho");
        break;
    case 5:
        printf("Borda:Magenta");
        break;
    case 6:
        printf("Borda:Marrom");
        break;
    case 7:
        printf("Borda:Cinza Claro");
        break;
    case 8:
        printf("Borda:Cinza Escuro");
        break;
    case 9:
        printf("Borda:Azul Claro");
        break;
    case 10:
        printf("Borda:Verde Claro");
        break;
    case 11:
        printf("Borda:Ciano Claro");
        break;
    case 12:
        printf("Borda:Vermelho Claro");
        break;
    case 13:
        printf("Borda:Magenta Claro");
        break;
    case 14:
        printf("Borda:Amarelo");
        break;
    }
    gotoxy(x + 35, y);
    switch (corast)
    {
    case 15:
        printf("Quadrado:Branco");
        break;
    case 1:
        printf("Quadrado:Azul");
        break;
    case 2:
        printf("Quadrado:Verde");
        break;
    case 3:
        printf("Quadrado:Ciano");
        break;
    case 4:
        printf("Quadrado:Vermelho");
        break;
    case 5:
        printf("Quadrado:Magenta");
        break;
    case 6:
        printf("Quadrado:Marrom");
        break;
    case 7:
        printf("Quadrado:Cinza Claro");
        break;
    case 8:
        printf("Quadrado:Cinza Escuro");
        break;
    case 9:
        printf("Quadrado:Azul Claro");
        break;
    case 10:
        printf("Quadrado:Verde Claro");
        break;
    case 11:
        printf("Quadrado:Ciano Claro");
        break;
    case 12:
        printf("Quadrado:Vermelho Claro");
        break;
    case 13:
        printf("Quadrado:Magenta Claro");
        break;
    case 14:
        printf("Quadrado:Amarelo");
        break;
    }

    /*******************/
    gotoxy(x + 62, y);
    switch (dir_horinzontal)
    {
    case 1:
        printf("D:Dir");
        break;
    case -1:
        printf("D:Esq");
        break;
    default:
        break;
    }
    switch (dir_vertical)
    {
    case 1:
        printf("D:Baixo");
        break;
    case -1:
        printf("D:Cima");
        break;
    default:
        break;
    }

    return 0;
}

int limpa_tela(int cor, float x_esquerda, float y_esquerda, int x_direita, int y_direita, float velocidade, int corast, int dir_horinzontal, int dir_vertical)
{

    textbackground(cor);
    window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
    imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
    textbackground(BLACK);
    window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);

    return 0;
}

/*Criação do quadrado de asteristicos,e controle de teclas input*/
int quadrado(int dir_horinzontal, int dir_vertical, int x, int y, float velocidade, float x_esquerda, float y_esquerda, int x_direita, int y_direita, int cor, int corast)
{
	
    int i;
    int j;
    int tecla;
    float temp;

    while (1)
    {
        clrscr();
		
        /*Faz o quadrado de asteristico inicializado no centro e movimento*/
        for (i = 0; i < TAMANHO_QUADRADO; i++)
        {
			
            gotoxy(x, y + i);
            for (j = 0; j < TAMANHO_QUADRADO; j++)
            {
			
                if (i == 0 || i == TAMANHO_QUADRADO - 1 || j == 0 || j == TAMANHO_QUADRADO - 1)
                {
					
                    textcolor(corast);
					
                    printf("*");
                }
                else
                {
                    printf(" ");
					
                }
				
            }
            printf("\n");
			
        }
		

        x += dir_horinzontal;
        y += dir_vertical;

        /*Controle de velocidade do quadrado de asteristicos*/
        Sleep(velocidade);

        if (x + TAMANHO_QUADRADO >= x_direita || x <= 1)
        {
            dir_horinzontal = -dir_horinzontal;
        }

        if (y + TAMANHO_QUADRADO >= y_direita || y <= 1)
        {
            dir_vertical = -dir_vertical;
        }

        /*Entrada de teclas*/
        if (kbhit())
        {
            clrscr();

            limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
            tecla = getch();

            switch (tecla)
            {

            case CIMA:

                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);

                dir_vertical = -1;
                dir_horinzontal = 0;
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);
                break;

            case BAIXO:

                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                dir_vertical = 1;
                dir_horinzontal = 0;
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);
                break;

            case ESQUERDA:
                clrscr();
                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                dir_horinzontal = -1;
                dir_vertical = 0;

                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);
                break;

            case F1:

                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                if (velocidade > 100)
                {
                    velocidade = velocidade - 100;
                }
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);
                break;

            case F2:

                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                if (velocidade < 1000)
                {
                    velocidade = velocidade + 100;
                }
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);
                break;

            case TAB:
                cor = muda_cor();
                textbackground(cor);
                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);

                break;

            case SPACE:
                corast = muda_cor();
                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);

                break;
				
            case F4:
				
				if (x_direita >4)
				{
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					x_esquerda++;

					textbackground(BLUE);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);

					x_direita--;

					textbackground(BLUE);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(x_esquerda - 9, y_direita + 1, cor, velocidade, corast, dir_horinzontal, dir_vertical);
				}

                break;

            case F3:
				if (x_esquerda>10)
				{
				
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					x_esquerda--;

					textbackground(BLUE);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);

					x_direita++;

					textbackground(BLUE);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
				}
					
                break;

            case F5:
			
				if (x_direita<100)
				{
					limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
					x_direita++;
					textbackground(cor);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);
				}
				
                break;

            case F6:
			
				if (x_direita >4)
				{
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					x_direita--;

					textbackground(BLUE);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
				}
						
                break;

            case F7:
				
				if(y_direita<40)
				{
					limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
					y_esquerda--;
					y_direita++;

					textbackground(cor);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita - 1, y_esquerda + y_direita);

					temp = y_direita + 7;
					imprime(1, temp, cor, velocidade, corast, dir_horinzontal, dir_vertical);

					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);
				}
				
                break;

            case F8:
			
				if (y_direita >4)
				{
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					y_esquerda++;
					y_direita--;

					textbackground(cor);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita - 1, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
				}
				
                break;

            case F9:
				
				if(y_direita<40)
				{
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					y_direita++;

					textbackground(cor);
					window(x_esquerda + 1, y_esquerda, x_esquerda + x_direita - 1, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);

					textbackground(BLACK);
					window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
				}
                break;

            case F10:
			
				if (y_direita >4) 
				{
					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					y_direita--;

					textbackground(BLUE);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);

					textbackground(BLACK);
					window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
					imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
				}
				
                break;

            case ESC:

                exit(0);
				
			case CTRL:

                /*limpa_tela(cor, x_esquerda-10, y_esquerda-10, x_direita-10, y_direita-10, velocidade, corast, dir_horinzontal-10, dir_vertical-10);
                dir_horinzontal = 1;
                dir_vertical = 0;
                quadrado(dir_horinzontal-10, dir_vertical-10, x-10, y-10, velocidade, x_esquerda-10, y_esquerda-10, x_direita-10, y_direita-10, cor, corast);*/
				 exit(0);
                break;

            case DIREITA:

                limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
                dir_horinzontal = 1;
                dir_vertical = 0;
                quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast);

                break;

            default:
                break;
            }
        }
    }

    return 0;
}
/*Cria Janela gráfica inicial*/
int janela(int dir_horinzontal, int dir_vertical, float x_esquerda, float y_esquerda, int x_direita, int y_direita, int cor, float velocidade)
{
	

    int x = 50;
    int y = 20;
    int corast = 7;

    limpa_tela(cor, x_esquerda, y_esquerda, x_direita, y_direita, velocidade, corast, dir_horinzontal, dir_vertical);
	 HWND hwnd = GetConsoleWindow();  // Obtém o identificador da janela do console
    ShowWindow(hwnd, SW_MAXIMIZE);   // Maximiza a janela
	
    textbackground(cor);
    window(x_esquerda, y_esquerda, x_esquerda + x_direita, y_esquerda + y_direita);
    imprime(1, 41, cor, velocidade, corast, dir_horinzontal, dir_vertical);
    textbackground(BLACK);
    window(x_esquerda + 1, y_esquerda + 1, x_esquerda + x_direita - 1, y_esquerda + y_direita - 1);
    corast = LIGHTGRAY;
    quadrado(dir_horinzontal, dir_vertical, x, y, velocidade, x_esquerda, y_esquerda, x_direita, y_direita, cor, corast); /*AQUI*/

    return 0;
}

int main(int argc, char *argv[]))
{
	
   system("start /max cmd.exe"); 
   delline();
	
    float x_esquerda = 10; 
    float y_esquerda = 15;
    int x_direita = 100; 
    int y_direita = 40; 
    int dir;
    int cor = 1.5;
    int dir_horinzontal = 0;
    int dir_vertical = 0;
    float velocidade = 100;
	
	
	
    clrscr();
	
    srand(time(NULL));

    /*Inicializando movimento aleatório do quadrado de asteristicos (pra cima ou pro lado */
    dir = rand() % 4 + 1;

    if ((dir == 1) || (dir == 2))
    {
        dir_vertical = movimento_aleatorio(dir); /*cima ou baixo*/
    }
    else
    {
        dir_horinzontal = movimento_aleatorio(dir);
    }

    setlocale(LC_ALL, "Portuguese");
    /*Inicializa a janela gráfica principal*/
    janela(dir_horinzontal, dir_vertical, x_esquerda, y_esquerda, x_direita, y_direita, cor, velocidade);
	

    return 0;
}