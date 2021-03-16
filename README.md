# Interactive Menu

## Description
Menu de opciones de cmd desarrollado con C++.
Parece una aplicacion sencilla pero por dentro se mezclan profundos conceptos de POO y manejo de punteros.

## Inside the Project
Por dentro la clase `Menu` contiene un _vector_, en el sentido de C++, cada elemento de ese vector almacena un puntero a una estructura con un atributo _texto_, el cual representa la cadena de caracteres de un item, y un atributo _toDo_, que no es mas que un puntero a una funcion que determina el comportamiento a realizar del item en cuestion.
El `Menu`, se encarga de manejar su dibujado en pantalla y la interaccion con el cursor.

## Execution
Para probar el programa se puede descargar el archivo `menu_test.exe` o bien clonar el repositorio de manera local (en una pc con sistema operativo Windows) y luego desde el `cmd` ejecuta el script:

```bash
# compilation
C:/> make
```

Este comando compilara el codigo entero de los archivos de los directorios del proyecto, generando un archivo `menu_test.exe` y ejecutandolo automaticamente una vez que termine la compilacion.

## Stay in touch

- Author (this project) - [Facundo Conci](https://www.linkedin.com/in/facundo-ignacio-conci-caceres/)