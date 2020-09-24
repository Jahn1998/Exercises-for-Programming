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

	//���ļ������Ͳ���д�����ͣ�������д��
	if (file_handler->open_status != 2) {
		return 0;
	}
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0xB5;
	file_handler->point++;
	*(file_handler->buffer + file_handler->point) = 0xDA;
	

	char bb[20];
	static int b = 1;
	char* d = bb;
	sprintf(bb,"%d",b);

	while (*d != 0) {
		file_handler->point++;
		*(file_handler->buffer + file_handler->point) = *d;
		d++ ;
	}
	b++;

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
