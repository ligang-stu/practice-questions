#define _CRT_SECURE_NO_WARNINGS
#include "manage.h"

void add()
{
	if (number == 50)
	{
		printf("�ͻ��������޷���ӡ�");
		return;
	}
	printf("\n--------------��ӿͻ�--------------");
	custmoer[number].id = number+1;
	printf("\n������");
	scanf("%s", custmoer[number].name);
	getchar();
	
	printf("\n�Ա�");
	scanf("%s", custmoer[number].gender);
	getchar();

	printf("\n���䣺");
	scanf("%d", &custmoer[number].age);
	getchar();
	
	printf("\n�绰��");
	scanf("%s", custmoer[number].tel);
	getchar();
	
	printf("\n���䣺");
	scanf("%s", custmoer[number].email);
	getchar();

	number++;
	
	printf("\n--------------������--------------\n");
}

void list() {
	printf("\n--------------�ͻ��б�--------------");
	printf("\n���\t����\t�Ա�\t����\t�绰\t����");
	for (int i = 0; i < number;i++) {
		printf("\n%d\t%s\t%s\t%d\t%s\t%s",custmoer[i].id, custmoer[i].name, custmoer[i].gender, custmoer[i].age, custmoer[i].tel, custmoer[i].email);
	}
	printf("\n");
}

void del() {
	printf("\n--------------ɾ���ͻ�--------------");
	int id;
out:printf("\n������Ҫɾ���ͻ���id(-1�˳�):");
	scanf("%d",&id);
	getchar(); // ���������
	if (id == -1)
	{
		return 0;
	}
	if (id > number || id <= 0)
	{
		printf("��Ų����ڣ�����������");
		goto out;
	}
	char ch;
	printf("\nȷ���Ƿ�ɾ����Y/N����");
	scanf("%c", &ch);
	getchar(); // ���������
	if (ch == 'Y' || ch == 'y')
	{
		int index = id - 1;
	
		
		for (int i = index; i < number - 1; i++)
		{
			custmoer[i] = custmoer[i + 1];
			custmoer[i].id--;
		}
		number--;
		printf("\n--------------ɾ���ɹ�--------------\n");
	}
	else
		printf("\n�������ɾ����\n");
}


void edit(int id)
{
		int index = id -1;
		// �����ַ����洢���뻺����
		char input[20];
		// �޸�����
		printf("\n ����(%s):", custmoer[index].name);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input,"%s", custmoer[index].name);
		}
		// �޸��Ա�
		printf("\n �Ա�(%s):", custmoer[index].gender);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].gender);
		}
		// �޸�����
		printf("\n ����(%d):", custmoer[index].age);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%d", &custmoer[index].age);
		}
		// �޸ĵ绰
		printf("\n �绰(%s):", custmoer[index].tel);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].tel);
		}
		// �޸�����
		printf("\n ����(%s):", custmoer[index].email);
		fgets(input, sizeof(input), stdin);
		if (input[0] != '\n')
		{
			sscanf(input, "%s", custmoer[index].email);
		}
		printf("\n---------------�޸����---------------\n");
}
void modify() {
	printf("\n--------------�޸Ŀͻ�--------------");
	int id;
out:printf("\n��ѡ���޸Ŀͻ��ı�ţ�-1�˳�����");
	scanf("%d", &id);
	getchar();

	if (id == -1)
		return 0;
	if (id > number || id <= 0)
	{
		printf("��Ų����ڣ�����������");
		goto out;
	}
	edit(id);
}