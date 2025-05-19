td2:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    char jour[3];
    char mois[3];
    char annee[5];
} date;

typedef struct Produit {
    char Nom_produit[50];
    char Reference[100];
    float Montant;
    date DateAchat;
} produit;

typedef struct Liste {
    produit cellule;
    struct Liste* psuiv;
} liste;

liste* creer_liste_produits() {
    return NULL;
}

int est_vide(liste *tete) {
    return tete == NULL;
}

liste* creer_produit() {
    liste* nouveau = (liste*)malloc(sizeof(liste));
    
    printf("Nom du produit: ");
    scanf("%s", nouveau->cellule.Nom_produit);
    
    printf("Reference: ");
    scanf("%s", nouveau->cellule.Reference);
    
    printf("Montant: ");
    scanf("%f", &nouveau->cellule.Montant);
    
    printf("Date d'achat (JJ MM AAAA): ");
    scanf("%s %s %s", nouveau->cellule.DateAchat.jour, 
                      nouveau->cellule.DateAchat.mois, 
                      nouveau->cellule.DateAchat.annee);
    
    nouveau->psuiv = NULL;
    return nouveau;
}

void afficher_produit(liste* produit) {
    printf("Nom: %s\n", produit->cellule.Nom_produit);
    printf("Reference: %s\n", produit->cellule.Reference);
    printf("Montant: %.2f\n", produit->cellule.Montant);
    printf("Date d'achat: %s/%s/%s\n", produit->cellule.DateAchat.jour,
                                       produit->cellule.DateAchat.mois,
                                       produit->cellule.DateAchat.annee);
}

liste* ajouter_debut(liste* tete) {
    liste* nouveau = creer_produit();
    nouveau->psuiv = tete;
    return nouveau;
}

void ajouter_fin(liste* tete) {
    liste* nouveau = creer_produit();
    
    if(tete == NULL) {
        tete = nouveau;
        return;
    }
    
    liste* courant = tete;
    while(courant->psuiv != NULL) {
        courant = courant->psuiv;
    }
    courant->psuiv = nouveau;
}

void afficher_produits(liste* tete) {
    if(est_vide(tete)) {
        printf("La liste est vide\n");
        return;
    }
    
    liste* courant = tete;
    while(courant != NULL) {
        afficher_produit(courant);
        printf("----------------\n");
        courant = courant->psuiv;
    }
}

int longueur(liste* tete) {
    int count = 0;
    liste* courant = tete;
    while(courant != NULL) {
        count++;
        courant = courant->psuiv;
    }
    return count;
}

void filtrer_date(liste* tete, date dt) {
    int trouve = 0;
    liste* courant = tete;
    
    while(courant != NULL) {
        if(strcmp(courant->cellule.DateAchat.jour, dt.jour) == 0 &&
           strcmp(courant->cellule.DateAchat.mois, dt.mois) == 0 &&
           strcmp(courant->cellule.DateAchat.annee, dt.annee) == 0) {
            afficher_produit(courant);
            printf("----------------\n");
            trouve = 1;
        }
        courant = courant->psuiv;
    }
    
    if(!trouve) {
        printf("Aucun produit trouve pour cette date\n");
    }
}

liste* supprimer_debut(liste* tete) {
    if(est_vide(tete)) return NULL;
    
    liste* temp = tete;
    tete = tete->psuiv;
    free(temp);
    return tete;
}

void supprimer_fin(liste* tete) {
    if(est_vide(tete)) return;
    
    if(tete->psuiv == NULL) {
        free(tete);
        tete = NULL;
        return;
    }
    
    liste* courant = tete;
    while(courant->psuiv->psuiv != NULL) {
        courant = courant->psuiv;
    }
    
    free(courant->psuiv);
    courant->psuiv = NULL;
}

liste* rembourser(liste* liste, char* refer) {
    if(est_vide(liste)) return NULL;
    
    if(strcmp(liste->cellule.Reference, refer) == 0) {
        return supprimer_debut(liste);
    }
    
    liste* courant = liste;
    liste* precedent = NULL;
    
    while(courant != NULL && strcmp(courant->cellule.Reference, refer) != 0) {
        precedent = courant;
        courant = courant->psuiv;
    }
    
    if(courant == NULL) {
        printf("Produit non trouve\n");
        return liste;
    }
    
    if(courant->psuiv == NULL) {
        supprimer_fin(liste);
        return liste;
    }
    
    // Cas général (au milieu)
    precedent->psuiv = courant->psuiv;
    free(courant);
    return liste;
}

int main() {
    liste* stock = creer_liste_produits();
    
    stock = ajouter_debut(stock);
    ajouter_fin(stock);
    stock = ajouter_debut(stock);
   
    printf("\nListe des produits:\n");
    afficher_produits(stock);
   
    printf("\nLongueur de la liste: %d\n", longueur(stock));
    
    date dt;
    printf("\nFiltrer par date (JJ MM AAAA): ");
    scanf("%s %s %s", dt.jour, dt.mois, dt.annee);
    filtrer_date(stock, dt);
  
    printf("\nReference du produit a supprimer: ");
    scanf("%s", ref);
    stock = rembourser(stock, ref);
    printf("\nApres suppression:\n");
    afficher_produits(stock);
    
    return 0;
