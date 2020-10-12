#include "viruslarge.h"

VirusLarge::VirusLarge(QObject *parent): QObject(parent) {
    timer = new QTimer(this);

    x = 100;
    y = 100;

    this->setPixmap(QPixmap(picturePath).scaled(100, 100));
    this ->setPos(x, y);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);

}

void VirusLarge::update(){
    y+= 2;
    setPos(x,y);

//    if(!scene()->collidingItems(this).isEmpty()){
//        scene()->removeItem(this);
//        delete(this);
//    }
    if(y == 200){
        collidedWithSyringe();
    }
    if(y>800){
        scene()->removeItem(this);
        delete this;
    }
}

void VirusLarge::collidedWithSyringe(){
    this->setPixmap(QPixmap(smashedPicPath).scaled(100, 100));
}
