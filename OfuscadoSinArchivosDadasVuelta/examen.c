#include <stdlib.h>
#include <ctype.h>
#include "examen.h"
#include <stdio.h>
#include <string.h>

#define ESLETRA(X) (((X)>= 'a' && (X)<='z') || ((X)>='A' && (X)<='Z'))

#define MAX_TAM_PAL 24

char* desofuscarALU(char* linea)
{
    if(!linea)
        return NULL;

    char* iniPalabra;
    char* finPalabra;
    size_t tamPalabra;

    char* resultado = linea;

    char grupo[] = "abcdghijkoqtuv";

    tamPalabra = proximaPalabraALU(linea, &iniPalabra, &finPalabra);

    while(tamPalabra != 0)
    {
        corregirPalabraALU(iniPalabra, finPalabra, grupo);

        revertirPalabraALU(iniPalabra, finPalabra);

        linea = finPalabra + 1;

        tamPalabra = proximaPalabraALU(linea, &iniPalabra, &finPalabra);
    }

    return resultado;
}

size_t proximaPalabraALU(char* cad, char** ini, char** fin)
{
    if (!cad || !ini || !fin)
        return 0;

    while (*cad && !ESLETRA(*cad))
        cad++;

    if (*cad == '\0') {
        *ini = *fin = NULL;
        return 0;
    }

    *ini = cad;

    while (*cad && ESLETRA(*cad))
        cad++;

    *fin = cad - 1;

    return (size_t)(*fin - *ini + 1);
}

void corregirPalabraALU(char* ini, char* fin, const char* grupo)
{
    if(!ini || !fin || !grupo)
        return;

    char* cur = ini;
    char* letra;
    size_t pos;
    size_t offset;
    size_t cantElemGrupo = strlen(grupo);
    size_t indiceGrupo;

    while(cur <= fin)
    {
        letra = strchr(grupo, *cur);

        if(letra)
        {
            pos = (size_t)(cur - ini + 1);

            indiceGrupo = (letra - grupo);

            offset = (indiceGrupo + pos) % cantElemGrupo;

            *cur = *(grupo + offset);
        }

        cur++;
    }
}

void revertirPalabraALU(char* ini, char* fin)
{
    if(!ini || !fin)
        return;

    char aux;

    while(ini < fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;

        ini++;
        fin--;
    }
}
