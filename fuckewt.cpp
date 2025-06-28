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
    COLORREF Pause=GetPixel(Screen,692*screenx,641*screeny);//检测 认真度检测 按钮上的蓝色
    COLORREF End=GetPixel(Screen,480*screenx,574*screeny);//EWT植物人的喇叭上的深蓝色
    COLORREF End1=GetPixel(Screen,406*screenx,519*screeny);//EWT植物人的帽子上的棕色
    POINT pt;
    GetCursorPos(&pt);
    while(End!=RGB(75,126,251)&&End1!=RGB(170,103,108))
    {
        if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {   
            //移动鼠标
            SetCursorPos(692*screenx,641*screeny);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//点击
        }
        Sleep(1024);
    Pause=GetPixel(Screen,692,641);//检测 认真度检测 按钮上的蓝色
    End=GetPixel(Screen,480,574);//EWT植物人的喇叭上的深蓝色
    End1=GetPixel(Screen,406,519);//EWT植物人的帽子上的棕色

    }
    if(End==RGB(75,126,251)&&End1==RGB(170,103,108)&&pt.y<1034*screeny)
    {
     //两课程之间相差84px
    SetCursorPos((Classx+84)*screenx,(Classy+84)*screeny);
    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
    Classy+84*screeny;
    goto LANDEXIELE;
    }
    else if(End==RGB(75,126,251)&&End1==RGB(170,103,108)&&pt.y>1034*screeny)
    {
        std::cout<<"此页课程已经播放完毕，请下滑鼠标或者更换下一天的课程";
    }
    ReleaseDC(NULL,Screen);
    system("pause");
    return 0;

}
