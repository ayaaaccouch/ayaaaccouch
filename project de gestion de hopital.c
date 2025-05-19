#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Department {
    char name[50];
    struct Department* next;
} Department;

typedef struct Doctor {
    char name[50];
    Department* department;
    struct Doctor* next;
} Doctor;

typedef struct Patient {
    char name[50];
    int age;
    Doctor* doctor;
    struct Patient* next;
} Patient;

Department* departments = NULL;
Doctor* doctors = NULL;
Patient* patients = NULL;

void add_department(char* name) {
    Department* new_dept = (Department*)malloc(sizeof(Department));
    strcpy(new_dept->name, name);
    new_dept->next = departments;
    departments = new_dept;
    printf("Departement ajoute : %s\n", name);
}
void show_departments() {
    Department* current = departments;
    printf("\n--- Departements ---\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

Department* find_department(char* name) {
    Department* current = departments;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_doctor(char* name, char* dept_name) {
    Department* dept = find_department(dept_name);
    if (dept == NULL) {
        printf("Departement introuvable.\n");
        return;
    }
    Doctor* new_doc = (Doctor*)malloc(sizeof(Doctor));
    strcpy(new_doc->name, name);
    new_doc->department = dept;
    new_doc->next = doctors;
    doctors = new_doc;
    printf("Medecin ajoute : %s (%s)\n", name, dept_name);
}

void show_doctors() {
    Doctor* current = doctors;
    printf("\n--- Medecins ---\n");
    while (current != NULL) {
        printf("- %s (Departement : %s)\n", current->name, current->department->name);
        current = current->next;
    }
}

// Find a doctor by name
Doctor* find_doctor(char* name) {
    Doctor* current = doctors;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_patient(char* name, int age, char* doctor_name) {
    Doctor* doc = find_doctor(doctor_name);
    if (doc == NULL) {
        printf("Medecin introuvable.\n");
        return;
    }
    Patient* new_pat = (Patient*)malloc(sizeof(Patient));
    strcpy(new_pat->name, name);
    new_pat->age = age;
    new_pat->doctor = doc;
    new_pat->next = patients;
    patients = new_pat;
    printf("Patient ajoute : %s, %d ans (Docteur : %s)\n", name, age, doctor_name);
}

void show_patients() {
    Patient* current = patients;
    printf("\n--- Patients ---\n");
    while (current != NULL) {
        printf("- %s, %d ans (Suivi par : Dr. %s, Departement : %s)\n",
               current->name, current->age,
               current->doctor->name, current->doctor->department->name);
        current = current->next;
    }
}

int main() {
    int choice, age;
    char name[50], dept[50];

    while (1) {
        printf("\n=== Gestion de l Hopital ===\n");
        printf("1. Ajouter un departement\n");
        printf("2. Voir les departements\n");
        printf("3. Ajouter un medecin\n");
        printf("4. Voir les medecins\n");
        printf("5. Ajouter un patient\n");
        printf("6. Voir les patients\n");
        printf("7. Quitter\n> ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Nom du departement : ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                add_department(name);
                break;
            case 2:
                show_departments();
                break;
            case 3:
                printf("Nom du medecin : ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Departement : ");
                fgets(dept, 50, stdin);
                dept[strcspn(dept, "\n")] = 0;
                add_doctor(name, dept);
                break;
            case 4:
                show_doctors();
                break;
            case 5:
                printf("Nom du patient : ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Age : ");
                scanf("%d", &age);
                getchar();
                printf("Medecin traitant : ");
                fgets(dept, 50, stdin);
                dept[strcspn(dept, "\n")] = 0;
                add_patient(name, age, dept);
                break;
            case 6:
                show_patients();
                break;
            case 7:
                printf("Fermeture du programme...\n");
                return 0;
            default:
                printf("Choix invalide.\n");
        }
        Sleep(1000);
    }
}
