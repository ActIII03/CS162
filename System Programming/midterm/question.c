#include <stdio.h>
#include <stdlib.h>

void Allocate3DArray(double**** array, int sizex, int sizey, int sizez);
void Destory3DArray(double*** array, int sizex, int sizey);

int main(void)
{
    //Q1
    /*
    char b = -1;
    short int c = b;
    unsigned short int f = c & 0X8000;
    printf("f: %u\n", f);
    */

    //Q2
    /*
    char b = 4;
    char a = (b) ? b<<1 : b<<3;
    printf("c: %d\n", a);
    */

    //char c = 50;
    //char d = (c != 50);
    //printf("d: %d\n", d);

    //Q4
    char e = 48;
    char g = e | 20;
    printf("g: %d\n", g);

    //Q15
    //double*** array;
    //int sizex = 5;
    //int sizey = 5;
    //int sizez = 5;
    
    //Allocate3DArray(&array, 5, 5, 5);

    //Destory3DArray(&array, 5, 5);

    /*
    array = (double ***)malloc(sizex*sizeof(double**));

    for(int i = 0; i < sizex; ++i)
    {
        array[i] = (double **) malloc(sizey * sizeof(double*));
        for(int j = 0; j < sizey; ++j)
            array[i][j] = (double *)malloc(sizez * sizeof(double));
    }



    //destory

    for(int i = 0; i < sizex; ++i)
    {
        for(int j = 0; j < sizey; ++j)
            free(array[i][j]);

        free(array[i]);
    }

    free(array);
    */

    return 0;

}


void Allocate3DArray(double**** array, int sizex, int sizey, int sizez)
{
    *array = (double ***)malloc(sizex*sizeof(double**));

    for(int i = 0; i < sizex; ++i)
    {
        (*array)[i] = (double **) malloc(sizey * sizeof(double*));
        for(int j = 0; j < sizey; ++j)
            (*array)[i][j] = (double *)malloc(sizez * sizeof(double));
    }
}


void Destory3DArray(double*** array, int sizex, int sizey)
{
    for(int i = 0; i < sizex; ++i)
    {
        if(array[i] != NULL)
        {
            for(int j = 0; j < sizey; ++j)
                free(array[i][j]);
        }

        free(array[i]);
    }

    free(array);
}
