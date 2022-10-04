#include"main.h"


int main(void)
{
    //vars
    bool Finalizar = false;
    char *ip = NULL;
    int conexion, aux;
    socklen_t longitud_estructura;

    //Estructuras
    struct sockaddr_in cliente, servidor;

    init_vars();
    printf("Variables y estructuras inicializadas...\n");

    //Creacion del Socket
    conexion = socket(AF_INET, SOCK_STREAM, 0);
    if (conexion < 0)
    {
	   printf("Error al generar el socket...\n");
       stop_vars();
	   return 1;
    }
    printf("Socket creado...\n");

    //Bind del socket
    memset(&servidor, '\0', sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORT);
    servidor.sin_addr.s_addr = INADDR_ANY;

    aux = bind(conexion, (struct sockaddr*)&servidor, sizeof(servidor));
    if (aux < 0)
    {
	   printf("Error al enlazar la conexion...\n");
       stop_vars();
	   return 1;
    }
    printf("Conexion enlazada...\n");

    //Escucha del servidor
    if (listen(conexion, CLIENTES) == 0)
    {
	   printf("Escuchando en el puerto: %d\n", PORT);
       longitud_estructura = sizeof(cliente);
    }
    else
    {
	   printf("Error al iniciar la escucha\n");
       stop_vars();
       close(conexion);
	   return 1;
    }

    //Bucle del servidor
    while(!Finalizar)
    {
        aux = accept(conexion, (struct sockaddr*)&cliente, &longitud_estructura);
        if (aux < 0)
        {
            printf("Error al aceptar el cliente...\n");
            break;
        }
        ip = inet_ntoa(cliente.sin_addr);
        printf("Cliente con ip: %s se a conectado\n", ip);
        recv(conexion, orden, SIZE_ORDEN, 0);
        
    }

    close(conexion);
    printf("Socket cerrado...\n");

    stop_vars();
    printf("Memoria liberada...\n");
    
    return 0;
}