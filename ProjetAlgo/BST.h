
/// structure etudient
typedef struct
{
       int student_id;
       char student_name[100];
       int age;
       char major[100];
} student;
/// ABR de student

typedef struct
{
       student v;
       struct arbreS *FGS, *FDS;
} arbreS;
typedef arbreS *SArbreR;

/// structure de cour

typedef struct
{
       int course_id;
       char course_name[100];
       char instructor[100];
} cours;
typedef cours *co; // hadi mfhmthach 3laash

/// ABR de cours

typedef struct
{
       cours t;
       struct arbreC *FGC, *FDC;
} arbreC;

typedef arbreC *COArbreR;

/// structure Enrollement

typedef struct
{
       int student_id;
       int course_id;
} Enrollement;

// Functions of course tree
void InitCourse(COArbreR *a);
void AllouerCourse(COArbreR *a);
void LibererCourse(COArbreR a);
void AffIDCourse(COArbreR a, int x);
void AffFG_COURE(COArbreR a, COArbreR b);
void AffFD_COURE(COArbreR a, COArbreR b);
int IDCourse(COArbreR a);
void AffNAMECourse(COArbreR a, char x[100]);
void AffinstrCourse(COArbreR a, char x[100]);
char *instrtCourse(COArbreR a);
char *NAMECourse(COArbreR a);
COArbreR FilsG_CO(COArbreR a);
COArbreR FilsD_CO(COArbreR a);

// Fonctions of course
COArbreR newcourse(char *name, int id, char *inst);
void element_course(COArbreR a);
void InOrdre_course(COArbreR a);
void insertNewcourse(COArbreR *a, COArbreR newcourse);
/// fichier csv ///
void affichage_coursecsv(const char *fname);
void parse_courses_csv(const char *fname, COArbreR *r);

/// les elements de base de l'arbre etudient

void InitStudent(SArbreR *a);
void AllouerStudent(SArbreR *a);
void LibererStudent(SArbreR a);
void AffIDStudent(SArbreR a, int x);
void AffAGEStudent(SArbreR a, int x);
void AffFG_S(SArbreR a, SArbreR b);
void AffFD_S(SArbreR a, SArbreR b);
int IDStudent(SArbreR a);
int AGEStudent(SArbreR a);
void AffNAMEStudent(SArbreR a, char x[30]);
void AffMAJORStudent(SArbreR a, char x[30]);
char *MAJORStudent(SArbreR a);
char *NAMEStudent(SArbreR a);
SArbreR FilsG_S(SArbreR a);
SArbreR FilsD_S(SArbreR a);
/// les fonctions d'etudient ///
/// arbres///
SArbreR newStudent(char name[30], int ID, int age, char major[30]);
void insertNewStudent(SArbreR *a, SArbreR newStudent);
void printStudentTree(SArbreR root);
void parse_Student_csv(const char *fname, SArbreR *r);

// Enrollement functions

typedef struct
{
       Enrollement value;
       struct arbreE *right, *left;
} TreeEnrollment;

typedef TreeEnrollment *arbreE;

arbreE insertEnrollment(arbreE root, TreeEnrollment enrollment);

void parse_follow_course_csv(const char *filename, arbreS studentTree, arbreC courseTree);
