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

    // Зчитування тексту для шифрування.
    string textForCypher = GetString();
    if(textForCypher == NULL) {
        printf("%s", errorNotification);
        return 1;
    }

    // Шифрування введеного тексту для шифрування і його присвоєння в змінну textForCypher.
    // Функція з isupper, islower залишає великі літери великими, малі - малими.
    // 65 та 97 - номери першої малої та великої літери в таблиці ASKII, які ми віднімаємо та додаємо, аби шифрування не виходило за межі літер в таблиці ASKII.
    // n++%keyLenght - чергує літери в cypherKey і починає з початку, коли вони закінчуються.
    for (int i = 0, n = 0; i < strlen(textForCypher); i++) {
        if (isalpha(textForCypher[i])) {
            if (isupper(textForCypher[i]))
                printf("%c", ((((textForCypher[i] - 65) + ((toupper(cypherKey[n++%keyLenght]))-65)%26) % 26) + 65));

            if (islower(textForCypher[i]))
                printf("%c", ((((textForCypher[i] - 97) + ((tolower(cypherKey[n++%keyLenght]))-97)%26) % 26) + 97));
        } else
            printf("%c", textForCypher[i]);
    }

    printf("\n");
    return 0;
}
