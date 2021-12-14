#include <stdio.h>

char preword[30];
char presentence[256];
int toInt(char str){
    int value;
        value = str-'`';
        if (value<0)
            value = str-'0';
        if(value>26||value<0)
            value = 0;
    return value;
}


void minSequenceGematria(char[] str, int size){
    int i,j,k,sum=0;
    for(i=0; i<sizeof(str); i++){
        for(j=i; j<sizeof(str); j++){
            sum=sum+toInt(str[j]);
            if(sum>size) 
                break;
            if(sum==size){
                 for(k=i; k<=j; k++){
                    printf("%c", str[k]);
                 }
                printf("~");
                break;  
            }
        }
    }
}

void gematria(word, sentence){
    int word_size =0;
    for (int i = 0; i < sizeof(word); i++){
       word_size += toInt(word[i]);
    }
    printf("Gematria Sequences: ");
    minSequenceGematria(sentence, word_size);
    printf("\n");
}


char toAtbash(char c){
  if(c<90)
        return 90-(c-'A');
    else
        return 122-(c-'a');    
}



int main(){

}