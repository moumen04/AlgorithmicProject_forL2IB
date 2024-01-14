#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <string.h>
#include <unistd.h>

//******DECLARATION BOUTON******
    typedef struct bouton{
        Rectangle rect;
        Color color;
    }bouton;
    
//******INITIALISER BOUTON******
    void init_bouton(bouton *bout,Rectangle rect,Color color){
        bout->rect=rect;
        bout->color=color;
    }
    
//******MOUSE OVER BOUTON******
    bool mouse_bouton(bouton *bout){
        return CheckCollisionPointRec(GetMousePosition(),bout->rect);
    }
    
//******MOUSE CLICK BOUTON******
    bool click_bouton(bouton *bout){
        return (mouse_bouton(bout) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
    }

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
         DrawRectangle(xpos,ypos -temp->info *2,30,temp->info *2,listecolor);
         DrawText(TextFormat("%d",temp->info),xpos+5,ypos -temp->info-10,10,BLACK);
         xpos+=45;
         temp->swaping=false;
         temp=temp->suiv;
     }
 }
 
 
//******MAIN FONCTION******
 int main (){
     int win_widht=1000;
     int win_height=1000;
     //******WINDOW INITIALISATION******
     InitWindow(win_widht,win_height,"TRI PAR SELECTION");
     SetTargetFPS(60);
     
     //******DECLARATION LISTE******
     liste* non_trie=NULL;
     liste* trie=NULL;
     
     //******MAIN VARIABLES******
     
     int start=0;
     int textlength=0;
     char input[32]= "";
     int i=0;
     bool over=false;
     
     //******MAIN BOUTONS******
     bouton bout_stop;
     bouton bout_start;
     bouton bout_insert;
     bouton bout_supp;
     bouton bout_head;
     bouton bout_queu;
     bouton bout_val;
     bouton bout_pos;
     bouton bout_vide;
     bouton bout_exit;
     //******INITIALISATION DES BOUTON******
     init_bouton(&bout_start,(Rectangle){400,700,200,80},GREEN);
     init_bouton(&bout_stop,(Rectangle){400,700,200,80},RED);
     init_bouton(&bout_insert,(Rectangle){100,700,200,80},GREEN);
     init_bouton(&bout_supp,(Rectangle){700,700,200,80},GREEN);
     init_bouton(&bout_head,(Rectangle){250,460,200,80},BLUE);
     init_bouton(&bout_queu,(Rectangle){550,460,200,80},BLUE);
     init_bouton(&bout_val,(Rectangle){250,460,200,80},BLUE);
     init_bouton(&bout_pos,(Rectangle){550,460,200,80},BLUE);
     init_bouton(&bout_vide,(Rectangle){810,850,90,45},DARKGRAY);
     init_bouton(&bout_exit,(Rectangle){100,850,90,45},DARKGRAY);
     
     
     
     
     
     //******WINDOW START******
     while(!WindowShouldClose()){
         //******FIRST WINDOW SETTINGS******
         if(start==0){
             if(click_bouton(&bout_stop)){
                start=1; 
             }
             BeginDrawing();
             ClearBackground(RAYWHITE); 
             DrawText("Welcome,this project is represented by:",500-MeasureText("Welcome,this project is represented by:",30)/2,200,30,BLACK);
             DrawText("AMIRI ABDELMOUMENE 222231595017",500-MeasureText("AMIRI ABDELMOUMENE 222231595017",30)/2,300,30,BLACK);
             DrawText("AND",500-MeasureText("AND",30)/2,400,30,BLACK);
             DrawText("DORBANE WASSIM 222231620917",500-MeasureText("DORBANE WASSIM 222231620917",30)/2,500,30,BLACK);
             DrawText("TO START PRESS THE BUTTON BELLOW",500-MeasureText("TO START PRES THE BUTTON BELLOW",30)/2,600,30,BLACK);
             DrawRectangleRec(bout_start.rect,bout_start.color);
             DrawText("START",bout_start.rect.x+bout_start.rect.width/2-MeasureText("START",30)/2,bout_start.rect.y+bout_start.rect.height/2-10,30,BLACK);
             DrawRectangleLines(bout_start.rect.x,bout_start.rect.y,bout_start.rect.width,bout_start.rect.height,BLACK);

             EndDrawing();
         }
         
         //******WINDOW OF TREATEMENT******
         if(start==1){
             
             //******CLICK BOUTONS TEST******
             if(click_bouton(&bout_stop)){
                start=2; 
                over=false;
             }
             if(click_bouton(&bout_insert)){
                 start=3;
                 over=false;
             }
             if(click_bouton(&bout_supp)){
                 start=4;
                 over=false;
             }
             if(click_bouton(&bout_vide)){
                 start=9;
                 over=false;
             }
             if(click_bouton(&bout_exit)){
                 start=-1;
             }
             
             //******AFFICHAGE DE MESSAGE D'ERREUR******
             if(i==0){
                 bout_vide.color=RED;
             }
             else{
                 bout_vide.color=DARKGRAY;
             }
             
             //******SCANER LE NOMBRE
             if(textlength<31){
                 int key=GetKeyPressed();
                 if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textlength] = (char) key;
                textlength++;
                }
                 if(key==KEY_BACKSPACE&& textlength>=0){
                textlength--;
                input[textlength]=0;
                
                }
                 if(key == KEY_SPACE){
                input[textlength]='-';
                textlength++;}                 
             }            
             if (IsKeyPressed(KEY_ENTER)) {
            // Convert the input text to a float
            int info = (int) atoi(input);  
            ajouter(&non_trie,info);
             i=1;    
            // Clear the input text after pressing Enter
            textlength = 0;
            memset(input, 0, sizeof(input));            
            }
            
            //******DESSINER LA PAGE DE TRAITEMENT******
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        
        DrawRectangleRec(bout_stop.rect,bout_stop.color);
        DrawText("SORT THE LIST",bout_stop.rect.x+bout_stop.rect.width/2-MeasureText("SORT THE LIST",20)/2,bout_stop.rect.y+bout_stop.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_stop.rect.x,bout_stop.rect.y,bout_stop.rect.width,bout_stop.rect.height,BLACK);
        
        DrawRectangleRec(bout_insert.rect,bout_insert.color);
        DrawText("ADD ELEMT",bout_insert.rect.x+bout_insert.rect.width/2-MeasureText("ADD ELEMT",20)/2,bout_insert.rect.y+bout_insert.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_insert.rect.x,bout_insert.rect.y,bout_insert.rect.width,bout_insert.rect.height,BLACK);
        
        DrawRectangleRec(bout_supp.rect,bout_supp.color);
        DrawText("SUPP ELEMT",bout_supp.rect.x+bout_supp.rect.width/2-MeasureText("SUPP ELEMT",20)/2,bout_supp.rect.y+bout_supp.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_supp.rect.x,bout_supp.rect.y,bout_supp.rect.width,bout_supp.rect.height,BLACK);
        
        DrawRectangleRec(bout_vide.rect,bout_vide.color);
        DrawText("VOID",bout_vide.rect.x+bout_vide.rect.width/2-MeasureText("VOID",20)/2,bout_vide.rect.y+bout_vide.rect.height/2-10,20,YELLOW);
        DrawRectangleLines(bout_vide.rect.x,bout_vide.rect.y,bout_vide.rect.width,bout_vide.rect.height,BLACK);
        
        DrawRectangleRec(bout_exit.rect,bout_exit.color);
        DrawText("EXIT",bout_exit.rect.x+bout_exit.rect.width/2-MeasureText("EXIT",20)/2,bout_exit.rect.y+bout_exit.rect.height/2-10,20,YELLOW);
        DrawRectangleLines(bout_exit.rect.x,bout_exit.rect.y,bout_exit.rect.width,bout_exit.rect.height,BLACK);
        
        DrawText("Enter a Number to the List:", 10, 10, 30, DARKGRAY);
        DrawText(input,MeasureText("Enter a Number to the List: ",30), 10, 30, DARKGRAY);
        if(over){
            DrawText("YOUR POSITION IS OVER THE LIST CAPACITY",500-MeasureText("YOUR POSITION IS OVER THE LIST CAPACITY",30)/2,500,30,BLACK);
        }
        
        //******DESSINER LA LISTE SI ELLE EXISTE******
        if (i>0){
            drawlist(non_trie, BLUE, 10, 50);      
            DrawText("List not sorted", 10, 50, 20, RED);
        } 
        EndDrawing();
         }   
            
        //******WINDOW OF SORTING******
         if(start==2){
         liste *temp= non_trie;
         trie=NULL;
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
                 
                 //******AFFICHAGE DES DEUS LISTES******
                 BeginDrawing();
                 ClearBackground(RAYWHITE);
                 
                 DrawText("Sort by selection:", 10, 10, 20, DARKGRAY);
                 
                 drawlist(non_trie, BLUE, 10, 50);
                 DrawText("Unsorted List", 10, 50, 20, RED);
                 
                 drawlist(trie, RED, 10, 550);
                 DrawText("Sorted List", 10, 550, 20, BLUE);                 
                 
                 EndDrawing();
                 
                 usleep(800000); //pause
                 
                 swap(temp, min);
                 
                 BeginDrawing();
                 ClearBackground(RAYWHITE);

                 DrawText("Sort by selection", 10, 10, 20, DARKGRAY);

                 drawlist(non_trie, BLUE, 10, 50);
                 DrawText("Unsorted List", 10, 50, 20, RED);                 

                 drawlist(trie, RED, 10, 550);
                 DrawText("Sorted List", 10, 550, 20, BLUE);                 

                 EndDrawing();
                 
                 usleep(800000);//pause
                 
                 temp=temp->suiv;
             }
             
             start=1;//retourner a la page de traitement
             non_trie=trie;//charge la liste trie 
         }        
     }
     
        //******INSERT WINDOW H/Q******
        if(start==3){
            if(click_bouton(&bout_head)){
                start=5;
            }
            if(click_bouton(&bout_queu)){
                start=6;
            }
         BeginDrawing();
         ClearBackground(RAYWHITE); 
        
        DrawRectangleRec(bout_head.rect,bout_head.color);
        DrawText("IN THE HEAD:",bout_head.rect.x+bout_head.rect.width/2-MeasureText("IN THE HEAD:",20)/2,bout_head.rect.y+bout_head.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_head.rect.x,bout_head.rect.y,bout_head.rect.width,bout_head.rect.height,BLACK);
        
        DrawRectangleRec(bout_queu.rect,bout_queu.color);
        DrawText("IN THE QUEUE:",bout_queu.rect.x+bout_queu.rect.width/2-MeasureText("IN THE QUEUE:",20)/2,bout_queu.rect.y+bout_queu.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_queu.rect.x,bout_queu.rect.y,bout_queu.rect.width,bout_queu.rect.height,BLACK);
        
        EndDrawing();}
     
        //******SUPP WINDOW V/P******
        if(start==4){
            if(click_bouton(&bout_val)){
                start=7;
            }
            if(click_bouton(&bout_pos)){
                start=8;
            }
         BeginDrawing();
         ClearBackground(RAYWHITE); 
        
        DrawRectangleRec(bout_val.rect,bout_val.color);
        DrawText("VALUE:",bout_val.rect.x+bout_val.rect.width/2-MeasureText("VALUE:",20)/2,bout_val.rect.y+bout_val.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_val.rect.x,bout_val.rect.y,bout_val.rect.width,bout_val.rect.height,BLACK);
        
        DrawRectangleRec(bout_pos.rect,bout_pos.color);
        DrawText("POSITION:",bout_pos.rect.x+bout_pos.rect.width/2-MeasureText("POSITION:",20)/2,bout_pos.rect.y+bout_pos.rect.height/2-10,20,BLACK);
        DrawRectangleLines(bout_pos.rect.x,bout_pos.rect.y,bout_pos.rect.width,bout_pos.rect.height,BLACK);
        
        EndDrawing();}
        
        //******INSERT NUMBER IN HEAD******
        if(start==5){
           if(textlength<31){
                 int key=GetKeyPressed();
                 if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textlength] = (char) key;
                textlength++;
                }
                 if(key==KEY_BACKSPACE&& textlength>=0){
                textlength--;
                input[textlength]=0;
                
                }
                 if(key == KEY_SPACE){
                input[textlength]='-';
                textlength++;}
                 
             }
                if (IsKeyPressed(KEY_ENTER)) {
            // Convert the input text to an intigar 
            int info = (int) atoi(input); 
            if(non_trie==NULL){
                non_trie=add_liste();
                non_trie->info=info;
                non_trie->swaping=false;
                non_trie->suiv=NULL;
                non_trie->prec=NULL;
            }
            else{
            liste *temp=add_liste();
            temp->info=info;
            temp->suiv=non_trie;
            temp->swaping=false;
            non_trie->prec=temp;
            non_trie=temp;}
            
            start=1;
            i=1;
            // Clear the input text after pressing Enter
            textlength = 0;
            memset(input, 0, sizeof(input));
           
            
            }
            
            
            
        BeginDrawing();
        ClearBackground(RAYWHITE);   
        DrawText("Enter Number:", 10, 10, 30, DARKGRAY);
        DrawText(input,MeasureText("Enter Number: ",30), 10, 30, DARKGRAY);
        EndDrawing();
        }
        
            //******INSERT NUMBER IN QUEUE******
            if(start==6){
                if(textlength<31){
                 int key=GetKeyPressed();
                 if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textlength] = (char) key;
                textlength++;
                }
                 if(key==KEY_BACKSPACE&& textlength>=0){
                textlength--;
                input[textlength]=0;
                
                }
                 if(key == KEY_SPACE){
                input[textlength]='-';
                textlength++;}
             }    
             if (IsKeyPressed(KEY_ENTER)) {
            // Convert the input text to an intigar 
            int info = (int) atoi(input);
            if(non_trie==NULL){
                non_trie=add_liste();
                non_trie->info=info;
                non_trie->swaping=false;
                non_trie->suiv=NULL;
                non_trie->prec=NULL;
            }  
            else{            
            liste *temp=non_trie;
            liste *temp1=add_liste();
            temp1->info=info;
            temp1->swaping=false;    
            
            while(temp->suiv!=NULL){
                temp=temp->suiv;
            }
            temp1->prec=temp;
            temp1->suiv=NULL;
            temp->suiv=temp1;}
            
            start=1;
            i=1;
            // Clear the input text after pressing Enter
            textlength = 0;
            memset(input, 0, sizeof(input));
           
            
            }
            
            BeginDrawing();
            ClearBackground(RAYWHITE);   
            DrawText("Enter Number:", 10, 10, 30, DARKGRAY);
            DrawText(input,MeasureText("Enter Number: ",30), 10, 30, DARKGRAY);
            EndDrawing();
                
            }
            
            //******SUPP NUMBER WITH VALUE******
            if(start==7){
                 if(textlength<31){
                 int key=GetKeyPressed();
                 if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textlength] = (char) key;
                textlength++;
                }
                 if(key==KEY_BACKSPACE&& textlength>=0){
                textlength--;
                input[textlength]=0;                
                }
                if(key == KEY_SPACE){
                input[textlength]='-';
                textlength++;}                
             } 
              if (IsKeyPressed(KEY_ENTER)) {
            // Convert the input text to an intigar 
            int info = (int) atoi(input); 
            if(non_trie!=NULL){            
            liste *temp=non_trie->suiv;
            liste *temp1=non_trie;
            while(temp!=NULL){
                if(temp->info==info){
                    temp1->suiv=temp->suiv;
                }
                temp=temp->suiv;
                temp1=temp1->suiv;
            }}
            
            start=1;
            i=1;
            // Clear the input text after pressing Enter
            textlength = 0;
            memset(input, 0, sizeof(input));
           
            
            }  
            
            BeginDrawing();
            ClearBackground(RAYWHITE);   
            DrawText("Enter Number:", 10, 10, 30, DARKGRAY);
            DrawText(input,MeasureText("Enter Number: ",30), 10, 30, DARKGRAY);
            EndDrawing();
             
            }
            
            //******SUPP NUMBER WITH POSITION******
            if(start==8){
                if(textlength<31){
                 int key=GetKeyPressed();
                 if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textlength] = (char) key;
                textlength++;
                }
                 if(key==KEY_BACKSPACE&& textlength>=0){
                textlength--;
                input[textlength]=0;
                
                }
                 if(key == KEY_SPACE){
                input[textlength]='-';
                textlength++;}
                 
             } 
             
             if (IsKeyPressed(KEY_ENTER)) {
            // Convert the input text to an intigar 
            int info = (int) atoi(input); 
            if(non_trie!=NULL){
            int count=0;
            liste *temp=non_trie;
            while(temp!=NULL){
                count++;
            temp=temp->suiv;}
            
            temp=non_trie->suiv;
            liste *temp1=non_trie;
            if(info<=count){
                for(int j=1; j<info-1; j++){
                    temp=temp->suiv;
                    temp1=temp1->suiv;
                }
            
                temp1->suiv=temp->suiv;
            }else{over=true;}}
            
            start=1;
            i=1;
            // Clear the input text after pressing Enter
            textlength = 0;
            memset(input, 0, sizeof(input));
           
            
            
            }
            BeginDrawing();
            ClearBackground(RAYWHITE);   
            DrawText("Enter Position:", 10, 10, 30, DARKGRAY);
            DrawText(input,MeasureText("Enter Position: ",30), 10, 30, DARKGRAY);
            EndDrawing();
            }
            
            //******VIDER LA LISTE******
            if(start==9){
                non_trie=NULL;
                i=0;
                start=1;
            }
            //******EXIT PROGRAMM******
            if(start==-1){
                CloseWindow();
            }
     
     }
     
     return 0;
 }
