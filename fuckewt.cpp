#include<iostream>
#include<windows.h>
int main()
{
    HDC Screen=GetDC(NULL);
    int Classx=1469;
    int Classy=325;
    double screenx=GetSystemMetrics(SM_CXSCREEN)/1920;
    double screeny=GetSystemMetrics(SM_CYSCREEN)/1080;
    LANDEXIELE:
    COLORREF Pause=GetPixel(Screen,692*screenx,641*screeny);//��� ����ȼ�� ��ť�ϵ���ɫ
    COLORREF End=GetPixel(Screen,480*screenx,574*screeny);//EWTֲ���˵������ϵ�����ɫ
    COLORREF End1=GetPixel(Screen,406*screenx,519*screeny);//EWTֲ���˵�ñ���ϵ���ɫ
    POINT pt;
    GetCursorPos(&pt);
    while(End!=RGB(75,126,251)&&End1!=RGB(170,103,108))
    {
        if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {   
            //�ƶ����
            SetCursorPos(692*screenx,641*screeny);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//���
        }
        Sleep(1024);
    Pause=GetPixel(Screen,692,641);//��� ����ȼ�� ��ť�ϵ���ɫ
    End=GetPixel(Screen,480,574);//EWTֲ���˵������ϵ�����ɫ
    End1=GetPixel(Screen,406,519);//EWTֲ���˵�ñ���ϵ���ɫ

    }
    if(End==RGB(75,126,251)&&End1==RGB(170,103,108)&&pt.y<1034*screeny)
    {
     //���γ�֮�����84px
    SetCursorPos((Classx+84)*screenx,(Classy+84)*screeny);
    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
    Classy+84*screeny;
    goto LANDEXIELE;
    }
    else if(End==RGB(75,126,251)&&End1==RGB(170,103,108)&&pt.y>1034*screeny)
    {
        std::cout<<"��ҳ�γ��Ѿ�������ϣ����»������߸�����һ��Ŀγ�";
    }
    ReleaseDC(NULL,Screen);
    system("pause");
    return 0;

}
