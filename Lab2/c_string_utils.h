#ifndef C_STRING_UTILS_H_
#define C_STRING_UTILS_H_

int my_strlen(char c_string[]);
int my_strlen(char c_string[]){
    int i = 0;
    for(char* pcur = c_string; *pcur != '\0'; pcur++){
        i++;
    }
    return i;
}


#endif 