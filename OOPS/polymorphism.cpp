//Runtime Polymorphism 

#include <bits/stdc++.h>
using namespace std;

class Anime{
    public:
    virtual void watch(){
        cout<<"Watching anime"<<endl;
    }
};

class Naruto : public Anime{
    public:
    void watch() override{
        cout<<"Watching Naruto"<<endl;
    }
};

class OnePiece : public Anime{ 
    public:
    void watch() override{
        cout<<"Watching One Piece"<<endl;
    }
};

int main(){
    Anime anime;
    anime.watch();
    Anime *anime1 = new Naruto();
    Anime *anime2 = new OnePiece();

    anime1->watch();
    anime2->watch();

    delete anime1;
    delete anime2;

    return 0;  
}