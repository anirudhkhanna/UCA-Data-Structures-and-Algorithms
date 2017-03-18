/* Make a sorting program which sorts the given command line arguments according to given switch, as explained below:

   No switch : Sort lexicographically
   -i        : Sort lexicographically ignoring the case
   -n        : Sort numerically
   -r        : Sort numerically in reverse
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* The central sorting function which can take different comparison functions as argument via function pointer */
void sort(int argc, char *argv[], int (*compare)(char*, char*))
{
    int i, j;
    char *temp;

    for(i = 1; i < argc - 1; i++)
        for(j = 1; j < argc - 1; j++)
            if((*compare)(argv[j], argv[j+1]) > 0)  // Make comparison according to the passed comparison function pointer
            {
                temp = argv[j];     // Swapping of pointers to strings, argv[j] and argv[j+1]
                argv[j] = argv[j+1];
                argv[j+1] = temp;
            }
}

/* Function to compare 2 strings (having numbers) numerically */
int compNum(char *s1, char *s2)
{
    int n1, n2;
    sscanf(s1, "%d", &n1);
    sscanf(s2, "%d", &n2);
    
    if(n1 > n2)
        return 1;
    else
        return 0;
}

/* Function to compare 2 strings (having numbers) numerically (according to reverse/descending order) */
int compNumReverse(char *s1, char *s2)
{
    int n1, n2;
    sscanf(s1, "%d", &n1);
    sscanf(s2, "%d", &n2);
    
    if(n1 < n2)
        return 1;
    else
        return 0;
}

/* Function to compare 2 strings lexicographically */
int compStr(char *s1, char *s2)
{
    if(strcmp(s1, s2) > 0)
        return 1;
    else
        return 0;
}

/* Function to compare 2 strings lexicographically (ignoring the case) */
int compStrIgnoreCase(char *s1, char *s2)
{

    /*
       We can use strcmpi(s1, s2) function to compare 2 strings ignoring their case. But strcmpi() is not a standard C function and may not work on every platform.
       Similarly, strlwr() and strupr() functions that can convert a passed string to lower and upper case respectively can be used here, but they are also non-standard.
       So, we should prefer using tolower() (or toupper()) functions which are standard functions defined in the header file "ctype.h" to convert a passed character variable to lowercase (or uppercase).
       We can convert strings to lowercase (or uppercase) character-by-character, as done below, and then compare them using strcmp(s1, s2) function.
    */

    int i;
    char s11[strlen(s1)+1], s22[strlen(s2)+1];  // Make copy of strings and convert them to lowercase
    for(i = 0; s1[i]; i++)
        s11[i] = tolower(s1[i]);
    for(i = 0; s2[i]; i++)
        s22[i] = tolower(s2[i]);

    if(strcmp(s11, s22) > 0)  // Compare the duplicated and lowercased strings
        return 1;
    else
        return 0;
}

/* Function for left shifting the array of strings by one, to remove the first string having the switch, and reduce argc by 1 */
void leftShift(int *argcPtr, char *argv[])
{
    int i;
    for(i = 1; i < (*argcPtr) - 1; i++)
        argv[i] = argv[i+1];  // Just make each argv[i] poiner point to the next string
    
    (*argcPtr)--;  // Reduce (*argcPtr) by one
}

/* Main function */
int main(int argc, char *argv[])
{
    int i;

    /* Check if no arguments are provided, then return */
    if(argc == 1)
    {
        printf("\nNo input command line arguments provided.\n");
        return 0;
    }

    if(strcmp(argv[1], "-n") == 0)         // Switch "-n" was given
    {
        /* Left shift the array of strings by one to remove the string having the switch, and reduce argc by 1 */
        leftShift(&argc, argv);

        printf("\nSwitch -n detected. Sorting numerically:\n");
        /* Call sort() function with appropriate comparison function passed as argument */
        sort(argc, argv, compNum);
    }
    else if(strcmp(argv[1], "-r") == 0)    // Switch "-r" was given
    {
        leftShift(&argc, argv);
        
        printf("\nSwitch -r detected. Sorting numerically in reverse:\n");
        sort(argc, argv, compNumReverse);
    }
    else if(strcmp(argv[1], "-i") == 0)    // Switch "-i" was given
    {
        leftShift(&argc, argv);

        printf("\nSwitch -i detected. Sorting lexicographically ignoring the case:\n");
        sort(argc, argv, compStrIgnoreCase);
    }
    else                                   // No switch identified
    {
        /* No need to left shift the array of strings, as there is no switch */

        printf("\nNo switch detected. Sorting lexicographically:\n");
        sort(argc, argv, compStr);
    }

    /* Print the result */
    for(i = 1; i < argc; i++)
            printf("%s\n", argv[i]);

    return 0;
}
