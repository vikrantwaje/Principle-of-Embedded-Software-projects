#My project's readme
Project 2
This project consists of operating the UART module of FRDM KL25z by configuring its register and then operating the UART with help of transmit and receive interrupt which is implemented using UART0 IRQ handler.
Also, this project consists of implementing circular buffer and integrating it with UART module. Various circular buffer operations such as Buffer full, buffer empty, buffer add and buffer remove are implemented in program.
 Finally, to test the to check the correctness of program, cmocka uint framework testing has been done to verify the same.
 The uart folder contains the actual implemetation of circular buffer and uart modules.
 The src folder contains the cmocka and makefile.