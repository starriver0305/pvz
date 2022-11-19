#ifndef GLOOMSHROOM_H
#define GLOOMSHROOM_H
#include"basiczombie.h"
#include"basicplant.h"
#include"pea.h"
class GloomShroom:public BasicPlant
{
public:
    GloomShroom();
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // GLOOMSHROOM_H
