#include<iostream>
#include<windows.h>
int main()
{   
    std::cout<<"�õģ����Ȱ������������Ҫ���ŵĵ�һ���γ�����,Ȼ���������ȡ�������\n";
    system("pause");
    HDC Screen=GetDC(NULL);
    POINT pt;
    GetCursorPos(&pt);
    std::cout<<pt.x<<"\t"<<pt.y<<"\n";
    std::cout<<"��������������ֵ\n����������������\n";
    int Classx=pt.x;
    int Classy=pt.y;
    double screenx=GetSystemMetrics(SM_CXSCREEN)/1920;
    double screeny=GetSystemMetrics(SM_CYSCREEN)/1080;
    COLORREF Pause=GetPixel(Screen,692*screenx,641*screeny);//��� ����ȼ�� ��ť�ϵ���ɫ
    COLORREF End=GetPixel(Screen,480*screenx,575*screeny);//EWTֲ���˵������ϵ�����ɫ
    COLORREF End1=GetPixel(Screen,1606*screenx,749*screeny);//EWTֲ���˵�ñ���ϵ���ɫ
    while(1)
    {
        Pause=GetPixel(Screen,692*screenx,641*screeny);//��� ����ȼ�� ��ť�ϵ���ɫ
        End=GetPixel(Screen,480*screenx,574*screeny);//EWTֲ���˵������ϵ�����ɫ
        End1=GetPixel(Screen,402*screenx,520*screeny);//EWTֲ���˵�ñ���ϵ���ɫ
        if(End=RGB(75,126,251)&&End1==RGB(170,143,108)&&Classy<1034*screeny)
        {   
            SetCursorPos((Classx+84)*screenx,(Classy+84)*screeny);
            if((Classy+84)*screeny>1034*screeny)
            {
                std::cout<<"��ҳ�γ��Ѿ�������ϣ����»������߸�����һ��Ŀγ�\n";
                break;
            }
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            Classy=Classy+(84*screeny);
            std::cout<<"���ڿγ������\n";
            Sleep(1976);
        }
        else if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {
            //�ƶ����
            SetCursorPos(692*screenx,641*screeny);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//���
        }
        Sleep(1024);
    }

     //���γ�֮�����84px
    ReleaseDC(NULL,Screen);
    system("pause");
    return 0;

}
