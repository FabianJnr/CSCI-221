#include <stdio.h>
#include <stdlib.h>

char choose_mover(int num_boxes) {
    int alice_price = 200;
    int bob_price = 260;
    char alice = 'A';
    char bob = 'B';
    if (num_boxes <= 23){
        return alice;
    }
    else if ((23 < num_boxes)  && (num_boxes <= 30)){
        return bob;
    }

    int check_1_for_alice = num_boxes / 23;
    int check_2_for_alice = num_boxes % 23;
    if (check_2_for_alice > 0){
        check_1_for_alice += 1;
    }
    int total_price_for_alice = check_1_for_alice * alice_price;

    int check_1_for_bob = num_boxes / 30;
    int check_2_for_bob = num_boxes % 30;
    if (check_2_for_bob > 0){
        check_1_for_bob += 1;
    }
    int total_price_for_bob = check_1_for_bob * bob_price;

    if (total_price_for_bob > total_price_for_alice){
        return alice;
    }
    else {
        return bob;
    }

    return 0;
}

int main(int argc, char *argv[]){
    int input = atoi(argv[1]);
    printf("%c\n", choose_mover(input));
    return 0;
}