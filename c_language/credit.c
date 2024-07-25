#include <stdio.h>

enum Card_type {
    AMERICANEXPRESS,
    MASTERCARD,
    VISA,
    NON_BELONGING
};

const int CARD_MAX_NUMS = 16;
//functions prototypes;
int valid_nums(char* sample, int size);
enum Card_type detect_card(char* sample, int size);
void display_card(enum Card_type card);

// main function;
int main(void){
    char card_num[CARD_MAX_NUMS];
    int failed = 0;
    do{
        printf("enter a valid credit card num: \n");
        failed = scanf("%16s", card_num);
        failed = valid_nums(card_num, CARD_MAX_NUMS);
        fflush(stdin);
    }while(!failed);
    enum Card_type card = detect_card(card_num, CARD_MAX_NUMS);
    display_card(card);
}

enum Card_type detect_card(char* sample, int size){
    int counter = 0;
    enum Card_type card = NON_BELONGING;
    for(int i = 0; i < size; i++){
        if(sample[i] != '\0') counter++;
        else break;
    }


    switch (counter)
    {
    case 15:
        if((sample[0] == '3') && (sample[1] == '4' || sample[1] == '7')){
            card = AMERICANEXPRESS;
        }
        break;
    case 13:
        if(sample[0] == '4') {
            card = VISA;
        } 
        break;
    case 16:
        if(sample[0] == '4') {
            card = VISA;
        }else if(sample[0] == '5' && (sample[1] >= 49 && sample[1] <= 53)){
            card = MASTERCARD;
        }
        break;
    }
    return card;
}


int valid_nums(char* sample, int size){
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(int i = 0; i <= size; i++){
        if(sample[i] == '\0')
        {
            return 1;
        };
        int found = 0;
        for(int k = 0; k < 10; k++){
            if(sample[i] == digits[k]) found = 1;
        }
        if(!found) return 0;
    }
}

void display_card(enum Card_type card){
    switch(card){
        case AMERICANEXPRESS:
            printf("%s", "AMERICAN_EXPRESS");
            break;
        case MASTERCARD:
            printf("%s", "MASTER_CARD");
            break;
        case VISA:
            printf("%s", "VISA");
            break;
        case NON_BELONGING:
            printf("%s", "NON_BELONGING");
            break;
        default:
            printf("%s", "NON_BELONGING_DIGITS");
    }
}