#include "MapNode.h"
#include <iostream>

MapNode::MapNode(int i, float x, float y, int width, int height, bool s, Map* m) : SceneNode(i, x, y, width, height)
{
    map = m;
    solid = s;
}

MapNode::~MapNode()
{

}

void MapNode::render(Rectangle* view, Graphics* g)
{
    if(overlapsMap()) // COLLISION = RED
    {
        g->drawRect(getX() - view->getX(), getY() - view->getY(),
                getWidth(), getHeight(), 255, 0, 0);
    }
    else if (onTile()) // ONTOP = CYAN
    {
        g->drawRect(getX() - view->getX(), getY() - view->getY(),
                getWidth(), getHeight(), 0, 255, 255);
    }
    else if (underTile()) // ONBOT = GREEN
    {
        g->drawRect(getX() - view->getX(), getY() - view->getY(),
            getWidth(), getHeight(), 0, 255, 0);
    }
    else // DEFAULT = BLUE
    {
        g->drawRect(getX() - view->getX(), getY() - view->getY(),
            getWidth(), getHeight(), 0, 0, 255);
    }
}   

bool MapNode::overlapsMap()
{
    if(map == NULL)
        return false;

    for(int x = getX(); x < getX2(); x+= map->getTileWidth())
    {
        for(int y = getY(); y < getY2(); y+= map->getTileHeight())
        {
            if(map->checkSolid(x/map->getTileWidth(), y/map->getTileHeight()))
            {
                return true;
            }
        }

        if(map->checkSolid(x/map->getTileWidth(), getY2()/map->getTileHeight()))
        {
            return true;
        }
    }

    for (int y = getY(); y < getY2(); y += map->getTileHeight())
    {
        if(map->checkSolid(getX2()/map->getTileWidth(), y/map->getTileHeight()))
        {
            return true;
        }
    }

    return map->checkSolid(getX2()/map->getTileWidth(), getY2()/map->getTileHeight());
}

void MapNode::move(float x, float y)
{
    if(!solid || map == NULL)
    {
        setX(getX() + x);
        setY(getY() + y);
        return;
    }

    setX(getX() + x);

    if(x < 0)
    {
        if(overlapsMap())
        {
            setX( ((int)(getX() / map->getTileWidth()) + 1) * map->getTileWidth() );
        }
    }

    if(x > 0)
    {
        if(overlapsMap())
        {
            setX2( (int)(getX2()/map->getTileWidth()) * map->getTileWidth() - 1 );
        }
    }

    setY(getY() + y);

    if(y < 0)
    {
        if(overlapsMap())
        {
            setY( (int)((getY()/map->getTileHeight()) + 1) * map->getTileHeight() );
        }
    }

    if(y > 0)
    {
        if(overlapsMap())
        {
            setY2( (int)(getY2()/map->getTileHeight()) * map->getTileHeight() - 1 );
        }
    }
}

bool MapNode::onTile()
{
    if (map == NULL)
        return false;

    if (tileBelow())
    {
        if (getY2() == ( (int)(getY2() / map->getTileHeight() + 1) * map->getTileHeight() - 1)) return true;
    }

    return false;
}

bool MapNode::underTile()
{
    if (map == NULL)
        return false;

    if (tileAbove())
    {
        if (getY() == ((int)(getY() / map->getTileHeight()) * map->getTileHeight()))
        {
            return true;
        }
    }

    return false;
}

bool MapNode::tileAbove() // Is there a solid above my x position?
{
    return ((map->checkSolid((int)(getX() / map->getTileWidth()), (int)(getY() / map->getTileHeight() - 1)) ||
            (map->checkSolid((int)(getX2() / map->getTileWidth()), (int)(getY() / map->getTileHeight() - 1)))));
}

bool MapNode::tileBelow() // Is there a solid below my x position?
{
    return ((map->checkSolid((int)(getX() / map->getTileWidth()), (int)(getY2() / map->getTileHeight() + 1)) ||
            (map->checkSolid((int)(getX2() / map->getTileWidth()), (int)(getY2() / map->getTileHeight() + 1)))));
}

bool MapNode::tileLeft() // Is there a solid to the left of my x position?
{
    return ((map->checkSolid((int)(getX() / map->getTileWidth() - 1), (int)(getY2() / map->getTileHeight())) ||
            (map->checkSolid((int)(getX2() / map->getTileWidth() - 1), (int)(getY2() / map->getTileHeight())))));
}

bool MapNode::tileRight() // Is there a solid to the right of my x position?
{
    return ((map->checkSolid((int)(getX() / map->getTileWidth() + 1), (int)(getY2() / map->getTileHeight())) ||
            (map->checkSolid((int)(getX2() / map->getTileWidth() + 1), (int)(getY2() / map->getTileHeight())))));
}

bool MapNode::overlapsNode(SceneNode* other)
{
    if (getX() > other->getX2())
        return false;

    if (getY() > other->getY2())
        return false;

    if (other->getX() > getX2())
        return false;

    if (other->getY() > getY2())
        return false;
    return true;
}

bool MapNode::onNode()
{
    std::list<SceneNode*>::iterator it;
    for (it = scene->getNodes()->begin(); it != scene->getNodes()->end(); it++)
    {
        if ((*it) != this &&
            ((getX() < (*it)->getX2() && getX2() > (*it)->getX2()) ||
            (getX2() > (*it)->getX() && getX() < (*it)->getX() ||
            (!(getX() < (*it)->getX()) && !(getX2() > (*it)->getX2())))))
        {
            if (getY2() == (*it)->getY() - 1) return true;
        }
    }
    return false;
}

bool MapNode::underNode()
{
    std::list<SceneNode*>::iterator it;
    for (it = scene->getNodes()->begin(); it != scene->getNodes()->end(); it++)
    {
        if ((*it) != this &&
            ((getX() < (*it)->getX2() && getX2() > (*it)->getX2()) ||
            (getX2() > (*it)->getX() && getX() < (*it)->getX() ||
            (!(getX() < (*it)->getX()) && !(getX2() > (*it)->getX2())))))
        {
            if (getY() == (*it)->getY2()) return true;
        }
    }
    return false;
}

SceneNode* MapNode::overlapsType(int type)
{
    std::list<SceneNode*>::iterator it;
    for (it = scene->getNodes()->begin(); it != scene->getNodes()->end(); it++)
    {
        if ((*it) != this && (*it)->getID() == type && this->overlapsNode((*it)))
        {
            return (*it);
        }
    }
    return NULL;
}