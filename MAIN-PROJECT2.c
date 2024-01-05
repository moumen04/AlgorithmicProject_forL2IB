#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

//******DECLARATION DE LISTE******
    typedef struct liste{
        int info;
        struct liste* prec;
        struct liste* suiv;
        bool swaping;
}liste;

//******ALLOCATION******
    liste *add_liste(){
      return (liste*)malloc(sizeof(liste));}

//******INITIALISER LA LISTE******
liste * init_liste (int info){
    liste *nouv_liste=add_liste();
    nouv_liste->info=info;
    nouv_liste->prec=NULL;
    nouv_liste->suiv=NULL;
    nouv_liste->swaping=false;
    return nouv_liste;
}

//******AJOUTER UN ELEMENT A LA FIN DE LISTE******
void ajouter(liste **tete,int info){
    liste *nouv_liste=init_liste(info);
    if(*tete==NULL){
       *tete =nouv_liste;
    }else{
        liste* temp=*tete;
        while(temp->suiv!=NULL){temp=temp->suiv;}
        temp->suiv=nouv_liste;
        nouv_liste->prec=temp;
    }
}

//******ECHANGE DES LISTE******
void swap(liste * a,liste *b){
    int temp =a->info;
    a->info=b->info;
    b->info=temp;
    a->swaping=true;
    b->swaping=true;
}

//******DESSINER LA LISTE******
 void drawlist(liste *tete,Color color,int pos_x,int pos_y){
     liste *temp=tete;
     int xpos=10 +pos_x;
     int ypos=200 +pos_y;
     while(temp !=NULL) {
         Color listecolor=temp->swaping ? YELLOW :color;
         DrawRectangle(xpos,ypos -temp->info *2,20,temp->info *2,listecolor);
         DrawText(TextFormat("%d",temp->info),xpos+5,ypos -temp->info-10,10,WHITE);
         xpos+=30;
         temp->swaping=false;
         temp=temp->suiv;
     }
 }
 
 
 //******MAIN FONCTION******
 int main (){
     int win_widht=800;
     int win_height=1000;
     InitWindow(win_widht,win_height,"TRI PAR SELECTION");
     
     liste* non_trie=NULL;
     liste* trie=NULL;
     
     ajouter(&non_trie,64);
     ajouter(&non_trie,34);
     ajouter(&non_trie,25);
     ajouter(&non_trie,12);
     ajouter(&non_trie,22);
     ajouter(&non_trie,11);
     ajouter(&non_trie,45);
     ajouter(&non_trie,78);
     ajouter(&non_trie,3);
     ajouter(&non_trie,97);
     ajouter(&non_trie,16);
     ajouter(&non_trie,41);
     ajouter(&non_trie,8);
     
     
     SetTargetFPS(60);
     int fin_animation=0;
     
     
     while(!WindowShouldClose() && !fin_animation){
         liste *temp= non_trie;
         while(temp !=NULL){
             ajouter(&trie,temp->info);
             temp=temp->suiv;
         }
         
//******TRI DE LA 2EME LISTE******
         if(trie !=NULL){
             liste* temp=trie;
             while(temp->suiv!=NULL){
                 liste* min=temp;
                 liste* temp2=temp->suiv;
                 while(temp2!=NULL){
                     if(temp2->info<min->info){
                         min=temp2;
                     }
                     temp2=temp2->suiv;
                 }
                 min->swaping=true;
                 BeginDrawing();
                 ClearBackground(RAYWHITE);
                 
                 DrawText("Tri par sélection", 10, 10, 20, DARKGRAY);
                 
                 DrawText("Liste non triée", 10, 50, 20, BLUE);
                 drawlist(non_trie, BLUE, 10, 50);
                 
                 DrawText("Liste triée croissante", 10, 550, 20, RED);
                 drawlist(trie, RED, 10, 550);
                 
                 EndDrawing();
                 
                 SetTargetFPS(1.0 / 0.5); //pause
                 
                 swap(temp, min);
                 
                 BeginDrawing();
                 ClearBackground(RAYWHITE);

                 DrawText("Tri par sélection", 10, 10, 20, DARKGRAY);

                 DrawText("Liste non triée", 10, 50, 20, BLUE);
                 drawlist(non_trie, BLUE, 10, 50);

                 DrawText("Liste triée croissante", 10, 550, 20, RED);
                 drawlist(trie, RED, 10, 550);

                 EndDrawing();
                 
                 SetTargetFPS(1.0 / 0.5);//pause
                 
                 temp=temp->suiv;
             }
             fin_animation=1;
         }   
         
     }
     CloseWindow();
     return 0;
 }


























