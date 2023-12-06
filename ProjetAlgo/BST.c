#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include <malloc.h>
/// COURSE
/// les element de arbre COURSE

void InitCourse(COArbreR *a) { *a = NULL; }
void AllouerCourse(COArbreR *a) { *a = (COArbreR)malloc(sizeof(arbreC)); }
void LibererCourse(COArbreR a) { free(a); }
void AffIDCourse(COArbreR a, int x) { a->t.course_id = x; }
void AffFG_COURE(COArbreR a, COArbreR b) { a->FGC = b; }
void AffFD_COURE(COArbreR a, COArbreR b) { a->FDC = b; }
void AffNAMECourse(COArbreR a, char x[100]) { strcpy(a->t.course_name, x); }
void AffinstrCourse(COArbreR a, char x[100]) { strcpy(a->t.instructor, x); }
int IDCourse(COArbreR a) { return a->t.course_id; }
char *instrtCourse(COArbreR a) { return a->t.instructor; }
char *NAMECourse(COArbreR a) { return a->t.course_name; }
COArbreR FilsG_CO(COArbreR a) { return a->FGC; }
COArbreR FilsD_CO(COArbreR a) { return a->FDC; }

/// insertion des arbres///

COArbreR newcourse(char name[50], int id, char inst[50])
{
    COArbreR newcourse;
    InitCourse(&newcourse);
    AllouerCourse(&newcourse);
    if (newcourse != NULL)
    {
        AffNAMECourse(newcourse, name);
        AffinstrCourse(newcourse, inst);
        AffIDCourse(newcourse, id);
        AffFG_COURE(newcourse, NULL);
        AffFD_COURE(newcourse, NULL);
    }
    return newcourse;
}

void insertNewcourse(COArbreR *a, COArbreR newcourse)
{
    COArbreR s;
    if (*a == NULL)
    {
        *a = newcourse;
    }
    else
    {
        if (IDCourse(*a) > IDCourse(newcourse))
        {
            if (FilsG_CO(*a) == NULL)
            {
                AffFG_COURE(*a, newcourse);
            }

            else
            {
                s = FilsG_CO(*a);
                insertNewcourse(&s, newcourse);
            }
        }
        else if (FilsD_CO(*a) == NULL)
        {
            AffFD_COURE(*a, newcourse);
        }
        else
        {
            s = FilsD_CO(*a);
            insertNewcourse(&s, newcourse);
        }
    }
}

void InOrdre_course(COArbreR a)
{
    if (a == NULL)
    {
        printf("empty");
    }
    else
    {
        element_course(a);
    }
}

void element_course(COArbreR a)
{
    if (a != NULL)
    {
        element_course(FilsG_CO(a));

        printf("%d ", IDCourse(a));
        printf("%s ", NAMECourse(a));
        printf("%s \n", instrtCourse(a));

        element_course(FilsD_CO(a));
    }
}
/// fichiers csv ///

void affichage_coursecsv(const char *fname)
{
    FILE *file = fopen(fname, "r");

    if (file == NULL)
    {
        printf("Error opening file");
        return;
    }

    char line[100];
    // boucle pour parcourir ligne par ligne et avancer directrment
    while (fgets(line, sizeof(line), file) != NULL)
    { // line contient tout meme la virgule (;)
        // Remove newline character at the end of the line
        line[strcspn(line, "\n")] = '\0'; // strcspn : remplacer la premi�re saute de la ligne (\n) par \0 (terminale)
                                          //  fgets ne prend pas \0
        // Tokenize the line based on the delimiter
        char *token = strtok(line, ",");
        while (token != NULL)
        { // exist lorsque y a pas de mot � lire
            printf("%s ", token);

            token = strtok(NULL, ","); // go to the next word
        }

        printf("\n");
    }

    fclose(file);
}

void parse_courses_csv(const char *fname, COArbreR *r)
{
    COArbreR c;
    int id;
    char name[100];
    char inst[100];
    FILE *file = fopen(fname, "r");

    if (file == NULL)
    {
        printf("Error opening file: %s\n", fname);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%d,%99[^,],%99[^,]", &id, name, inst) == 3)
        {
            c = newcourse(name, id, inst);
            if (c != NULL)
            {
                insertNewcourse(r, c);
            }
            else
            {
                printf("Error creating new course.\n");
            }
        }
        else
        {
            printf("Unexpected format in line: %s", line);
        }
    }
    fclose(file);
}

/// STUDENT
// fonctions des bases student
void InitStudent(SArbreR *a) { *a = NULL; }
void AllouerStudent(SArbreR *a) { *a = (SArbreR)malloc(sizeof(arbreS)); }
void LibererStudent(SArbreR a) { free(a); }
void AffIDStudent(SArbreR a, int x) { a->v.student_id = x; }
void AffAGEStudent(SArbreR a, int x) { a->v.age = x; }
void AffFG_S(SArbreR a, SArbreR b) { a->FGS = b; }
void AffFD_S(SArbreR a, SArbreR b) { a->FDS = b; }
int IDStudent(SArbreR a) { return a->v.student_id; }
int AGEStudent(SArbreR a) { return a->v.age; }
void AffNAMEStudent(SArbreR a, char x[30]) { strcpy(a->v.student_name, x); }
void AffMAJORStudent(SArbreR a, char x[30]) { strcpy(a->v.major, x); }
char *MAJORStudent(SArbreR a) { return a->v.major; }
char *NAMEStudent(SArbreR a) { return a->v.student_name; }
SArbreR FilsG_S(SArbreR a) { return a->FGS; }
SArbreR FilsD_S(SArbreR a) { return a->FDS; }

SArbreR newStudent(char name[30], int ID, int age, char major[30])
{
    SArbreR newStudent;
    InitStudent(&newStudent);
    AllouerStudent(&newStudent);
    if (newStudent != NULL)
    {
        AffNAMEStudent(newStudent, name);
        AffAGEStudent(newStudent, age);
        AffMAJORStudent(newStudent, major);
        AffIDStudent(newStudent, ID);
        AffFG_S(newStudent, NULL);
        AffFD_S(newStudent, NULL);
    }

    return newStudent;
}

void insertNewStudent(SArbreR *a, SArbreR newStudent)
{
    SArbreR s;
    if (*a == NULL)
    {
        *a = newStudent;
    }
    else
    {
        if (IDStudent(*a) > IDStudent(newStudent))
        {
            if (FilsG_S(*a) == NULL)
            {
                AffFG_S(*a, newStudent);
            }

            else
            {
                s = FilsG_S(*a);
                insertNewStudent(&s, newStudent);
            }
        }
        else if (FilsD_S(*a) == NULL)
        {
            AffFD_S(*a, newStudent);
        }
        else
        {
            s = FilsD_S(*a);
            insertNewStudent(&s, newStudent);
        }
    }
}
void printStudentTree(SArbreR root)
{
    if (root != NULL)
    {
        // Parcours in-order (gauche, racine, droite)
        printStudentTree(FilsG_S(root)); // Parcours le sous-arbre gauche
        printf("ID: %d, Name: %s, Age: %d, Major: %s\n", IDStudent(root), NAMEStudent(root), AGEStudent(root), MAJORStudent(root));
        printStudentTree(FilsD_S(root)); // Parcours le sous-arbre droit
    }
}

void parse_Student_csv(const char *fname, SArbreR *r)
{
    SArbreR S;
    int id, age;
    char name[100];
    char major[100];
    FILE *file = fopen(fname, "r");

    if (file == NULL)
    {
        printf("Error opening file: %s\n", fname);
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%d,%99[^,],%d,%99[^,]", &id, name, &age, major) == 4)
        {
            S = newStudent(name, id, age, major);
            if (S != NULL)
            {
                insertNewStudent(r, S);
            }
            else
            {
                printf("Error creating new course.\n");
            }
        }
        else
        {
            printf("Unexpected format in line: %s", line);
        }
    }
    fclose(file);
}

// Enrollement functions
arbreE insertEnrollment(arbreE root, Enrollement enrollment)
{
    if (root == NULL)
    {
        arbreE newNode = (arbreE)malloc(sizeof(TreeEnrollment));
        newNode->value = enrollment;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (enrollment.student_id < root->value.student_id)
    {
        root->left = insertEnrollment(root->left, enrollment);
    }
    else if (enrollment.student_id > root->value.student_id)
    {
        root->right = insertEnrollment(root->right, enrollment);
    }
    else if (enrollment.course_id < root->value.course_id)
    {
        root->left = insertEnrollment(root->left, enrollment);
    }
    else if (enrollment.course_id > root->value.course_id)
    {
        root->right = insertEnrollment(root->right, enrollment);
    }

    return root;
}
