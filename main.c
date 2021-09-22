#include <stdio.h>
#include <math.h>
#include<string.h>

void create_marks_csv_secuencial(char *filename,float a[100],int n,int m){
    printf("\n Creating %s.csv file",filename);
    FILE *fp;
    filename=strcat(filename,".csv");
    fp=fopen(filename,"w+");
    fprintf(fp,"ID, Tiempo");
    int i,j = 0;
    for(i=0;i<m;i++){
        fprintf(fp,"\n%d",i+1);
        for(j=0;j<n;j++)
            fprintf(fp,",%f ",a[i]);
        }
    fclose(fp);
    printf("\n %sfile created",filename);
}

int main() {
    int n [] = {10, 20, 40, 80, 160, 320 };
    int p [] = {1, 2, 4, 8, 16, 32, 64, 128 };

    size_t lengthN = sizeof(n) / sizeof(n[0]);
    size_t lengthP = sizeof(p) / sizeof(p[0]);

    float resultadosN [lengthN];
    float resultadoP [lengthN][lengthP];
    
    float resultadosSpeedUpCaso1 [lengthN];
    float resultadosEficenciaCaso1 [lengthP];

    float resultadosSpeedUpCaso2 [lengthN];
    float resultadosEficenciaCaso2 [lengthP];


    int i,j,k = 0;

    for (int z = 0; z < lengthN; z++) {
        resultadosN[z] = pow(n[z],2);
    }  

    for (i = 0; i < lengthN; i++) {
        for (j = 0; j < lengthP; ++j) {   
            resultadoP[i][j] =  ((pow(n[i],2)/ p[j]) + log2(p[j]));
        }
        printf("\n");
        printf("Indice de I %d", i);
        printf("\n");
        printf("Resultados de N %f", resultadosN[i]);
        printf("\n");

        for (k = 0; k < lengthP; ++k) {
            printf("\n");
            printf("Indice de P %d", k);
            printf("\n");
            printf("---> Resultados de P %f", resultadoP[i][k]);
            printf("\n"); 
        } 
    }
    
    printf("\n");

    char ste[100] = "ResultadosSecuencial";
    create_marks_csv_secuencial(ste,resultadosN, 1,lengthN);
    
    char ste2[100] = "ResultadosParallelIteracion1";
    create_marks_csv_secuencial(ste2,resultadoP[0], 1, 8);
   
    char ste3[100] = "ResultadosParallelIteracion2";
    create_marks_csv_secuencial(ste3,resultadoP[1], 1, 8);
    
    char ste4[100] = "ResultadosParallelIteracion3";
    create_marks_csv_secuencial(ste4,resultadoP[2], 1, 8);
 
    char ste5[100] = "ResultadosParallelIteracion4";
    create_marks_csv_secuencial(ste5,resultadoP[3], 1, 8);
 
    char ste6[100] = "ResultadosParallelIteracion5";
    create_marks_csv_secuencial(ste6,resultadoP[4], 1, 8);
 
    char ste7[100] = "ResultadosParallelIteracion6";
    create_marks_csv_secuencial(ste7,resultadoP[5], 1, 8);

    printf("\n");
    printf("\n");

    printf("PREGUNTA 1:\n");

    printf("-------------------------------------------");

    for (int i = 0; i < lengthP; i++) {
      printf("\n La N es %d", n[0]);
      printf("\n Cantidad de procesadores %d", p[i]);
      float speedUp = resultadosN[0] / resultadoP[0][i];
      resultadosSpeedUpCaso1[i] = speedUp;
      printf("\n El speedUp es: %f", speedUp);
      float efficency = speedUp / p[i];
      resultadosEficenciaCaso1[i] = efficency;
      printf("\n La efficency es: %f", efficency);
      printf("\n");

      printf("------------------------------------------------");
    }

    printf("\n");
    printf("\n");
    printf("PREGUNTA 2:\n");

    printf("-------------------------------------------");

    for (int i = 0; i < lengthN; i++) {
      printf("\n La N es %d", n[i]);
      printf("\n Cantidad de procesadores %d", p[4]);
      float speedUp = resultadosN[i] / resultadoP[i][4];
      resultadosSpeedUpCaso2[i] = speedUp;
      printf("\n El speedUp es: %f", speedUp);
      float efficency = speedUp / p[i];
      resultadosEficenciaCaso2[i] = efficency;
      printf("\n La efficency es: %f", efficency);
      printf("\n");

      printf("------------------------------------------------");
    }

    printf("\n");
    
    char speedUp[100] = "ResultadosSpeedUpCaso1";
    create_marks_csv_secuencial(speedUp,resultadosSpeedUpCaso1, 1,lengthP);
    printf("\n");
    char eficencia[100] = "ResultadosEficenciaCaso1";
    create_marks_csv_secuencial(eficencia, resultadosEficenciaCaso1 , 1,lengthP);

    char speedUp2[100] = "resultadosSpeedUpCaso2";
    create_marks_csv_secuencial(speedUp2, resultadosSpeedUpCaso2, 1, lengthN);

    char eficencia2[100] = "ResultadosEficenciaCaso2";
    create_marks_csv_secuencial(eficencia2, resultadosEficenciaCaso2, 1 , lengthN);


    printf("\n");
    return 0;
}

