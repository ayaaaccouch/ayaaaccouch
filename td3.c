#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
    struct Noeud *precedent;
} Noeud;

Noeud* creer_noeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

void afficher(Noeud *debut) {
    Noeud* courant = debut;
    while(courant != NULL) {
        printf("%d <-> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

void afficherInverse(Noeud *debut) {
    if(debut == NULL) return;
    
    Noeud* courant = debut;
    while(courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    while(courant != NULL) {
        printf("%d <-> ", courant->valeur);
        courant = courant->precedent;
    }
    printf("NULL\n");
}

Noeud* ajouterD(Noeud *debut, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);
    
    if(debut == NULL) return nouveau;
    
    nouveau->suivant = debut;
    debut->precedent = nouveau;
    return nouveau;
}

Noeud* ajouterF(Noeud *debut, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);
    
    if(debut == NULL) return nouveau;
    
    Noeud* courant = debut;
    while(courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->suivant = nouveau;
    nouveau->precedent = courant;
    return debut;
}

int taille(Noeud *debut) {
    int count = 0;
    Noeud* courant = debut;
    while(courant != NULL) {
        count++;
        courant = courant->suivant;
    }
    return count;
}

Noeud* insertion(Noeud *debut, int pos, int valeur) {
    if(pos < 1 || pos > taille(debut)+1) return debut;
    
    if(pos == 1) return ajouterD(debut, valeur);
    
    Noeud* nouveau = creer_noeud(valeur);
    Noeud* courant = debut;
    
    for(int i = 1; i < pos-1; i++) {
        courant = courant->suivant;
    }
    
    nouveau->suivant = courant->suivant;
    nouveau->precedent = courant;
    if(courant->suivant != NULL) {
        courant->suivant->precedent = nouveau;
    }
    courant->suivant = nouveau;
    
    return debut;
}

Noeud* rechercher(Noeud *debut, int valeur) {
    Noeud* courant = debut;
    while(courant != NULL) {
        if(courant->valeur == valeur) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

Noeud* suppressionD(Noeud *debut) {
    if(debut == NULL) return NULL;
    
    Noeud* temp = debut;
    debut = debut->suivant;
    if(debut != NULL) {
        debut->precedent = NULL;
    }
    free(temp);
    return debut;
}

Noeud* suppressionF(Noeud *debut) {
    if(debut == NULL) return NULL;
    
    if(debut->suivant == NULL) {
        free(debut);
        return NULL;
    }
    
    Noeud* courant = debut;
    while(courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->precedent->suivant = NULL;
    free(courant);
    return debut;
}

Noeud* suppressionP(Noeud *debut, int pos) {
    if(pos < 1 || pos > taille(debut)) return debut;
    
    if(pos == 1) return suppressionD(debut);
    
    Noeud* courant = debut;
    for(int i = 1; i < pos; i++) {
        courant = courant->suivant;
    }
    
    if(courant->suivant == NULL) {
        courant->precedent->suivant = NULL;
    } else {
        courant->precedent->suivant = courant->suivant;
        courant->suivant->precedent = courant->precedent;
    }
    
    free(courant);
    return debut;
}

Noeud* modifierD(Noeud *debut, int valeur) {
    if(debut == NULL) return NULL;
    debut->valeur = valeur;
    return debut;
}

Noeud* modifierF(Noeud *debut, int valeur) {
    if(debut == NULL) return NULL;
    
    Noeud* courant = debut;
    while(courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->valeur = valeur;
    return debut;
}

Noeud* modifierP(Noeud *debut, int pos, int valeur) {
    if(pos < 1 || pos > taille(debut)) return debut;
    
    Noeud* courant = debut;
    for(int i = 1; i < pos; i++) {
        courant = courant->suivant;
    }
    
    courant->valeur = valeur;
    return debut;
}

Noeud* tri(Noeud *debut) {
    if(debut == NULL || debut->suivant == NULL) return debut;
    
    int swapped;
    Noeud* ptr1;
    Noeud* lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = debut;
        
        while(ptr1->suivant != lptr) {
            if(ptr1->valeur > ptr1->suivant->valeur) {
                // Échange des valeurs
                int temp = ptr1->valeur;
                ptr1->valeur = ptr1->suivant->valeur;
                ptr1->suivant->valeur = temp;
                swapped = 1;
            }
            ptr1 = ptr1->suivant;
        }
        lptr = ptr1;
    } while(swapped);
    
    return debut;
}

int main() {
    Noeud* liste = NULL;
    
    liste = ajouterF(liste, 30);
    liste = ajouterF(liste, 10);
    liste = ajouterF(liste, 20);
    liste = ajouterF(liste, 40);
    
    printf("Liste initiale:\n");
    afficher(liste);
    printf("Liste inverse:\n");
    afficherInverse(liste);

    liste = ajouterD(liste, 5);
    printf("\nApres ajout debut:\n");
    afficher(liste);
    
    liste = ajouterF(liste, 50);
    printf("\nApres ajout fin:\n");
    afficher(liste);
    
    printf("\nTaille: %d\n", taille(liste));
    
    liste = insertion(liste, 3, 15);
    printf("\nApres insertion position 3:\n");
    afficher(liste);
    
    Noeud* recherche = rechercher(liste, 20);
    if(recherche != NULL) {
        printf("\n20 trouve dans la liste\n");
    } else {
        printf("\n20 non trouve\n");
    }
    
    liste = suppressionD(liste);
    printf("\nApres suppression debut:\n");
    afficher(liste);
    
    liste = suppressionF(liste);
    printf("\nApres suppression fin:\n");
    afficher(liste);
    
    liste = suppressionP(liste, 2);
    printf("\nApres suppression position 2:\n");
    afficher(liste);
    
    liste = modifierD(liste, 100);
    printf("\nApres modification debut:\n");
    afficher(liste);
    
    liste = modifierF(liste, 200);
    printf("\nApres modification fin:\n");
    afficher(liste);
    
    liste = modifierP(liste, 2, 150);
    printf("\nApres modification position 2:\n");
    afficher(liste);
    
    liste = tri(liste);
    printf("\nApres tri:\n");
    afficher(liste);
    
    return 0;
}
