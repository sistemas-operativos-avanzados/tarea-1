Tarea 1: Rastreador de _System Calls_
=====================================

## Tabla de contenidos
* [Descripción](#descripción)
* [Construcción](#construcción)
* [Ejecución](#ejecución)
  * [Ejemplo 1: llamando a `cal`](#ejemplo-1-llamando-al-programa-cal)
  * [Ejemplo 2: llamando a `ls -lath`](ejemplo-2-llamado-a-programa-ls-con-las-opciones--laht)
* [Bibliografía](#bibliografía)


## Descripción
[Volver arriba](#tabla-de-contenidos)  
Programa que rastrea todas las llamadas al sistema de un programa y las presenta en una tabla acumulada en el _standard output_.
Opciones:
* `-v` muestra todos las llamadas al sistema de un programa
* `-V` "modo interactivo". Se debe de presionar cualquier teclas antes de obtener todas las llamadas al sistema de un programa.

## Construcción
[Volver arriba](#tabla-de-contenidos)  

```bash
> make
```

La ejecución de `make` va a realizar los siguientes pasos:  
1. Compilacion de archivos fuente bajo la carpet `src/`  
2. Crea la carpeta `target/` en donde se van a dejar los archivos resultantes del proceso de compilacion (objeto, ejecutable)


## Ejecución
[Volver arriba](#tabla-de-contenidos)  

```bash
> target/rastreador [opciones] Prog [opciones de Prog]

```

### Ejemplo 1: llamando al programa `cal`.
[Volver arriba](#tabla-de-contenidos)  

```bash
> target/rastreador -v cal 


   February 2017      
Su Mo Tu We Th Fr Sa  
          1  2  3  4  
 5  6  7  8  9 10 11  
12 13 14 15 16 17 18  
19 20 21 22 23 24 25  
26 27 28              
                      
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  -nan    0.000000           0         7           read
  -nan    0.000000           0         8           write
  -nan    0.000000           0         8           open
  -nan    0.000000           0         8           close
  -nan    0.000000           0         4         1 stat
  -nan    0.000000           0        10           fstat
  -nan    0.000000           0         2         1 lseek
  -nan    0.000000           0        18           mmap
  -nan    0.000000           0         8           mprotect
  -nan    0.000000           0         3           munmap
  -nan    0.000000           0         3           brk
  -nan    0.000000           0         5           ioctl
  -nan    0.000000           0         6         5 access
  -nan    0.000000           0         1           execve
  -nan    0.000000           0         1           arch_prctl
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    92         7 total

```

### Ejemplo 2: llamado a programa `ls` con las opciones `-laht`
[Volver arriba](#tabla-de-contenidos)  
 
```bash
target/rastreador -v ls -laht

total 36K
drwxr-xr-x 1 vagrant vagrant  272 Feb 25 20:44 .idea
drwxr-xr-x 1 vagrant vagrant  544 Feb 25 20:41 .git
drwxr-xr-x 1 vagrant vagrant  408 Feb 25 20:41 .
-rw-r--r-- 1 vagrant vagrant 2.0K Feb 25 20:41 README.md
drwxr-xr-x 1 vagrant vagrant  102 Feb 25 20:39 src
drwxr-xr-x 1 vagrant vagrant  136 Feb 25 20:34 target
drwxr-xr-x 6 vagrant vagrant 4.0K Feb 25 19:29 ..
-rw-r--r-- 1 vagrant vagrant  14K Feb 17 02:38 demo.json
drwxr-xr-x 1 vagrant vagrant  238 Feb 16 00:18 cmake-build-debug
-rw-r--r-- 1 vagrant vagrant  194 Feb 16 00:17 CMakeLists.txt
-rw-r--r-- 1 vagrant vagrant   50 Feb 16 00:01 .gitignore
-rw-r--r-- 1 vagrant vagrant  546 Feb 16 00:01 Makefile
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
100.00    0.000201          15        13           write
  0.00    0.000000           0        19           read
  0.00    0.000000           0        29         7 open
  0.00    0.000000           0        29           close
  0.00    0.000000           0        11           stat
  0.00    0.000000           0        24           fstat
  0.00    0.000000           0        12           lstat
  0.00    0.000000           0         5           lseek
  0.00    0.000000           0        43           mmap
  0.00    0.000000           0        24           mprotect
  0.00    0.000000           0        10           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           rt_sigaction
  0.00    0.000000           0         1           rt_sigprocmask
  0.00    0.000000           0         2           ioctl
  0.00    0.000000           0        13        13 access
  0.00    0.000000           0         4           socket
  0.00    0.000000           0         4         4 connect
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2           getdents
  0.00    0.000000           0         1           getrlimit
  0.00    0.000000           0         1           statfs
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0        25        25 lgetxattr
  0.00    0.000000           0         1         1 futex
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0         1           openat
  0.00    0.000000           0         1           set_robust_list
------ ----------- ----------- --------- --------- ----------------
100.00    0.000201                   283        50 total
``` 

## Demo
[Volver arriba](#tabla-de-contenidos)  
[![asciicast](https://asciinema.org/a/49jms7rs12c7u6yohx2lopy62.png)](https://asciinema.org/a/49jms7rs12c7u6yohx2lopy62?autoplay=1)

## Bibliografía
[Volver arriba](#tabla-de-contenidos)   

Griffiths Dawn, Griffiths David. _**Head First C**_.  O'Reilly Media, Inc. Apéndice A: _Tracing System Calls_. 2012.   

Kerrisk Michaeil, _**The Linux Programming Interface**_. No Starch Press, 2010

Matthew Neil, Stones Richard. _**Beginning Linux Programming**_. Wiley Publishing, Inc. Cuarta Edidión. Capítulo 5: _Terminals_. 2008.
