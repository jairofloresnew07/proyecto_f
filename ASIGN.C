void venderProducto() {
    char nombre_comprador[50], nombre_producto[50];
    int cantidad_a_comprar, encontrado_cliente = 0, encontrado_producto = 0;
    float precio_total;
    int cliente_encontrado = 0, producto_encontrado = 0;
    int cliente_indice = -1, producto_indice = -1;

    clrscr();
    textcolor(CYAN);
    gotoxy(24, 4); cprintf("---- Compra de productos ----");

    textcolor(BLUE);
    gotoxy(24, 8); cprintf("Nombre del comprador: ");
    while (getchar() != '\n');
    fgets(nombre_comprador, sizeof(nombre_comprador), stdin);
    nombre_comprador[strcspn(nombre_comprador, "\n")] = '\0';

    for (i = 0; i < contador_clientes; i++) {
        if (strcmp(clientes[i].nombre, nombre_comprador) == 0) {
            cliente_encontrado = 1;
            cliente_indice = i;
            break;
        }
    }

    if (!cliente_encontrado) {
        gotoxy(28, 20);
        textcolor(RED);
        cprintf("<<< Cliente no registrado >>>\n");
        delay(1000);
        return;
    }

    textcolor(BLUE);
    gotoxy(24, 10); cprintf("Nombre del producto: ");
    fgets(nombre_producto, sizeof(nombre_producto), stdin);
    nombre_producto[strcspn(nombre_producto, "\n")] = '\0';

    for (j = 0; j < contador_productos; j++) {
        if (strcmp(productos[j].nombre, nombre_producto) == 0) {
            producto_encontrado = 1;
            producto_indice = j;
            break;
        }
    }

    if (!producto_encontrado) {
        gotoxy(28, 20);
        textcolor(RED);
        cprintf("<<< Producto no existe >>>\n");
        delay(1000);
        return;
    }

    do {
        textcolor(BLUE);
        gotoxy(24, 12); cprintf("Cantidad a comprar: ");
        if (scanf("%d", &cantidad_a_comprar) != 1 || cantidad_a_comprar < 1 || cantidad_a_comprar > productos[producto_indice].cantidad) {
            gotoxy(28, 20);
            textcolor(RED);
            cprintf("<<< Cantidad excesiva o invalida >>>\n");
            delay(1000);
            gotoxy(28, 20); cprintf("                                         \r");
        } else {
            break;
        }
    } while (1);

    precio_total = productos[producto_indice].precio * cantidad_a_comprar;
    if (clientes[cliente_indice].creditos < precio_total) {
        gotoxy(28, 20);
        textcolor(RED);
        cprintf("<<< Creditos insuficientes >>>\n");
        delay(1000);
        return;
    }

    productos[producto_indice].cantidad -= cantidad_a_comprar;
    clientes[cliente_indice].creditos -= precio_total; 

    gotoxy(28, 20);
    textcolor(GREEN);
    cprintf("Compra realizada con exito!\n");
    delay(1000);
}

void venderCreditos() {
    char nombre_cliente[50];
    int cliente_encontrado = 0, cliente_indice = -1;
    char respuesta[2];

    clrscr();
    textcolor(CYAN);
    gotoxy(24, 4); cprintf("---- Compra de Creditos ----");

    textcolor(BLUE);
    gotoxy(24, 8); cprintf("Nombre del comprador: ");
    while (getchar() != '\n');
    fgets(nombre_cliente, sizeof(nombre_cliente), stdin);
    nombre_cliente[strcspn(nombre_cliente, "\n")] = '\0';

    for (i = 0; i < contador_clientes; i++) {
        if (strcmp(clientes[i].nombre, nombre_cliente) == 0) {
            cliente_encontrado = 1;
            cliente_indice = i;
            break;
        }
    }

    if (!cliente_encontrado) {
        gotoxy(28, 20);
        textcolor(RED);
        cprintf("<<< Cliente no registrado >>>\n");
        delay(1000);
        return;
    }

    textcolor(BLUE);
    gotoxy(24, 10); cprintf("Desea adquirir creditos? (S/N): ");
    fgets(respuesta, sizeof(respuesta), stdin);
    respuesta[strcspn(respuesta, "\n")] = '\0';

    if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
        clientes[cliente_indice].creditos += 500;
        gotoxy(23, 12);
        textcolor(GREEN);
        cprintf("creditos agregados con exito!\n");
    } else {
        gotoxy(28, 12);
        textcolor(RED);
        cprintf("Sin adquisicion de creditos.\n");
    }
    delay(1000);
}

/* Caso 6 de inventario */

void menuVender() {
    int opcion;

    clrscr();
    textcolor(CYAN);
    gotoxy(24, 4); cprintf("---- Menu de Venta ----");

    textcolor(BLUE);
    gotoxy(24, 8); cprintf("1. Comprar Productos");
    gotoxy(24, 10); cprintf("2. Comprar Creditos");
    gotoxy(24, 12); cprintf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        venderProducto();
    } else if (opcion == 2) {
        venderCreditos();
    } else {
        gotoxy(28, 20);
        textcolor(RED);
        cprintf("Opcion invalida!\n");
        delay(1000);
    }
}
