#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"
#include "hash.h"

#include "yn.h"

int get_hash(char* str) {
	unsigned int BKDRHash(char* str);
	return BKDRHash(str) % 23767;
}



int write_line(FileHandler* file_handler, char* str) {


	//if the file is not under the writing status
	if (file_handler->open_status != 2) {
		return 0;
	}
	file_handler->point++;
    
    //di
	*(file_handler->buffer + file_handler->point) = 0xB5;
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0xDA;
	
    //convert the numbers to be auto-changed
	char target[20];//we have 6306 numbers
	static int num = 1;//numbers will change
	char* t = target;
	sprintf(target,"%d",num);

	while (*t != 0) {
		file_handler->point++;
		*(file_handler->buffer + file_handler->point) = *t;
        t++ ;
	}
    num++;

    //hang:
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0xD0;
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0xD0;
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0x3A;
	//���ַ���д�뻺������
	
    while (*str != 0) {

		file_handler->point++;
		*(file_handler->buffer + file_handler->point) = *str;
		str++;
	}
	//���뻻�з�
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 10;

	return 0;
}
