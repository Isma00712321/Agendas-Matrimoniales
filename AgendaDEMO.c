/**
 * @file Agenda.c
 *
 * @brief TODO
 *
 * @author  Ismael <ismael@ismael-XPS-13-9380>
 * @version 2025-12-30
 *
 **/

#include <stdio.h>
#include <stdbool.h>
#include "intro.h"
#include <unistd.h>

#define CONTACTO_MAX 10
#define CONTACTO_MIN 1
#define NOMBRE_MAX 12

typedef enum estado {CASADO, RELACION, RARO, SOSPECHA, SOLTERA, MUYSOLTERA, NADA} estado_t;

const char civil [7][14] = {"Casada","En relacion", "Algo raro", "Hay sospechas", "Soltera", "MUY Soltera", "NADA"};

typedef struct persona {
    int orden;   
    char nombre [NOMBRE_MAX];
    char apellidos [NOMBRE_MAX];
    estado_t solteria;
    int edad;
    char instagram [NOMBRE_MAX];
    char residencia[NOMBRE_MAX];
    int madre_hijos;
    int posibilidad;
    

} persona_t;

void mostrar (persona_t *ptr);

void rellenar (persona_t *ptr, int *eleccion);

void logo (void);

void elegirID (int *eleccion);

void inicializar (persona_t *ptr);




int main (void) {
    int eleccion;
    int menu;
    int *eleccion_ptr = &eleccion;
        
    persona_t sujeto[CONTACTO_MAX];
    
    persona_t *ptr;
    
    ptr = &sujeto[0];
    inicializar(ptr);
    
    do{
    logo();
    printf ("\nBienvenido a la agenda de mujeres de Codigos Lamsallak\n");
    printf ("\nElije una opcion");
    printf ("\n1)Registrar contacto");
    printf ("\n2)Ver agenda\n");
    printf ("\nCualquier otro para SALIR\n");
    scanf ("%1d", &menu);
    while ((getchar()) != '\n');
    
    switch (menu) {
            case 1:
                elegirID (eleccion_ptr);
                ptr = &sujeto[eleccion - 1];
                rellenar (ptr, eleccion_ptr);
                break;
            case 2:
                elegirID (eleccion_ptr);
                ptr = &sujeto[eleccion - 1];
                mostrar (ptr);
                break;
            default:
                logo();
                printf ("\nAnte todo recuerda\n");
                sleep(2);
                printf ("Son todas iguales\n");
                sleep(2);
                printf ("Para mas programas compra la subscripcion de 12.99 euros al mes a CODIGOS LAMSALLAK");
                return 0;
                
    }
    } while (true);
}

void mostrar (persona_t *ptr) {
    int menu;
    logo();
    printf ("\nID:%d", ptr->orden);
    printf ("\nNombre:%s", ptr->nombre);
    printf ("\nApellido:%s", ptr->apellidos);
    printf ("\nEstado Civil:%s", civil[ptr->solteria]);
    printf ("\nEdad:%d", ptr->edad);
    printf ("\nInstagram:@%s", ptr->instagram);
    printf ("\n\nMunicipio:%s", ptr->residencia);
    printf ("\nNivel de MDMH (Madre De Mis Hijos):%d", ptr->madre_hijos);
    printf ("\nNivel de esperanza:%d", ptr->posibilidad);
    printf ("\n\n\nPulsa 1 para ir al siguiente, 2 para ir al anterior y cualquier otro numero para volver al menu\n");
    scanf ("%1d", &menu);
    switch (menu) {
        case 1:
        if (ptr->orden == CONTACTO_MAX) {
             printf ("\nNo quedan mas espacio en memoria\n");
             sleep (2);
             mostrar (ptr);
             break;
        }        
        ptr++;
        mostrar (ptr);

        break;
        case 2:
        if (ptr->orden == CONTACTO_MIN) {
             printf ("\nNo quedan mas espacio en memoria\n");
             sleep (2);
             mostrar (ptr);
             break;
        }  
        ptr--;
        mostrar (ptr);
        break;
    }
}

void rellenar (persona_t *ptr, int *eleccion) {
    int opcion;
    logo();
    ptr->orden = *eleccion;
    
    printf ("\nIntroduce el nombre del contacto\n");
    scanf ("%11s", ptr->nombre);
    while ((getchar()) != '\n');
    
    printf ("Introduce el primer apellido (el segundo suda)\n");
    scanf ("%11s", ptr->apellidos);
    while ((getchar()) != '\n');
    
    printf ("Introduce la edad del contacto\n");
    scanf ("%3d", &ptr->edad);
    while ((getchar()) != '\n');
    
    printf ("Introduce el instagram del contacto (sin el @):\n");
    scanf ("%11s", ptr->instagram);
    while ((getchar()) != '\n');
    
    printf ("Introduce el municipio de residencia del contacto:\n");
    scanf ("%11s", ptr->residencia);
    while ((getchar()) != '\n');
    
    printf ("Introduce el nivel de MDMI (Madre De Mis Hijos)\n");
    scanf ("%5d", &ptr->madre_hijos);
    while ((getchar()) != '\n');
    
    printf ("Introduce el nivel de esperanza que tienes\n");
    scanf ("%5d", &ptr->posibilidad);
    while ((getchar()) != '\n');
    
    logo();
    
    printf ("\nDe estas opciones cual la que la representa mas:\n");
    printf ("0.Casada\n");
    printf ("1.En relacion\n");
    printf ("2.Algo raro\n");
    printf ("3.Hay sospechas\n");
    printf ("4.Soltera\n");
    printf ("5.MUY soltera\n");
    
    scanf ("%1d", &opcion);
    while ((getchar()) != '\n');
    
    ptr->solteria = opcion;


}

void logo (void) {
    clear_terminal();
    printf("\n================================================================================");
    printf("\n=========================AGENDA    PERSONAL=====================================");
    printf("\n================================================================================");
}

void elegirID (int *eleccion) {
    printf ("\nElije el ID\n");
    do {
        scanf ("%d", eleccion);
        if (*eleccion > 100) {
            printf ("Valor demasiado alto\n");
        }
        if (*eleccion < 1) {
            printf ("Valor demasiado bajo\n");
        }
        
    } while ((*eleccion > 100) || (*eleccion < 1));
}

void inicializar (persona_t *ptr) {
    for (int i = 0; i < CONTACTO_MAX; i++) {
        for (int x = 0; x < NOMBRE_MAX; x++) {
            ptr->nombre[x] = '\0';
            ptr->apellidos[x] = '\0';
            ptr->residencia[x] = '\0';
            ptr->instagram[x] = '\0';
            
        }
    ptr->edad = 0;
    ptr->orden = i + 1;
    ptr->solteria = NADA;
    ptr->madre_hijos = 0;
    ptr->posibilidad = 0;
    ptr++;
    }
}
