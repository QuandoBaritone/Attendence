#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 15
#define maxnum 1000
 
typedef struct {
char Student_ID[maxsize];
char Name[maxsize];
char Class_Number[maxsize];
char Attandance_date[maxsize];
char Attandance_Result[maxsize];
} student; /*学生信息结构*/

 
student Students[maxnum];
 
int num = 0;
char buf[maxsize];
/*实现每次输入结束,最后输入回车退出的功能*/
void wait_for_Enter() {
getchar();
getchar();
}
/*对日期进行排序，对于月份，直接用atoi截取出来转化成月份，对于天数，用以下函数计算*/
int convert(char str[]) {
int i,res = 0, cnt = 0;
for (i = strlen(str) - 3; i >= 0; i--) {
if (str[i] >= &apos;0&apos;&&str[i] <= &apos;9&apos;) res *= 10, res += (str[i] - &apos;0&apos;);
else break;
}
return res;/*返回天数，也就是一月中的第几天*/}
/*该函数实现的是把student类型变量b的所有信息赋给student类型的变量a*/
void copy(student *a,student *b) {
strcpy_s(a->Student_ID ,20,b->Student_ID);
strcpy_s(a->Name ,20,b->Name);
strcpy_s(a->Class_Number ,20,b->Class_Number);
strcpy_s(a->Attandance_Result ,20, b->Attandance_Result);
strcpy_s(a->Attandance_date ,20,b->Attandance_date);
}
/*对已存在的学生不可再次添加*/
int judge(char *ID) {
int i;
for (i = 0; i < num; i++) {
if (strcmp(Students[i].Student_ID, ID) == 0) return 0;
}
return 1;
}
/*输入函数，为了简化代码*/
void setInfo(char pinfo[], char desinfo[]) {
printf("%s：", pinfo);
scanf("%s", desinfo);
}
/*输出每个学生的详细信息*/
void PrintAllInformation() {
int i;
printf("------------------------------------\n");
for (i = 0; i < num; i++)
printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*输出每个学生的部分信息*/
void PrintPartInformation() {
int i;
printf("------------------------------------\n");
for (i = 0; i < num; i++)
printf("%s %s %s\n", Students[i].Name, Students[i].Attandance_date, Students[i].Attandance_Result);
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*增加函数，向系统中添加同学*/
void ADD() {
char ID[maxsize];
printf("请输入学生的学号：");
scanf("%s", ID);
if (!judge(ID)) {
printf("此人已经存在\n");
printf("添加完成！请按回车键返回\n");
wait_for_Enter();
return;
}
strcpy(Students[num].Student_ID, ID);
setInfo("请输入学生的姓名", Students[num].Name);
setInfo("请输入学生的班级", Students[num].Class_Number);
setInfo("请输入学生的考勤日期", Students[num].Attandance_date);
setInfo("请输入学生的考勤结果出 勤 √   旷 课 X   事 假 △   病 假 ○   迟 到 +   早 退 –", Students[num].Attandance_Result);
num++;/*同学人数+1*/
printf("添加成功！按回车键返回\n");
wait_for_Enter();
}
/*查找函数，可以按学号，姓名，考勤日期进行查找*/
void Find() {
int i, op, flag = -1;
char information[maxsize];
printf("<1>按学号查找  <2>按姓名查找  <3>按考勤日期查找\n");
scanf("%d", &op);
if (op == 1) {
printf("请输入该生学号：");
scanf("%s", information);
for (i = 0; i < num; i++) {
if (strcmp(information, Students[i].Student_ID) == 0) printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
 
}
} else if (op == 2) {
printf("请输入该生姓名：");
scanf("%s", information);
for (i = 0; i < num; i++) {
if (strcmp(information, Students[i].Name) == 0) printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;
}
} else {
printf("请输入考勤日期：");
scanf("%s", information);
for (i = 0; i < num; i++) {
if (strcmp(information, Students[i].Attandance_date) == 0)  printf("%s %s %s %s %s\n\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), flag = 1;;
}
}
if (flag == -1) printf("不存在此信息！\n");
printf("查找完成！按回车键返回\n");
wait_for_Enter();
}

/*修改函数，可以根据不同的信息选择想要修改的信息进行修改*/
void Change() {
int i, j = -1;
char op[2], information[maxsize], find[maxsize];
printf("<1>按学号修改  <2>按姓名修改  <3>按考勤日期修改\n");
scanf("%s", op);
if (op[0] == &apos;1&apos;) setInfo("请输入该生学号", information);
else if (op[0] == &apos;2&apos;) setInfo("请输入该生姓名", information);
else setInfo("请输入考核日期", information);
strcpy(find, information);
if(op[0]==&apos;1&apos;)
for (i = 0; i < num; i++) {
if (strcmp(find, Students[i].Student_ID) == 0) j = i;
}
else if(op[0]==&apos;2&apos;)
for (i = 0; i < num; i++) {
if (strcmp(find, Students[i].Name) == 0) j = i;
}
else
for (i = 0; i < num; i++) {
if (strcmp(find, Students[i].Attandance_date) == 0) j = i;
}
if (j == -1) {
printf("不存在要找的信息！\n");
printf("修改完成！按回车键返回\n");
wait_for_Enter();
return;
}
setInfo("<1>修改学号  <2>修改姓名  <3>修改考勤日期", op);
if (op[0] == &apos;1&apos;) {
setInfo("请输入修改后的新学号", information);
strcpy(Students[j].Student_ID, information);
} else if (op[0] == &apos;2&apos;) {
setInfo("请输入修改后的新姓名", information);
strcpy(Students[j].Name, information);
} else {
setInfo("请输入修改后的新考核日期", information);
strcpy(Students[j].Attandance_date, information);
}
printf("修改完成！按回车键返回！\n");
wait_for_Enter();
}

/*删除函数，学生人数num--，后面所有人的信息前移一个位置，实现信息的覆盖*/
void Delete() {
int i, j,flag = -1;
char op[2],information[maxsize];
setInfo("请输入：<1>按学号删除<2>按姓名删除", op);
if (op[0] == &apos;1&apos;) {
setInfo("请输入学号", information);
for (i = 0; i < num; i++) {
if (strcmp(Students[i].Student_ID, information) == 0) {
flag = 1;
for (j = i + 1; j < num; j++) {
copy(&Students[i], &Students[j]);
 
}
}
}
} else {
setInfo("请输入姓名", information);
for (i = 0; i < num; i++) {
if (strcmp(Students[i].Name, information) == 0) {
flag = 1;
for (j = i + 1; j < num; j++) {
copy(&Students[i], &Students[j]);
 
}
}
}
}
if (flag == -1) {
printf("不存在此信息！\n");
printf("删除完成！按回车键返回\n");
wait_for_Enter();
return ;
}
num--;
printf("不存在此信息！\n");
printf("删除完成！按回车键返回\n");
wait_for_Enter();
}
/*输出函数 */
void Print() {
int op;
printf("请选择\n<1>部分打印（输出学生姓名和考勤日期和考勤情况）\n<2>全部打印（输出所有学生的所有信息）：");
scanf("%d", &op);
if (op == 1) PrintPartInformation();
else PrintAllInformation();
 
}

/*交换两个变量的所有成员的数值，因为成员都是char数组，所以用到了strcmp函数。此函数主要是为排序进行服务，采用指针进行交换*/
void exchange(student *a, student *b) {
char tmp[maxsize];
strcpy(tmp, a->Student_ID);
strcpy(a->Student_ID, b->Student_ID);
strcpy(b->Student_ID, tmp);
 
strcpy(tmp, a->Name);
strcpy(a->Name, b->Name);
strcpy(b->Name, tmp);
 
strcpy(tmp, a->Class_Number);
strcpy(a->Class_Number, b->Class_Number);
strcpy(b->Class_Number, tmp);
 
strcpy(tmp, a->Attandance_Result);
strcpy(a->Attandance_Result, b->Attandance_Result);
strcpy(b->Attandance_Result, tmp);
 
strcpy(tmp, a->Attandance_date);
strcpy(a->Attandance_date, b->Attandance_date);
strcpy(b->Attandance_date, tmp);
return;
}
/*排序函数，按学号，姓名，考勤日期进行排序，使用的是冒泡排序对所要求的信息进行排序*/
void Order() {
int op, i, j;
char tmp[maxsize];
printf("请输入：<1>按学号从小到大排序 <2>按学生姓名ASCLL码排序 <3>按考勤日期从小到大排序：\n");
scanf("%d", &op);
if (op == 1) {
for (i = 0; i < num; i++) {
for (j = i+1; j < num; j++) {
if (strcmp(Students[i].Student_ID, Students[j].Student_ID) > 0) {
exchange(&Students[i], &Students[j]);
}
}
}
} else if (op == 2) {
for (i = 0; i < num; i++) {
for (j = i+1; j < num; j++) {
if (strcmp(Students[i].Name, Students[j].Name) > 0) {
exchange(&Students[i], &Students[j]);
}
}
}
} else {
int month_1, month_2, day_1, day_2;
for (i = 0; i < num; i++) {
month_1 = atoi(Students[i].Attandance_date);
day_1 = convert(Students[i].Attandance_date);
for (j = i+1; j < num; j++) {
month_2 = atoi(Students[j].Attandance_date);
day_2 = convert(Students[j].Attandance_date);
if(month_1>month_2) exchange(&Students[i], &Students[j]);
else if(month_1==month_2&&day_1>day_2) exchange(&Students[i], &Students[j]);
}
 
}
}
printf("排序成功！按回车键返回\n");
wait_for_Enter();
}

/*输出考勤明细表*/ 
void Detail_Print() {
int i, j;
char tmp[maxsize];
int month_1, month_2, day_1, day_2;
for (i = 0; i < num; i++) {
month_1 = atoi(Students[i].Attandance_date);
day_1 = convert(Students[i].Attandance_date);
for (j = 0; j < num; j++) {
month_2 = atoi(Students[j].Attandance_date);
day_2 = convert(Students[j].Attandance_date);
if (month_1 < month_2) exchange(&Students[i], &Students[j]);
else if (month_1 == month_2 && day_1 < day_2) exchange(&Students[i], &Students[j]);
}
}
printf("------------------------------------\n");
printf("考勤明细表：\n");
printf("%s：\n", Students[0].Attandance_date);
printf("%s %s %s %s\n", Students[0].Student_ID, Students[0].Name, Students[0].Class_Number, Students[0].Attandance_Result);
strcmp(tmp, Students[0].Attandance_date);
for (i = 1; i < num; i++) {
if (strcmp(Students[i].Attandance_date, tmp) != 0) {
printf("%s：\n", Students[i].Attandance_date);
strcmp(tmp, Students[i].Attandance_date);
}
printf("%s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
}
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*考勤日报表*/ 
void Daily_Print() {
int i;
char information[maxsize];
setInfo("请输入要查看的日期", information);
printf("------------------------------------\n");
printf("%s的考勤情况：\n", information);
for (i = 0; i < num; i++) {
if (strcmp(information, Students[i].Attandance_date) == 0) printf("%s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_Result);
}
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*考勤异常表，输出所有不是 ‘对勾 ’的人的信息*/ 
void Informal_Print() {
int i, cnt = 0;
printf("------------------------------------\n");
printf("考勤异常表：\n");
for (i = 0; i < num; i++) {
if (strcmp(Students[i].Attandance_Result, "√") != 0)
printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
}
printf("考勤异常人数：%d人\n", cnt);
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*请假异常表，输出所有请假的人的信息*/ 
void AskForLeave_Print() {
int i, cnt = 0;
printf("------------------------------------\n");
printf("请假异常表\n");
for (i = 0; i < num; i++) {
if (strcmp(Students[i].Attandance_Result, "○") == 0 || strcmp(Students[i].Attandance_Result, "○") == 0)
printf("%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result), cnt++;
}
printf("请假人数：%d人\n", cnt);
printf("------------------------------------\n");
printf("打印成功！按回车键返回\n");
wait_for_Enter();
}
/*事项功能7进行数据统计*/ 
void Statistics() {
char op[2];
setInfo("请选择\n<1>考勤明细表\n<2>考勤日报表\n<3>考勤异常表\n<4>请假汇总表",op);
if (op[0] == &apos;1&apos;) {
Detail_Print();
} else if (op[0] == &apos;2&apos;) {
Daily_Print();
} else if (op[0] == &apos;3&apos;) {
Informal_Print();
} else {
AskForLeave_Print();
}
}
 
int main() {
int i, a, b = 1;
FILE *F=fopen("Manage.txt","wt");//注意这里是wt  只写打开或建立一个文本文件，只允许写数据
FILE *fp= fopen("Manage.txt", "at+");
if (!fp) {
printf("错误！未能打开文件\n");
exit(0);
}
fscanf(fp, "%d", &num);//读入已经在系统中的学生的个数 
printf("当前系统中储存的学生个数：%d人\n", num);
for (i = 0; i < num; i++) {//读入系统中学生的信息 
fscanf(fp, "%s%s%s%s%s", &Students[i].Student_ID, &Students[i].Name, &Students[i].Class_Number, &Students[i].Attandance_date, &Students[i].Attandance_Result);
}
fclose(fp);
while (b != 0) {
printf("==============================================================================\n\n");
printf("                          大学生考勤系统\n\n");
printf("==============================================================================\n\n");
printf("<1> 新增学生数据        <2> 查找学生数据             <3>修改学生记录     \n");
printf("<4>删除学生记录         <5> 显示学生考勤的数据列表   <6> 对指定数据进行排序 \n");
printf("<7>进行数据统计         <8>  quit\n\n");
scanf("%d", &a);
switch (a) {
case 1:
ADD();
break;
case 2:
Find();
break;
case 3:
Change();
break;
case 4:
Delete();
break;
case 5:
Print();
break;
case 6:
Order();
break;
case 7:
Statistics();
break;
case 8:
printf("已退出\n");
b = 0;
break;
}
system("cls");//清屏函数，界面更美观 
}
//在最后把信息输入到文件，保留以备下次运行使用  
fprintf(F,"%d\n",num);
for (i = 0; i<num; i++) {
fprintf(F, "%s %s %s %s %s\n", Students[i].Student_ID, Students[i].Name, Students[i].Class_Number, Students[i].Attandance_date, Students[i].Attandance_Result);
}
fclose(F);
//文件操作结束 
return 0;
}
