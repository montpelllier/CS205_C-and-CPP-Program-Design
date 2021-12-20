//
// Created by Think on 2021/5/13.
//

#ifndef LAB_CSTEREOSHAPE_H
#define LAB_CSTEREOSHAPE_H

#include <iostream>

struct Formatting{
    std::ios_base::fmtflags flag;
    std::streamsize pr;
};

class CStereoShape {//立体图形
private:
    static int numberOfObject;

protected:
    Formatting SetFormat(int prec) const;
    void Restore(Formatting& f) const;

public:
    //CStereoShape;
    CStereoShape(){
        numberOfObject++;
    };
    virtual double GetArea();
    virtual double GetVolume();
    virtual void Show();
    static int GetNumOfObject(){
        return numberOfObject;
    };

};

class CCube : public CStereoShape{
private:
    double length, width, height;

public:
    CCube(double length, double width, double height);
    CCube(CCube& cub);
    CCube(){
        length = 1;
        width = 1;
        height = 1;
    }
    double GetArea();
    double GetVolume();
    void Show();
};

class CSphere : public CStereoShape{
private:
    double radius;

public:
    CSphere(double radius);
    CSphere(CSphere& sphere);
    CSphere(){
        radius = 1;
    }
    double GetArea();
    double GetVolume();
    void Show();
};

#endif //LAB_CSTEREOSHAPE_H
