#include <stdio.h>

int
strlen_p(char *str)
{
        int     len = 0;

        //go to address of str and get the char value. If the value is not null, len++
        //if the value is null, break
        while (*str++)  {
                len++;
        }   
        return len;
}

int
strlen_a(char str[])
{
        int i;

        for (i = 0 ; str[i] != '\0' ; i++) 
                ;   
        return i;
}

void
strcpy_p(char *dst, char *src)
{
        while (*src)  {
                //write char of src in dst and move to the next index.
                //if char of src is null, break
                *dst++ = *src++;
        }   
        *dst = *src;
}

void
strcpy_a(char dst[], char src[])
{
        int i;
    
        //write src[i] into dst[i] if src[i] is not null, then i++ 
        for (i = 0 ; src[i] != '\0' ; i++)
                dst[i] = src[i];
        dst[i] = src[i];
}

void
strcat_p(char *dst, char *src)
{
        while (*dst++)
                ;   
    
        //dst-- because index got 1 more value than my purpose in the while loop
        dst--;
        //append char of src to dst 
        while (*src)  {
                *dst++ = *src++;
        }   
        *dst = *src;
}

void
strcat_a(char dst[], char src[])
{
        int i, j;

        for (i = 0 ; dst[i] != '\0' ; i++)
                ;   
        for (j = 0 ; src[j] != '\0' ; j++)
                dst[i+j] = src[j];
        //set dst[i+j] to null to notice that the str is end 
        dst[i+j] = src[j];
}

int
strcmp_p(char *dst, char *src)
{
        //break when *dst, *src is all null
        while (*dst || *src) {
                //when ASCII code of dst is bigger
                if (*dst > *src) {
                        return 1;
                }
                else if (*dst < *src) {
                        return -1;
                }
                else {
                        dst++;
                        src++;
                }
        }
        return 0;
}

int
strcmp_a(char dst[], char src[])
{
        int i = 0;
        while (dst[i] != '\0'|| src[i] != '\0') {
                if (dst[i] > src[i]) {
                        return 1;
                }
                else if (dst[i] < src[i]) {
                        return -1;
                }
                else {
                        i++;
                }
        }
        return 0;
}

int main()
{
        int             len1, len2, strcmp1, strcmp2;
        char    str1[20], str2[20], str3[20];

        len1 = strlen_p("Hello");
        len2 = strlen_a("Hello");
        printf("strlen: p=%d, a=%d\n", len1, len2);

        strcpy_p(str1, "Hello");
        strcpy_a(str2, "Hello");
        printf("strcpy: p=%s, a=%s\n", str1, str2);

        strcat_p(str1, ", World!");
        strcat_a(str2, ", World!");
        printf("strcat: p=%s, a=%s\n", str1, str2);

		//strcmp example
        strcpy_p(str3, "hello");
        strcmp1 = strcmp_p(str1, str3);
        strcmp2 = strcmp_a(str1, str3);
        printf("strcmp(Hello, hello): p=%d, a=%d\n", strcmp1, strcmp2);
        return 0;
}
