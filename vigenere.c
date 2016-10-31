#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const string errorNotification = "Please, try again.\n"

int main(int argc, string argv[]) {


    if (argc != 2) {
        printf("%s", errorNotification);
        return 1;
    }

    // Перевірка на наявність цифр в ключі шифрування.
    string cypherKey = argv[1];
    unsigned long keyLenght = strlen(cypherKey);
    for(int k = 0; k < keyLenght; k++) {
        if (!isalpha(cypherKey[k])) {
            printf("%s", errorNotification);
            return 1;
        }
    }

    string textForCypher = GetString();
    if(textForCypher == NULL) {
        printf("%s", errorNotification);
        return 1;
    }


    // 97 та 65 - порядкові номери перших літер в ASKII які ми додаємо та віднімаємо, щоб залишатись в межах літер в ASKII
    // n++%keyLenght - чергує літери в cypherKey і починає з початку, коли вони закінчуються.
    for (int i = 0, n = 0; i < strlen(textForCypher); i++) {
        if (isalpha(textForCypher[i])) {
            if (isupper(textForCypher[i]))
                // Encryption uppercase letters.
                printf("%c", ((((textForCypher[i] - 65) + ((toupper(cypherKey[n++%keyLenght]))-65)%26) % 26) + 65));
            if (islower(textForCypher[i]))
                // Encryption lowercase letters.
                printf("%c", ((((textForCypher[i] - 97) + ((tolower(cypherKey[n++%keyLenght]))-97)%26) % 26) + 97));
        } else
            printf("%c", textForCypher[i]);
    }

    printf("\n");
    return 0;
}
