#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant {
    int id;
    char nom[50];
    float moyenne;
    struct Etudiant* suivant;
    struct Etudiant* precedent;
} Etudiant;

Etudiant* creer_etudiant() {
    Etudiant* nouveau = (Etudiant*)malloc(sizeof(Etudiant));
    
    printf("ID: ");
    scanf("%d", &nouveau->id);
    
    printf("Nom: ");
    scanf("%s", nouveau->nom);
    
    printf("Moyenne: ");
    scanf("%f", &nouveau->moyenne);
    
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    
    return nouveau;
}

int longueur(Etudiant* tete) {
    int count = 0;
    Etudiant* courant = tete;
    while(courant != NULL) {
        count++;
        courant = courant->suivant;
    }
    return count;
}

Etudiant* ajouter_position(Etudiant* tete, Etudiant* nouveau, int position) {
    if(position < 1 || position > longueur(tete)+1) {
        printf("Position invalide\n");
        return tete;
    }
    
    if(position == 1) {
        nouveau->suivant = tete;
        if(tete != NULL) {
            tete->precedent = nouveau;
        }
        return nouveau;
    }
    
    Etudiant* courant = tete;
    for(int i = 1; i < position-1; i++) {
        courant = courant->suivant;
    }
    
    nouveau->suivant = courant->suivant;
    nouveau->precedent = courant;
    if(courant->suivant != NULL) {
        courant->suivant->precedent = nouveau;
    }
    courant->suivant = nouveau;
    
    return tete;
}

Etudiant* supprimer_position(Etudiant* tete, int position) {
    if(position < 1 || position > longueur(tete)) {
        printf("Position invalide\n");
        return tete;
    }
    
    if(position == 1) {
        Etudiant* temp = tete;
        tete = tete->suivant;
        if(tete != NULL) {
            tete->precedent = NULL;
        }
        free(temp);
        return tete;
    }
    
    Etudiant* courant = tete;
    for(int i = 1; i < position; i++) {
        courant = courant->suivant;
    }
    
    courant->precedent->suivant = courant->suivant;
    if(courant->suivant != NULL) {
        courant->suivant->precedent = courant->precedent;
    }
    free(courant);
    
    return tete;
}

void afficher_liste(Etudiant* tete) {
    Etudiant* courant = tete;
    while(courant != NULL) {
        printf("ID: %d, Nom: %s, Moyenne: %.2f\n", 
               courant->id, courant->nom, courant->moyenne);
        courant = courant->suivant;
    }
}

Etudiant* derniere_cellule(Etudiant* tete) {
    if(tete == NULL) return NULL;
    
    Etudiant* courant = tete;
    while(courant->suivant != NULL) {
        courant = courant->suivant;
    }
    return courant;
}

int main() {
    Etudiant* liste = NULL;
    
    Etudiant* e1 = creer_etudiant();
    Etudiant* e2 = creer_etudiant();
    Etudiant* e3 = creer_etudiant();
    
    liste = ajouter_position(liste, e1, 1);
    liste = ajouter_position(liste, e2, 1);
    liste = ajouter_position(liste, e3, 2);
    
    printf("\nListe des etudiants:\n");
    afficher_liste(liste);
    
    printf("\nLongueur de la liste: %d\n", longueur(liste));
    
    Etudiant* dernier = derniere_cellule(liste);
    printf("\nDernier etudiant: %s\n", dernier->nom);
    
    liste = supprimer_position(liste, 2);
    printf("\nApres suppression position 2:\n");
    afficher_liste(liste);
    
    return 0;
}
