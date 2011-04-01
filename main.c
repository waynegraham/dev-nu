#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This code is totally stolen from brucespang's awesome dev-null-DB
 * repo at https://github.com/brucespang/dev-null-DB
 */

#define LENGTH 65535

// TODO: Sharding!
// TODO: Make a server

char **explode(char *str, char delimiter, char *segs[LENGTH]){
    char seg[LENGTH] = {};
    int num_segs = 0;
    int n, i;
    
    for(i = 0, n = 0; i <= strlen(str); i++, n++){
        if(str[i] == delimiter || str[i] == '\0'){
            segs[num_segs++] = (char *)malloc(strlen(seg));
            strncpy(segs[num_segs-1], seg, strlen(seg));
            int c;
            for(c = 0; c < 256; c++)
                seg[c] = 0;
            n = -1;
        } else {
            seg[n] = str[i];
        }
    }
    
    return segs;
}

int set(char *key, char *value){
    char command[65535] = "";
	int length;
    
    strcat(command, key);
    strcat(command, ",");
    strcat(command, value);
	length = strlen(command) + 1;

    FILE *dev_null = fopen("/dev/null", "w");
    fwrite(command, sizeof(char), length, dev_null);
	fclose(dev_null);
    
    return 1;
}

char *get(char *key){
    char buffer[LENGTH];
    char *segs[LENGTH];
    
    FILE *dev_null = fopen("/dev/null", "r");
        
    while(!feof(dev_null)){
        while(fgets(buffer, sizeof(buffer), dev_null)){
            explode(buffer, ',', segs);
            if(strcmp(segs[0], key) == 0){
                return segs[1];
            }
        }
    }
    
    fclose(dev_null);
    
    return "(null)\n";
}

int main(int argc, char *argv[]){
    printf("/dev/null DB is fully operational\n");
    
    while(1){
        char command[256] = {};
        int i = 0;
        
        printf("> ");
        int ch;
        while ((ch = getchar()) != '\n')
            command[i++] = ch;

        char *args[256] = {};
        explode(command, ' ', args);        
        
        if((strcmp(args[0], "set")) == 0){
            set(args[1], args[2]);
            printf("Set %s to %s\n", args[1], args[2]);
        } else if((strcmp(args[0], "get")) == 0){
            printf("%s", get(args[1]));
        } else if((strcmp(args[0], "exit")) == 0){
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    
    return 0;
}

