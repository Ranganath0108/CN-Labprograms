#include<stdio.h>
#include<string.h>
#define max 1000
int main(int argc, char const *argv[])
{
    // intialization of required variables
    int source_index=0,dest_index=0,one_count=0;
    char flag_byte[]="01111110";
    char source[max],destination[max];
    printf("\n Enter the frame in binary\n");
    gets(source);

// Bitstuffing


// Adding  flag byte to destination message on the first
    strcpy(destination,flag_byte);
    dest_index=strlen(flag_byte);
    while(source[source_index]!='\0')
    {
        if(source[source_index]=='1'){
            one_count++;            
        }
        else
        one_count=0;
        destination[dest_index]=source[source_index];
        dest_index++;source_index++;
        
        // stuffing happens here
        if(one_count==5){
            destination[dest_index]='0';
            dest_index++;
            one_count=0;
        }

    }
// adding null to end the string

destination[dest_index]='\0';
// adding flagbyte and end of frame

strcat(destination,flag_byte);
printf("\n The stuffed frame is \n %s",destination);

    return 0;
}
