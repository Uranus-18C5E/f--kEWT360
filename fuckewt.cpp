#include<iostream>
#include<windows.h>
int main()
{
    HDC Screen=GetDC(NULL);
    COLORREF Pause=GetPixel(Screen,692,641);//��� ����ȼ�� ��ť�ϵ���ɫ
    COLORREF End=GetPixel(Screen,480,574);//EWTֲ���˵������ϵ�����ɫ
    COLORREF End1=GetPixel(Screen,406,519);//EWTֲ���˵�ñ���ϵ���ɫ
    while(End!=RGB(75,126,251)&&End1!=RGB(170,103,108))
    {
        if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {   
            //�ƶ����
            SetCursorPos(692,641);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//���
        }
        Sleep(1024);
    Pause=GetPixel(Screen,692,641);//��� ����ȼ�� ��ť�ϵ���ɫ
    End=GetPixel(Screen,480,574);//EWTֲ���˵������ϵ�����ɫ
    End1=GetPixel(Screen,406,519);//EWTֲ���˵�ñ���ϵ���ɫ

    }
    std::cout<<"���ڿγ̽���\n����Ҫ�������ã��밴1������Ҫ���밴0";
    return 0;
}
