#include <iostream>
using namespace std;

class Hero{
    private:
        
        
    public:
        int health;
        char level;
        Hero(){
            cout<<"Default"<<endl;
        }
        Hero(Hero &temp){
            this->health=temp.health;
            this->level=temp.level;
        }
        Hero(int health){
            this->health=health;
        }
        Hero(int health, char level){
            this->health=health;
            this->level=level;
        }
        void print(){
            cout<<level;
            cout<<health;
        }

        int getHealth(){
            return health;
        }
        void setHealth(int h){
            health=h;
        }
};
int main()
{
    Hero Timo;
    Timo.setHealth(100);
    Hero Timo1(100);
    Hero Timo2(100,'b');
    Timo.print();
    cout<<Timo2.getHealth()<<endl;
    Timo2.setHealth(80);
    Timo2.print();
    Hero *Timo3=new Hero();
    Hero Timo4(Timo2);
    // Deep copy vs Shallow copy
    delete Timo3;
    return 0;
}
