
# Practica 2.5 Examen
## Analizar códigos de C++ con LEX


### Instrucciones:

Genera un analizador léxico en Flex para el lenguaje de programación C++ que identifique los siguientes tipos de TOKENS:

a. Palabras reservadas del LP 

b. Identificadores (variables)

c. Números enteros

d. Números flotantes, hexadecimales, binarios y octales

e. Cadenas de carácteres

f. Caracteres

g. Operadores

h. Separadores

i. Comentarios de una lìnea

j. Bloque de comentarios

La entrada de los códigos en C++ debe ser desde un archivo (por ejemplo, código.cpp) la salida debe presentarse en un archivo de nombre MyScanner.txt


## Explicacion de Comando

Iniciamos con la estructura general y añadi el FILE para declarar mi archivo de salida por el cual mis datos seran imprimidos en el cuerpo del codigo, ademas declaro yyin para poder leer un documento como entrada.
```
   %option noyywrap
%{
	#include<stdio.h>
	FILE *MyScanner;
	extern FILE *yyin;
%}
```
Reglas:

Cada regla mostrada termina con la sig estrictura que declara que si entra en los parametros imprime con fprintf dentro de el documento MyScanner el texto "X". El \n para que el sig valor este en la sig linea.

{ fprintf(MyScanner," x \n"); }

```
%%

[ \t\n]+                { }

\"([^\\\"]|\\.)*\"         { fprintf(MyScanner,"String\n"); }
\'([^\\\']|\\.)\'         { fprintf(MyScanner,"Char\n"); }

0[xX][0-9a-fA-F]+       { fprintf(MyScanner,"Hexadecimal\n"); }
0[bB][01]+              { fprintf(MyScanner,"Binario\n"); }
0[0-7]+                 { fprintf(MyScanner,"Octal\n"); }

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?	{ fprintf(MyScanner,"Flotante\n"); }
[0-9]+					{ fprintf(MyScanner,"Entero\n"); }

(int|float|double|char|void|if|else|switch|case|for|while|do|break|continue|return|class|struct|public|private|protected|new|delete|try|catch|throw|namespace|using)  { fprintf(MyScanner,"Palabra Reservada\n"); }

[a-zA-Z_][a-zA-Z0-9_]*  { fprintf(MyScanner,"Identificador\n");}

"++"  { fprintf(MyScanner,"Operador\n"); }
"--"  { fprintf(MyScanner,"Operador\n"); }
"=="  { fprintf(MyScanner,"Operador\n"); }
"!="  { fprintf(MyScanner,"Operador\n"); }
"<="  { fprintf(MyScanner,"Operador\n"); }
">="  { fprintf(MyScanner,"Operador\n"); }
"&&"  { fprintf(MyScanner,"Operador\n"); }
"||"  { fprintf(MyScanner,"Operador\n"); }
"<<"  { fprintf(MyScanner,"Operador\n"); }
">>"  { fprintf(MyScanner,"Operador\n"); }

"+="  { fprintf(MyScanner,"Operador\n"); }
"-="  { fprintf(MyScanner,"Operador\n"); }
"*="  { fprintf(MyScanner,"Operador\n"); }
"/="  { fprintf(MyScanner,"Operador\n"); }

"+"   { fprintf(MyScanner,"Operador\n"); }
"-"   { fprintf(MyScanner,"Operador\n"); }
"*"   { fprintf(MyScanner,"Operador\n"); }
"/"   { fprintf(MyScanner,"Operador\n"); }
"%"   { fprintf(MyScanner,"Operador\n"); }
"="   { fprintf(MyScanner,"Operador\n"); }
"<"   { fprintf(MyScanner,"Operador\n"); }
">"   { fprintf(MyScanner,"Operador\n"); }
"!"   { fprintf(MyScanner,"Operador\n"); }
"&"   { fprintf(MyScanner,"Operador\n"); }
"|"   { fprintf(MyScanner,"Operador\n"); }
"^"   { fprintf(MyScanner,"Operador\n"); }
"~"   { fprintf(MyScanner,"Operador\n"); }


(\(|\)|\{|\}|\[|\]|;|,|\.|:)  {fprintf(MyScanner,"Separador\n"); }

%%
```


### Cuerpo de Codigo
En nuestro main encontramos primero la declaracion del doc de entrada (.cpp), llamado EntradaDTS, el codigo declara al doc como fopen para abrirlo usando la ruta absolita, con su propia excepcion por si no lo encuentra y declara MyScanner de la misma manera con su excepcion.

luego hace el recorrido de simbolos del documento y los va imprimiendo en el documento de salida MyScanner, al final fclose() cierra los docimentos que abrimos en el programa.

```
int main() {
    FILE *EntradaDTS;

    EntradaDTS = fopen("C:/Flex Windows/EditPlusPortable/EntradaDTS.cpp", "r");
    if (EntradaDTS == NULL) {
        printf("No existe Entrada.cpp\n");
        return 1;
    }

    MyScanner = fopen("C:/Flex Windows/EditPlusPortable/MyScanner.txt", "w");
    if (MyScanner == NULL) {
        printf("No se pudo crear MyScanner.txt\n");
        return 1;
    }

    yyin = EntradaDTS;

    yylex();

    fclose(EntradaDTS);
    fclose(MyScanner);

    printf("Listo. Revisa MyScanner.txt\n");
	system("notepad MyScanner.txt");
    return 0;
    
}
```

## Resultado:


![Evidencia](https://imgur.com/a/GUTe2Ek)
https://imgur.com/a/GUTe2Ek

## CODIGO EN YYLEX

```

%option noyywrap
%{
	#include<stdio.h>
	FILE *MyScanner;
	extern FILE *yyin;
%}

%%

[ \t\n]+                { }

\"([^\\\"]|\\.)*\"         { fprintf(MyScanner,"String\n"); }
\'([^\\\']|\\.)\'         { fprintf(MyScanner,"Char\n"); }

0[xX][0-9a-fA-F]+       { fprintf(MyScanner,"Hexadecimal\n"); }
0[bB][01]+              { fprintf(MyScanner,"Binario\n"); }
0[0-7]+                 { fprintf(MyScanner,"Octal\n"); }

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?	{ fprintf(MyScanner,"Flotante\n"); }
[0-9]+			{ fprintf(MyScanner,"Entero\n"); }

(int|float|double|char|void|if|else|switch|case|for|while|do|break|continue|return|class|struct|public|private|protected|new|delete|try|catch|throw|namespace|using)  { fprintf(MyScanner,"Palabra Reservada\n"); }

[a-zA-Z_][a-zA-Z0-9_]*  { fprintf(MyScanner,"Identificador\n");}

"++"  { fprintf(MyScanner,"Operador\n"); }
"--"  { fprintf(MyScanner,"Operador\n"); }
"=="  { fprintf(MyScanner,"Operador\n"); }
"!="  { fprintf(MyScanner,"Operador\n"); }
"<="  { fprintf(MyScanner,"Operador\n"); }
">="  { fprintf(MyScanner,"Operador\n"); }
"&&"  { fprintf(MyScanner,"Operador\n"); }
"||"  { fprintf(MyScanner,"Operador\n"); }
"<<"  { fprintf(MyScanner,"Operador\n"); }
">>"  { fprintf(MyScanner,"Operador\n"); }

"+="  { fprintf(MyScanner,"Operador\n"); }
"-="  { fprintf(MyScanner,"Operador\n"); }
"*="  { fprintf(MyScanner,"Operador\n"); }
"/="  { fprintf(MyScanner,"Operador\n"); }

"+"   { fprintf(MyScanner,"Operador\n"); }
"-"   { fprintf(MyScanner,"Operador\n"); }
"*"   { fprintf(MyScanner,"Operador\n"); }
"/"   { fprintf(MyScanner,"Operador\n"); }
"%"   { fprintf(MyScanner,"Operador\n"); }
"="   { fprintf(MyScanner,"Operador\n"); }
"<"   { fprintf(MyScanner,"Operador\n"); }
">"   { fprintf(MyScanner,"Operador\n"); }
"!"   { fprintf(MyScanner,"Operador\n"); }
"&"   { fprintf(MyScanner,"Operador\n"); }
"|"   { fprintf(MyScanner,"Operador\n"); }
"^"   { fprintf(MyScanner,"Operador\n"); }
"~"   { fprintf(MyScanner,"Operador\n"); }


(\(|\)|\{|\}|\[|\]|;|,|\.|:)  {fprintf(MyScanner,"Separador\n"); }

%%


int main() {
    FILE *EntradaDTS;

    EntradaDTS = fopen("C:/Flex Windows/EditPlusPortable/EntradaDTS.cpp", "r");
    if (EntradaDTS == NULL) {
        printf("No existe Entrada.cpp\n");
        return 1;
    }

    MyScanner = fopen("C:/Flex Windows/EditPlusPortable/MyScanner.txt", "w");
    if (MyScanner == NULL) {
        printf("No se pudo crear MyScanner.txt\n");
        return 1;
    }

    yyin = EntradaDTS;

    yylex();

    fclose(EntradaDTS);
    fclose(MyScanner);

    printf("Listo. Revisa MyScanner.txt\n");
	system("notepad MyScanner.txt");
    return 0;
    
}
```
