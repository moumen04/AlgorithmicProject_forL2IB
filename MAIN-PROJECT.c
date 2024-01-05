#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//******VECTEUR******
    typedef struct vect{
    int i;
    int j;}vect;
//******PLATFORM******
    typedef struct platform{
    int x;
    int y;
    int radius ;
    int info;
    Color color;}platform;
    
//******DECLARATION DE LISTE******
    typedef struct liste{ 
    int info;
    struct liste *suivant;
    struct liste *preced;}liste; 
//*****TRIE PAR CELECTION******

    
//******ALLOCATION******
    liste *add_liste(){
      return (liste*)malloc(sizeof(liste));}
      
//******INITIALISATION******
    void initialiser_liste(liste **ptete,liste **pqueue){
    *ptete = add_liste();(*ptete)->info=0;
    *pqueue = add_liste();(*pqueue)->info=0;
    (*ptete)->suivant = NULL;
    (*pqueue)->suivant = NULL;}
    
//******REMPLICAGE******
    void remplire_liste(liste **ptete,liste **pqueue,int info){
        
        if((*ptete)->info==0){
            (*ptete)->info=info;
            (*ptete)->preced=NULL;
            (*ptete)->suivant=*pqueue;
            *pqueue=*ptete;}
            
        else{
             liste *temp=add_liste();
             temp->info=info;
             temp->suivant=NULL;
             temp->preced=*pqueue;
             (*pqueue)->suivant=temp;
             *pqueue=temp;}}
             
//******MINIMUM******
int minimum_numb(platform platforms[],int i){
    int minimum=platforms[0].info;
    int indice=0;
    platforms[0].color=YELLOW;
    for(int j=1; j<i+1;j++){
        if(platforms[j].info<minimum){
            minimum=platforms[j].info;
            platforms[j].color=YELLOW;
            if(platforms[indice].info<=25){
                platforms[indice].color=WHITE;}
            else{if(platforms[indice].info<=50){
                    platforms[indice].color=GREEN;}
                 else{if(platforms[indice].info<=75){
                        platforms[indice].color=RED;}
                      else{platforms[indice].color=BLACK;}}}
            indice=j;
            
        }
    }
    return(minimum);
    
}     
//******TRIE PAR CELECTION******
    void trier_liste(platform platforms[],int i,vect vect){
      int min=platforms[vect.i].info;
      
      for(int j=vect.j+1;j<i+1; j++){
          if(platforms[j].info<min){
              
          }
      }
            
        
        
        
        
    }
        
            
    
    
    
    
    
    
    



int main(){
    int window_width=1000;
    int window_hieght=800;
    char input[32] = ""; 
    char stop='y';
    char permut='N';
    int textLength = 0;
    vect vect={0,0};
    InitWindow(window_width,window_hieght,"MY PROJECT");
    SetTargetFPS(60);
    
   liste *ptete;
   liste *pqueue;
   initialiser_liste(&ptete,&pqueue);
   int info;
   int i=0;
   int text_x=10;
   
   liste *l=add_liste();
   platform platforms[10];
   int minimum;
   
   
   while(!WindowShouldClose()){
   
   
   //***********************************
   if (IsKeyPressed(KEY_ENTER) && stop=='y') {
            // Convert the input text to a float
            info = (int) atoi(input);
            i++;
            //************
            platforms[i].x=i*(70)-30;
            platforms[i].y=200;
            platforms[i].radius=30;
            platforms[i].info=info;
            
            if(info<=25){
                platforms[i].color=WHITE;}
            else{if(info<=50){
                    platforms[i].color=GREEN;}
                 else{if(info<=75){
                        platforms[i].color=RED;}
                      else{platforms[i].color=BLACK;}}}
                     
            
            remplire_liste(&ptete,&pqueue,info);
            
            // Clear the input text after pressing Enter
            textLength = 0;
            memset(input, 0, sizeof(input));
           
            
            }
                                            
            
            
            
            
        
        
        // Capture key input to build the input text
        if (textLength < 31&& stop =='y') {
            int key = GetKeyPressed();
            if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                input[textLength] = (char) key;
                textLength++;
            }
            if(key==KEY_BACKSPACE&& textLength>=0){
                textLength--;
                input[textLength]=0;
                
            }
            // Press SPACE_KEY to enter negative number 
            if(key == KEY_SPACE){
                input[textLength]='-';
                textLength++;}
        if ((key == KEY_N)){
        stop='N';}  
            }

    //***************************************
       
        if (i==0){minimum=0;}
        else{minimum=minimum_numb(platforms,i);}
        
        if(stop == 'N'){
            int key =GetKeyPressed();
            if(key == KEY_P){
                permut='y';
            }
            if(key == KEY_N){
                permut='N';
            }
        }
        
        
        
    
    
        
        
        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(500,400,pqueue->info,RED);
        DrawText("Enter Radius:", 10, 10, 20, DARKGRAY);
        DrawText(input, 160, 10, 20, DARKGRAY);
        if(stop=='N'){
            DrawText("**YOU HAVE FINISHED ENTERING NUMBERS**",10,50,20,DARKGRAY);
        }
        
        
       if (permut=='y'&& stop =='N'){
           if(platforms[2].x==110){
            if(platforms[2].y<270){
                platforms[2].y+=1;
           }}
            if(platforms[2].y>=270){
               if(platforms[1].x<110){
                   platforms[1].x+=1;
               }
            }
            if(platforms[1].x>=110){
                if(platforms[2].x>40){
                    platforms[2].x-=1;
                }
            }
            if(platforms[2].x==40){
               if (platforms[2].y>200){
                    platforms[2].y-=1;
                
            }}         
            
        }
        
        l=ptete;text_x=10;
            while(l!=NULL){
                
                 DrawText(TextFormat("|%i|->",l->info),text_x,30,20,WHITE);
                 l=l->suivant;
                text_x+=(int)sizeof(l->info)*10+15;}
        
    
    DrawText("NULL",text_x,30,20,WHITE);
     
     l=ptete;
    if(i>0){
    for (int j=1;j<i+1;j++){
        DrawCircle(platforms[j].x,platforms[j].y,platforms[j].radius,platforms[j].color);
        DrawText(TextFormat("%i",l->info),platforms[j].x-10,platforms[j].y-10,20,PURPLE);
       l=l->suivant;
    }}

   
    DrawText(TextFormat("minimum: %i",minimum),10,600,20,DARKGRAY);
    if(permut == 'y'){
        DrawText("************",10,700,20,DARKGRAY);
    }
    
    EndDrawing();}
    
    
    CloseWindow();
    return 0;
    
}
