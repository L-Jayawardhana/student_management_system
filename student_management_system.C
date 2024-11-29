#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct details {
    int registration_number;
    char name[30];
    char birthday[11] ;
    int birth_year ;
    int subject_1;
    int subject_2;
    int subject_3;
    int subject_4;
    float avg;
};

float FindClassAverage(int n , struct details student[] , int subject);
void FindStudentAvg(int n , struct details student[]);
int FindTop(int n , struct details student[]);
void Details(int i , struct details student[]);

int main (){

        int choice;
        int n;
        struct details student[5] ;

    do {
        printf("\n");
            printf("\x1b[1m"); // Start bold font
            printf("\x1b[36m"); // change the title color
        printf("%30s","Student management system\n");
            printf("\x1b[0m"); // end font changers

        printf("1 - Enter student detils\n");
        printf("2 - Summarize student details\n");
        printf("3 - Search student details\n");
        printf("4 - Exit\n");

        printf("Enter your choice : ");
        scanf("%d" , &choice);
        printf("\n");

        while (choice > 4 || choice <= 0) {
            printf("Invalid choice, Pls Re-enter : ");
            scanf("%d", &choice);
        }

        if (choice == 1){
            printf("How many students in the class :");
            scanf("%d", &n);
            for (int i = 0 ; i < n ; i++){
                printf("\n");
                printf("Enter details for student %d\n" ,i+1);

                printf("registration number : ");
                scanf("%d" , &student[i].registration_number);
                printf("first name : ");
                scanf("%s" , &student[i].name);
                printf("birthday (dd/mm/yyyy) : ");
                scanf("%s" , &student[i].birthday);

                    char *birthyear = &student[i].birthday[strlen(student[i].birthday) - 4]; // Pointer to the last 4 characters
                    //save integer to the student birth year
                    student[i].birth_year = atoi(birthyear); // Convert the last 4 characters to an integer
                
                printf("marks for subject 1 : ");
                scanf("%d" , &student[i].subject_1);
                printf("marks for subject 2 : ");
                scanf("%d" , &student[i].subject_2);
                printf("marks for subject 3 : ");
                scanf("%d" , &student[i].subject_3);
                printf("marks for subject 4 : ");
                scanf("%d" , &student[i].subject_4);     
            } 
            printf("\n");
            printf("All details are stored...!\n");
        }

        if (choice == 2){
            
                printf("\x1b[1m");
                printf("\x1b[35m");
            printf("%47s","Average marks of the class in each subject\n");
                printf("\x1b[0m");

                printf("\x1b[1m");
            printf("%15s %22s\n", "Subject" ,"Average Marks");
                printf("\x1b[0m");
            printf("      ----------------------------------\n");

                printf("%16s %17.2f\n" , "Subject 1" , FindClassAverage(n , student , 1));
                printf("%16s %17.2f\n" , "Subject 2" , FindClassAverage(n , student , 2));
                printf("%16s %17.2f\n" , "Subject 3" , FindClassAverage(n , student , 3));
                printf("%16s %17.2f\n" , "Subject 4" , FindClassAverage(n , student , 4));

            printf("\n");

            FindStudentAvg(n ,student);
            int TopN = FindTop(n ,student);

            printf("\x1b[1m");
                printf("\x1b[35m");
            printf("%47s","Top student details\n");
                printf("\x1b[0m");

                printf("\x1b[1m");
            printf("%-19s %-15s %s %15s %12s %12s %12s %15s\n","Reg. number","Name","Age","Subject 1","Subject 2","Subject 3","Subject 4","Average mark");
                printf("\x1b[0m");
            printf("-------------------------------------------------------------------------------------------------------------------\n");                
            printf("%-18d %-15s %d yr %10d %12d %12d %12d %15.2f\n",student[TopN].registration_number,student[TopN].name,2024-student[TopN].birth_year
                    ,student[TopN].subject_1,student[TopN].subject_2,student[TopN].subject_3,student[TopN].subject_4,student[TopN].avg);
        }

        if (choice == 3){
            int regnumber;
            printf("Enter the student register number : ");
            scanf("%d", &regnumber);
            printf("\n");

            bool findreg = true ;
            for(int i = 0 ; i < n ; i++){
                if (regnumber == student[i].registration_number){
                    Details(i , student);
                    findreg = false ;
                }
            }
            if (findreg){
                printf("The student you are searching for is not in our system..!\n");
            }
            
        }

        if (choice == 4){
                printf("\x1b[1m");
            printf("Exiting..!\n");
                printf("\x1b[0m");
            break;
        }
    } while (choice != 4);
   
    return 0;
}

void Details(int i , struct details student[]){
    printf("\x1b[1m");
                printf("\x1b[35m");
            printf("%47s","student details\n");
                printf("\x1b[0m");

                printf("\x1b[1m");
            printf("%-19s %-15s %s %15s %12s %12s %12s %15s\n","Reg. number","Name","Bithday","Subject 1","Subject 2","Subject 3","Subject 4","Average mark");
                printf("\x1b[0m");
            printf("-------------------------------------------------------------------------------------------------------------------\n");                
            printf("%-18d %-15s %s  %8d %12d %12d %12d %15.2f\n",student[i].registration_number,student[i].name,student[i].birthday
                    ,student[i].subject_1,student[i].subject_2,student[i].subject_3,student[i].subject_4,student[i].avg);
}

float FindClassAverage(int n , struct details student[] , int subject){
    int sum = 0;
    for (int j = 0 ; j < n ; j++){
        if (subject == 1){
            sum += student[j].subject_1;
        }
        if (subject == 2){
            sum += student[j].subject_2;
        }
        if (subject == 3){
            sum += student[j].subject_3;
        }
        if (subject == 4){
            sum += student[j].subject_4;
        }
    }
    float avg = sum / n ;
    return avg ;
}

void FindStudentAvg(int n , struct details student[]){
    for (int i = 0 ; i < n ; i++){
        float Avg ;
        Avg = (student[i].subject_1 + student[i].subject_2 + student[i].subject_3 + student[i].subject_4)/4.0 ;
        student[i].avg = Avg ;
    }    
}

int FindTop(int n , struct details student[]){
    float top_avg = 0 ;
    int Top = 0;
    for (int u = 0 ; u < n ; u++){
        if (student[u].avg > top_avg){
            top_avg = student[u].avg ;
            Top = u;
        }
    }
    return Top;
}