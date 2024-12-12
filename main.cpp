#include "TXLib.h"

struct Mario
{
    int x;
    int y;
    int vx;
    HDC image;
    HDC image_r;
    HDC image_l;
    int n_cadr;


    void draw()
    {
        txTransparentBlt(txDC(), x, y, 67, 100, image, 67*n_cadr, 0, TX_WHITE );
    }

    void animation()
    {
        n_cadr += 1;
        if(n_cadr>=12)
        {
            n_cadr = 0;
        }
    }

};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

Mario mario1 = {100, 300, 10, txLoadImage("mario_r.bmp"), txLoadImage("mario_r.bmp"), txLoadImage("mario_l.bmp"), 0};
Mario mario2 = {300, 150, 10, mario1.image, mario1.image_r, mario1.image_l, 0};

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        txBegin();

        mario1.draw();
        mario2.draw();

        mario1.animation();
        mario2.animation();

        mario1.x += mario1.vx;
        mario2.x += mario2.vx;

        if(mario1.x>700)

        {
            mario1.vx = -mario1.vx;
            mario1.image = mario1.image_l;
        }

        if(mario1.x<100)
        {
            mario1.vx = -mario1.vx;
            mario1.image = mario1.image_r;
        }
        if(mario2.x>700)

        {
            mario2.vx = -mario2.vx;
            mario2.image = mario2.image_l;
        }

        if(mario2.x<100)
        {
            mario2.vx = -mario2.vx;
            mario2.image = mario2.image_r;
        }


        txEnd();
        txSleep(50);

    }

txDeleteDC(mario1.image);
txDisableAutoPause();
return 0;
}

