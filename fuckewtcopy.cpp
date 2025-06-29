#include<iostream>
#include<windows.h>
int main()
{   
    std::cout<<"好的，请先把你的鼠标放在你要播放的第一个课程上面,然后按任意键读取鼠标坐标\n";
    system("pause");
    HDC Screen=GetDC(NULL);
    POINT pt;
    GetCursorPos(&pt);
    std::cout<<pt.x<<"\t"<<pt.y<<"\n";
    std::cout<<"不用在意这两个值\n现在鼠标可以移走了\n";
    int Classx=pt.x;
    int Classy=pt.y;
    double screenx=GetSystemMetrics(SM_CXSCREEN)/1920;
    double screeny=GetSystemMetrics(SM_CYSCREEN)/1080;
    COLORREF Pause=GetPixel(Screen,692*screenx,641*screeny);//检测 认真度检测 按钮上的蓝色
    COLORREF End=GetPixel(Screen,480*screenx,575*screeny);//EWT植物人的喇叭上的深蓝色
    COLORREF End1=GetPixel(Screen,1606*screenx,749*screeny);//EWT植物人的帽子上的棕色
    while(1)
    {
        Pause=GetPixel(Screen,692*screenx,641*screeny);//检测 认真度检测 按钮上的蓝色
        End=GetPixel(Screen,480*screenx,574*screeny);//EWT植物人的喇叭上的深蓝色
        End1=GetPixel(Screen,402*screenx,520*screeny);//EWT植物人的帽子上的棕色
        if(End=RGB(75,126,251)&&End1==RGB(170,143,108)&&Classy<1034*screeny)
        {   
            SetCursorPos((Classx+84)*screenx,(Classy+84)*screeny);
            if((Classy+84)*screeny>1034*screeny)
            {
                std::cout<<"此页课程已经播放完毕，请下滑鼠标或者更换下一天的课程\n";
                break;
            }
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
            Classy=Classy+(84*screeny);
            std::cout<<"本节课程已完成\n";
            Sleep(1976);
        }
        else if(Pause==RGB(46,134,255)||Pause==RGB(0,102,255))
        {
            //移动鼠标
            SetCursorPos(692*screenx,641*screeny);
            mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//点击
        }
        Sleep(1024);
    }

     //两课程之间相差84px
    ReleaseDC(NULL,Screen);
    system("pause");
    return 0;

}
