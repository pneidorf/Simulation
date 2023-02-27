#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;
//дистанция между точками
int distance_point(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
//класс точки
class Point{
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y){
    }
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    void set_x(int new_x){
        x = new_x;
    }
    void set_y(int new_y){
        y = new_y;
    }
};
//Класс объекта
class Object{
private:
    const int id;
    int x_pos, y_pos;
    int speed;
    int S;//расстояние пройденное
    vector<Point> list_point = {};
public:
    Object(int id, int x_pos, int y_pos, int speed) \
    : id(id), x_pos(x_pos), y_pos(y_pos), speed(speed){
        Point one_point(x_pos, y_pos);
        list_point.push_back(one_point);
        S = 0;
    }
    int get_id(){
        return id;
    }
    int get_x_pos(){
        return x_pos;
    }
    int get_y_pos(){
        return y_pos;
    }
    void set_x_pos(int new_x_pos){
        x_pos = new_x_pos;
    }
    void set_y_pos(int new_y_pos){
        y_pos = new_y_pos;
    }
    int get_count_point(){
        return list_point.size();
    }
    int get_S(){
        return S;
    }
    //случ движение
    void randmove(int x_size_map, int y_size_map){
        int rrand = rand() % 10;
        int m_x = 0, m_y = 0;
        if(rrand == 0){
            if(x_pos + speed <= x_size_map)
                m_x = speed;
        }
        else if(rrand == 1){
            if(x_pos - speed >= 0)
                m_x = -1 * speed;       
        }
        else if(rrand == 2){
            if(y_pos + speed <= y_size_map)
                m_y = speed;
        }
        else if(rrand == 3){
            if(y_pos - speed >= 0)
                m_y = -1 * speed;
        }
        
        if(m_x != 0 || m_y != 0){
            int x1 = x_pos, y1 = y_pos;
            y_pos += m_y;
            x_pos += m_x;
            S += distance_point(x1, y1, x_pos, y_pos);
            Point *point = new Point(x_pos, y_pos);
            list_point.push_back(*point);

        }
    }
    int dist_to_point(int x, int y){
        return distance_point(x, y, x_pos, y_pos);
    }
    int dist_to_point(Point point){
        return distance_point(point.get_x(), point.get_y(), x_pos, y_pos);
    }
};
//создание не повторяющегося id
int create_id_object(vector<Object*> list_obj){
    int i;
    int id;
    int proverka;
    while(1){
        proverka = 1;
        id = (rand() % 10000) + 1;
        for(i = 0; i < list_obj.size(); ++i){
            if(id == list_obj[i]->get_id()){
                proverka = 0;
                break;
            }
        }
        if(proverka == 1){
            return id;
        }
    }
}
//Движение обектов 
void randmoves(int x_size_map, int y_size_map, vector<Object*> list_obj){
    int i;
    for(i = 0; i < list_obj.size(); ++i){
        list_obj[i]->randmove(x_size_map, y_size_map);
    }
}
//Симуляция обьектов
int Simulation(int x_size_map, int y_size_map){
    int cn_obj, ch_per;
    int i;
    cout<<"Vvedite kolichestvo objectov: ";
    if(!scanf("%d", &cn_obj)){
        cout<<"Error cn_obj: ne chislo\n";
        return -1;
    }
    cout<<"Vvedite kolichestvo peremeshenii: ";
    if(!scanf("%d", &ch_per)){
        cout<<"Error ch_per: ne chislo\n";
        return -1;
    }
    vector<Object*> list_obj;
    int id, x_pos, y_pos, speed;
    //создание обьектов
    for(i = 0; i < cn_obj; ++i){
        id = create_id_object(list_obj);
        x_pos = rand() % 1000;
        y_pos = rand() % 1000;
        speed = (rand() % 50) + 20;
        Object *ptr_pbj = new Object(id, x_pos, y_pos, speed);
        list_obj.push_back(ptr_pbj);
        cout<<"Create new obj: id = "<<id<<endl;
        cout<<"pos obj: "<<x_pos<<", "<<y_pos<<" speed = "<<speed<<endl;
    }
    for(i = 0; i < ch_per; ++i){
        randmoves(x_size_map, y_size_map, list_obj);
    }
    for(i = 0; i < list_obj.size(); ++i){
        cout<<"id: "<<list_obj[i]->get_id()<<endl;
        cout<<"count points: "<<list_obj[i]->get_count_point()<<",  S = "<<list_obj[i]->get_S()<<endl;

    }

}

int main(){
    srand(time(NULL));
    Simulation(1000,1000);
    cout << "End\n";
}






