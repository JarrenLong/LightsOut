#include "lights.h"

LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hInst;
HBITMAP hBmp[2], hAward;
BITMAP bm;
HWND    hBtn[25];
int tileStatus[25];

bool checkWin()
{
    for(int i=0;i<25;i++)
    {
        if(tileStatus[i]!=0)
        {
            return false;
        }
    }
    return true;
}

void InitBoard()
{
    srand(GetTickCount());
    for(int i=0;i<25;i++)
    {
        tileStatus[i]=rand()%2;
    }
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
    HWND    hwnd;
    MSG     Msg;
    char *chClassName="LIGHTSOUT";
    WNDCLASSEX wcx;
    g_hInst=hInstance;

    wcx.cbSize           = sizeof(WNDCLASSEX);
    wcx.style            = CS_HREDRAW|CS_VREDRAW;
    wcx.lpfnWndProc      = (WNDPROC)WndProc;
    wcx.cbClsExtra       = 0;
    wcx.cbWndExtra       = 0;
    wcx.hInstance        = hInstance;
    wcx.hIcon            = LoadIcon(g_hInst,MAKEINTRESOURCE(MAINICON));
    wcx.hCursor          = NULL;
    wcx.hbrBackground    = (HBRUSH)CreateSolidBrush(RGB(128,0,0));
    wcx.lpszMenuName     = NULL;
    wcx.lpszClassName    = chClassName;
    wcx.hIconSm          = NULL;
    if (!RegisterClassEx(&wcx))
    {
        return FALSE;
    }

    hwnd=CreateWindowEx(0,chClassName,"Light's Out!",WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,CW_USEDEFAULT,258,277,NULL,NULL,hInstance,NULL);

    ShowWindow(hwnd,nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&Msg,NULL,0,0)>0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam)
{
    switch (Message)
    {
        case WM_CREATE:
        {
            int i=0;
            InitBoard();
            hAward = LoadBitmap(g_hInst, "GOLD_MEDAL");
            GetObject(hAward,sizeof(bm),&bm);
            for(int b=0;b<2;b++)
            {
                hBmp[b]=(HBITMAP)LoadImage(g_hInst,MAKEINTRESOURCE(100+b),IMAGE_BITMAP,0,0,LR_SHARED);
            }
            for(int i=0;i<25;i++)
            {
                if(hBtn[i]!=NULL)
                {
                    DestroyWindow(hBtn[i]);
                }
            }
            for(int y=0;y<5;y++)
            {
                for(int x=0; x<5;x++)
                {
                    hBtn[i]=CreateWindowEx(0,"BUTTON",NULL,WS_CHILD|WS_VISIBLE|BS_FLAT|BS_BITMAP,
                        50*x,50*y,50,50,hwnd,(HMENU)(1000+i),g_hInst,NULL);
                    SendMessage(hBtn[i],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[tileStatus[i]]);
                    i++;
                }
            }
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdcWindow, hdcMemory;
            hdcWindow = BeginPaint(hwnd, &ps);
            hdcMemory = CreateCompatibleDC(hdcWindow);
            SelectObject(hdcMemory, hAward);
            BitBlt(hdcWindow, 0, 0, bm.bmWidth, bm.bmHeight, hdcMemory, 0, 0, SRCAND);
            SelectObject(hdcMemory, hAward);
            BitBlt(hdcWindow, 0, 0, bm.bmWidth, bm.bmHeight, hdcMemory, 0, 0, SRCPAINT);
            DeleteDC(hdcMemory);
            EndPaint(hwnd, &ps);
        }
        break;
        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case 1000:
                case 1001:
                case 1002:
                case 1003:
                case 1004:
                case 1005:
                case 1006:
                case 1007:
                case 1008:
                case 1009:
                case 1010:
                case 1011:
                case 1012:
                case 1013:
                case 1014:
                case 1015:
                case 1016:
                case 1017:
                case 1018:
                case 1019:
                case 1020:
                case 1021:
                case 1022:
                case 1023:
                case 1024:
                {
                    if(tileStatus[((LOWORD(wParam))-1000)]==0)
                    {
                        tileStatus[((LOWORD(wParam))-1000)]=1;
                        SendMessage(hBtn[((LOWORD(wParam))-1000)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[1]);
                    }
                    else
                    {
                        tileStatus[((LOWORD(wParam))-1000)]=0;
                        SendMessage(hBtn[((LOWORD(wParam))-1000)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[0]);
                    }
                    //Change surrounding lights
                    if(tileStatus[((LOWORD(wParam))-999)]==0)
                    {
                        tileStatus[((LOWORD(wParam))-999)]=1;
                        SendMessage(hBtn[((LOWORD(wParam))-999)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[1]);
                    }
                    else
                    {
                        tileStatus[((LOWORD(wParam))-999)]=0;
                        SendMessage(hBtn[((LOWORD(wParam))-999)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[0]);
                    }
                    if(tileStatus[((LOWORD(wParam))-1001)]==0)
                    {
                        tileStatus[((LOWORD(wParam))-1001)]=1;
                        SendMessage(hBtn[((LOWORD(wParam))-1001)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[1]);
                    }
                    else
                    {
                        tileStatus[((LOWORD(wParam))-1001)]=0;
                        SendMessage(hBtn[((LOWORD(wParam))-1001)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[0]);
                    }
                    if(tileStatus[((LOWORD(wParam))-995)]==0)
                    {
                        tileStatus[((LOWORD(wParam))-995)]=1;
                        SendMessage(hBtn[((LOWORD(wParam))-995)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[1]);
                    }
                    else
                    {
                        tileStatus[((LOWORD(wParam))-995)]=0;
                        SendMessage(hBtn[((LOWORD(wParam))-995)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[0]);
                    }
                    if(tileStatus[((LOWORD(wParam))-1005)]==0)
                    {
                        tileStatus[((LOWORD(wParam))-1005)]=1;
                        SendMessage(hBtn[((LOWORD(wParam))-1005)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[1]);
                    }
                    else
                    {
                        tileStatus[((LOWORD(wParam))-1005)]=0;
                        SendMessage(hBtn[((LOWORD(wParam))-1005)],BM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hBmp[0]);
                    }
                    if(checkWin()==true)
                    {
                        for(int i=0;i<25;i++)
                        {
                            DestroyWindow(hBtn[i]);
                        }
                        hBtn[0]=CreateWindowEx(0,"BUTTON","Play Again",WS_CHILD|WS_VISIBLE|BS_FLAT,
                            0,226,125,24,hwnd,(HMENU)(1025),g_hInst,NULL);
                        hBtn[1]=CreateWindowEx(0,"BUTTON","Quit",WS_CHILD|WS_VISIBLE|BS_FLAT,
                            126,226,125,24,hwnd,(HMENU)(1026),g_hInst,NULL);
                        SendMessage(hwnd,WM_PAINT,0,0);
                    }
                }
                break;
                case 1025:
                {
                    SendMessage(hwnd,WM_CREATE,0,0);
                }
                break;
                case 1026:
                {
                    SendMessage(hwnd,WM_DESTROY,0,0);
                }
                break;
            }
        }
        break;
        case WM_DESTROY:
        {
            DeleteObject(hAward);
            DeleteObject(hBmp);
            DestroyWindow(hwnd);
            PostQuitMessage(0);
        }
        break;
        default:
            return DefWindowProc(hwnd,Message,wParam,lParam);
    }
}
