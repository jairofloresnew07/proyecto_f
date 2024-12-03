#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
typedef struct {
    int cantidad;
    char codigo[6];
    float precio;
    char nombre[50];
    char descripcion[50];
} Producto;

typedef struct {
    char nombre[50];
    char codigo[6];
    char telefono[9];
    int creditos;
    char membresia[20];
} Cliente;
int ancho = 15;
int alto = 3;
int i, j, k, l, intentos = 0, codev = 0, v = 1;
int opcion, subopcion, cantidad;
float precio;
char usuario[20];
char contrasena[20];
char codep[20];
char nombre_producto[50];
char descripcion[50];
const char *upre = "jairoftm";
const char *cpre = "2024";
Producto productos[MAX_PRODUCTOS];
int contador_productos = 0;
char buscarp;
char tipo_busqueda;
int encontrado, i_producto;
char respuesta;
char nombre_cliente[50];
int valido, es_valido, valido_telefono, i_cliente;
char codigo_cliente[6];
char telefono_cliente[9];
char membresia;
int creditos, codigo_repetido;
Cliente clientes[MAX_CLIENTES];
int contador_clientes = 0;
char confirmacion;
void eliminarProducto() {
    clrscr();
    textcolor(CYAN);
    gotoxy(26,4); cprintf("---- Eliminacion de productos ----");

    textcolor(BLUE);
    getchar();
    gotoxy(16,8); cprintf("Deseas eliminar el producto por (C)odigo o (N)ombre: ");
    tipo_busqueda = getchar();

    if(toupper(tipo_busqueda) == 'C') {
        gotoxy(16,10); cprintf("Ingrese el codigo del producto: ");
        scanf("%s", codep);
        encontrado = 0;

        for(i_producto = 0; i_producto < contador_productos; i_producto++) {
            if(strcmp(productos[i_producto].codigo, codep) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31,13); cprintf("Producto encontrado!");

                textcolor(LIGHTBLUE);
                gotoxy(31,15); cprintf("Cantidad: %d", productos[i_producto].cantidad);
                gotoxy(31,16); cprintf("Codigo: %s", productos[i_producto].codigo);
                gotoxy(31,17); cprintf("Precio: %.2f", productos[i_producto].precio);
                gotoxy(31,18); cprintf("Nombre: %s", productos[i_producto].nombre);
                gotoxy(31,19); cprintf("Descripcion: %s", productos[i_producto].descripcion);

                textcolor(BLUE);
                gotoxy(22,21); cprintf("Seguro que lo quieres eliminar (Y/N)? ");

                getchar();
                confirmacion = getchar();
                if(toupper(confirmacion) == 'Y') {
                    for(j = i_producto; j < contador_productos - 1; j++) {
                        productos[j] = productos[j+1];
                    }
                    contador_productos--;
                    textcolor(GREEN);
                    gotoxy(31,23); cprintf("Producto eliminado con exito!");
                    delay(1000);
                } else if(toupper(confirmacion) == 'N') {
                    textcolor(RED);
                    gotoxy(31,23); cprintf("Eliminacion cancelada");
                    delay(1000);
                } else {
                    textcolor(RED);
                    gotoxy(31,23); cprintf("Sin registro de respuesta");
                    delay(1000);
                }
                break;
            }
            textcolor(WHITE);
        }

        if(!encontrado) {
            textcolor(RED);
            gotoxy(29,23); cprintf("Producto no encontrado!");
            delay(1000);
        }
        textcolor(WHITE);
    } else if (toupper(tipo_busqueda) == 'N') {
        gotoxy(16,10); cprintf("Ingrese el nombre del producto: ");
        getchar();
        fgets(nombre_producto, sizeof(nombre_producto), stdin);
        nombre_producto[strcspn(nombre_producto, "\n")] = '\0';
        encontrado = 0;

        for(i_producto = 0; i_producto < contador_productos; i_producto++) {
            if(strcmp(productos[i_producto].nombre, nombre_producto) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31,13); cprintf("Producto encontrado!");

                textcolor(LIGHTBLUE);
                gotoxy(31,15); cprintf("Cantidad: %d", productos[i_producto].cantidad);
                gotoxy(31,16); cprintf("Codigo: %s", productos[i_producto].codigo);
                gotoxy(31,17); cprintf("Precio: %.2f", productos[i_producto].precio);
                gotoxy(31,18); cprintf("Nombre: %s", productos[i_producto].nombre);
                gotoxy(31,19); cprintf("Descripcion: %s", productos[i_producto].descripcion);

                textcolor(BLUE);
                gotoxy(22,21); cprintf("Seguro que lo quieres eliminar (Y/N)? ");

                confirmacion = getchar();
                if(toupper(confirmacion) == 'Y') {
                    for(j = i_producto; j < contador_productos - 1; j++) {
                        productos[j] = productos[j + 1];
                    }
                    contador_productos--;
                    textcolor(GREEN);
                    gotoxy(31,23); cprintf("Producto eliminado con exito!");
                    delay(1000);
                } else if (toupper(confirmacion) == 'N'){
                    textcolor(RED);
                    gotoxy(31,23); cprintf("Eliminacion cancelada");
                    delay(1000);
                } else {
                    textcolor(RED);
                    gotoxy(31,23); cprintf("Sin registro de respuesta");
                    delay(1000);
                }
                break;
            }
        }
        if(!encontrado) {
            textcolor(RED);
            gotoxy(29,23); cprintf("Producto no encontrado!");
            delay(1000);
        }
        textcolor(WHITE);
    }
}

void verProducto() {
    clrscr();
    if (contador_productos == 0) {
        textcolor(RED);
		gotoxy(25, 12);
        cprintf("No hay productos en el inventario.");
        delay(1000);
        textcolor(WHITE);
    } else {
        for (i = 0; i < contador_productos; i++) {
            clrscr();
			textcolor(CYAN);
			gotoxy(24,4); cprintf("---- Disponibilidad del inevntario ----");
			gotoxy(37, 6); cprintf("Producto %d", i + 1);
            textcolor(LIGHTBLUE);
			gotoxy(35.5, 8); cprintf("Codigo: %s", productos[i].codigo);
			gotoxy(35.5, 9); cprintf("Nombre: %s", productos[i].nombre);
			gotoxy(35.5, 10); cprintf("Descripcion: %s", productos[i].descripcion);
			gotoxy(35.5, 11); cprintf("Cantidad: %d", productos[i].cantidad);
			gotoxy(35.5, 12); cprintf("Precio: %.2f", productos[i].precio);
			textcolor(WHITE);
			gotoxy(25, 14); cprintf("Presiona una tecla para continuar -->");
			getch();
			textcolor(WHITE);
        }
    }
	textcolor(WHITE);
}

void actualizarProducto() {
    clrscr();
    textcolor(CYAN);
    gotoxy(26, 4); cprintf("---- Actualizacion de productos ----");

    textcolor(BLUE);
    getchar();
    gotoxy(16, 8); cprintf("Deseas buscar el producto por (C)odigo o (N)ombre: ");
    tipo_busqueda = getchar();
    getchar();

    if (toupper(tipo_busqueda) == 'C') {
        gotoxy(16, 10); cprintf("Ingrese el codigo del producto: ");
        scanf("%s", codep);
        getchar();
        encontrado = 0;
        
        for (i_producto = 0; i_producto < contador_productos; i_producto++) {
            if (strcmp(productos[i_producto].codigo, codep) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31, 13); cprintf("Producto encontrado!");
                textcolor(LIGHTBLUE);
                gotoxy(31, 15); cprintf("Cantidad: %d", productos[i_producto].cantidad);
                gotoxy(31, 16); cprintf("Codigo: %s", productos[i_producto].codigo);
                gotoxy(31, 17); cprintf("Precio: %.2f", productos[i_producto].precio);
                gotoxy(31, 18); cprintf("Nombre: %s", productos[i_producto].nombre);
                gotoxy(31, 19); cprintf("Descripcion: %s", productos[i_producto].descripcion);
                gotoxy(31, 21); cprintf("Deseas actualizar este producto? (S/N): ");
                respuesta = getchar();
                getchar();
                textcolor(WHITE);
                
                if (toupper(respuesta) == 'S') {
                    do {
                        clrscr();
					    textcolor(CYAN);
						gotoxy(26,4); cprintf("---- Actualizando producto ----");
						textcolor(BLUE);
						gotoxy(24,8); cprintf("Ingrese nueva cantidad: ");
                        if (scanf("%d", &cantidad) != 1 || cantidad < 1 || cantidad > 100) {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Cantidad invalida >>>\n");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                  \r");
							while (getchar() != '\n');
							textcolor(BLUE);
                        } else {
                            break;
                        }
                    } while (1);
                    productos[i_producto].cantidad = cantidad;
                    do {
                        gotoxy(24,10); cprintf("Ingrese nuevo precio: ");
                        if (scanf("%f", &precio) != 1 || precio < 1) {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Inserta un precio valido >>>");
                            delay(1000);
                            gotoxy(28, 20); cprintf("                                                \r");
                            while (getchar() != '\n');
							textcolor(BLUE);
                        } else {
                            break;
                        }
                    } while (1);
                    productos[i_producto].precio = precio;
                    do {
                        gotoxy(24,12); cprintf("Ingrese nuevo nombre: ");
                        getchar();
                        fgets(nombre_producto, sizeof(nombre_producto), stdin);
                        nombre_producto[strcspn(nombre_producto, "\n")] = '\0';
                        v = 1;

                        for (k = 0; nombre_producto[k] != '\0'; k++) {
                            if (!isalpha(nombre_producto[k]) && nombre_producto[k] != ' ') {
                                v = 0;
                                break;
                            }
                        }
                        if (v) {
                            break;
                        } else {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Nombre invalido, usa solo letras y espacios >>>\n");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                                   \r");
							textcolor(BLUE);
                        }
                    } while (1);
                    strcpy(productos[i_producto].nombre, nombre_producto);
                    gotoxy(24,14); cprintf("Ingrese nueva descripcion: ");
                    fgets(descripcion, sizeof(descripcion), stdin);
                    descripcion[strcspn(descripcion, "\n")] = '\0';
                    strcpy(productos[i_producto].descripcion, descripcion);
                    
                    do {
                        gotoxy(24,16); cprintf("Ingrese nuevo codigo: ");
                        scanf("%s", codep);
                        getchar();
                        codev = 0;
                        
                        if (codep[0] == '#' && strlen(codep) == 5 &&
                        isdigit(codep[1]) && isdigit(codep[2]) &&
                        isdigit(codep[3]) && isdigit(codep[4])) {
                            for (j = 0; j < contador_productos; j++) {
                                if (strcmp(productos[j].codigo, codep) == 0) {
                                    codev = 0;
                                    break;
                                } else {
                                    codev = 1;
                                }
                            }
                        }
                        if (!codev) {
                            gotoxy(28, 20);
                            textcolor(RED);
							cprintf("<<< Codigo no valido o ya existe >>>");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                           \r");
							textcolor(BLUE);
                        }
                    } while (!codev);
                    strcpy(productos[i_producto].codigo, codep);
                    textcolor(GREEN);
					gotoxy(28, 20); cprintf("Producto actualizado con exito!\n");
                }
                getch();
                textcolor(WHITE);
                break;
            }
        }
        if (!encontrado) {
            textcolor(RED);
            gotoxy(29, 23); cprintf("Producto no encontrado!");
            delay(1000);
            textcolor(WHITE);
        }
    } else if (toupper(tipo_busqueda) == 'N') {
        gotoxy(16, 10); cprintf("Ingrese el nombre del producto: ");
        getchar();
        fgets(nombre_producto, sizeof(nombre_producto), stdin);
        nombre_producto[strcspn(nombre_producto, "\n")] = '\0';
        encontrado = 0;

        for (i_producto = 0; i_producto < contador_productos; i_producto++) {
            if (strstr(productos[i_producto].nombre, nombre_producto) != NULL) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31, 13); cprintf("Producto encontrado!");
                textcolor(LIGHTBLUE);
                gotoxy(31, 15); cprintf("Cantidad: %d", productos[i_producto].cantidad);
                gotoxy(31, 16); cprintf("Codigo: %s", productos[i_producto].codigo);
                gotoxy(31, 17); cprintf("Precio: %.2f", productos[i_producto].precio);
                gotoxy(31, 18); cprintf("Nombre: %s", productos[i_producto].nombre);
                gotoxy(31, 19); cprintf("Descripcion: %s", productos[i_producto].descripcion);
                gotoxy(31, 21); cprintf("Deseas actualizar este producto? (S/N): ");
                respuesta = getchar();
                getchar();
                textcolor(WHITE);

                if (toupper(respuesta) == 'S') {
                    do {
                        clrscr();
						textcolor(CYAN);
						gotoxy(24,4); cprintf("---- Actualizando producto ----");
						textcolor(BLUE);
						gotoxy(24, 8); cprintf("Ingrese nueva cantidad: ");
                        if (scanf("%d", &cantidad) != 1 || cantidad < 1 || cantidad > 100) {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Cantidad invalida >>>");
                            delay(1000);
                            gotoxy(28, 20); cprintf("                                \r");
                            while (getchar() != '\n');
                            textcolor(BLUE);
                        } else {
                            break;
                        }
                    } while (1);
                    productos[i_producto].cantidad = cantidad;
                    do {
                        gotoxy(24, 10); cprintf("Ingrese nuevo precio: ");
                        if (scanf("%f", &precio) != 1 || precio < 1) {
                            gotoxy(28, 20);
                            textcolor(RED);
							cprintf("<<< Inserta un precio valido >>>");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                         \r");
							while (getchar() != '\n');
							textcolor(BLUE);
                        } else {
                            break;
                        }
                    } while (1);
                    productos[i_producto].precio = precio;
                    do {
                        gotoxy(24, 12); cprintf("Ingrese nuevo nombre: ");
                        getchar();
                        fgets(nombre_producto, sizeof(nombre_producto), stdin);
                        nombre_producto[strcspn(nombre_producto, "\n")] = '\0';
                        v = 1;
                        for (k = 0; nombre_producto[k] != '\0'; k++) {
                            if (!isalpha(nombre_producto[k]) && nombre_producto[k] != ' ') {
                                v = 0;
                                break;
                            }
                        }

                        if (v) {
                            break;
                        } else {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Nombre invalido, usa solo letras y espacios >>>");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                                         \r");
							textcolor(BLUE);
                        }
                    } while (1);
                    strcpy(productos[i_producto].nombre, nombre_producto);

				    gotoxy(24, 14); cprintf("Ingrese nueva descripcion: ");
                    fgets(descripcion, sizeof(descripcion), stdin);
                    descripcion[strcspn(descripcion, "\n")] = '\0';
                    strcpy(productos[i_producto].descripcion, descripcion);

                    do {
                        gotoxy(24, 16); cprintf("Ingrese nuevo codigo: ");
                        scanf("%s", codep);
                        getchar();

                        codev = 0;
                        if (codep[0] == '#' && strlen(codep) == 5 &&
                        isdigit(codep[1]) && isdigit(codep[2]) &&
                        isdigit(codep[3]) && isdigit(codep[4])) {
                            for (j = 0; j < contador_productos; j++) {
                                if (strcmp(productos[j].codigo, codep) == 0) {
                                    codev = 0;
                                    break;
                                } else {
                                    codev = 1;
                                }
                            }
                        }
                        if (!codev) {
                            gotoxy(28, 20);
                            textcolor(RED);
							cprintf("<<< Codigo no valido o ya existe >>>");
                            delay(1000);
							gotoxy(28, 20); cprintf("                                         \r");
							textcolor(BLUE);
                        }
                    } while (!codev);
                    strcpy(productos[i_producto].codigo, codep);

                    textcolor(GREEN);
					gotoxy(28, 20); cprintf("Producto actualizado con exito!\n");
                }
                getch();
                textcolor(WHITE);
                break;
            }
        }
        if (!encontrado) {
            textcolor(RED);
            gotoxy(29, 23); cprintf("Producto no encontrado!");
            delay(1000);
            textcolor(WHITE);
        }
    } else {
        textcolor(RED);
        gotoxy(29, 23); cprintf("Sin registro de busqueda");
        textcolor(WHITE);
    }
    delay(1000);
}

void actualizarCliente() {
    clrscr();
    textcolor(CYAN);
    gotoxy(26, 4); cprintf("---- Actualizar cliente ----");
                                
    do {
        textcolor(BLUE);
        gotoxy(24, 8); cprintf("Codigo del cliente a actualizar: ");
        scanf("%s", codigo_cliente);
        encontrado = 0;
                                    
        for (i_cliente = 0; i_cliente < contador_clientes; i_cliente++) {
            if (strcmp(clientes[i_cliente].codigo, codigo_cliente) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31, 10); cprintf("Cliente encontrado!");
                textcolor(LIGHTBLUE);
                gotoxy(31, 12); cprintf("Nombre: %s", clientes[i_cliente].nombre);
                gotoxy(31, 13); cprintf("Codigo: %s", clientes[i_cliente].codigo);
                gotoxy(31, 14); cprintf("Telefono: %s", clientes[i_cliente].telefono);
                gotoxy(31, 15); cprintf("Creditos: %d", clientes[i_cliente].creditos);
                gotoxy(31, 16); cprintf("Membresia: %s", clientes[i_cliente].membresia);
                
                do {
                    textcolor(BLUE);
                    gotoxy(24, 18); cprintf("Nuevo nombre: ");
                    while (getchar() != '\n');
                    fgets(nombre_cliente, sizeof(nombre_cliente), stdin);
                    nombre_cliente[strcspn(nombre_cliente, "\n")] = '\0';
                    valido = 1;
                    for (i = 0; nombre_cliente[i] != '\0'; i++) {
                        if (!isalpha(nombre_cliente[i]) && nombre_cliente[i] != ' ') {
                            valido = 0;
                            break;
                        }
                    }
                    if (valido) {
                        strcpy(clientes[i_cliente].nombre, nombre_cliente);
                        break;
                    } else {
                        gotoxy(28, 20);
                        textcolor(RED);
                        cprintf("<<< Nombre invalido, usa solo letras y espacios >>>");
                        delay(1000);
                        gotoxy(28, 20); cprintf("                                                   \r");
                    }
                } while (!valido);
                do {
                    textcolor(BLUE);
                    gotoxy(24, 20); cprintf("Nuevo codigo: ");
                    fgets(codigo_cliente, sizeof(codigo_cliente), stdin);
                    codigo_cliente[strcspn(codigo_cliente, "\n")] = '\0';
                    if (codigo_cliente[0] == '#' && strlen(codigo_cliente) == 5) {
                        es_valido = 1;
                        for (i = 1; i < 5; i++) {
                            if (!isalpha(codigo_cliente[i])) {
                                es_valido = 0;
                                break;
                            }
                        }
                        if (es_valido) {
                            codigo_repetido = 0;
                            for (i = 0; i < contador_clientes; i++) {
                                if (strcmp(clientes[i].codigo, codigo_cliente) == 0 && i != i_cliente) {
                                    codigo_repetido = 1;
                                    break;
                                }
                            }
                            if (codigo_repetido) {
                                gotoxy(28, 20);
                                textcolor(RED);
                                cprintf("<<< Codigo ya registrado, usa otro >>>");
                                delay(1000);
                                gotoxy(28, 20); cprintf("                                                         \r");
                            } else {
                                strcpy(clientes[i_cliente].codigo, codigo_cliente);
                                break;
                            }
                        } else {
                            gotoxy(28, 20);
                            textcolor(RED);
                            cprintf("<<< Codigo invalido, debe ser # seguido de 4 letras >>>\n");
                            delay(1000);
                            gotoxy(28, 20); cprintf("                                                                \r");
                        }
                    } else {
                        gotoxy(28, 20);
                        textcolor(RED);
                        cprintf("<<< Codigo invalido, debe ser # seguido de 4 letras >>>\n");
                        delay(1000);
                        gotoxy(28, 20); cprintf("                                                               \r");
                    }
                } while (1);
                
                do {
                    textcolor(BLUE);
                    gotoxy(24, 22); cprintf("Nuevo telefono: ");
                    scanf("%s", telefono_cliente);
                    valido_telefono = 1;
                    if (strlen(telefono_cliente) == 8) {
                        for (i = 0; telefono_cliente[i] != '\0'; i++) {
                            if (!isdigit(telefono_cliente[i])) {
                                valido_telefono = 0;
                                break;
                            }
                        }
                    } else {
                        valido_telefono = 0;
                    }
                    if (valido_telefono) {
                        strcpy(clientes[i_cliente].telefono, telefono_cliente);
                        break;
                    } else {
                        gotoxy(28, 20);
                        textcolor(RED);
                        cprintf("<<< Telefono invalido, debe tener 8 digitos numericos >>>\n");
                        delay(1000);
                        gotoxy(28, 20); cprintf("                                                                  \r");
                    }
                } while (!valido_telefono);
                                            
                do {
                    textcolor(BLUE);
                    gotoxy(24, 24); cprintf("Nueva Membresia (A. VIP B. PREMIUM C. ALPHA D. NINGUNA): ");
                    scanf(" %c", &membresia);
                    
                    membresia = toupper(membresia);
                                                
                    if (membresia == 'A' || membresia == 'B' || membresia == 'C' || membresia == 'D') {
                        switch (membresia) {
                            case 'A':
                                strcpy(clientes[i_cliente].membresia, "VIP");
                                break;
                            case 'B':
                                strcpy(clientes[i_cliente].membresia, "PREMIUM");
                                break;
                            case 'C':
                                strcpy(clientes[i_cliente].membresia, "ALPHA");
                                break;
                            case 'D':
                                strcpy(clientes[i_cliente].membresia, "NO EXISTENTE");
                                break;
                        }
                        break;
                    } else {
                        gotoxy(28, 20);
                        textcolor(RED);
                        cprintf("<<< Opcion invalida, ingresa A, B, C o D >>>\n");
                        delay(1000);
                        gotoxy(28, 20); cprintf("                                                       \r");
                    }
                } while (1);
                gotoxy(28, 23);
                textcolor(GREEN);
                cprintf("Cliente actualizado con exito!\n");
                delay(1000);
                break;
            }
        }
        if (!encontrado) {
            textcolor(RED);
            gotoxy(29, 23); cprintf("Cliente no encontrado!");
            delay(1000);
            textcolor(WHITE);
        }
    } while (!encontrado);
}

void eliminarCliente() {
    clrscr();
    textcolor(CYAN);
    gotoxy(26, 4); cprintf("---- Eliminacion de clientes ----");
                                
    textcolor(BLUE);
    getchar();
    gotoxy(16, 8); cprintf("Deseas eliminar el cliente por (C)odigo o (N)ombre: ");
    tipo_busqueda = getchar();
                                
    if (toupper(tipo_busqueda) == 'C') {
        gotoxy(16, 10); cprintf("Ingrese el codigo del cliente: ");
        scanf("%s", codigo_cliente);
        encontrado = 0;
        for (i_cliente = 0; i_cliente < contador_clientes; i_cliente++) {
            if (strcmp(clientes[i_cliente].codigo, codigo_cliente) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31, 13); cprintf("Cliente encontrado!");
                                            
                textcolor(LIGHTBLUE);
                gotoxy(31, 15); cprintf("Nombre: %s", clientes[i_cliente].nombre);
                gotoxy(31, 16); cprintf("Codigo: %s", clientes[i_cliente].codigo);
                gotoxy(31, 17); cprintf("Telefono: %s", clientes[i_cliente].telefono);
                gotoxy(31, 18); cprintf("Membresia: %s", clientes[i_cliente].membresia);
                textcolor(BLUE);
                gotoxy(22, 21); cprintf("Seguro que lo quieres eliminar (Y/N)? ");
                getchar();
                confirmacion = getchar();
                if (toupper(confirmacion) == 'Y') {
                    for (j = i_cliente; j < contador_clientes - 1; j++) {
                        clientes[j] = clientes[j + 1];
                    }
                    contador_clientes--;
                    textcolor(GREEN);
                    gotoxy(31, 23); cprintf("Cliente eliminado con exito!");
                    delay(1000);
                } else if (toupper(confirmacion) == 'N') {
                    textcolor(RED);
                    gotoxy(31, 23); cprintf("Eliminacion cancelada");
                    delay(1000);
                } else {
                    textcolor(RED);
                    gotoxy(31, 23); cprintf("Sin registro de respuesta");
                    delay(1000);
                }
                break;
            }
            textcolor(WHITE);
        }
        if (!encontrado) {
            textcolor(RED);
            gotoxy(29, 23); cprintf("Cliente no encontrado!");
            delay(1000);
        }
        textcolor(WHITE);
    } else if (toupper(tipo_busqueda) == 'N') {
        gotoxy(16, 10); cprintf("Ingrese el nombre del cliente: ");
        getchar();
        fgets(nombre_cliente, sizeof(nombre_cliente), stdin);
        nombre_cliente[strcspn(nombre_cliente, "\n")] = '\0';
        encontrado = 0;
        for (i_cliente = 0; i_cliente < contador_clientes; i_cliente++) {
            if (strcmp(clientes[i_cliente].nombre, nombre_cliente) == 0) {
                encontrado = 1;
                textcolor(GREEN);
                gotoxy(31, 13); cprintf("Cliente encontrado!");
                textcolor(LIGHTBLUE);
                gotoxy(31, 15); cprintf("Nombre: %s", clientes[i_cliente].nombre);
                gotoxy(31, 16); cprintf("Codigo: %s", clientes[i_cliente].codigo);
                gotoxy(31, 17); cprintf("Telefono: %s", clientes[i_cliente].telefono);
                gotoxy(31, 18); cprintf("Membresia: %s", clientes[i_cliente].membresia);
                textcolor(BLUE);
                gotoxy(22, 21); cprintf("Seguro que lo quieres eliminar (Y/N)? ");
                confirmacion = getchar();
                if (toupper(confirmacion) == 'Y') {
                    for (j = i_cliente; j < contador_clientes - 1; j++) {
                        clientes[j] = clientes[j + 1];
                    }
                    contador_clientes--;
                    textcolor(GREEN);
                    gotoxy(31, 23); cprintf("Cliente eliminado con exito!");
                    delay(1000);
                } else if (toupper(confirmacion) == 'N') {
                    textcolor(RED);
                    gotoxy(31, 23); cprintf("Eliminacion cancelada");
                    delay(1000);
                } else {
                    textcolor(RED);
                    gotoxy(31, 23); cprintf("Sin registro de respuesta");
                    delay(1000);
                }
                break;
            }
        }
        if (!encontrado) {
            textcolor(RED);
            gotoxy(29, 23); cprintf("Cliente no encontrado!");
            delay(1000);
        }
        textcolor(WHITE);
    }
}

void verCliente() {
    clrscr();
    if (contador_clientes == 0) {
        textcolor(RED);
        gotoxy(25, 12);
        cprintf("No hay clientes registrados.");
        delay(1000);
        textcolor(WHITE);
    } else {
        for (i_cliente = 0; i_cliente < contador_clientes; i_cliente++) {
            clrscr();
            textcolor(CYAN);
            gotoxy(24, 4); cprintf("---- Datos de los clientes ----");
            gotoxy(37, 6); cprintf("Cliente %d", i_cliente + 1);
            textcolor(LIGHTBLUE);
            gotoxy(35.5, 8); cprintf("Codigo: %s", clientes[i_cliente].codigo);
            gotoxy(35.5, 9); cprintf("Nombre: %s", clientes[i_cliente].nombre);
            gotoxy(35.5, 10); cprintf("Telefono: %s", clientes[i_cliente].telefono);
            gotoxy(35.5, 11); cprintf("Creditos: %d", clientes[i_cliente].creditos);
            gotoxy(35.5, 12); cprintf("Membresia: %s", clientes[i_cliente].membresia);
            textcolor(WHITE);
            gotoxy(25, 14); cprintf("Presiona una tecla para continuar -->");
            getch();
            textcolor(WHITE);
        }
    }
}

void venderProducto() {
    char nombre_comprador[50], nombre_producto[50];
    int cantidad_a_comprar, encontrado_cliente = 0, encontrado_producto = 0;
    float precio_total;
    int cliente_encontrado = 0, producto_encontrado = 0;
    int cliente_indice = -1, producto_indice = -1;

    clrscr();
    textcolor(CYAN);
    gotoxy(24, 4); cprintf("---- Vender producto ----");

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