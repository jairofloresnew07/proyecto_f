#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>
#include <jai.h>

void eliminarProducto();
void verProducto();
void actualizarProducto();
void actualizarCliente();
void eliminarCliente();
void verCliente();
void venderProducto();
int main() {
	clrscr();

    textcolor(WHITE);
    gotoxy(24, 4); cprintf("Bienvenido a la isla Paradise\n");
    gotoxy(20, 8); cprintf("Para continuar, se debe iniciar sesion.\n");
    delay(1000);
    gotoxy(20, 8); cprintf("                                       \r");
    gotoxy(31, 9); cprintf("Iniciar Sesion");

    while (intentos < 3) {
        textcolor(WHITE);
        gotoxy(35, 12); cprintf("Usuario");
        gotoxy(35, 13); cprintf("-------");
        gotoxy(34, 18); cprintf("Contrasena");
        gotoxy(34, 19); cprintf("----------");

        gotoxy(25, 14);
        for (i = 0; i < ancho; i++) {
            textcolor(WHITE);
            cprintf("* ");
        }
        cprintf("\n");

        gotoxy(25, 15);
        for (i = 0; i < alto - 2; i++) {
            textcolor(WHITE);
            cprintf("* ");
            for (j = 0; j < ancho - 2; j++) {
                cprintf("  ");
            }
            textcolor(WHITE);
            cprintf("* \n");
        }

        gotoxy(25, 16);
        for (i = 0; i < ancho; i++) {
            textcolor(WHITE);
            cprintf("* ");
        }
        cprintf("\n");
        gotoxy(27, 15); scanf("%s", usuario);

        gotoxy(25, 20);
        for (i = 0; i < ancho; i++) {
            textcolor(WHITE);
            cprintf("* ");
        }
        cprintf("\n");

        gotoxy(25, 21);
        for (i = 0; i < alto - 2; i++) {
            textcolor(WHITE);
            cprintf("* ");
            for (j = 0; j < ancho - 2; j++) {
                cprintf("  ");
            }
            textcolor(WHITE);
            cprintf("* \n");
        }

        gotoxy(25, 22);
        for (i = 0; i < ancho; i++) {
            textcolor(WHITE);
            cprintf("* ");
        }
        cprintf("\n");
        gotoxy(27, 21); scanf("%s", contrasena);

        if (strcmp(usuario, upre) == 0 && strcmp(contrasena, cpre) == 0) {
            gotoxy(28, 24);
            textcolor(GREEN);
            cprintf("<<< Acceso concedido >>>");
            delay(1000);
            clrscr();
            menu_principal:
            textcolor(WHITE);
            gotoxy(25, 4); cprintf("Has accedido al historial Paradise");
            gotoxy(22, 6); cprintf("Selecciona la opcion que deseas realizar");
            gotoxy(22, 8); cprintf("1. Inventario");
            gotoxy(22, 9); cprintf("2. Clientes");
            gotoxy(22, 10); cprintf("3. Ayuda");
            gotoxy(22,11); cprintf("4. Salir");
            gotoxy(22, 12); cprintf("Opcion: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    do {
                        clrscr();
                        textcolor(WHITE);
                        gotoxy(33, 4); cprintf("Menu de Inventario");
                        gotoxy(22, 6); printf("Selecciona la opcion que deseas realizar");
                        gotoxy(22, 8); cprintf("1. Agregar");
                        gotoxy(22, 9); cprintf("2. Buscar");
                        gotoxy(22, 10); cprintf("3. Eliminar");
                        gotoxy(22, 11); cprintf("4. Ver");
                        gotoxy(22, 12); cprintf("5. Actualizar");
                        gotoxy(22, 13); cprintf("6. Vender");
                        gotoxy(22, 14); cprintf("7. Volver");
                        gotoxy(22, 16); cprintf("Opcion: ");
                        scanf("%d", &subopcion);

                        switch (subopcion) {
                            case 1:
                                clrscr();
                                textcolor(CYAN);
                                gotoxy(24, 4); cprintf("---- Acceso para agregar productos ----");

                                if (contador_productos < MAX_PRODUCTOS) {
                                    do {
                                        textcolor(BLUE);
                                        gotoxy(24, 8); cprintf("Cantidad del producto: ");
                                        if (scanf("%d", &cantidad) != 1 || cantidad < 1 || cantidad > 100) {
                                            gotoxy(28, 20);
                                            textcolor(RED);
                                            cprintf("<<< Entrada incorrecta >>>\n");
                                            delay(1000);
                                            gotoxy(28, 20); cprintf("                                           \r");
                                            while (getchar() != '\n');
                                        } else {
                                            break;
                                        }

                                    } while (1);

                                    do {
                                        gotoxy(24, 10); cprintf("Codigo de producto: ");
                                        scanf("%s", codep);

                                        if (codep[0] == '#' && strlen(codep) == 5 &&
                                            isdigit(codep[1]) && isdigit(codep[2]) &&
                                            isdigit(codep[3]) && isdigit(codep[4])) {
                                            codev = 1;
                                        } else {
                                            gotoxy(28, 20);
                                            textcolor(RED);
                                            cprintf("<<< Codigo no verificado >>>\n");
                                            delay(1000);
                                            gotoxy(28, 20); cprintf("                                           \r");
                                            textcolor(BLUE);
                                        }

                                    } while (!codev);

                                    do {
                                        gotoxy(24, 12); cprintf("Precio del producto: ");
                                        if (scanf("%f", &precio) != 1 || precio < 1) {
                                            gotoxy(28, 20);
                                            textcolor(RED);
                                            cprintf("<<< Inserta un precio valido >>>\n");
                                            delay(1000);
                                            gotoxy(28, 20); cprintf("                                           \r");
                                            while (getchar() != '\n');
                                            textcolor(BLUE);
                                        } else {
                                            break;
                                        }

                                    } while (1);

                                    do {
                                        gotoxy(24, 14); cprintf("Nombre del producto: ");
                                        while (getchar() != '\n');
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
                                            gotoxy(28, 20); cprintf("                                           \r");
                                            textcolor(BLUE);
                                        }

                                    } while (1);

                                    gotoxy(24, 16); cprintf("Descripcion del producto: ");
                                    fgets(descripcion, sizeof(descripcion), stdin);
                                    descripcion[strcspn(descripcion, "\n")] = '\0';

                                    productos[contador_productos].cantidad = cantidad;
                                    strcpy(productos[contador_productos].codigo, codep);
                                    productos[contador_productos].precio = precio;
                                    strcpy(productos[contador_productos].nombre, nombre_producto);
                                    strcpy(productos[contador_productos].descripcion, descripcion);

                                    contador_productos++;

                                    gotoxy(28, 23);
                                    textcolor(GREEN);
                                    cprintf("Producto agregado con exito!\n");
                                    delay(1000);
                                    textcolor(WHITE);
                                } else {
                                    textcolor(RED);
                                    gotoxy(28, 20);
                                    cprintf("<<< Limite de productos alcanzado >>>\n");
                                    delay(1000);
                                }
                                break;

                            case 2:
                                clrscr();
                                textcolor(CYAN);
                                gotoxy(26, 4); cprintf("---- Busqueda de productos ----");

								textcolor(BLUE);
								getchar();
								gotoxy(16, 8); cprintf("Deseas buscar el producto por (C)odigo o (N)ombre: ");
                                tipo_busqueda = getchar();

                                if (toupper(tipo_busqueda) == 'C') {
									gotoxy(16, 10); cprintf("Ingrese el codigo del producto: ");
                                    scanf("%s", codep);
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
                                    scanf("%s", nombre_producto);
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
                                break;
                                textcolor(WHITE);

                            case 3:
                                eliminarProducto();
                                break;
                            case 4:
                                verProducto();
                                break;
                            case 5:
                                actualizarProducto();
                                break;
                            case 6:
                                venderProducto();
                                break;
							case 7:
								clrscr();
                                goto menu_principal;
                                break;
							default:
                                break;
                        }
					} while (subopcion != 7);
                    break;

                case 2:
                    do {
                        clrscr();
                        textcolor(WHITE);
                        gotoxy(33, 4); cprintf("Menu de Clientes");
                        gotoxy(22, 6); cprintf("Selecciona la opcion que deseas realizar");
                        gotoxy(22, 8); cprintf("1. Agregar");
                        gotoxy(22, 9); cprintf("2. Buscar");
                        gotoxy(22, 10); cprintf("3. Actualizar");
                        gotoxy(22, 11); cprintf("4. Eliminar");
                        gotoxy(22, 12); cprintf("5. Ver");
                        gotoxy(22, 13); cprintf("6. Volver");
                        gotoxy(22, 15); cprintf("Opcion: ");
                        scanf("%d", &subopcion);

                        switch (subopcion) {
                            case 1:
                                clrscr();
                                textcolor(CYAN);
                                gotoxy(24, 4); cprintf("---- Agregar cliente ----");

                                do {
                                    textcolor(BLUE);
                                    gotoxy(24, 8); cprintf("Nombre del cliente: ");

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
                                        break;
                                    } else {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("<<< Nombre invalido, usa solo letras y espacios >>>\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                           \r");
                                    }
                                } while (!valido);

                                do {
                                    textcolor(BLUE);
                                    gotoxy(24, 10); cprintf("Codigo de cliente: ");

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
                                                if (strcmp(clientes[i].codigo, codigo_cliente) == 0) {
                                                    codigo_repetido = 1;
                                                    break;
                                                }
                                            }
                                            if (codigo_repetido) {
                                                gotoxy(28, 20);
                                                textcolor(RED);
                                                cprintf("<<< Codigo ya registrado, usa otro >>>\n");
                                                delay(1000);
                                                gotoxy(28, 20); cprintf("                                                    \r");
                                            } else {
                                                break;
                                            }
                                        } else {
                                            gotoxy(28, 20);
                                            textcolor(RED);
                                            cprintf("<<< Codigo invalido, debe ser # seguido de 4 letras >>>\n");
                                            delay(1000);
                                            gotoxy(28, 20); cprintf("                                                    \r");
                                        }
                                    } else {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("<<< Codigo invalido, debe ser # seguido de 4 letras >>>\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                                    \r");
                                    }
                                } while (1);

                                do {
                                    textcolor(BLUE);
                                    gotoxy(24, 12); cprintf("Telefono del cliente: ");
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
                                        break;
                                    } else {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("<<< Telefono invalido, debe tener 8 digitos numericos >>>\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                                         \r");
                                    }
                                } while (!valido_telefono);

                                do {
                                    textcolor(BLUE);
                                    gotoxy(24, 14); cprintf("Tienes creditos? (S/N): ");
                                    scanf(" %c", &respuesta);

                                    if (respuesta == 'S' || respuesta == 's') {
                                        do {
                                            textcolor(BLUE);
                                            gotoxy(24, 16); cprintf("Cantidad de creditos: ");
                                            if (scanf("%d", &creditos) != 1 || creditos <= 1) {
                                                gotoxy(28, 20);
                                                textcolor(RED);
                                                cprintf("<<< La cantidad debe ser un numero mayor a 1 >>>\n");
                                                delay(1000);
                                                gotoxy(28, 20); cprintf("                                                \r");
                                                while (getchar() != '\n');
                                            } else {
                                                creditos += 100;
                                                break;
                                            }
                                        } while (1);
                                    } else if (respuesta == 'N' || respuesta == 'n') {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("Ve por tus compras de creditos.\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                               \r");
                                        creditos = 100;
                                    } else {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("<<< Respuesta invalida, por favor ingresa S o N >>>\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                                  \r");
                                        continue;
                                    }
                                    clientes[contador_clientes].creditos = creditos;
                                    break;
                                } while (1);

                                do {
                                    textcolor(BLUE);
                                    gotoxy(24, 18); cprintf("Membresia (A. VIP B. PREMIUM C. ALPHA D. NINGUNA): ");
                                    scanf(" %c", &membresia);

                                    membresia = toupper(membresia);

                                    if (membresia == 'A' || membresia == 'B' || membresia == 'C' || membresia == 'D') {
                                        switch (membresia) {
                                            case 'A':
                                                strcpy(clientes[contador_clientes].membresia, "VIP");
                                                break;
                                            case 'B':
                                                strcpy(clientes[contador_clientes].membresia, "PREMIUM");
                                                break;
                                            case 'C':
                                                strcpy(clientes[contador_clientes].membresia, "ALPHA");
                                                break;
                                            case 'D':
                                                strcpy(clientes[contador_clientes].membresia, "NO EXISTENTE");
                                                break;
                                        }
                                        break;
                                    } else {
                                        gotoxy(28, 20);
                                        textcolor(RED);
                                        cprintf("<<< Opcion invalida, ingresa A, B, C o D >>>\n");
                                        delay(1000);
                                        gotoxy(28, 20); cprintf("                                                  \r");
                                    }
                                } while (1);


                                strcpy(clientes[contador_clientes].codigo, codigo_cliente);
                                strcpy(clientes[contador_clientes].nombre, nombre_cliente);
                                strcpy(clientes[contador_clientes].telefono, telefono_cliente);
                                if (creditos > 1) {
                                    clientes[contador_clientes].creditos = creditos;
                                }
                                contador_clientes++;
                                gotoxy(28, 23);
                                textcolor(GREEN);
                                cprintf("Cliente agregado con exito!\n");
                                delay(1000);
                                break;

                            case 2:
                                clrscr();
                                textcolor(CYAN);
                                gotoxy(26, 4); cprintf("---- Busqueda de clientes ----");

                                textcolor(BLUE);
                                getchar();
                                gotoxy(16, 8); cprintf("Deseas buscar el cliente por (C)odigo o (N)ombre: ");
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
                                            gotoxy(31, 18); cprintf("Creditos: %d", clientes[i_cliente].creditos);
                                            gotoxy(31, 19); cprintf("Membresia: %s", clientes[i_cliente].membresia);
                                            getch();
                                            textcolor(WHITE);
                                            break;
                                        }
                                    }
                                    if (!encontrado) {
                                        textcolor(RED);
                                        gotoxy(29, 23); cprintf("Cliente no encontrado!");
                                        delay(1000);
                                        textcolor(WHITE);
                                    }
                                } else if (toupper(tipo_busqueda) == 'N') {
                                    gotoxy(16, 10); cprintf("Ingrese el nombre del cliente: ");
                                    getchar();
                                    fgets(nombre_cliente, sizeof(nombre_cliente), stdin);
                                    nombre_cliente[strcspn(nombre_cliente, "\n")] = '\0';
                                    encontrado = 0;

                                    for (i_cliente = 0; i_cliente < contador_clientes; i_cliente++) {
                                        if (strstr(clientes[i_cliente].nombre, nombre_cliente) != NULL) {
                                            encontrado = 1;
                                            textcolor(GREEN);
                                            gotoxy(31, 13); cprintf("Cliente encontrado!");
                                            textcolor(LIGHTBLUE);
                                            gotoxy(31, 15); cprintf("Nombre: %s", clientes[i_cliente].nombre);
                                            gotoxy(31, 16); cprintf("Codigo: %s", clientes[i_cliente].codigo);
                                            gotoxy(31, 17); cprintf("Telefono: %s", clientes[i_cliente].telefono);
                                            gotoxy(31, 18); cprintf("Creditos: %d", clientes[i_cliente].creditos);
                                            gotoxy(31, 19); cprintf("Membresia: %s", clientes[i_cliente].membresia);
                                            getch();
                                            textcolor(WHITE);
                                            break;
                                        }
                                    }
                                    if (!encontrado) {
                                        textcolor(RED);
                                        gotoxy(29, 23); cprintf("Cliente no encontrado!");
                                        delay(1000);
                                        textcolor(WHITE);
                                    }
                                } else {
                                    textcolor(RED);
                                    gotoxy(29, 23); cprintf("Sin registro de busqueda");
                                    textcolor(WHITE);
                                }
                                delay(1000);
                                break;


                            case 3:
							   actualizarCliente();
                               break;
                            case 4:
                                eliminarCliente();
                                break;
                            case 5:
                                verCliente();
                                break;
                            case 6:
                                clrscr();
                                goto menu_principal;
                                break;
                            default:
                                gotoxy(22, 14);
                                cprintf("Opcion invalida");
                                break;
                        }
                    } while (subopcion != 6);
                    break;
                case 3:
                    clrscr();                
                    cprintf("---- Formato paradise ----");
                    break;
                case 4:
                    cprintf("Adios");
                    break;
                default:
                    gotoxy(25, 14);
                    cprintf("Opcion invalida");
                    break;
            }
            delay(1000);
            break;
        } else {
            textcolor(RED);
            gotoxy(21, 24);
            cprintf("<<< Usuario o contrasena invalida >>>");
            delay(1000);
            gotoxy(21, 24);
            cprintf("                                     \r");
            intentos++;
        }

        if (intentos >= 3) {
            textcolor(YELLOW);
            gotoxy(25, 24);
            cprintf("Llegaste al maximo de intentos");
            gotoxy(30, 25);
            cprintf("Intenta mas tarde");
        }
    }

    getch();
    clrscr();
    return 0;
}