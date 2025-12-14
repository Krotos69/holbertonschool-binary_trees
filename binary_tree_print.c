#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

#define PRINT_WIDTH 255

/**
 * _print_t - función recursiva que construye la representación del árbol
 * @tree: puntero al nodo raíz
 * @is_left: indica si el nodo es hijo izquierdo
 * @offset: posición horizontal
 * @depth: nivel de profundidad
 * @s: matriz de caracteres donde se dibuja el árbol
 *
 * Return: ancho ocupado por este subárbol
 */
int _print_t(binary_tree_t *tree, int is_left, int offset, int depth, char s[20][PRINT_WIDTH])
{
    char b[6];
    int width = 5;
    int i;
    int left, right; /* ✅ declaradas al inicio */

    if (!tree)
        return 0;

    sprintf(b, "(%03d)", tree->n);

    left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (i = 0; i < width && b[i]; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '+';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '+';
    }

    return left + width + right;
}

/**
 * print_t - imprime la matriz que contiene el árbol
 * @tree: puntero al nodo raíz
 */
void print_t(binary_tree_t *tree)
{
    char s[20][PRINT_WIDTH];
    int i, j;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < PRINT_WIDTH; j++)
            s[i][j] = ' ';
    }

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < PRINT_WIDTH; j++)
            putchar(s[i][j]);
        putchar('\n');
    }
}

/**
 * binary_tree_print - función pública para imprimir un árbol binario
 * @tree: puntero al nodo raíz
 */
void binary_tree_print(const binary_tree_t *tree)
{
    print_t((binary_tree_t *)tree);
}
