#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 15
#define maxnum 1000
 
typedef struct {
	char Student_ID[maxsize];
	char Name[maxsize];
	char Class_Number[maxsize];
	char Attandance_date[maxsize];
	char Attandance_Result[maxsize];
} student;
 
student Students[maxnum];
 
int num = 0;
char buf[maxsize];
/*ʵ��ÿ����������������س��˳��Ĺ��ܣ����õ�ʵ�����û��Ľ��� */
void wait_for_Enter() {
	getchar();
	getchar();
}
/*Ϊ��ʵ�ֶ����ڽ��������ҵ��뷨�Ƕ����·ݣ�ֱ����atoi��ȡ����ת�����·ݣ���������������Ҫ�����º�������*/
int convert(char str[]) {
	int i,res = 0, cnt = 0;
	for (i = strlen(str) - 3; i >= 0; i--) {
		if (str[i] >= '0'&&str[i] <= '9') res *= 10, res += (str[i] - '0');
		else break;
	}
	return res;//����������Ҳ����һ���еĵڼ��죬����11��5�գ����صľ���5;5��23�գ����صľ���23
}
/*�ú���ʵ�ֵ��ǰ�student���ͱ���b��������Ϣ����student���͵ı���a*/
void copy(student *a,student *b) {
	strcpy_s(a->Student_ID ,20,b->Student_ID);
	strcpy_s(a->Name ,20,b->Name);
	strcpy_s(a->Class_Number ,20,b->Class_Number);
	strcpy_s(a->Attandance_Result ,20, b->Attandance_Result);
	strcpy_s(a->Attandance_date ,20,b->Attandance_date);
}
/*�˺�����������ʵ�ֶ��Ѵ��ڵ�ѧ�������ٴ���ӵ�����*/
int judge(char *ID) {
	int i;
	for (i = 0; i < num; i++) {
		if (strcmp(Students[i].Student_ID, ID) == 0) return 0;
	}
	return 1;
}
/*���뺯����Ϊ�˼򻯴���*/
void setInfo(char pinfo[], char desinfo[]) {
	printf("%s��", pinfo);
	scanf("%s", desinfo);
}
/*���ÿ��ѧ������ϸ��Ϣ*/
void PrintAllInformation() {
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*���ÿ��ѧ���Ĳ�����Ϣ*/
void PrintPartInformation() {
	int i;
	printf("------------------------------------\n");
	for (i = 0; i < num; i++)
		printf("%s %s %s\n", Students[i].Name, Students[i].Attandance_date, Students[i].Attandance_Result);
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*�ú���ʵ�ֵ�����ϵͳ�����ͬѧ*/
void ADD() {
	char ID[maxsize];
	printf("������ѧ����ѧ�ţ�");
	scanf("%s", ID);
	if (!judge(ID)) {
		printf("�����Ѿ�����\n");
		printf("�����ɣ��밴�س�������\n");
		wait_for_Enter();
		return;
	}
	strcpy(Students[num].Student_ID, ID);
	setInfo("������ѧ��������", Students[num].Name);
	setInfo("������ѧ���İ༶", Students[num].Class_Number);
	setInfo("������ѧ���Ŀ�������", Students[num].Attandance_date);
	setInfo("������ѧ���Ŀ��ڽ���� �� ��   �� �� X   �� �� ��   �� �� ��   �� �� +   �� �� �C", Students[num].Attandance_Result);
	num++;//ͬѧ������һ
	printf("��ӳɹ������س�������\n");
	wait_for_Enter();
}
/*�ú���ʵ�ֵ��ǲ��ҵĹ��ܣ����԰�ѧ�ţ��������������ڽ��в���*/
void Find() {
	int i, op, flag = -1;
	char information[maxsize];
	printf("<1>��ѧ�Ų���  <2>����������  <3>���������ڲ���\n");
	scanf("%d", &op);
	if (op == 1) {
		printf("���������ѧ�ţ�");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Student_ID) == 0) printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
 
		}
	} else if (op == 2) {
		printf("���������������");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Name) == 0) printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
		}
	} else {
		printf("�����뿼�����ڣ�");
		scanf("%s", information);
		for (i = 0; i < num; i++) {
			if (strcmp(information, Students[i].Attandance_date) == 0) 	printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;;
		}
	}
	if (flag == -1) printf("�����ڴ���Ϣ��\n");
	printf("������ɣ����س�������\n");
	wait_for_Enter();
}
/*�ú���ʵ�ֵ��Ƕ�ϵͳ���Ѿ����ڵ���Ϣ�����޸ģ���������Ĳ��ң�Ҳ���Ը��ݲ�ͬ����Ϣѡ����Ҫ�޸ĵ���Ϣ�����޸�*/
void Change() {
	int i, j = -1;
	char op[2], information[maxsize], find[maxsize];
	printf("<1>��ѧ���޸�  <2>�������޸�  <3>�����������޸�\n");
	scanf("%s", op);
	if (op[0] == '1') setInfo("���������ѧ��", information);
	else if (op[0] == '2') setInfo("�������������", information);
	else setInfo("�����뿼������", information);
	strcpy(find, information);
	if(op[0]=='1')
		for (i = 0; i < num; i++) {
			if (strcmp(find, Students[i].Student_ID) == 0) j = i;
		}
	else if(op[0]=='2')
		for (i = 0; i < num; i++) {
			if (strcmp(find, Students[i].Name) == 0) j = i;
		}
	else
		for (i = 0; i < num; i++) {
			if (strcmp(find, Students[i].Attandance_date) == 0) j = i;
		}
	if (j == -1) {
		printf("������Ҫ�ҵ���Ϣ��\n");
		printf("�޸���ɣ����س�������\n");
		wait_for_Enter();
		return;
	}
	setInfo("<1>�޸�ѧ��  <2>�޸�����  <3>�޸Ŀ�������", op);
	if (op[0] == '1') {
		setInfo("�������޸ĺ����ѧ��", information);
		strcpy(Students[j].Student_ID, information);
	} else if (op[0] == '2') {
		setInfo("�������޸ĺ��������", information);
		strcpy(Students[j].Name, information);
	} else {
		setInfo("�������޸ĺ���¿�������", information);
		strcpy(Students[j].Attandance_date, information);
	}
	printf("�޸���ɣ����س������أ�\n");
	wait_for_Enter();
}
/*�ú���ʵ�ֵ��Ƕ��Ѿ�������ϵͳ�ֵ�ͬѧ����Ϣ����ɾ�������������뷨��ѧ������num--�����������˵���Ϣǰ��һ��λ�ã�ʵ����Ϣ�ĸ���*/
void Delete() {
	int i, j,flag = -1;
	char op[2],information[maxsize];
	setInfo("�����룺<1>��ѧ��ɾ��<2>������ɾ��", op);
	if (op[0] == '1') {
		setInfo("������ѧ��", information);
		for (i = 0; i < num; i++) {
			if (strcmp(Students[i].Student_ID, information) == 0) {
				flag = 1;
				for (j = i + 1; j < num; j++) {
					copy(&Students[i], &Students[j]);
 
				}
			}
		}
	} else {
		setInfo("����������", information);
		for (i = 0; i < num; i++) {
			if (strcmp(Students[i].Name, information) == 0) {
				flag = 1;
				for (j = i + 1; j < num; j++) {
					copy(&Students[i], &Students[j]);
 
				}
			}
		}
	}
	if (flag == -1) {
		printf("�����ڴ���Ϣ��\n");
		printf("ɾ����ɣ����س�������\n");
		wait_for_Enter();
		return ;
	}
	num--;
	printf("�����ڴ���Ϣ��\n");
	printf("ɾ����ɣ����س�������\n");
	wait_for_Enter();
}
/*�˺���ʵ�ֵ��ǹ���5 ��ϵͳ���Ѿ����ڵ���Ϣ�������*/
void Print() {
	int op;
	printf("��ѡ��\n<1>���ִ�ӡ�����ѧ�������Ϳ������ںͿ��������\n<2>ȫ����ӡ���������ѧ����������Ϣ����");
	scanf("%d", &op);
	if (op == 1) PrintPartInformation();
	else PrintAllInformation();
 
}
/*�����������������г�Ա����ֵ����Ϊ��Ա����char���飬�����õ���strcmp�������˺�����Ҫ��Ϊ������з��񣬲���ָ����н���*/
void exchange(student *a, student *b) {
	char tmp[maxsize];
	strcpy(tmp, a->Student_ID);
	strcpy(a->Student_ID, b->Student_ID);
	strcpy(b->Student_ID, tmp);
 
	strcpy(tmp, a->Name);
	strcpy(a->Name, b->Name);
	strcpy(b->Name, tmp);
 
	strcpy(tmp, a->Class_Number);
	strcpy(a->Class_Number, b->Class_Number);
	strcpy(b->Class_Number, tmp);
 
	strcpy(tmp, a->Attandance_Result);
	strcpy(a->Attandance_Result, b->Attandance_Result);
	strcpy(b->Attandance_Result, tmp);
 
	strcpy(tmp, a->Attandance_date);
	strcpy(a->Attandance_date, b->Attandance_date);
	strcpy(b->Attandance_date, tmp);
	return;
}
/*ʵ�ֹ���6���򣬿��԰�ѧ�ţ��������������ڽ�������ʹ�õ���ð���������Ҫ�����Ϣ��������*/
void Order() {
	int op, i, j;
	char tmp[maxsize];
	printf("�����룺<1>��ѧ�Ŵ�С�������� <2>��ѧ������ASCLL������ <3>���������ڴ�С��������\n");
	scanf("%d", &op);
	if (op == 1) {
		for (i = 0; i < num; i++) {
			for (j = i+1; j < num; j++) {
				if (strcmp(Students[i].Student_ID, Students[j].Student_ID) > 0) {
					exchange(&Students[i], &Students[j]);
				}
			}
		}
	} else if (op == 2) {
		for (i = 0; i < num; i++) {
			for (j = i+1; j < num; j++) {
				if (strcmp(Students[i].Name, Students[j].Name) > 0) {
					exchange(&Students[i], &Students[j]);
				}
			}
		}
	} else {
		int month_1, month_2, day_1, day_2;
		for (i = 0; i < num; i++) {
			month_1 = atoi(Students[i].Attandance_date);
			day_1 = convert(Students[i].Attandance_date);
			for (j = i+1; j < num; j++) {
				month_2 = atoi(Students[j].Attandance_date);
				day_2 = convert(Students[j].Attandance_date);
				if(month_1>month_2) exchange(&Students[i], &Students[j]);
				else if(month_1==month_2&&day_1>day_2) exchange(&Students[i], &Students[j]);
			}
 
		}
	}
	printf("����ɹ������س�������\n");
	wait_for_Enter();
}
/*���������ϸ��������ϸ�����ֵ����ɶ���ı��ǰ��Ҹ��˵���⣬�������������⣬�����ٽ��Ҹ�*/ 
void Detail_Print() {
	int i, j;
	char tmp[maxsize];
	int month_1, month_2, day_1, day_2;
	for (i = 0; i < num; i++) {
		month_1 = atoi(Students[i].Attandance_date);
		day_1 = convert(Students[i].Attandance_date);
		for (j = 0; j < num; j++) {
			month_2 = atoi(Students[j].Attandance_date);
			day_2 = convert(Students[j].Attandance_date);
			if (month_1 < month_2) exchange(&Students[i], &Students[j]);
			else if (month_1 == month_2 && day_1 < day_2) exchange(&Students[i], &Students[j]);
		}
	}
	printf("------------------------------------\n");
	printf("������ϸ��\n");
	printf("%s��\n", Students[0].Attandance_date);
	printf("%s %s %s %s\n", Students[0].Student_ID, Students[0].Name, Students[0].Class_Number, Students[0].Attandance_Result);
	strcmp(tmp, Students[0].Attandance_date);
	for (i = 1; i < num; i++) {
		if (strcmp(Students[i].Attandance_date, tmp) != 0) {
			printf("%s��\n", Students[i].Attandance_date);
			strcmp(tmp, Students[i].Attandance_date);
		}
		printf("%s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
	}
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*�����ձ���*/ 
void Daily_Print() {
	int i;
	char information[maxsize];
	setInfo("������Ҫ�鿴������", information);
	printf("------------------------------------\n");
	printf("%s�Ŀ��������\n", information);
	for (i = 0; i < num; i++) {
		if (strcmp(information, Students[i].Attandance_date) == 0) printf("%s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
	}
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*�����쳣��������в��� ���Թ� �����˵���Ϣ*/ 
void Informal_Print() {
	int i, cnt = 0;
	printf("------------------------------------\n");
	printf("�����쳣��\n");
	for (i = 0; i < num; i++) {
		if (strcmp(Students[i].Attandance_Result, "��") != 0)
			printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
	}
	printf("�����쳣������%d��\n", cnt);
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*����쳣�����������ٵ��˵���Ϣ*/ 
void AskForLeave_Print() {
	int i, cnt = 0;
	printf("------------------------------------\n");
	printf("����쳣��\n");
	for (i = 0; i < num; i++) {
		if (strcmp(Students[i].Attandance_Result, "��") == 0 || strcmp(Students[i].Attandance_Result, "��") == 0)
			printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
	}
	printf("���������%d��\n", cnt);
	printf("------------------------------------\n");
	printf("��ӡ�ɹ������س�������\n");
	wait_for_Enter();
}
/*�����7��������ͳ��*/ 
void Statistics() {
	char op[2];
	setInfo("��ѡ��\n<1>������ϸ��\n<2>�����ձ���\n<3>�����쳣��\n<4>��ٻ��ܱ�",op);
	if (op[0] == '1') {
		Detail_Print();
	} else if (op[0] == '2') {
		Daily_Print();
	} else if (op[0] == '3') {
		Informal_Print();
	} else {
		AskForLeave_Print();
	}
}
 
int main() {
	int i, a, b = 1;
	FILE *F=fopen("Manage.txt","wt");//ע��������wt  ֻд�򿪻���һ���ı��ļ���ֻ����д����
	FILE *fp= fopen("Manage.txt", "at+");
	if (!fp) {
		printf("����δ�ܴ��ļ�\n");
		exit(0);
	}
	fscanf(fp, "%d", &num);//�����Ѿ���ϵͳ�е�ѧ���ĸ��� 
	printf("��ǰϵͳ�д����ѧ��������%d��\n", num);
	for (i = 0; i < num; i++) {//����ϵͳ��ѧ������Ϣ 
		fscanf(fp, "%s%s%s%s%s", &Students[i].Student_ID, &Students[i].Name, &Students[i].Class_Number, &Students[i].Attandance_date, &Students[i].Attandance_Result);
	}
	fclose(fp);
	while (b != 0) {
		printf("==============================================================================\n\n");
		printf("                          ��ѧ������ϵͳ\n\n");
		printf("==============================================================================\n\n");
		printf("<1> ����ѧ������        <2> ����ѧ������             <3>�޸�ѧ����¼     \n");
		printf("<4>ɾ��ѧ����¼         <5> ��ʾѧ�����ڵ������б�   <6> ��ָ�����ݽ������� \n");
		printf("<7>��������ͳ��         <8>  quit\n\n");
		scanf("%d", &a);
		switch (a) {
			case 1:
				ADD();
				break;
			case 2:
				Find();
				break;
			case 3:
				Change();
				break;
			case 4:
				Delete();
				break;
			case 5:
				Print();
				break;
			case 6:
				Order();
				break;
			case 7:
				Statistics();
				break;
			case 8:
				printf("���˳�\n");
				b = 0;
				break;
		}
		system("cls");//����������Ϊ��ʹ����������� 
	}
	//��������Ϣ���뵽�ļ��������Ա��´�����ʹ��  
	fprintf(F,"%d\n",num);
	for (i = 0; i<num; i++) {
		fprintf(F, "%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);
	}
	fclose(F);
	//�ļ��������� 
	return 0;
}