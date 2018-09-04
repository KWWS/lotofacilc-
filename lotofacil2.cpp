//Autor: Kelvio Wallisson
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <ctime>

char nome[40];
int vetor[15];
int tam=0;

bool existe(int x){
    for(int j=0;j<tam;j++){
        if(vetor[j]==x)
            return true;
    }
    return false;
}
void sortear(){
    int x, aux=0;
    srand(time(NULL));
    for(int i=0;i<15;i++){
        tam++;
        x=1+(rand() % 25);
        while(existe(x)){
            x=1+(rand() % 25);
        }
        vetor[i]=x;
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if (vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
void datahora(){
    time_t timer;
    struct tm *horarioLocal;
    time(&timer);
    horarioLocal = localtime(&timer);
    int dia = horarioLocal->tm_mday;
    int mes = horarioLocal->tm_mon + 1;
    int ano = horarioLocal->tm_year + 1900;
    int hora = horarioLocal->tm_hour;
    int min  = horarioLocal->tm_min;
    int sec  = horarioLocal->tm_sec;
    FILE *file;
    file=fopen("lotofacil.txt", "a");
    printf("Horario: %d:%d:%d\n",hora,min,sec);
    printf("Data: %d/%d/%d\n",dia,mes,ano);
    fprintf(file, "Horario: %d:%d:%d\n",hora,min,sec);
    fprintf(file, "Data: %d/%d/%d\n",dia,mes,ano);
    fclose(file);
}

void cadastrar(){
    FILE *file;
    file=fopen("lotofacil.txt", "a");
    fprintf(file, "Autor: %s\n", nome);
    printf("Numeros:\n");
    fprintf(file, "Numeros:\n");
    for(int i=0;i<15;i++){
        printf("(%d)", vetor[i]);
        fprintf(file, "(%d)", vetor[i]);
    }
    fprintf(file, "\n\n\n");
    fclose(file);
}

int main()
{
    printf("Para quem eh este sorteio: \n");
    scanf("%s", &nome);
    sortear();
    datahora();
    cadastrar();
    return 0;
}
