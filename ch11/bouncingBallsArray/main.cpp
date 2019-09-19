//Program to make circles move back and forth across the screen
//              -- for _C++ for Lazy Programmers_

#include "SSDL.h"

enum {RADIUS = 20};     //Ball radius & speed
enum {SPEED  =  5};     // ...move 5 pixels for every frame

enum class Direction { LEFT=-1, RIGHT=1 };
//Why -1 for left?  Because left means going in the minus direction.
//See where we update ball.x_ in the main loop for how this can work


struct Point2D                                  
{
    int x_=0, y_=0;
};

struct Ball             //A ball is an X, Y location, 
{                       //and a direction, left or right
    Point2D   location_;
    Direction direction_;
};

//Ball functions
void initializeBalls (      Ball balls[], int howMany);
void drawBalls       (const Ball balls[], int howMany);
void moveBalls       (      Ball balls[], int howMany);
void bounceBalls     (      Ball balls[], int howMany);

int main (int argc, char** argv)
{
    SSDL_SetWindowTitle ("Back-and-forth balls example.  "
                         "Hit Esc to exit.");

    //initialize balls' position, size, and rate and direction of movement
    enum {MAX_BALLS = 3};
    Ball balls [MAX_BALLS];
    initializeBalls (balls, MAX_BALLS);

    enum {FRAMES_PER_SECOND = 70};      
    SSDL_SetFramesPerSecond(FRAMES_PER_SECOND); 

    while (SSDL_IsNextFrame ())
    {
        SSDL_DefaultEventHandler ();
        
        //*** DISPLAY THINGS ***
        SSDL_RenderClear ();    //first, erase previous frame
        drawBalls (balls, MAX_BALLS);

        //*** UPDATE  THINGS ***
        moveBalls (balls, MAX_BALLS);
        bounceBalls(balls, MAX_BALLS); //if ball moves offscreen, 
                                       // reverse its direction
    }

    return 0;
}

//Ball functions

void initializeBalls (Ball balls[], int howMany)
{
    for (int i = 0; i < howMany; ++i)
    {
        balls[i].location_.x_ = i * SSDL_GetWindowWidth ()/3;
        balls[i].location_.y_ = i * SSDL_GetWindowHeight()/3 
                                 + SSDL_GetWindowHeight()/6;
        balls[i].direction_   = Direction::RIGHT;
    }
}

void drawBalls  (const Ball balls[], int howMany)
{
    for (int i = 0; i < howMany; ++i)
        SSDL_RenderDrawCircle (balls[i].location_.x_,
                               balls[i].location_.y_, RADIUS);
}

void moveBalls  (Ball balls[], int howMany)
//update balls' x position based on speed
// and current direction
{
    for (int i = 0; i < howMany; ++i)
        balls[i].location_.x_ += int (balls[i].direction_)*SPEED;
}

void bounceBalls(Ball balls[], int howMany)
{
    //if any ball moves off screen, reverse its direction
    for (int i = 0; i < howMany; ++i)
        if      (balls[i].location_.x_ >= SSDL_GetWindowWidth()) 
            balls[i].direction_ = Direction::LEFT;
        else if (balls[i].location_.x_ <  0) 
            balls[i].direction_ = Direction::RIGHT;
}
