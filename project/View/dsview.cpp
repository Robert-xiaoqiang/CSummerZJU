#include "dsview.h"

State state;

DSView::DSView()
{
    spTCN = shared_ptr<ICommandNotification>(new TreeCommandNotification(this));
    spTPN = shared_ptr<IPropertyNotification>(new TreePropertyNotification(this));

    viewStart.setView(this);
    viewDraw.setView(this);

    state = start;
    viewStart.flashShow(1000);
}

DSView::~DSView()
{
}

StartMenu * DSView::getStartMenu()
{
    return &viewStart;
}

DrawWindow * DSView::getDrawWindow()
{
    return &viewDraw;
}

std::shared_ptr<ICommandNotification> DSView::getTreeCommandNotification()
{
    return spTCN;
}

std::shared_ptr<IPropertyNotification> DSView::getTreePropertyNotification()
{
    return spTPN;
}
