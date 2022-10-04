#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdbool.h>

#include"files.h"

#define PORT 4500
#define CLIENTES 32
#define SIZE_ORDEN 150

char *file = NULL;
char *orden = NULL;
unsigned char orden_flags = 0;

struct punteros
{
    char *cop_orden;
} cop_var_ptr;


void init_vars()
{
    orden = malloc(SIZE_ORDEN * sizeof(char));
    cop_var_ptr.cop_orden = orden;
}

void stop_vars()
{
    free(cop_var_ptr.cop_orden);
}

void LogicaServidor(const int *cp_conexion)
{
    return;
}

void interpretar(char *DATA)
{
    return;
}
