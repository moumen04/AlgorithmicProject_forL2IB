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
    return (liste*)malloc(sizeof(liste));}

//INITIALISATION
void initialiser_liste(liste **ptete,liste **pqueue){
    ptete=NULL;
    pqueue=NULL;}

//REMPLICAGE
liste * remplire_liste(liste **ptete,liste **pqueue){
    int x;*ptete=add_liste();*pqueue=add_liste();
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
    int i=3; char c='y';
    do
    {   printf("entrer 'Y'si tu veut continuer: ");
        scanf("%s",&c);
        switch (c)
        {
        case 'Y':
            liste *temp=add_liste();
            printf("entrer le %deme entier:",i);i++;int x;
            scanf("%d",&x);
            temp->info=x;
            temp->preced=*pqueue;
            temp->suivant=NULL;
            (*pqueue)->suivant=temp;
            *pqueue=temp;
            break;
        
        default:printf("*****FIN DE REMPLICAGE*****");
            break;
        }
        
    
    } while (c=='Y');


}

//AFFICHAGE 
void afficher_liste(liste **ptete){
    liste *temp=add_liste();
    temp=*ptete;printf("\n");
    while (temp!=NULL)
    {printf("| %d |-->",temp->info);
     temp=temp->suivant;
    }
    printf("NULL\n*****FIN D'AFFICHAGE*****");}



//TRIE PAR CELECTION
void trier_liste(liste **ptete){
    liste *tetetemp=add_liste(),*test=add_liste();
    int min;
    tetetemp=*ptete;
    while (tetetemp!=NULL)
    {int min=tetetemp->info;
     test=tetetemp->suivant;
     while (test!=NULL)
     {if (test->info<min)
     {int perm=test->info;
     test->info=tetetemp->info;
     tetetemp->info=perm;
     }
     test=test->suivant;
     }
     tetetemp=tetetemp->suivant;
    }
    
}






int main (){
    liste *ptete=NULL;liste *pqueue=NULL;
    initialiser_liste(&ptete,&pqueue);
    remplire_liste(&ptete,&pqueue);
    afficher_liste(&ptete);
    printf("\nEND OF PROGRAMME :)");



    trier_liste(&ptete);
    afficher_liste(&ptete);


}



