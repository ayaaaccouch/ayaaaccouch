#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* creer_noeud(int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

void afficher(Noeud *debut) {
    Noeud* courant = debut;
    while(courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

Noeud* ajouterD(Noeud *debut, int valeur) {
    Noeud* nouveau = creer_noeud(valeur);
    nouveau->suivant = debut;
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
    courant->suivant = nouveau;
    return debut;
}

void rechercher(Noeud *debut, int valeur) {
    Noeud* courant = debut;
    int pos = 1;
    while(courant != NULL) {
        if(courant->valeur == valeur) {
            printf("Valeur %d trouvee a la position %d\n", valeur, pos);
            return;
        }
        courant = courant->suivant;
        pos++;
    }
    printf("Valeur %d non trouvee\n", valeur);
}

Noeud* suppressionD(Noeud *debut) {
    if(debut == NULL) return NULL;
    Noeud* temp = debut;
    debut = debut->suivant;
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
    while(courant->suivant->suivant != NULL) {
        courant = courant->suivant;
    }
    free(courant->suivant);
    courant->suivant = NULL;
    return debut;
}

Noeud* suppressionP(Noeud *debut, int pos) {
    if(pos < 1 || pos > taille(debut)) return debut;
    if(pos == 1) return suppressionD(debut);
    
    Noeud* courant = debut;
    for(int i = 1; i < pos-1; i++) {
        courant = courant->suivant;
    }
    Noeud* temp = courant->suivant;
    courant->suivant = temp->suivant;
    free(temp);
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

int main() {
    Noeud* liste = NULL;
    
    // Création initiale
    liste = ajouterF(liste, 10);
    liste = ajouterF(liste, 20);
    liste = ajouterF(liste, 30);
    
    // Affichage
    printf("Liste initiale: ");
    afficher(liste);
    
    // Test des fonctions
    liste = ajouterD(liste, 5);
    printf("Apres ajout debut: ");
    afficher(liste);
    
    liste = ajouterF(liste, 40);
    printf("Apres ajout fin: ");
    afficher(liste);
    
    printf("Taille: %d\n", taille(liste));
    
    liste = insertion(liste, 3, 15);
    printf("Apres insertion position 3: ");
    afficher(liste);
    
    rechercher(liste, 20);
    rechercher(liste, 99);
    
    liste = suppressionD(liste);
    printf("Apres suppression debut: ");
    afficher(liste);
    
    liste = suppressionF(liste);
    printf("Apres suppression fin: ");
    afficher(liste);
    
    liste = suppressionP(liste, 2);
    printf("Apres suppression position 2: ");
    afficher(liste);
    
    liste = modifierD(liste, 100);
    printf("Apres modification debut: ");
    afficher(liste);
    
    liste = modifierF(liste, 200);
    printf("Apres modification fin: ");
    afficher(liste);
    
    liste = modifierP(liste, 2, 150);
    printf("Apres modification position 2: ");
    afficher(liste);
    
    return 0;
}

