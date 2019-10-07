#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>



struct student
{
	char fam[255], name[255];
	int klassNumber;
	char klassLetter;
} stud;
char a;

int k = 0, k1 = 0, i = 0, k2 = 0, s = 0;
FILE* f1;
char s3[255], s1[255], s2[255], s4[255], s5[255], s6[255], s7[255], s8[255];

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	f1 = fopen("f1.txt", "w+");
	setlocale(LC_ALL, "Russian");
	do {
		k++;
		puts("Введите Фамилию");
		scanf("%s", (stud.fam));
		fprintf(f1, "%s", stud.fam);
		fprintf(f1, "%s", " ");
		puts("Введите имя");
		scanf("%s", (stud.name));
		fprintf(f1, "%s", stud.name);
		fprintf(f1, "%s", " ");
		puts("Введите класс (цифру)");
		scanf("%d", &(stud.klassNumber));
		fprintf(f1, "%d", (stud.klassNumber));
		fprintf(f1, "%s", " ");
		puts("Введите класс (букву)");
		while (getchar() != '\n');
		scanf("%c", &(stud.klassLetter));
		fprintf(f1, "%c", (stud.klassLetter));
		fprintf(f1, "\n");
		while (getchar() != '\n');
		puts("Если вы хотите продолжить ввод нажмите 'z',если хотите завершить ввод нажмите любую кнопку ");
		scanf("%c", &a);
		if (a != 'z') break;

	} while ((a == 'z') || (a == 'Z'));

	fseek(f1, 0, 0);

	for (int i = 0; i < k; i++)
	{
		fseek(f1, s, 0);
		fscanf(f1, "%s%s%s%s", &s1, &s2, &s3, &s4);
		s = (strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4));
		for (int j = i; j < k + 1; j++) {
			fscanf(f1, "%s%s%s%s", &s5, &s6, &s7, &s8);
			if ((strcmp(s1, s5) == 0) && ((strcmp(s4, s8) == 0)) && ((strcmp(s3, s7) == 0))) k1++;
		}
	}
	if (k1 == 0)puts(" No");
	else
		puts(" Yes");
	fclose(f1);
	system("pause");
}