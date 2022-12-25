#include <stdio.h>
#include <string.h>
#include <ctype.h>  //for using toupper(int)

int main(int argc, char *argv[]) {
    FILE *fptr1, *fptr2;
    char filename[30];
    int ch; 
	int countConverted = 0;
	int charNum = -1; //문자열이 끝나는 마지막 줄은 char로 인식하지 않게끔 한다.
	int blankNum = 0;
	int numChar = 0;
	int specialChar = 0;
	int countAfterConvert = 0;

    fptr1 = fopen(argv[1],"r");
	fptr2 = fopen(argv[2],"wt");         //open file
    
    while((ch = fgetc(fptr1)) != EOF) {  //iteration while the file is end
        if(ch >= 'a' && ch <= 'z'){
			countConverted++;
		}
		ch = toupper(ch);
   		fputc(ch,fptr2);
	}   
    fclose(fptr1);                       //close file
	fclose(fptr2);

	fptr2 = fopen(argv[2],"r");
	while((ch = fgetc(fptr2)) != EOF) {
		charNum++;
		if(ch == ' ') {
			blankNum++;
		}
		else if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch =='5' || ch == '6' || ch == '7' || ch =='8' || ch =='9') {
			numChar++;
		}
		else if(ch >= 'A' && ch <= 'Z') {
			countAfterConvert++;
		}
	}	

	specialChar = charNum - blankNum - numChar - countAfterConvert;
	printf("Converted file: %s\n",argv[2]);
	printf("Total characters: %d\n", charNum);
	printf("Converted characters: %d\n", countConverted);
	printf("Blank characters: %d\n", blankNum);
	printf("Number characters: %d\n", numChar);
	printf("Special characters: %d\n", specialChar);
    return 0;
}
