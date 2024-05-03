//
//  Temp.cpp
//  IT003-OT
//
//  Created by Thinnn on 27/06/2023.
//
#include <iostream>
#include <stdio.h>

struct point
{
    int x, y;
};

struct vertex
{
    point P;
};

struct shape
{
    vertex V[100];
};

struct Shapes
{
    shape A;
};



int main()
{
    Shapes hinhanh;
    int i = 1;
    hinhanh.A.V[1].P.x;
}
