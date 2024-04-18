

#ifndef UNTITLED7_TASKS10_H
#define UNTITLED7_TASKS10_H
void reverseWords(char *string){
    char buffer[100];
    int i,j,k;
    for ( i = 0; string[i]!='\0'; ++i) {
        buffer[i]=string[i];
    }
    buffer[i]='\0';
    i=i-1;
    k=0;
    while(i>=0) {
        while (i >= 0 && buffer[i] != " ") {
            i--;
        }
        j = i + 1;
        while(buffer[j] != '\0' && buffer[j] != ' ') {
            string[k++] = buffer[j++];
        }

        if (i >= 0) {
            string[k++] = ' ';

        }
        i--;
    }
    string[k]='\0';
}
#endif //UNTITLED7_TASKS10_H
