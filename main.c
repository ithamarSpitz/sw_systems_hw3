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


void minSequenceGematria(char sentence[], int sentenceSize, int gematria){
    int i,j,k,sum, count=0;
    for(i=0; i<sentenceSize; i++){
        sum = 0;
        if(sentence[i] == ' ')
            continue;
        for(j=i; j<sentenceSize; j++){
            sum=sum+toInt(sentence[j]);
            if(sum>gematria) 
                break;
            if(sum==gematria){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                 for(k=i; k<=j; k++){
                    printf("%c", sentence[k]);
                 }
                break;  
            }
        }
    }
}

void gematria(char word[], int wordSize, char sentence[], int sentenceSize){
    int word_gematria =0;
    for (int i = 0; i < wordSize; i++){
       word_gematria += toInt(word[i]);
    }
    printf("word's gematria is: %d\n", word_gematria);
    printf("Gematria Sequences: ");
    minSequenceGematria(sentence, sentenceSize, word_gematria);
    printf("\n");
}

void copy(char arry[], char word[], int wordSize){
    for (int i = 0; i < wordSize; i++){
        arry[i] = word[i];
    }
}

void minSequenceAnagram(char word[], int wordSize, char sentence[], int sentenceSize){
    char wordCopy[wordSize];
    int count = 0, bool = 1;
    for (int i = 0; i < sentenceSize-wordSize+1; i++){
        count++;
        copy(wordCopy, word, wordSize);
        for (int j = i; j < wordSize; i++){
            for (int k = 0; k < wordSize; k++){
                if(wordCopy[k] == sentence[j])
                    wordCopy[k] = '~';
            } 
        }
        for (int q = 0; q < wordSize; q++){
            if(wordCopy[q] != '~')
                bool = 0;
        }
        if(bool){
            if(count)
                printf("~");
            for (int k=i; k<wordSize; k++)
                printf("%c", sentence[k]);
        }
        bool =1;
    }    
}

void anagram(char word[], int wordSize, char sentence[], int sentenceSize){
    printf("enter anagram");
    printf("Anagram Sequences : ");
    minSequenceAnagram(word, wordSize, sentence, sentenceSize);
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

void minSequenceAtbash(char word[], int wordSize, char sentence[], int sentenceSize){
    int i,j,k,count=0;
    for(i=0; i<sentenceSize;i++){
        k=0;
        for (j = i; j <sentenceSize; j++){
            if (sentence[j]==word[k]){
                     k++;
                if (k==wordSize){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<=j; k++)
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
        k=wordSize-1;
        for (j = i; j < sentenceSize; j++){
            if (sentence[j]==word[k]){
                     k--;                
                if (k==-1){
                    if(count==0)
                        count++;
                    else
                        printf("~");
                    for (k=i; k<=j; k++)
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

void atbash(char word[], int wordSize, char sentence[], int sentenceSize){
    char atbash[wordSize];
    for (int i = 0; i < wordSize; i++){
        atbash[i] = toAtbash(word[i]);
    }
    printf("Atbash Sequences : ");
    minSequenceAtbash(atbash, wordSize, sentence, sentenceSize);
    printf("\n");
    anagram(word, wordSize, sentence, sentenceSize);

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
    int wordSize = idx;
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
    int ws = wordSize;
    int ss = idx;
    char *wl = word;
    char *sl = sentence;
    gematria(word, wordSize , sentence, idx);
    atbash(word, wordSize, sentence, idx);
    printf("atbash ends\n");
    if(ss!=idx)
        printf("this is not the problem");
    if(wl != word)
        printf("this is not the problem");
    if(sl != sentence)
        printf("this is not the problem");
    anagram(word, wordSize, sentence, idx);
    return 0;
}