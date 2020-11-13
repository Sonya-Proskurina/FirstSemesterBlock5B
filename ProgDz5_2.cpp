#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<string.h> 
#include<math.h>
#include<windows.h>

struct sprite {
    int xM, yM, directionM, frequencyM,RM;
};
 int newDirection(int direction) {
    if (direction == 0) direction = 315;
    else direction++;
    return direction;
}
void step(int x, int y, int M, int direction,int a[2]) {
    metka:
    switch (direction) {
    case 0:
        if (y + 1 < M ) {
            a[0] = x;
            a[1] = y + 1;
        }
        else {
            direction = 315;
            goto metka;
        }
      
        break;
    case 45:
        if (y + 1 < M &&x+1<M) {
            a[0] = x+1;
            a[1] = y + 1;
        }
        else {
            direction -=45;
            goto metka;
        }
        break;
    case 90:
        if ( x + 1 < M) {
            a[0] = x + 1;
            a[1] = y ;
        }
        else {
            direction -= 45;
            goto metka;
        }
        break;
    case 135:
        if (y - 1 >= 0 && x + 1 < M) {
            a[0] = x + 1;
            a[1] = y - 1;
        }
        else {
            direction -= 45;
            goto metka;
        }
        break;
    case 180:
        if (y - 1 >= 0 ) {
            a[0] = x ;
            a[1] = y - 1;
        }
        else {
            direction -= 45;
            goto metka;
        }
        break;
    case 225:
        if (y - 1 >= 0 && x - 1 >= 0) {
            a[0] = x - 1;
            a[1] = y - 1;
        }
        else {
            direction -= 45;
            goto metka;
        }
        break;
    case 270:
        if (x - 1 >=0) {
            a[0] = x - 1;
            a[1] = y ;
        }
        else {
            direction -= 45;
            goto metka;
        }
        break;
    case 315:
        if (y + 1 < M && x - 1 >= 0) {
            a[0] = x - 1;
            a[1] = y + 1;
        }
        else {
            direction -=45;
            goto metka;
        }
        break;
    }
   
}
void main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N, M, Q,bid=0;
    int myXY[2];
    int numHod = 0;
    int x, y, direction, frequency;
    bool live = true;
    struct sprite arr[100];
    printf("Введите размер поля:\n");
    scanf("%d",&M);
    printf("Введите количество монстров:\n");
    scanf("%d",&N);
    printf("Введите количество ходов:\n");
    scanf("%d",&Q);
    printf("Введите x, y, направление движения (в градусах) и частоту смены направлений героя:\n");
    scanf("%d%d%d%d",&x,&y,&direction,&frequency);
    for (int i = 0; i < N; i++) {
        printf("Введите x, y, направление движения (в градусах), частоту смены направлений и радиус врага №%d:\n",i+1);
        scanf("%d%d%d%d%d", &arr[i].xM, &arr[i].yM, &arr[i].directionM, &arr[i].frequencyM,&arr[i].RM);
      
    }
    if (M == 1) {
        goto end;
        live = false;
    }
    else
    for (int i = 0; i < Q; i++) {
        step(x,y,M,direction, myXY);
        x = myXY[0];
        y= myXY[1];
        for (int j = 0; j < N; j++) {
            step(arr[j].xM, arr[j].yM, M, arr[j].directionM, myXY);
            arr[j].xM = myXY[0];
            arr[j].yM = myXY[1];
            for (int k = arr[j].yM-arr[j].RM; k < arr[j].yM + arr[j].RM; k++) {
             
                /*if (arr[j].yM - arr[j].RM < 0) continue;
                if (arr[j].yM + arr[j].RM > M) break;*/
                for (int p = arr[j].xM - arr[j].RM; p < arr[j].xM + arr[j].RM; p++) {
              /*      if (arr[j].xM - arr[j].RM < 0) continue;
                    if (arr[j].xM + arr[j].RM > M) break;*/
                    if (k == x && p == y) { live = false; bid = j; goto end; }
                }
            }
        }

        numHod++;
        if (numHod == frequency) {
            direction = newDirection(direction);
            for (int j = 0; j < N; j++) {
                arr[j].directionM = newDirection(arr[j].directionM);
            }
        }
    }
end:
    if (live) printf("Игрок будет жить");
    else printf("Игрока уничтожит монстр №%d",bid+1);
    _getch();
}


