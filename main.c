#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_upper(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_lower(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_digit(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_special(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i]) && password[i] != ' ' && password[i] != '_') {
            return 1;
        }
    }
    return 0;
}

void evaluate_password(const char *password) {
    if (strlen(password) >= 8 && has_upper(password) && has_lower(password) && has_digit(password) && has_special(password)) {
        printf("Strength: Strong\n");
    } else if (strlen(password) >= 6 && has_upper(password) && has_lower(password) && has_digit(password)) {
        printf("Strength: Moderate\n");
    } else {
        printf("Strength: Weak\n");
    }
}

int main() {
    char password[100];
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character
    evaluate_password(password);
    return 0;
}