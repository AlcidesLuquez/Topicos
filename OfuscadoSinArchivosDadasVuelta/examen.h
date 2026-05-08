#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

size_t quieroUnaLineaDeTextoOfuscadaDVV(char* linea);
char* desofuscarALU(char* linea);

size_t proximaPalabraALU(char* cad, char** ini, char** fin);

void corregirPalabraALU(char* ini, char* fin, const char* grupo);
void revertirPalabraALU(char* ini, char* fin);

#endif // OFUSCADO_INCLUDED
