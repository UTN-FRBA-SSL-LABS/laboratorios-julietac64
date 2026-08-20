#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void)
{
    Carrito c;
    carrito_init(&c);
    Producto pan = {"Pan", 200, 3}; /*$600*/
    Producto leche = {"Leche", 350, 2};/*$700*/
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);
    ASSERT_IGUAL(1300, carrito_total(&c));
    int total_descuento = carrito_descuento(1300, 10);
    ASSERT_IGUAL(1170, total_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void)
{
    Carrito c;
    carrito_init(&c);
    Producto leche = {"Leche", 350, 1};
    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);
    carrito_agregar(&c, leche);
    ASSERT_IGUAL(0, carrito_agregar(&c, leche));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
