

/****
*
* T�tulo: permuta os caracteres de um string
*
* Autor: M�rcio Assis
*
* Data de Cria��o: 14/06/2003
*
* Descri��o Geral:
*
* Entrada:
*
* Sa�da: r
*
****/

#include <stdio.h>
#include <string.h>

#define MAX_STRING_PERMUTA 15  /* tamanho m�ximo do string auxiliar usado
                                  na permuta��o de um string */

extern void PermutaString(char *, int, int );
extern void ArmazenaPermutacoes(char*);
FILE *out; /* global */

int main(void)
{
    char str[MAX_STRING_PERMUTA];
    printf("\nIntroduza um string: ");
    scanf("%s",str);
   
    out = fopen("permuta.txt", "w");
    PermutaString(str, 0, strlen(str) - 1);
    fclose(out);

    printf("\nConcluido" " O arquivo permuta.txt cont�m todas as permuta��es");
    printf("\ncopyright �2003, M�rcio Assis");
    getchar();
    getchar();
    return 0;
}

/*
* A fun��o PermutaString() gera todas as permuta��es poss�veis de um string
*
* Entrada: str - string a ser permutado
*          k - o indice inicial, em que k>=0
*          n - o �ndice final, em que n < comprimento(str)
*          os �ndices k e n especificam o conjunto de caracteres que deve ser permutado
*
* Sem retorno
*
* Algoritmo:
*          Permuta(str, k, n)
*          inicio
*              if k == n then {Guarda(str); return}
*              aux = Copia(str)
*              for (i = k; i <= n; i++)
*                  Troca(str, k, i) //permuta o caracter k-�simo de str com o
*                                  // caracter i-�simo de str
*                  Permuta(str, k+1, n)
*                  str = Copia(aux)
*          fim
*
* Observa��o: Deve-se definir o tamanho do string auxiliar e a fun��o ArmazenaPermutacoes(),
* este �ltimo conter� o resultado de todas as permuta��es
*/
void PermutaString( char *str, int k, int n )
{
    int i;
    char aux[MAX_STRING_PERMUTA],
         c; /* armazena um caracter temporariamente */

    if ( k == n ) {
        ArmazenaPermutacoes(str);
        return;
    }

    strcpy(aux, str);
    for ( i = k; i <= n; i++ ) {
        c = str[k];
        str[k] = str[i];
        str[i] = c;

        PermutaString(str, k+1, n);
        strcpy(str,aux); /* restaurando string original */
    }
} /* Permuta */

/*
* A fun��o ArmazenaPermutacoes()
*
* Entrada:
*
* Sem retorno
*
* Algoritmo:
*
*/
void ArmazenaPermutacoes(char *str)
{
    fputs(str, out);
    fputs("\n",out);
}

