#include<iostream>
#include<windows.h>
int main()
{
    HDC Screen=GetDC(NULL);
    COLORREF Pause=GetPixel(Screen,692,641);//检测 认真度检测 按钮上的蓝色
    COLORREF End=GetPixel(Screen,480,574);//EWT植物人的喇叭上的深蓝色
    COLORREF End1=GetPixel(Screen,406,519);//EWT植物人的帽子上的棕色
    while(End!=RGB(75,126,251)&&End1!=RGB(170,103,108))
    {
        if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {   
            //移动鼠标
            SetCursorPos(692,641);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//点击
        }
        Sleep(1024);
    Pause=GetPixel(Screen,692,641);//检测 认真度检测 按钮上的蓝色
    End=GetPixel(Screen,480,574);//EWT植物人的喇叭上的深蓝色
    End1=GetPixel(Screen,406,519);//EWT植物人的帽子上的棕色

    }
    std::cout<<"本节课程结束\n若需要重新启用，请按1；不需要，请按0";
    return 0;
}
