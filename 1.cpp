#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <MMSystem.h>

void main()
{
    initgraph(800, 600);// ������

    IMAGE logo_img;
    loadimage(&logo_img, _T("logo1.jpg"), 800, 600);
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

    MOUSEMSG mouse;
    IMAGE illustrate_img;
    loadimage(&illustrate_img, _T("illustrate.jpg"), 800, 600);

    while (1) {
        mouse = GetMouseMsg();

        switch (mouse.uMsg)
        {
        case WM_LBUTTONDOWN:
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 390 && mouse.y < 450))
            {
                putimage(0, 0, &illustrate_img);
                fillrectangle(649, 350, 751, 290);
                outtextxy(650, 310, _T("���ز˵�"));
                if (WM_LBUTTONDOWN&&(mouse.x>649&&mouse.x<751)&&(mouse.y>290&&mouse.y<350)) {
                    cleardevice();
                }
                
            }
            break;
        
            if ((mouse.x > 349 && mouse.x < 451) &&
                (mouse.y > 290 && mouse.y < 350))
            {
                cleardevice();
                return;
            }
        }
    }
}
