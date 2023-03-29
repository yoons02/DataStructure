#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

// Constants 
#define MAX 100
// Structures 
typedef struct {
char name[10]; 
int id;
char grade[4];
} StudentRecord;

// Global variables
StudentRecord r[MAX]; // Student record: name, id, grade 
int num_record = 0; // Total # of records read from file 
const char *ifp = "grade.txt"; // Grade file name
// Function prototypes
void read_record(char *ifp); 
void print_record();
void search_record();
void change_record();
void write_record(char *ifp);