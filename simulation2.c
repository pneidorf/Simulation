#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"



typedef struct object{
    int id;
    int coordination[2];
    int **save;
}obj;


void randomove(obj * stek, int ch_obj, int ch_per){   // ch_obj - кол-во объектов; ch_per - кол-во перемещений
    int rrand, i, j;
    for (j = 0; j < ch_obj; j++){
        for(i = 1; i < ch_per; i++){
            rrand = rand()%4;
            
            if (rrand == 1){
                stek[j].coordination[1] += 2;
            }
            if (rrand == 2){
                stek[j].coordination[0] += 2;
            }
            if (rrand = 3){
                stek[j].coordination[1] -= 2;
            }
            if (rrand ==4){
                stek[j].coordination[0] -= 2;
            }
            
        stek[j].save[i][0]=stek[j].coordination[0];
        stek[j].save[i][1]=stek[j].coordination[1];
        }
    }
}

int rast(int id1, int id2, obj * stek, int ch_obj, int ch_per){
    int x1,y1,x2,y2;
    int i,j;
    int result;
    int f1,f2;

    for(i = 0; i < ch_obj; i++){
        if(id1 == stek[i].id){
            x1 = stek[i].coordination[0];
            y1 = stek[i].coordination[1];
        }

        if(id2 == stek[i].id){
            x2 = stek[i].coordination[0];
            y2 = stek[i].coordination[0];
        }
    }

    printf("Coordinati pervoy tochki(%d,%d)", x1,y1);
    printf("\nCoordinati vtoroy tochki(%d,%d)", x2,y2);

    f1 = x2 - x1;
    f2 = y2 - y1;

    result = sqrt(pow(f1,2) + pow(f2,2));
    return result; 

}

int main(){

srand(time(NULL));
int i, j, ch_obj, ch_per, id;
obj *stek;
int x,y;
int srav;
int id1, id2, distance;

printf("Vvedite kolichestvo objectov: ");
scanf("%d", &ch_obj);


printf("Vvedite kolichestvo peremeshenii: ");
scanf("%d", &ch_per);

stek = (obj*)malloc(ch_obj * sizeof(obj));

    for(i = 0; i < ch_obj; i++){
        obj point;
        point.id = 0;
        point.coordination[0] = -1;
        point.coordination[1] = -1;
        point.save = (int**)malloc(ch_per * sizeof(int*));

        for(j = 0; j < ch_per; j++){

            point.save[j] = (int*)malloc(sizeof(int) * 2);
        }
    
    stek[i] = point;

    }

    for(i = 0; i < ch_obj; i++){
        printf("Vvedite Id objecta: ", i+1);
        scanf("%d", &id);
        srav = 0;

        for(j = 0; j < ch_obj; j++){
            if(id == stek[j].id){
                srav = 1;
            }
        }

        if (srav == 0){
            stek[i].id = id;
        }
        else{
            printf("\nId ne dolzhen sovpadat");
            i--;
        }
    }
    
    for(j = 0; j<ch_obj; j++){
        if(x!=stek[j].coordination[0] && y!=stek[j].coordination[1]){
            srav = 1;
        }

        else{
            srav = 0;
            continue;
        }
    }

    if (srav == 1){
        stek[i].coordination[0] = x;
        stek[i].coordination[1] = y;
        stek[i].save[0][0] = x;
        stek[i].save[0][1] = y;
    }
    else{
        i--;
    }

    randomove(stek,ch_obj,ch_per);

    printf("Vvedite Id pervoiy tochki:");
    scanf("%d", &id1);

    printf("Vvedite Id vtoroy tochki:");
    scanf("%d", &id2);

    distance = rast(id1,id2,stek,ch_obj,ch_per);
    printf("\nDistance between points: %d", distance);


    for(int jj = 0; jj < ch_obj; jj++){
        for(j=0; j<ch_per; j++){
            free(stek[jj].save[j]);
        }
    free(stek[jj].save);
    }
    free(stek);


}
