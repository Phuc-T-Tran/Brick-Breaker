#include "Ball.h"

#include "Paddle.h"
#include "Brick.h"
#include <stdlib.h>
#include "Constants.h"
#include "PlayState.h"

#include <iostream>
using std::cout;
using std::endl;

Ball::Ball(PlayState* playState)
    : playState(playState),
    image(playState->getResources().getTexture("ball")),
    velocity(0,-BallConstants::SPEED)
{
    rect.width = image.getWidth();
    rect.height = image.getHeight();

    velocity.rotate(rand() % 360);
}

Ball::Ball(ResourceManager& resources)
    : image(resources.getTexture("ball"))
{
    rect.x = rand() % GameConstants::GAME_WIDTH;
    rect.y = rand() % GameConstants::GAME_HEIGHT;

    rect.width = image.getWidth();
    rect.height = image.getHeight();

    int mod = BallConstants::TITLE_SPEED_MAX;
    velocity.y = -(rand() % mod + BallConstants::TITLE_SPEED_MIN);
    velocity.rotate(rand() % 360);
}

Ball::~Ball()
{
}

void Ball::setOnPaddle()
{
    Paddle& paddle = playState->getPaddle();
    onPaddle = true;
    rect.x = (float)(paddle.getX() + paddle.getWidth() / 2 - image.getWidth() / 2);
    rect.y = (float)(paddle.getY() - image.getHeight());
    velocity = { 0, -BallConstants::SPEED };
}

void Ball::idleBounce()
{
    rect.x += velocity.x;
    rect.y += velocity.y;

    if (rect.left() < 0)
    {
        rect.setLeft(0);
        velocity.x *= -1;
    }
    if (rect.right() > GameConstants::GAME_WIDTH)
    {
        rect.setRight(GameConstants::GAME_WIDTH);
        velocity.x *= -1;
    }
    if (rect.top() < 0)
    {
        rect.setTop(0);
        velocity.y *= -1;
    }
    if (rect.bot() > GameConstants::GAME_HEIGHT)
    {
        rect.setBot(GameConstants::GAME_HEIGHT);
        velocity.y *= -1;
    }
}

void Ball::update(Input& input)
{
    Paddle& paddle = playState->getPaddle();
    std::vector<Brick*>& bricks = playState->getBricks();

    if (onPaddle)
    {
        setOnPaddle();
        if (input.keyHit(SDL_SCANCODE_SPACE))
        {
            // Shoot off paddle in a random direction
            float angle = 0.0f;
            while (angle >= -10 && angle <= 10)
            {
                angle = (rand() % 90 - 45.0);
            }

            velocity.rotate(angle);
            onPaddle = false;
        }
    }
    else
    {
        // x-Collisions
        rect.x += velocity.x;

        // Check paddle collision
        if (rect.overlaps(paddle.getRect()))
        {
            if (rect.left() < paddle.getRect().left())
            {
                rect.setRight(paddle.getRect().left());
                if (velocity.x > 0)
                    velocity.x *= -1;
            }
            else if (rect.right() > paddle.getRect().right())
            {
                rect.setLeft(paddle.getRect().right());
                if (velocity.x < 0)
                    velocity.x *= -1;
            }
        }

        // Check brick collisions
        for (std::vector<Brick*>::iterator it = bricks.begin();
            it != bricks.end(); it++)
        {
            Rectangle colRect = (*it)->getRect();
            if (rect.overlaps(colRect))
            {
                (*it)->damage();
                if (rect.right() > colRect.right())
                    rect.setLeft(colRect.right());
                else if (rect.left() < colRect.left())
                    rect.setRight(colRect.left());
                velocity.x *= -1;

                if ((*it)->isDead())
                    bricks.erase(it);
                break;
            }
        }

        // y-Collisions
        rect.y += velocity.y;

        // Check paddle collisions
        if (rect.overlaps(paddle.getRect()))
        {
            velocity.x = (rect.centerX() - paddle.getRect().centerX()) / 12;
            if (velocity.x > 3)
                velocity.x = 3;
            else if (velocity.x < -3)
                velocity.x = -3;

            if (rect.top() < paddle.getRect().top())
                rect.setBot(paddle.getRect().top());
            else if (rect.bot() > paddle.getRect().bot())
                rect.setTop(paddle.getRect().bot());
            velocity.y *= -1;
        }

        // Check brick collisions
        for (std::vector<Brick*>::iterator it = bricks.begin();
            it != bricks.end(); it++)
        {
            Rectangle colRect = (*it)->getRect();
            if (rect.overlaps(colRect))
            {
                (*it)->damage();
                if (rect.top() < colRect.top())
                    rect.setBot(colRect.top());
                else if (rect.bot() > colRect.bot())
                    rect.setTop(colRect.bot());
                velocity.y *= -1;

                if ((*it)->isDead())
                    bricks.erase(it);
                break;
            }
        }

        // Check wall collisions
        if (rect.left() < 0)
        {
            rect.setLeft(0);
            velocity.x *= -1;
        }
        if (rect.right() > GameConstants::GAME_WIDTH)
        {
            rect.setRight(GameConstants::GAME_WIDTH);
            velocity.x *= -1;
        }
        if (rect.top() < 0)
        {
            rect.setTop(0);
            velocity.y *= -1;
        }
        if (rect.top() > GameConstants::GAME_HEIGHT)
        {
            setOnPaddle();
            playState->loseLife();
        }
    }
}

void Ball::render(Graphics& graphics)
{
    image.render(rect.x, rect.y, graphics);
}

int Ball::getX()
{
    return rect.x;
}

int Ball::getY()
{
    return rect.y;
}