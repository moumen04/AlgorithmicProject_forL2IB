#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct poly
{   float c;
    int d;
    struct poly *P;
   
}poly;
//ALLOCATION
poly * add(){
    return (poly*) malloc(sizeof(poly));}
//CREATION DE LISTE
poly *lirepoly(int n){
  poly *p=add();
    p->d=n;
    printf("entrer la coefficient de degre %d : ",n);
    scanf("%f",&p->c);
    p->P=NULL;
    for (int i = 1; i <n; i++)
        {poly *nv=add();
        nv->d=n-i;
        printf("\nentrer la coefficient de degre %d : ",n-i);
        scanf("%f",&nv->c);
        nv->P=p;
        p=nv;}
    poly *nv=add();
    printf("\nentrer la coefficient de degre 0 :");
    scanf("%f",&nv->c);
    nv->P=p; 
    p=nv;
    return p;
    free(nv); }
//AFFICHAGE
void affichpoly (poly *p,int n){
    float g;
    printf("\nP(x)= %.1f",p->c);
    p=p->P;
    for (int i = 0; i < n ; i++)
    {if (p->c==0){p=p->P;}
        else printf(" + %.1fx^%d",  p->c, p->d);
             p=p->P;}}

//CALCULE EN UN POIN
float evaluepoly(poly *p,int n,float x){
    float a=p->c;
    p=p->P;
    for (int i = 0; i < n; i++)
    {a=a+p->c*pow(x,p->d);p=p->P;}
    return a; }  
//SOMME DE DEUX POLY
poly * sompoly (poly *p1,poly *p2,int n,int m){
    poly *p3=add(),*l=add();
    p3->c=p1->c+p2->c;
    p3->d=0;
    l=p3;
    p1=p1->P;p2=p2->P;
    if (n>=m)
    {
     for (int i = 1; i < m+1; i++)
     {poly *pt=add();
      pt->d=i;
      pt->c=p1->c+p2->c;
      pt->P=NULL;
      l->P=pt;
      l=pt;
      p1=p1->P;p2=p2->P;  
     }
     for (int i = m+1; i < n+1; i++)
     {poly *pt=add();
      pt->d=i;
      pt->c=p1->c;
      pt->P=NULL;
      l->P=pt;
      l=pt;
      p1=p1->P;  
     }}
    else{
     for (int i = 1; i < n+1; i++)
     {poly *pt=add();
      pt->d=i;
      pt->c=p1->c+p2->c;
      pt->P=NULL;
      l->P=pt;
      l=pt;
      p1=p1->P;p2=p2->P;  
     }
     for (int i = n+1; i < m+1; i++)
     {poly *pt=add();
      pt->d=i;
      pt->c=p2->c;
      pt->P=NULL;
      l->P=pt;
      l=pt;
      p2=p2->P;  
     }    
    }
    return p3;
}
void main (){
    int n,m,w;float x,a;
    poly *p,*p1,*p3;
    printf("entrer le nombre de premier degre: ");
    scanf("%d",&n);
    p=lirepoly(n);
    affichpoly(p,n);

    printf("\nentrer le point X a evaluer : ");
    scanf("%f",&x);
    a=evaluepoly(p,n,x);
    printf("\nyour finnal result is : %.1f",a);

    printf("\nentrer le nombre de premier degre du polynome a addissioner : ");
    scanf("%d",&m);
    p1=lirepoly(m);
    affichpoly(p1,m);

    p3=sompoly(p,p1,n,m);
    if (n>=m){w=n;}else{w=m;}  
    affichpoly(p3,w);
    
    
    
    



}