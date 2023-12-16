#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//DECLARATION DE LISTE 
typedef struct liste 
{   int info;
    struct liste *suivant;
    struct liste *preced;   
}liste;

//ALLOCATION
liste *add_liste(){
    liste *p=(liste*)malloc(sizeof(liste));}

//INITIALISATION
void initialiser_liste(liste **ptete,liste **pqueue){
    ptete=NULL;
    pqueue=NULL;}

//RAMPLICAGE

liste * ramplire_liste(liste **ptete,liste **pqueue){
    int x;
    printf("entrer le 1er entier: ");
    scanf("%d",&x);
    (*ptete)->info=x;
    (*ptete)->preced=NULL;
    printf("\nentrer le 2eme entier: ");
    scanf("%d",&x);
    (*pqueue)->info=x;
    (*pqueue)->preced=*ptete;
    (*pqueue)->suivant=NULL;
    (*ptete)->suivant=*pqueue;
    int i=3; char c;
    do
    {   printf("entrer 'y'si tu veut continuer");
        scanf("%c",&c);
        switch (c)
        {
        case 'y':
            liste *temp=add_liste();
            printf("entrer le %deme entier:");
            scanf("%d",&temp->info);
            temp->preced=*pqueue;
            temp->suivant=NULL;
            *pqueue=temp;
            break;
        
        default:printf("donc vous voullez quiter");
            break;
        }
        
    
    } while (c=='y');
    

    
}
int main (){

printf("*****************************");


}



