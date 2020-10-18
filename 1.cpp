#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <MMSystem.h>
#include<malloc.h>
#include<stdio.h>
#include<easyx.h>
#include<stdlib.h>
#define up 72
#define down 80
#define lift 75
#define right 77
int move = 72;

/*����һ��ʧ�ܵ�̰����
����������ھ�������ɵ������ǲ�����
ֻ���Ҹ���ʧ����

�Ҵ���������ʼ��moocѧϰ
ѧ��������ļ��㡢�жϡ�ѭ��������
Ȼ���˰���ʱ��Ū����git
�ٺķ������ʱ��Ϊ������ui����Ļ���ȥѧeasyx
ʼ���ǳ�����Ȥ�͸ɾ���

����Ϸ������ԶԶû���������ô��
Ϊ���ٳ�����Щ��Ծ��ѧϰ
���ҿ�ʼ�Ӵ�����
Ȼ���֪��Ҫѧָ��
ѧϰ��������������struct��û������ָ��
����ԽѧԽ����ĸо�

����Ϸ����Ȥ���е�
���Ҷ�����Ϸ����ȤҲ�����
����ԭ��
������ʶ��һ���ѧ�Ǽ��������ܰ�ʱ��ɺ�
�Ҿ���ѧ����ѧ
���������̰���ߵ�Դ����Ȼ���о�
������ԴԴ����

��֮
��ʧ����
������Ȼ��лMEMO��������Ҷ����ʵϰ�ڵĻ��ᣨ�ұ���һ��ͱ�ˢ�ģ�
��������ҹ��ĸ����ʵ
��������
�����컹����
�����������������

��������򲻶�����������ˣ�Ҳû�г�����ʾ���������Ҳ���ã�
*/


//������Ϸ�ر����
int abc = 0;

void start()
{
    //��������
    initgraph(800, 600,NULL);
    //�����汳��ͼƬ
    IMAGE logo_img;
    loadimage(&logo_img, _T("logo1.jpg"), 800, 600);
    putimage(0, 0, &logo_img);
    //ѡ����ʾ
    setlinecolor(WHITE);
    setfillcolor(BLACK);
    settextstyle(25, 0, _T("����"));

    fillrectangle(349, 550, 451, 490);
    outtextxy(350, 510, _T("�˳���Ϸ"));

    fillrectangle(349, 450, 451, 390);
    outtextxy(350, 410, _T("��Ϸ����"));

    fillrectangle(349, 350, 451, 290);
    outtextxy(350, 310, _T("��ʼ��Ϸ"));
   
    MOUSEMSG mouse;
    IMAGE illustrate_img;
    loadimage(&illustrate_img, _T("illustrate.jpg"), 800, 600);

    int o = 1;
       
    while (o==1) {
        mouse = GetMouseMsg();
        switch (mouse.uMsg) {
        case WM_LBUTTONDOWN:
            //��Ϸ����
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 390 && mouse.y < 450)) {
                putimage(0, 0, &illustrate_img);
                _getch();
                cleardevice();

                putimage(0, 0, &logo_img);

                setlinecolor(WHITE);
                setfillcolor(BLACK);
                settextstyle(25, 0, _T("����"));

                fillrectangle(349, 550, 451, 490);
                outtextxy(350, 510, _T("�˳���Ϸ"));

                fillrectangle(349, 450, 451, 390);
                outtextxy(350, 410, _T("��Ϸ����"));

                fillrectangle(349, 350, 451, 290);
                outtextxy(350, 310, _T("��ʼ��Ϸ"));  
                    
            }
            //��ʼ��Ϸ
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 290 && mouse.y < 350)) {
                cleardevice();
                o = 0;
                break;
            }
            //�˳���Ϸ
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 450 && mouse.y < 550)) {
                cleardevice();
                o = 0;
                abc = 1;
                break;
            }

        }
    } 
    
}

//�����͵ȼ�
void print_score_grade(int nodemun,int grade)
{
   
    wchar_t ch[5];
    wchar_t ch2[2];

   
    settextcolor(RGB(0, 255, 255));
    settextstyle(20, 0, _T("����"));

    setfillcolor(RED);
    solidrectangle(580, 150, 700, 170);
    solidrectangle(580, 100, 700, 120);

    swprintf(ch, 5, _T("%d"), nodemun * 10 - 10);
    swprintf(ch2, 2, _T("%d"), grade);

    outtextxy(580, 150, ch);
    outtextxy(580, 100, ch2);
    system("pause");
}

//����
typedef struct ac
{
    int x;
    int y;
    struct ac *next;
}lianbiao;


 lianbiao *createlink()
{
    lianbiao *head;
    head = (lianbiao*)malloc(sizeof(struct ac));
    if (head == NULL)
        exit(0);
    head->x = 550;
    head->y = 550;
    head->next = NULL;
    return head;
}

 //��
 void create(lianbiao *head, int *end)
 {
     lianbiao *p;
     p = head;
     setfillcolor(RGB(0, 255, 255));
     while (p->next != NULL)
     {
         solidrectangle(p->x, p->y, p->x + 10, p->y + 10);
         p = p->next;
     }
     solidrectangle(p->x, p->y, p->x + 10, p->y + 10);
     if (end != NULL)//Ĩȥ��һ������β
     {
         setfillcolor(RED);
         solidrectangle(end[0], end[1], end[0] + 10, end[1] + 10);
     }
 }

 lianbiao* changeLink(lianbiao* head, int* end, int nodemun)
 {
     int i;
     lianbiao* new_node;
     lianbiao* current;
     lianbiao* p;
     new_node = (lianbiao*)malloc(sizeof(struct ac));
     if (new_node == NULL)
         exit(0);
     current = head;
     new_node->next = head;
     while (current->next != NULL)//Ѱ����β
     {
         current = current->next;
     }

     switch (move)//����µ�ͷ�ڵ㣬ɾ��β�ڵ�
     {
     case up:
         new_node->x = head->x;
         new_node->y = head->y - 10;
         end[0] = current->x;
         end[1] = current->y;
         free(current);
         current = NULL;
         break;
     case down:
         new_node->x = head->x;
         new_node->y = head->y + 10;
         end[0] = current->x;
         end[1] = current->y;
         free(current);
         current = NULL;
         break;
     case right:
         new_node->x = head->x + 10;
         new_node->y = head->y;
         end[0] = current->x;
         end[1] = current->y;
         free(current);
         current = NULL;
         break;
     case lift:
         new_node->x = head->x - 10;
         new_node->y = head->y;
         end[0] = current->x;
         end[1] = current->y;
         free(current);
         current = NULL;
         break;
     }
     p = new_node;
     for (i = 1; i < nodemun; i++)//Ѱ���µ���β
     {
         p = p->next;
     }
     p->next = NULL;//���µ�β�ڵ�ָ��NULL
     return new_node;//�����µ�ͷ�ڵ�
 }

 void chose_speed(int nodemun)
 {
     switch (nodemun / 15)
     {
     case 0:Sleep(300); break;
     case 1:Sleep(250); break;
     case 2:Sleep(200); break;
     case 3:Sleep(150); break;
     case 4:Sleep(100); break;
     default:Sleep(100);
     }
 }

 void create_food(int* position)
 {
     int x, y;
     srand(time(NULL));
     x = rand() % 49;
     y = rand() % 39;
     position[0] = x * 10;
     position[1] = y * 10;
     setfillcolor(RED);
     solidrectangle(position[0], position[1], position[0] + 10, position[1] + 10);
 }

 void add_node(lianbiao* head, int* nodemun, int* end)
 {
     int i = 1;
     int tail[2], sec_tail[2];
     lianbiao* current;
     lianbiao* new_node;

     new_node = (lianbiao*)malloc(sizeof(struct ac));
     if (new_node == NULL)
         exit(0);
     current = head;

     if (*nodemun > 1)//���������ڵ㼰����
     {
         while (current->next != NULL)
         {
             if (i == *nodemun - 1)//Ѱ�ҵ����ڶ����ڵ㣬��������ֵ
             {
                 sec_tail[0] = current->x;
                 sec_tail[1] = current->y;
                 current = current->next;
             }
             else
             {
                 i++;
                 current = current->next;
             }
         }
         tail[0] = current->x;
         tail[1] = current->y;

         //������β�˶�������ӽڵ�
         if (tail[0] > sec_tail[0])
         {
             end[0] = end[0] + 10;
             new_node->x = current->x + 10;
             new_node->y = current->y;
         }
         if (tail[0] < sec_tail[0])
         {
             end[0] = end[0] - 10;
             new_node->x = current->x - 10;
             new_node->y = current->y;
         }
         if (tail[1] > sec_tail[1])
         {
             end[1] = end[1] + 10;
             new_node->x = current->x;
             new_node->y = current->y + 10;
         }
         if (tail[1] < sec_tail[1])
         {
             end[1] = end[1] - 10;
             new_node->x = current->x;
             new_node->y = current->y - 10;
         }
     }


     if (*nodemun == 1)//��ֻ��һ���ڵ�
     {
         switch (move)
         {
         case up:
             end[1] = end[1] + 10;
             new_node->x = current->x;
             new_node->y = current->y + 10; break;
         case down:
             end[1] = end[1] - 10;
             new_node->x = current->x;
             new_node->y = current->y - 10; break;
         case right:
             end[0] = end[0] - 10;
             new_node->x = current->x - 10;
             new_node->y = current->y; break;
         case lift:
             end[0] = end[0] + 10;
             new_node->x = current->x + 10;
             new_node->y = current->y; break;
         }
     }
     new_node->next = NULL;
     current->next = new_node;
     *nodemun = *nodemun + 1;
 }
 
 void chose_speed(int nodemun)
 {
     switch (nodemun / 15)
     {
     case 0:Sleep(300); break;
     case 1:Sleep(250); break;
     case 2:Sleep(200); break;
     case 3:Sleep(150); break;
     case 4:Sleep(100); break;
     default:Sleep(100);
     }
 }

 int check(lianbiao* head, int nodemun)
 {
     int i;
     lianbiao* current;
     if (nodemun >= 5)//����5���ڵ�����
     {
         current = head->next->next->next->next;//currentָ���5���ڵ�
         for (i = 5; i <= nodemun; i++)//�ж����Ƿ�Ե��Լ�
         {
             if (head->x == current->x && head->y == current->y)
             {
                 return 0;
             }
             current = current->next;
             i++;
         }
     }
     if (head->x < 0 || head->x>490 || head->y < 0 || head->y>390)//�ж������Ƿ񳬳���Ϸ����
         return 0;
     return 1;
 }


 void graph_thinks(int nodemun)
 {
     wchar_t ch[5];
     setfillcolor(BLACK);
     solidrectangle(0, 0, 850, 400);
     setbkmode(TRANSPARENT);//���ñ���ģʽ
     settextcolor(RGB(0, 255, 255));
     settextstyle(40, 0, _T("����"));
     outtextxy(300, 100, _T(" game over!"));
     outtextxy(200, 200, _T(" your grade :     points"));

     swprintf(ch, 5, _T("%d"), nodemun * 10 - 10);
     outtextxy(470, 200, ch);
 }


 void main()
 {
     start();
     lianbiao* head;
     int kb;
     int end[2];
     int position[2];
     int nodemun = 1;
     head = createlink();
     create_food(position);
     print_score_grade(nodemun, nodemun / 15 + 1);
     if (abc == 0) {
         setfillcolor(RGB(69, 139, 116));
         solidrectangle(0, 0, 800, 600);
         
         while (1)
         {
             create(head, end);
             chose_speed(nodemun);
             if (_kbhit())//��ȡ������
             {
                 _getch();
                 kb = _getch();
                 //������ǰ��ͷ�ƶ�����ķ������˶�
                 if (!(kb == up && move == down || kb == down && move == up || kb == right && move == lift || kb == lift && move == right))
                     move = kb;
             }
             head = changeLink(head, end, nodemun);
             if (check(head, nodemun) == 0)//�Ϸ��Լ��
                 break;

             if (head->x == position[0] && head->y == position[1])
             {
                 add_node(head, &nodemun, end);
                 create_food(position);
             }
         }
         graph_thinks(nodemun);
         system("pause");
     }
}