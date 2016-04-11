#include "Ball.h"
#include <stdio.h>

Ball::Ball(Colors color)
    : m_color(color)
{
}

bool Ball::isRed()
{
    if (m_color == Red)
        return true;
    else
        return false;
}

void Ball::printBall(){
	if(m_color== Red )printf(" Red ");
	else printf(" White ");
}