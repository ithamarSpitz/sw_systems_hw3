#include <stdio.h>

int toInt(char str){
    int value;
        value = str-'`';
        if (value<0)
            value = str-'0';
        if(value>26||value<0)
            value = 0;
    return value;
}


void minSequenceGematria(char str[], int size){
    int i,j,k,sum=0, count=0;
    for(i=0; i<(sizeof(str)/sizeof(str[0])); i++){
        for(j=i; j<(sizeof(str)/sizeof(str[0])); j++){
            sum=sum+toInt(str[j]);
            if(sum>size) 
                break;
            if(sum==size){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                 for(k=i; k<=j; k++){
                    printf("%c", str[k]);
                 }
                break;  
            }
        }
    }
}

void gematria(char word[], char sentence[]){
    int word_size =0;
    for (int i = 0; i < sizeof(word)/sizeof(word[0]); i++){
       word_size += toInt(word[i]);
    }
    printf("Gematria Sequences: ");
    minSequenceGematria(sentence, word_size);
    printf("\n");
}


char toAtbash(char c){
  if( (c<65||c>122) || (c>90 && c<97) )
    return c;
  if(c<90)
        return 90-(c-'A');
    else
        return 122-(c-'a');    
}

void minSequenceAtbash(char sentence[], char word[]){
    int i,j,k,count=0;
    for(i=0; i<(sizeof(sentence)/sizeof(sentence[0]));i++){
        k=0;
        for (j = i; j < (sizeof(sentence)/sizeof(sentence[0])); j++){
            if (sentence[j]==word[k]){
                     k++;
                if (k==sizeof(word)/sizeof(word[0])){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<j; k++)
                       printf("%c", sentence[k]);
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
        count=0;
        k=sizeof(word)/sizeof(word[0])-1;
        for (j = i; j < (sizeof(sentence)/sizeof(sentence[0])); j++){
            if (sentence[j]==word[k]){
                     k--;                
                if (k==0){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<j; k++)
                       printf("%c", sentence[k]);
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

void atbash(char sentence[], char word[]){
    printf("Atbash Sequences : ");
    char atbash[sizeof(word)/sizeof(word[0])];
    for (int i = 0; i < (sizeof(word)/sizeof(word[0])); i++){
        atbash[i] = toAtbash(word[i]);
    }
    minSequenceAtbash(sentence, atbash);
    printf("\n");
}



int main (void) {
    char preword[31];
    char presentence[256];
    int letter = 0;  
    int idx = 0; 
    while ((letter = getchar()) != ' ' && letter != '\n' && letter != '\t'){
        preword[idx] = letter;
        idx++;
        }
    char word[idx];
    for (int i = 0; i < idx; i++)
       word[i] = preword[i];
    idx = 0; 
    while ((letter = getchar()) != '~'){
        presentence[idx] = letter;
        idx++;
        }
    char sentence[idx];
    for (int i = 0; i < idx; i++)
       sentence[i] = presentence[i];
    printf("word is: \n %s \n size of word is: %d \n sentence is: \n %s \n sizeof sentence is: %d\n", word,sizeof(word)/sizeof(word[0]),sentence,sizeof(sentence)/sizeof(sentence[0]));
    gematria(word, sentence);
    atbash(sentence, word);
    return 0;
}