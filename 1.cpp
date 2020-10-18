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

/*这是一个失败的贪吃蛇
零基础很难在九天内完成但并不是不可能
只是我个人失败了

我从上周六开始看mooc学习
学了最基本的计算、判断、循环、数组
然后花了半天时间弄明白git
再耗费两天的时间为了做好ui界面的互动去学easyx
始终是充满兴趣和干劲的

但游戏的运行远远没有我想的那么简单
为了速成我有些跳跃地学习
当我开始接触链表
然后才知道要学指针
学习过程中又碰到了struct等没讲过的指令
就是越学越不会的感觉

做游戏的兴趣是有的
但我对玩游戏的兴趣也是真的
懒是原罪
当我意识到一点点学是几乎不可能按时完成后
我就速学、跳学
看网上最简单贪吃蛇的源代码然后研究
可问题源源不断

总之
我失败了
但我仍然感谢MEMO程序组给我二面和实习期的机会（我本是一面就被刷的）
这个星期我过的格外充实
不出意外
我明天还回来
不过不再是零基础了

（这个程序不懂哪里出问题了，也没有出错提示，重启多次也无用）
*/


//决定游戏关闭与否
int abc = 0;

void start()
{
    //创建窗口
    initgraph(800, 600,NULL);
    //主界面背景图片
    IMAGE logo_img;
    loadimage(&logo_img, _T("logo1.jpg"), 800, 600);
    putimage(0, 0, &logo_img);
    //选项显示
    setlinecolor(WHITE);
    setfillcolor(BLACK);
    settextstyle(25, 0, _T("宋体"));

    fillrectangle(349, 550, 451, 490);
    outtextxy(350, 510, _T("退出游戏"));

    fillrectangle(349, 450, 451, 390);
    outtextxy(350, 410, _T("游戏帮助"));

    fillrectangle(349, 350, 451, 290);
    outtextxy(350, 310, _T("开始游戏"));
   
    MOUSEMSG mouse;
    IMAGE illustrate_img;
    loadimage(&illustrate_img, _T("illustrate.jpg"), 800, 600);

    int o = 1;
       
    while (o==1) {
        mouse = GetMouseMsg();
        switch (mouse.uMsg) {
        case WM_LBUTTONDOWN:
            //游戏帮助
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 390 && mouse.y < 450)) {
                putimage(0, 0, &illustrate_img);
                _getch();
                cleardevice();

                putimage(0, 0, &logo_img);

                setlinecolor(WHITE);
                setfillcolor(BLACK);
                settextstyle(25, 0, _T("宋体"));

                fillrectangle(349, 550, 451, 490);
                outtextxy(350, 510, _T("退出游戏"));

                fillrectangle(349, 450, 451, 390);
                outtextxy(350, 410, _T("游戏帮助"));

                fillrectangle(349, 350, 451, 290);
                outtextxy(350, 310, _T("开始游戏"));  
                    
            }
            //开始游戏
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 290 && mouse.y < 350)) {
                cleardevice();
                o = 0;
                break;
            }
            //退出游戏
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

//分数和等级
void print_score_grade(int nodemun,int grade)
{
   
    wchar_t ch[5];
    wchar_t ch2[2];

   
    settextcolor(RGB(0, 255, 255));
    settextstyle(20, 0, _T("宋体"));

    setfillcolor(RED);
    solidrectangle(580, 150, 700, 170);
    solidrectangle(580, 100, 700, 120);

    swprintf(ch, 5, _T("%d"), nodemun * 10 - 10);
    swprintf(ch2, 2, _T("%d"), grade);

    outtextxy(580, 150, ch);
    outtextxy(580, 100, ch2);
    system("pause");
}

//链表
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

 //蛇
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
     if (end != NULL)//抹去上一个的蛇尾
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
     while (current->next != NULL)//寻找蛇尾
     {
         current = current->next;
     }

     switch (move)//添加新的头节点，删除尾节点
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
     for (i = 1; i < nodemun; i++)//寻找新的蛇尾
     {
         p = p->next;
     }
     p->next = NULL;//将新的尾节点指向NULL
     return new_node;//返回新的头节点
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

     if (*nodemun > 1)//蛇有两个节点及以上
     {
         while (current->next != NULL)
         {
             if (i == *nodemun - 1)//寻找倒数第二个节点，并保存其值
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

         //根据蛇尾运动方向添加节点
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


     if (*nodemun == 1)//蛇只有一个节点
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
     if (nodemun >= 5)//蛇有5个节点以上
     {
         current = head->next->next->next->next;//current指向第5个节点
         for (i = 5; i <= nodemun; i++)//判断蛇是否吃到自己
         {
             if (head->x == current->x && head->y == current->y)
             {
                 return 0;
             }
             current = current->next;
             i++;
         }
     }
     if (head->x < 0 || head->x>490 || head->y < 0 || head->y>390)//判断蛇身是否超出游戏界面
         return 0;
     return 1;
 }


 void graph_thinks(int nodemun)
 {
     wchar_t ch[5];
     setfillcolor(BLACK);
     solidrectangle(0, 0, 850, 400);
     setbkmode(TRANSPARENT);//设置背景模式
     settextcolor(RGB(0, 255, 255));
     settextstyle(40, 0, _T("宋体"));
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
             if (_kbhit())//获取鼠标操作
             {
                 _getch();
                 kb = _getch();
                 //不能向当前蛇头移动方向的反方向运动
                 if (!(kb == up && move == down || kb == down && move == up || kb == right && move == lift || kb == lift && move == right))
                     move = kb;
             }
             head = changeLink(head, end, nodemun);
             if (check(head, nodemun) == 0)//合法性检测
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