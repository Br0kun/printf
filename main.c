#include <limits.h>
#include <stdio.h>
#include "main.h"

// Prototype de la fonction alternative
int _printf_custom(const char *format, ...);

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf_custom("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    _printf_custom("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf_custom("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf_custom("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf_custom("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf_custom("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf_custom("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf_custom("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf_custom("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf_custom("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf_custom("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf_custom("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}

// Définition de la fonction alternative
int _printf_custom(const char *format, ...) {
    // Implémentation de la fonction _printf_custom
    // Assurez-vous de gérer correctement les arguments variables et de retourner la longueur totale imprimée
    // Cette fonction devrait fonctionner de manière similaire à _printf mais avec une implémentation différente
    return 0; // Remplacer cette valeur de retour par la longueur totale imprimée
}

