#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

typedef struct File {
    Noeud *debut;
    Noeud *fin;
} File;

void initialiserFile(File *f) {
    f->debut = NULL;
    f->fin = NULL;
}

int estVide(File *f) {
    return (f->debut == NULL);
}

void enfiler(File *f, int valeur) {
    Noeud nouveau = (Noeud)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    
    if (estVide(f)) {
        f->debut = f->fin = nouveau;
    } else {
        f->fin->suivant = nouveau;
        f->fin = nouveau;
    }
}

void defiler(File *f) {
    if (estVide(f)) {
        printf("La file est vide, impossible de defiler\n");
        return;
    }
    
    Noeud *temp = f->debut;
    f->debut = f->debut->suivant;
    
    if (f->debut == NULL) {
        f->fin = NULL;
    }
    
    free(temp);
}

void afficherFile(File *f) {
    if (estVide(f)) {
        printf("La file est vide\n");
        return;
    }
    
    Noeud *courant = f->debut;
    printf("Contenu de la file (debut -> fin): ");
    while (courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
    printf("\n");
}

void viderFile(File *f) {
    while (!estVide(f)) {
        defiler(f);
    }
}

int teteFile(File *f) {
    if (estVide(f)) {
        printf("La file est vide\n");
        return -1; 
    }
    return f->debut->valeur;
}

int main() {
    File maFile;
    initialiserFile(&maFile);
    
    printf("=== TEST DE LA FILE ===\n");
    
    printf("\n1. Enfiler 10, 20, 30...\n");
    enfiler(&maFile, 10);
    enfiler(&maFile, 20);
    enfiler(&maFile, 30);
    
    printf("\n2. Affichage de la file:\n");
    afficherFile(&maFile);
    
    printf("\n3. Defiler un element...\n");
    defiler(&maFile);
    
    printf("\n4. Affichage apres defilage:\n");
    afficherFile(&maFile);
    
    printf("\n5. Enfiler 40, 50, 60...\n");
    enfiler(&maFile, 40);
    enfiler(&maFile, 50);
    enfiler(&maFile, 60);
    
    printf("\nAffichage avant vidage:\n");
    afficherFile(&maFile);
    
    printf("\nVider la file...\n");
    viderFile(&maFile);
    
    printf("\nAffichage apres vidage:\n");
    afficherFile(&maFile);
    
    printf("\nTest supplementaire:\n");
    enfiler(&maFile, 100);
    enfiler(&maFile, 200);
    printf("Tete de file: %d\n", teteFile(&maFile));
    
    return 0;
}
