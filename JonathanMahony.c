#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char student[100];
    char initial;
    char surname[10];
    int year;
    char course_name[10];
    char group;
    int average;
};

struct list_node {
    int data_type;
    void* data; // void pointer!!!
    struct list_node* next;
};

struct student* new_student() {
    struct student* s;// pointer - holds addresses
    s = malloc(sizeof(struct student)); //returns a memory address
}


struct list_node* new_node(struct student* data, int data_type) {
    struct list_node* n;
    n = malloc(sizeof(struct list_node));
    n->data_type = data_type;
    n->data = data;
    n->next = NULL;
    return n;
}


void append(struct list_node **headp,struct list_node *p) {
    struct list_node* head = *headp;
    if (p == NULL)return;
    if (head->data == NULL) {
        head = p;
    }
    else {
        struct list_node* ptr=head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = p;
    }
    *headp = head;
}

int my_scanf(FILE *fp,char* format, char *student, char *initial, char *surname, int* year, char *course_name, char *group, int* average) {
    int param = 0;//type of parameter
    char c;
    char word[100];
    int i = 0;
    int num;
    while (*format) {
        if (*format=='%') {
            switch (format[1])
            {
            case 's':
                c = (char)fgetc(fp);
                if (c == ' ') c = (char)fgetc(fp);
                while (c != ' ') {
                    word[i++] = c;//Keeps track of current word
                    c = (char)fgetc(fp);
                    if (c == EOF) { break; };
                    if (c == '\n') {
                        break;
                    }
                }
                word[i] = '\0';
                i = 0;
                if(param==0)
                    strcpy(student, word);
                if(param==2)
                    strcpy(surname, word);
                if(param==4)
                    strcpy(course_name, word);
                if (c == EOF) { return 0; };
                if (c == '\n') {
                    return 1;
                }
                break;
            case 'c':
                c = (char)fgetc(fp);
                if (c== '(') {
                    c = (char)fgetc(fp);
                    char d = (char)fgetc(fp);
                } 
                if (c == EOF) {  return 0; }
                if (c == '\n') {
                    return 1;
                }
                if (param == 1)
                    *initial = c;
                if (param == 5)*group = c;
                break;
            case 'd':
                c = (char)fgetc(fp);
                if (c == ' ') c = (char)fgetc(fp);
                while (c != ' ') {
                    word[i++] = c;
                    c = (char)fgetc(fp);
                    if (c == EOF) { break; };
                    if (c == '\n') {
                        break;
                    }
                }
                word[i] = '\0';
                i = 0;
                num = atoi(word);//converting str to int
                if (param == 3)*year = num;
                if (param == 6)*average = num;
                if (c == '\n')return 1;
                if (c == EOF) { return 0; };
                break;
            default:
                break;
            }
            param++;
        }
        format++;    
    }
    
}


int main()
{
    char input = 0;
    struct list_node *list_head=new_node(NULL,1);
    char file_name[20];
    FILE* fp = NULL;
    int reading = 1;
    printf ("Enter the name of the file: ");
    gets(file_name);
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error\n");
    }
    else {
        while (reading)
        {
            struct student* s = new_student();
            reading = my_scanf(fp, "%s (%c) %s %d %s %c %d", s->student, &s->initial, s->surname, &s->year, s->course_name, &s->group, &s->average);
            struct list_node* cursor = new_node(s, 1);
            append(&list_head, cursor);
        }
    }
    fclose(fp);
    struct list_node* ptr = list_head;
    struct student* stu;
    while (ptr)
    {
        stu = (struct student*)ptr->data;
        printf("%s (%c) %s %d %s %c %d \n", stu->student, stu->initial, stu->surname, stu->year, stu->course_name, stu->group, stu->average);
        ptr = ptr->next;
    }
    return 0;
}
