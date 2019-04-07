/* Name : common.h	ver 1.0
 * Content : main �Լ�
 * ���α׷� ������� �Է��� �ް� �׿� ���� ó����
 * ����ϵ��� ����
 * Implementation : YHS
 *
 * Last modified 2018 / 01 / 05
 */

#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

/* �Լ� : int main(void
 * ��� : ����� ���� ó��
 * ��ȯ : ���� ���� �� 0)
 */

enum {INPUT=1 , SHOWALL, SEARCH, DELETE, CHANGE, QUIT};
int main(){

	int inputMenu = 0;

	while (1){
		ShowMenu(); //ȭ�鿡 �޴��� ǥ��
		scanf("%d", &inputMenu);
		fflush(stdin);
		
		switch (inputMenu){
		case INPUT :
			InputPhoneData();
			break;
		case SHOWALL :
			ShowAllData();
			break;
		case SEARCH :
			SearchPhoneData();
			break;
		case DELETE :
			DeletePhoneData();
			break;
		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT){
			puts("�̿��� �ּż� �����մϴ�.");
			break;
		}
	}

	return 0;
}