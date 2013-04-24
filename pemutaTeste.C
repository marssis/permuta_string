

/****
*
* Título: permuta os caracteres de um string
*
* Autor: Márcio Assis
*
* Data de Criação: 14/06/2003
*
* Descrição Geral:
*
* Entrada:
*
* Saída: r
*
****/

#include <stdio.h>
#include <string.h>

#define MAX_STRING_PERMUTA 15  /* tamanho máximo do string auxiliar usado
                                  na permutação de um string */

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

    printf("\nConcluido" " O arquivo permuta.txt contém todas as permutações");
    printf("\ncopyright ©2003, Márcio Assis");
    getchar();
    getchar();
    return 0;
}

/*
* A função PermutaString() gera todas as permutações possíveis de um string
*
* Entrada: str - string a ser permutado
*          k - o indice inicial, em que k>=0
*          n - o índice final, em que n < comprimento(str)
*          os índices k e n especificam o conjunto de caracteres que deve ser permutado
*
* Sem retorno
*
* Algoritmo:
*          Permuta(str, k, n)
*          inicio
*              if k == n then {Guarda(str); return}
*              aux = Copia(str)
*              for (i = k; i <= n; i++)
*                  Troca(str, k, i) //permuta o caracter k-ésimo de str com o
*                                  // caracter i-ésimo de str
*                  Permuta(str, k+1, n)
*                  str = Copia(aux)
*          fim
*
* Observação: Deve-se definir o tamanho do string auxiliar e a função ArmazenaPermutacoes(),
* este último conterá o resultado de todas as permutações
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
* A função ArmazenaPermutacoes()
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

