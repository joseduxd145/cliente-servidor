#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE_SIZE 256
#define LOG_FILE "serverlog.txt"

//Funcion para leer archivos de texto
char *read_data(const char *Nombre_Archivo)
{
    //Descriptor de archivo
    FILE *f = fopen(Nombre_Archivo, "r");
    unsigned long long size = 0;
    char *Salida;

    if (f == NULL)
    {
        printf("Error archivos lectura\n");
        exit(1);
    }
    
    //Determinar como de grande es el archivo
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    //Asignar memoria
    Salida = malloc(size);

    //Lectura del Archivo
    fread(Salida, sizeof(char), size, f);
    fclose(f);
    return Salida;
}

void write_data(const char *Nombre_Archivo, const char *DATA)
{
    //Descriptor Archivo
    FILE *f = fopen(Nombre_Archivo, "w");
    if (f == NULL)
    {
        printf("Error archivos escritura\n");
        return;
    }
    
    //Escritura
    fwrite(DATA, 1, strlen(DATA), f);
    fclose(f);
}

void log_data(const char *DATA)
{
    //Descriptor archivo
    FILE *f = fopen(LOG_FILE, "a");
    if (f == NULL)
    {
        printf("Error log\n");
        return;
    }

    //Escritura al log
    fwrite(DATA, 1, strlen(DATA), f);
    fclose(f);
    return;
}