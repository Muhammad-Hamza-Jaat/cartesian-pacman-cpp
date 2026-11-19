#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
    srand(time(NULL));
    int WIDTH = 20, HEIGHT = 10;
    int Px, Py, cx, cy, ix, iy, px, py, bx, by, dir_Px, dir_Py, dist_i_P, dist_p_P, dist_b_P, dist_c_P;
    int i,j, hor_dis_px, ver_dis_py, win=0;
    char move;
    bool move_hor, move_ver;
    do
    {
    Px = rand()%WIDTH; Py = rand()%HEIGHT; //P = Pacman
    cx = rand()%WIDTH; cy = rand()%HEIGHT;
    ix = rand()%WIDTH; iy = rand()%HEIGHT;
    px = rand()%WIDTH; py = rand()%HEIGHT;
    bx = rand()%WIDTH; by = ((rand()%HEIGHT)%2==0)? 2: HEIGHT-3;
    }while( (Px==cx && Py==cy) || (Px==ix && Py==iy) ||(Px==px && Py==py) || (Px==bx && Py==by) ||(ix==cx && iy==cy) || (ix==px && iy==py) ||(ix==bx && iy==by) || (px==cx && py==cy) ||(bx==cx && by==cy) || (px==bx && py==by) );
    
    cout<<"W (up), A (left), S (down), D (right)\n\n";
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            (i==Py && j==Px)?  cout<<"\033[33m@\033[0m ":
            (i==cy && j==cx)?  cout<<"\033[38;5;208mC\033[0m ":
            (i==iy && j==ix)?  cout<<"\033[96mI\033[0m ":
            (i==py && j==px)?  cout<<"\033[95mP\033[0m ":
            (i==by && j==bx)?  cout<<"\033[31mB\033[0m ":  cout<<"* ";
        }
        cout<<endl;
    }
    do
    {
        do
    {
    cout<<"Move: "; cin>>move;
    dir_Px = dir_Py = 0;
    switch(move)
    {
        case 'W':
        case 'w': dir_Py= -1; break;
        case 'S':
        case 's': dir_Py= 1; break;
        case 'A':
        case 'a': dir_Px= -1; break;
        case 'D':
        case 'd': dir_Px= 1; break;
    }
        } while( move!='W'&&move!='w'&&move!='S'&&move!='s'&&move!='A'&&move!='a'&&move!='D'&&move!='d');

     move_hor = move=='A'||move=='a'||move=='D'||move=='d';
     move_ver = move=='W'||move=='w'||move=='S'||move=='s';

        Px= (move_hor && Px+dir_Px>=0 && Px+dir_Px<WIDTH)? Px+dir_Px:Px;
        Py= (move_ver && Py+dir_Py>=0 && Py+dir_Py<HEIGHT)? Py+dir_Py: Py;
        // Clyde
        cx= (move_hor && cx+dir_Px>=0 && cx+dir_Px<WIDTH)? cx+dir_Px:cx;
        cy= (move_ver && cy+dir_Py>=0 && cy+dir_Py<HEIGHT)? cy+dir_Py: cy;
        (cx==Px && cy==Py)? win=1:win=-1;
        switch(win)
    {
        case 1: break;
        case -1:
        {
            // Inky
            dist_c_P = ((cx-Px)*(cx-Px) + (cy-Py)*(cy-Py));
            dist_p_P = ((px-Px)*(px-Px) + (py-Py)*(py-Py));
            dist_b_P = ((bx-Px)*(bx-Px) + (by-Py)*(by-Py));
            dist_i_P = ((ix-Px)*(ix-Px) + (iy-Py)*(iy-Py));

            ( !(dist_i_P<dist_c_P && dist_i_P<dist_p_P && dist_i_P<dist_b_P))? ix=ix, iy=iy:
            (ix==Px&&iy==Py)? ix=ix, iy=iy:
// top
            ( Py!=0 && !(cx==Px&&cy==(Py-1)) && !(ix==Px&&iy==(Py-1))&& !(px==Px&&py==(Py-1)) && !(bx==Px&&by==(Py-1)))? iy=(Py-1), ix=Px:
//topright
            ( (Px!=WIDTH-1&&Py!=0) && !(cx==Px+1 && cy==Py-1)&&!(ix==Px+1 && iy==Py-1)&&!(px==Px+1 && py==Py-1)&&!(bx==Px+1 && by==Py-1) )? ix=Px+1, iy=Py-1:
//right
            ( Px!=WIDTH-1 && !(cx==Px+1 && cy==Py)&&!(ix==Px+1 && iy==Py)&&!(px==Px+1 && py==Py)&&!(bx==Px+1 && by==Py) )? ix=Px+1, iy=Py:
//bottomright
            ( (Px!=WIDTH-1&&Py!=HEIGHT-1) && !(cx==Px+1 && cy==Py+1)&&!(ix==Px+1 && iy==Py+1)&&!(px==Px+1 && py==Py+1)&&!(bx==Px+1 && by==Py+1) )? ix=Px+1, iy=Py+1:
//bottom
            ( Py!=HEIGHT-1 && !(cx==Px && cy==Py+1)&&!(ix==Px && iy==Py+1)&&!(px==Px && py==Py+1)&&!(bx==Px && by==Py+1) )? ix=Px, iy=Py+1:
//bottomleft
            ( (Px!=0 && Py!=HEIGHT-1) && !(cx==Px-1 && cy==Py+1)&&!(ix==Px-1 && iy==Py+1)&&!(px==Px-1 && py==Py+1)&&!(bx==Px-1 && by==Py+1) )? ix=Px-1, iy=Py+1:
//left
            ( Px!=0 && !(cx==Px-1 && cy==Py)&&!(ix==Px-1 && iy==Py)&&!(px==Px-1 && py==Py)&&!(bx==Px-1 && by==Py) )? ix=Px-1, iy=Py:
//topleft
            ( (Px!=0 && Py!=0) && !(ix==(Px-1) && iy==(Py-1)) && !(cx==Px-1 && cy==Py-1) &&!(px==Px-1 && py==Py-1) && !(bx==Px-1 && by==Py-1) )? ix=Px-1, iy=Py-1: ix=ix, iy=iy;
            (ix==Px&&iy==Py)? win=11:win=-1;
            
            switch(win)
            {
                case 11: break;
                case -1:
                {
                    //Pinky
                    hor_dis_px= abs(px-Px); ver_dis_py= abs(py-Py);
                    (px==Px&&py==Py)? px=px,py=py:
                    (hor_dis_px>ver_dis_py)?
                    (px>Px)? px-=1:px+=1
                    :
                    (hor_dis_px==ver_dis_py)?
//topleft
                    (px<Px && py<Py)? px+=1, py+=1:
//topright
                    (px>Px && py<Py)? px-=1, py+=1:
//bottomright
                    (px>Px && py>Py)? px-=1,py-=1
                    :
//bottomleft
                    px+=1,py-=1
                    : // ver_dis_py > hor_dis_px
                    (py>Py)? py-=1:py+=1 ;
                    (px==Px && py==Py)? win=12: win=-1;

                    switch(win)
                    {
                        case 12: break;
                        case -1:
                        {
                            // Blinky
                            (bx==Px && by==Py)? bx=bx, by=by
                            :
                            (by==2)?
                            ((bx<WIDTH-1)? bx+=1: (bx=WIDTH-1,by=HEIGHT-3)) // <-- when bx==WIDTH-1 i.e on the right edge
                            :
                            ((bx>0)? bx-=1: (bx=0, by=2)); //<-- when bx==0 i.e on the left edge
                            (bx==Px && by==Py)? win=13:win=-1;
                        }
                        break;
                    }
                }
                break;
            }
        }
        break;
    }
        for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            (i==iy && j==ix)?  cout<<"\033[96mI\033[0m ":
            (i==py && j==px)?  cout<<"\033[95mP\033[0m ":
            (i==by && j==bx)?  cout<<"\033[31mB\033[0m ": 
            (i==Py && j==Px)?  cout<<"\033[33m@\033[0m ":
            (i==cy && j==cx)?  cout<<"\033[38;5;208mC\033[0m ": cout<<"* ";
        }
        cout<<endl;
    }
    } while(win==-1);
    
    (win==1)? cout<<"\033[38;5;208mClyde\033[0m sounded the siren. The Ghostbusters saved \033[33mPac-Man\033[0m.\n\tYou win!" :
    (win==11)? cout<<"\033[96mInky\033[0m caught \033[33mPac-Man\033[0m.\n\tGame over!" :
    (win==12)? cout<<"\033[95mPinky\033[0m caught \033[33mPac-Man\033[0m.\n\tGame over!":
    (win==13)? cout<<"\033[31mBlinky\033[0m caught \033[33mPac-Man\033[0m.\n\tGame over!":
    cout<<"Unexpected Game State!";
    cout<<endl;
    return 0;
}