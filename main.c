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
    for(i=0; i<(sizeof(str)/sizeof(str[0])); i++){
        for(j=i; j<(sizeof(str)/sizeof(str[0])); j++){
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

void gematria(char[] word, char[] sentence){
    int word_size =0;
    for (int i = 0; i < sizeof(word)/sizeof(word[0]); i++){
       word_size += toInt(word[i]);
    }
    printf("Gematria Sequences: ");
    minSequenceGematria(sentence, word_size);
    printf("\n");
}


int toAtbash(char c){
  if(c<90)
        return 90-(c-'A');
    else
        return 122-(c-'a');    
}

void minSequenceAtbash(char[] sentence, char[] word){
    int i,j,k;
    for(i=0; i<(sizeof(sentence)/sizeof(sentence[0]));i++){
        k=0;
        for (j = i; j < (sizeof(sentence)/sizeof(sentence[0])); j++){
            if (sentence[j]==word[k]){
                     k++;                
                if (k==sizeof(word)/sizeof(word[0])){
                    for (k=i; k<j; k++)
                       printf(sentence[k]);
                    printf("~");
                    break;   
                }
            }else{
                if(sentence[j] == ' '){
                    if(i==j)
                        break;
                    else
                        continue;
                }else
                    break;
            }
        }
        k=sizeof(word)/sizeof(word[0]);
        for (j = i; j < (sizeof(sentence)/sizeof(sentence[0])); j++){
            if (sentence[j]==word[k]){
                     k--;                
                if (k==0){
                    for (k=i; k<j; k++)
                       printf(sentence[k]);
                    printf("~");
                    break;   
                }
            }else{
                if(sentence[j] == ' '){
                    if(i==j)
                        break;
                    else
                        continue;
                }else
                    break;
            }
        }
    }
}



int main(){

}