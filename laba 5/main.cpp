#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>

#include "coordinates.hpp"
#include "Object.hpp"
#include "UserEquipment.hpp"

using namespace std;

vector <Object*> Create_UserEquipment(int mapx, int mapy, double latA, double lonA, double scale){
    int count;
    cout<<"Count objects (recommended: 1 - 10) = ";
    cin>>count;
    vector <Object*> obj;
    Object *newobj;
    int i, i2;
    int id;
    int create_id;
    double pos_lat, pos_lon;
    for(i = 0; i < count; ++i){
        create_id = 0;
        while(create_id != 1){
            create_id = 1;
            id = 1000 + (rand() % 10000);
            for(i2 = 0; i2 < i; ++i2){
                if(id == obj[i2]->get_id()){
                    create_id = 0;
                    break;
                }
            }
        }
        cout<<"id = "<<id<<endl;
        pos_lat = latA + (rand() % mapx) * scale;
        pos_lon = lonA + (rand() % mapy) * scale;
        newobj = new UserEquipment(id, pos_lat, pos_lon, scale);
        obj.push_back(newobj);
    }
    return obj;
}

void Simulation(vector <Object*> *objs, int mapx, int mapy){
    int count;
    cout<<"Count iteration move(recommended: 1 - 10) = ";
    cin>>count;
    int i, i2;
    for(i = 0; i < count; ++i){
        cout<<"step: "<<i<<"\n";
        for(i2 = 0; i2 < objs->size(); ++i2){
            objs->at(i2)->randomwalk(mapx, mapy);
            cout<<"\tid = "<<objs->at(i2)->get_id()<<"\tlat = "<<objs->at(i2)->get_position()->get_lat()<<"\tlon = "<< objs->at(i2)->get_position()->get_lon()<<"\n";
        }
    }
    Object *ptr, *ptr2;
    for(i2 = 0; i2 < objs->size(); ++i2){
        ptr = objs->at(i2);
        cout<<"id = "<<ptr->get_id()<<"\n";
        cout<<"\tpath = "<<ptr->get_path()<<"\n";
        cout<<"\tpath to object:\n";
        for(i = 0; i < objs->size(); ++i){
            if(i != i2){
                ptr2 = objs->at(i);
                cout<<"\t\tid("<<ptr2->get_id()<<") = "<<ptr->get_path_coord(ptr2->get_position())<<"\n";
            }
        }
    }
}
int main(){
    srand(time(NULL));
    int size_x = 1000, size_y = 1000;
    double latA = 55.030377, lonA = 82.924486;
    double latB = 54.992544, lonB = 82.992803;
    vector <Object*> objs;
    double scale = (lonB - lonA)/(double)size_x;
    cout<<"scale = "<<scale<<"\n";
    objs = Create_UserEquipment(size_x, size_y, latA, latB, scale);
    Simulation(&objs, size_x, size_y);
}
