#include<stdio.h>
#include<string.h>
#define max 1000
int main(int argc, char const *argv[])
{
    // intialization of required variables
    int i,si=0,di=0,one_count=0;
    char flag_byte[]="01111110";
    char src[max],dest[max];
    printf("\n Enter the frame in binary\n");
    gets(src);

// Bitstuffing
// Adding first flag byte to dest message
    strcpy(dest,flag_byte);
    di=strlen(flag_byte);
    while(src[si]!='\0')
    {
        if(src[si]=='1'){
            one_count++;            
        }
        else
        one_count=0;
        dest[di++]=src[si++];
        
        // stuffing happens here
        if(one_count==5){
            dest[di++]='0';
            one_count=0;
        }

    }

dest[di]='\0';
// adding flagbyte and end of frame
strcat(dest,flag_byte);
printf("\n The stuffed frame is \n %s",dest);


    return 0;
}
