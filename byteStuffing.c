#include <stdio.h>
#include <string.h>

#define max 1000
int main(int argc, char const *argv[])
{
    // intialization of required variable
    int source_index = 0, dest_index = 0;
    char start_flag[] = "DLESTX", end_flag[] = "DLEETX", source[max], destination[max];

    printf("\n Enter the frame to send\n");
    gets(source);
    // adding  start flag to destination frame
    strcpy(destination, start_flag);
    // setting the index of the destination  to the length of staart flag so that next letter add from source get added adjacent to it
    dest_index = strlen(start_flag);

    while (source[source_index] != '\0')
    {
        if (source[source_index] == 'D' && source[source_index + 1] == 'L' && source[source_index + 2] == 'E') //checking  for DLE in the source message
        {
            // DLE of source message
            destination[dest_index + 0] = 'D';
            destination[dest_index + 1] = 'L';
            destination[dest_index + 2] = 'E';

            // Stuffed DLE
            destination[dest_index + 3] = 'D';
            destination[dest_index + 4] = 'L';
            destination[dest_index + 5] = 'E';
            // destination index incremented by 6 since 3 charcters of DLE(msg) DLE (stuffed) joined to destination
            dest_index += 6;
            // only  3 charrcter read in source so 3 increments
            source_index += 3;
        }
        else
            destination[dest_index++] = source[source_index++]; //note:- assignment and increment ++ represent post increment
    }
    // added  null at end of the destination to end string
    destination[dest_index] = '\0';
    // concatanate (startflag+stuffed source) destination + end_flag to get final frame;
    strcat(destination, end_flag);
    printf("\n\n The stuffed byte frame is :- %s \n", destination);
    return 0;
}
