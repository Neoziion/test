#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#ifdef _WIN32
#include <windows.h>
#endif
#include <time.h>*/


#define SIZE 30
#define joueurs 50

//srand(time(NULL));
int rand_a_b(int a, int b){
    //srand(time(NULL));
    return rand()%(b-a)+ a;
}

void afficher_carte(int tab[SIZE][SIZE]){
    int i,j, k;
    system("cls");
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
                if(tab[i][j]==0) printf("X ");
            else if(tab[i][j]==1) printf("| ");
            else if(tab[i][j] < 11) printf("%d ", tab[i][j]-1);
            else printf("%d", tab[i][j]-1);
        }
        printf("\n");
    }
}
//return 0;


void classement(int tab[SIZE][SIZE]){
    int i;
    int podium[joueurs];
    for(i=0;i=joueurs-1;i++){
        podium[joueurs] = 0;
    }
    if(tab[(SIZE/2)-1][(SIZE/2)-1] > 2){
        podium[0] = tab[(SIZE/2)-1][(SIZE/2)-1] - 2;
    }
}

void alea_carte(int tab[SIZE][SIZE]){ //pose un nombre défini de 1 dans un tableau
    int i,j;
    int nbrblocs;
    nbrblocs = 10; //le nombre de 1 à mettre
    printf("%d\n", nbrblocs);
    while(nbrblocs > 0){
        for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                if(tab[i][j] == 0){ //si la case est vide
                    tab[i][j] = rand_a_b(0,2);

                     if (tab[i][j] == 1){ //si on a posé un 1
                                nbrblocs = nbrblocs - 1;
                     }
                }
            }
        }
    }

    if (nbrblocs !=0) {
        printf("faux\n");
    }
    tab[(SIZE/2)-1][(SIZE/2)-1] = 2;
}

void init_tab(int tab[SIZE][SIZE]){
    int i,j, compt = 0, aleaX, aleaY, switcher;
    int nbjoueurs[SIZE*SIZE];

    for(i=0; i < SIZE*SIZE; i++) nbjoueurs[i] = 0;

    for(i=1; i < joueurs; i++) nbjoueurs[i] = i + 2;

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
           tab[i][j] = nbjoueurs[compt];
            compt++;
        }
    }
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            aleaX = rand_a_b(0,SIZE);
            aleaY = rand_a_b(0,SIZE);
            switcher = tab[i][j];
            tab[i][j] = tab[aleaX][aleaY];
            tab[aleaX][aleaY] = switcher;
        }
    }
}
```C

```


int ligne_joueur(int tab[SIZE][SIZE], int n) {//retourne la ligne d'un joueur n est le nmero du jouer
    int i, j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            if (tab[i][j]==n+2){
                return(i);
            }
        }
    }
}
int col_joueur(int tab[SIZE][SIZE], int n) {//retourne la colonne d'un joueur, n est le nimeo du joue
    int i,j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            if (tab[i][j]==n+2){
                return(j);
            }
        }
    }
}
void avancer(int tab[SIZE][SIZE], int n){
    int h, b, d, g, s;
    h=0;
    b=0;
    d=0;
    g=0;
    if (ligne_joueur(tab,n)==0) {
        printf("Vous ne pouvez pas avancer vers le haut \n");
        h=2;
    }
      if (ligne_joueur(tab,n)==SIZE-1) {
        printf("Vous ne pouvez pas avancer vers le haut \n");
        b=2;
    }
    if (col_joueur(tab,n)==SIZE-1) {
        printf("Vous ne pouvez pas avancer vers la droite \n");
        d=2;
    }
    if (col_joueur(tab,n)==0) {
        printf("Vous ne pouvez pas avancer vers la gauche \n");
        g=2;
    }
    if (tab[ligne_joueur(tab,n)-1][col_joueur(tab,n)]==0 && h!=2){
        printf("Saisissez 1 pour avancer vers le haut\n");
        h=1;
    }
    if (tab[ligne_joueur(tab,n)+1][col_joueur(tab,n)]==0 && b!=2){
        printf("Saisissez 2 pour avancer vers le bas\n");
        b=1;
    }
    if (tab[ligne_joueur(tab,n)][col_joueur(tab,n)+1]==0 && d!=2){
        printf("Saisissez 3 pour avancer vers la droite \n");
        d=1;
    }
    if (tab[ligne_joueur(tab,n)][col_joueur(tab,n)-1]==0 && g!=2){
        printf("Saisissez 4 pour avancer vers la gauche \n");
        g=1;
        }

    scanf("%d", &s);

    if (s==1 && h==1){
            tab[ligne_joueur(tab,n)-1][col_joueur(tab,n)]=n+2;
            tab[ligne_joueur(tab,n)+1][col_joueur(tab,n)]=0;
    }
    else if (s==2 && b==1){
            tab[ligne_joueur(tab,n)+1][col_joueur(tab,n)]=n+2;
            tab[ligne_joueur(tab,n)][col_joueur(tab,n)]=0;
    }
    else if (s==3 && d==1){
            tab[ligne_joueur(tab,n)][col_joueur(tab,n)+1]=n+2;
            tab[ligne_joueur(tab,n)][col_joueur(tab,n)]=0;
    }
     else if (s==4 && g==1){
            tab[ligne_joueur(tab,n)][col_joueur(tab,n)-1]=n+2;
            tab[ligne_joueur(tab,n)][col_joueur(tab,n)+1]=0;
    }
    else {
        printf("Vous ne pouvez pas avancer \n");
    }


    }


int gagnant(int tab[SIZE][SIZE]){
    int i,j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            if(tab[i][j] > 1) return tab[i][j];
        }
    }
}


int main(){
    int tab[SIZE][SIZE];
    int a [99];
    int i,j;
    for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                    tab[i][j] = 0;
            }
    }
    srand(time(NULL));

    init_tab(tab);
    alea_carte(tab);
    afficher_carte(tab);
    avancer(tab,1);
    afficher_carte(tab);

return 0;
}


