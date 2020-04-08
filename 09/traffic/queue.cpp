#include "queue.hh"
#include <iostream>

using namespace std;
// Implement the member functions of Queue here

Queue::Queue(unsigned int cycle){
    cycle_=cycle;
}

Queue::~Queue(){
    while (first_!= nullptr){
        Vehicle*car_released=first_;
        first_=first_->next_;
        free(car_released);
    }
}

void Queue::enqueue(string reg)
{
    if(light_=="GREEN"){
        cout<<light_<<": The vehicle "<<reg<<" need not stop to wait"<<endl;
    }
    else{
        vehicle_wait_=vehicle_wait_+1;
        Vehicle* new_car= new Vehicle;
        new_car->reg_number_=reg;
        new_car->next_=nullptr;
        if(first_==nullptr){
            first_=last_=new_car;
        }
        else{
            last_->next_=new_car;
            last_=new_car;

        }
    }
}



void Queue::switch_light(){
    if(light_=="RED"){
        vehicle_pass_=cycle_;
        light_="GREEN";
        if(vehicle_wait_==0){
            cout<<light_<<": No vehicles waiting in traffic lights"<<endl;
        }
        else if(vehicle_wait_<vehicle_pass_&&vehicle_wait_!=0)
        {
            cout<<light_<<": Vehicle(s) ";
            while (vehicle_wait_!= 0){
                Vehicle* car_released = first_;
                first_ = first_ -> next_;
                cout<<car_released->reg_number_<<" ";
                free (car_released);
                --vehicle_wait_;
            }
            cout<<"can go on"<<endl;
            light_="RED";
        }
        else if(vehicle_wait_>=vehicle_pass_)
        {
            cout<<light_<<": Vehicle(s) ";
            while (vehicle_pass_!= 0){
                Vehicle*car_released= first_;
                first_ = first_ -> next_;
                cout<<car_released->reg_number_<<" ";
                free (car_released);
                --vehicle_pass_;
                --vehicle_wait_;
            }
            cout<<"can go on"<<endl;
            light_="RED";
        }
    }

    else
    {
        light_="RED";
        if(vehicle_wait_==0){
            cout<<light_<<": No vehicles waiting in traffic lights"<<endl;
        }
        else {
            Vehicle* temp;
            temp=first_;
            cout<<light_<<": Vehicle(s) ";
            while(temp !=0)
            {
                cout<<temp->reg_number_<<" ";
                temp=temp->next_;
            }
            vehicle_pass_=0;
            cout<<"waiting in traffic lights"<<endl;

        }
    }
}





void Queue::print()
    {
        if(vehicle_wait_==0){
            cout<<light_<<": No vehicles waiting in traffic lights"<<endl;
        }
        else
        {
            Vehicle* temporary_;
            temporary_=first_;
            cout<<light_<<": Vehicle(s) ";
            while(temporary_!=0){
                cout<<temporary_->reg_number_<<" ";
                temporary_=temporary_->next_;
            }
            cout<<"waiting in traffic lights"<<endl;

        }
    }


void Queue::reset_cycle(unsigned int cycle){
        cycle_=cycle;
    }
