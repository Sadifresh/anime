#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

HDC image = txLoadImage("mario.bmp");
int n_cadr = 0;
int x = 100;


    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        txBegin();

        txTransparentBlt(txDC(), 400, 300, 67, 100, image, 67*n_cadr, 0, TX_WHITE );

        if(GetAsyncKeyState(VK_RIGHT))
        {
        x += 10;
        n_cadr += 1;
        if(n_cadr>=12)
         {
            n_cadr = 0;
         }
        }
        txEnd();
        txSleep(50);

    }

txDeleteDC(image);
txDisableAutoPause();
return 0;
}

