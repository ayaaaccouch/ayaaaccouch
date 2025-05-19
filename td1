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
    
    // Vérifier si c'est le premier élément
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
    
    // Vérifier si c'est le dernier élément
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
    
    // Ajout de produits
    stock = ajouter_debut(stock);
    ajouter_fin(stock);
    stock = ajouter_debut(stock);
    
    // Affichage
    printf("\nListe des produits:\n");
    afficher_produits(stock);
    
    // Test des fonctions
    printf("\nLongueur de la liste: %d\n", longueur(stock));
    
    date dt;
    printf("\nFiltrer par date (JJ MM AAAA): ");
    scanf("%s %s %s", dt.jour, dt.mois, dt.annee);
    filtrer_date(stock, dt);
    
    // Suppression
    char ref[100];
    printf("\nReference du produit a supprimer: ");
    scanf("%s", ref);
    stock = rembourser(stock, ref);
    printf("\nApres suppression:\n");
    afficher_produits(stock);
    
    return 0;
}
td3:
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
    
    // Création initiale
    liste = ajouterF(liste, 30);
    liste = ajouterF(liste, 10);
    liste = ajouterF(liste, 20);
    liste = ajouterF(liste, 40);
    
    // Affichage
    printf("Liste initiale:\n");
    afficher(liste);
    printf("Liste inverse:\n");
    afficherInverse(liste);
    
    // Test des fonctions
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
td4:
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
    
    // Création d'étudiants
    Etudiant* e1 = creer_etudiant();
    Etudiant* e2 = creer_etudiant();
    Etudiant* e3 = creer_etudiant();
    
    // Ajout à différentes positions
    liste = ajouter_position(liste, e1, 1);
    liste = ajouter_position(liste, e2, 1);
    liste = ajouter_position(liste, e3, 2);
    
    // Affichage
    printf("\nListe des etudiants:\n");
    afficher_liste(liste);
    
    // Test des fonctions
    printf("\nLongueur de la liste: %d\n", longueur(liste));
    
    Etudiant* dernier = derniere_cellule(liste);
    printf("\nDernier etudiant: %s\n", dernier->nom);
    
    // Suppression
    liste = supprimer_position(liste, 2);
    printf("\nApres suppression position 2:\n");
    afficher_liste(liste);
    
    return 0;
}
td5:
#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

// Partie Pile
void push(Noeud** top, int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = *top;
    *top = nouveau;
}

void pop(Noeud** top) {
    if(*top == NULL) return;
    
    Noeud* temp = *top;
    *top = (*top)->suivant;
    free(temp);
}

void peek(Noeud* top) {
    if(top == NULL) {
        printf("Pile vide\n");
    } else {
        printf("Sommet: %d\n", top->valeur);
    }
}

void afficher_pile(Noeud* top) {
    Noeud* courant = top;
    printf("Pile (sommet en haut): ");
    while(courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
    printf("\n");
}

int taille_pile(Noeud* top) {
    int count = 0;
    Noeud* courant = top;
    while(courant != NULL) {
        count++;
        courant = courant->suivant;
    }
    return count;
}

// Partie File
typedef struct File {
    Noeud* debut;
    Noeud* fin;
} File;

void initialiser_file(File* f) {
    f->debut = NULL;
    f->fin = NULL;
}

void enfiler(File* f, int valeur) {
    Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    
    if(f->fin == NULL) {
        f->debut = f->fin = nouveau;
    } else {
        f->fin->suivant = nouveau;
        f->fin = nouveau;
    }
}

void defiler(File* f) {
    if(f->debut == NULL) return;
    
    Noeud* temp = f->debut;
    f->debut = f->debut->suivant;
    
    if(f->debut == NULL) {
        f->fin = NULL;
    }
    
    free(temp);
}

void afficher_file(File* f) {
    Noeud* courant = f->debut;
    printf("File (debut a gauche): ");
    while(courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
    printf("\n");
}

void viderFile(File* f) {
    while(f->debut != NULL) {
        defiler(f);
    }
}

int main() {
    // Test de la pile
    Noeud* pile = NULL;
    
    printf("=== TEST PILE ===\n");
    push(&pile, 10);
    push(&pile, 20);
    push(&pile, 30);
    
    afficher_pile(pile);
    peek(pile);
    printf("Taille: %d\n", taille_pile(pile));
    
    pop(&pile);
    pop(&pile);
    afficher_pile(pile);
    
    // Test de la file
    File file;
    initialiser_file(&file);
    
    printf("\n=== TEST FILE ===\n");
    enfiler(&file, 10);
    enfiler(&file, 20);
    enfiler(&file, 30);
    
    afficher_file(&file);
    defiler(&file);
    afficher_file(&file);
    
    enfiler(&file, 40);
    enfiler(&file, 50);
    afficher_file(&file);
    
    viderFile(&file);
    printf("Apres vidage: ");
    afficher_file(&file);
    
    return 0;
}
td6:
#include <stdio.h>
#include <stdlib.h>

// Exercice 1 - Écriture dans un fichier texte
void exercice1() {
    FILE *fichier;
    char nom[50];
    int age;
    
    fichier = fopen("donnees.txt", "w");
    if(fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    
    printf("Entrez votre nom: ");
    scanf("%s", nom);
    printf("Entrez votre age: ");
    scanf("%d", &age);
    
    fprintf(fichier, "Nom: %s\nAge: %d\n", nom, age);
    fclose(fichier);
    printf("Donnees enregistrees dans donnees.txt\n");
}

// Exercice 2 - Lecture d'un fichier texte
void exercice2() {
    FILE *fichier;
    char ligne[100];
    
    fichier = fopen("donnees.txt", "r");
    if(fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    
    printf("\nContenu du fichier:\n");
    while(fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }
    
    fclose(fichier);
}

// Exercice 3 - Copie de fichier
void exercice3() {
    FILE *source, *destination;
    char c;
    
    source = fopen("source.txt", "r");
    if(source == NULL) {
        printf("Erreur d'ouverture du fichier source\n");
        return;
    }
    
    destination = fopen("destination.txt", "w");
    if(destination == NULL) {
        printf("Erreur d'ouverture du fichier destination\n");
        fclose(source);
        return;
    }
    
    while((c = fgetc(source)) != EOF) {
        fputc(c, destination);
    }
    
    fclose(source);
    fclose(destination);
    printf("Copie terminee\n");
}

// Exercice 4 - Comptage
void exercice4() {
    FILE *fichier;
    char c;
    int lignes = 0, mots = 0, caracteres = 0;
    int dans_mot = 0;
    
    fichier = fopen("texte.txt", "r");
    if(fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    
    while((c = fgetc(fichier)) != EOF) {
        caracteres++;
        
        if(c == '\n') {
            lignes++;
        }
        
        if(c == ' ' || c == '\n' || c == '\t') {
            if(dans_mot) {
                dans_mot = 0;
                mots++;
            }
        } else {
            dans_mot = 1;
        }
    }
    
    // Compter le dernier mot si le fichier ne se termine pas par un espace
    if(dans_mot) {
        mots++;
    }
    
    fclose(fichier);
    
    printf("\nStatistiques du fichier:\n");
    printf("Lignes: %d\n", lignes);
    printf("Mots: %d\n", mots);
    printf("Caracteres: %d\n", caracteres);
}

int main() {
    exercice1();
    exercice2();
    exercice3();
    exercice4();
    return 0;
}
