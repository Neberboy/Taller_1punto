#include <stdio.h>
#include <string.h>

#define NUM_COMPETIDORES 6

void ingresarCompetidores(char nombres[][30]) {
    int len;
    for (int i = 0; i < NUM_COMPETIDORES; i++) {
        printf("Ingrese el nombre del peleador %d: ", i + 1);
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        len = strlen(nombres[i]) - 1;
        nombres[i][len] = '\0';
    }
}

void registrarCombates(char nombres[][30], int puntos[]) {
    int opc, val, cont = 0, puntosGanador;
    
    while (cont < NUM_COMPETIDORES) {
        printf("\nElija el ganador del combate entre:\n1. %s\n2. %s\nElija una opción: ", nombres[cont], nombres[cont+1]);
        
        do {
            fflush(stdin);
            val = scanf("%d", &opc);
            if (val != 1 || opc < 1 || opc > 2) {
                printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
            }
        } while (val != 1 || opc < 1 || opc > 2);

        int ganador = (opc == 1) ? cont : cont+1;

        printf("El peleador %s ganó por cuántos puntos: \n", nombres[ganador]);
        
        do {
            fflush(stdin);
            val = scanf("%d", &puntosGanador);
            if (val != 1 || puntosGanador < 1) {
                printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
            }
        } while (val != 1 || puntosGanador < 1);

        puntos[ganador] += puntosGanador;
        cont += 2;
    }
}

void determinarFinalistas(char nombres[][30], int puntos[], char finalistas[][30]) {
    int primero_idx = 0, segundo_idx = 1;

    for (int i = 2; i < NUM_COMPETIDORES; i++) {
        if (puntos[i] > puntos[primero_idx]) {
            segundo_idx = primero_idx;
            primero_idx = i;
        } else if (puntos[i] > puntos[segundo_idx]) {
            segundo_idx = i;
        }
    }
    
    strcpy(finalistas[0], nombres[primero_idx]);
    strcpy(finalistas[1], nombres[segundo_idx]);
}

void definirGanador(char finalistas[][30]) {
    int opc, val, puntosGanador;
    printf("\nElija el ganador de la final entre:\n1. %s\n2. %s\nElija una opción: ", finalistas[0], finalistas[1]);
    
    do {
        fflush(stdin);
        val = scanf("%d", &opc);
        if (val != 1 || opc < 1 || opc > 2) {
            printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
        }
    } while (val != 1 || opc < 1 || opc > 2);

    printf("El peleador %s ganó la final por cuántos puntos: \n", finalistas[opc - 1]);

    do {
        fflush(stdin);
        val = scanf("%d", &puntosGanador);
        if (val != 1 || puntosGanador < 1) {
            printf("El valor ingresado no es correcto. \nIngrese nuevamente: ");
        }
    } while (val != 1 || puntosGanador < 1);

    printf("\n¡%s es el campeón del torneo con %d puntos!\n", finalistas[opc - 1], puntosGanador);
}

int main() {
    char nombres[NUM_COMPETIDORES][30], finalistas[2][30];
    int puntos[NUM_COMPETIDORES] = {0};

    ingresarCompetidores(nombres);
    registrarCombates(nombres, puntos);
    determinarFinalistas(nombres, puntos, finalistas);
    definirGanador(finalistas);

    return 0;
}
