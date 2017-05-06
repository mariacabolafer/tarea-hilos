#include <math.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAXTHREAD 100

void *print (void *arg) 
{
     
     pthread_t id;
     id = pthread_self();
     printf("Hola %u \n",id );
}

int main (int argc , char ** argv) 
{
        //long array[MAXTHREAD];
        pthread_t threadarray[MAXTHREAD];
	int nuhil;
    if (argc !=2)
    {
	printf("por favor ingrese el numero de hilos a usar\n");
	printf("\t%s <nuhil>\n",argv[0]);
	exit(-1);
    }

    nuhil = atoi(argv[1]);
    
    if (nuhil > MAXTHREAD || nuhil == 0 )
    {
            printf("Máximo numero de hilos es %d, solicitó: %d \n" , MAXTHREAD, nuhil);
            exit(-1);
    }

for (int i=0 ; i < nuhil; i++) 
{
// array[i] ? (long) i;
   pthread_create(&threadarray [i] , NULL, &print,NULL);
}

for (int i = 0; i < nuhil; i++)
{
      pthread_join(threadarray [i],NULL);
}
 
return 0;

}






