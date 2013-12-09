#ifndef ICONTEXT_H
#define ICONTEXT_H

#include <hge.h>

#include "resourcemanager.h"

namespace NeonHockey
{

    struct IContextData
    {
        int screenWidth;
        int screenHeight;
        virtual ~IContextData() {}
    };

    class IContext
    {
    public:
        IContext(HGE* hge, ResourceManager* rm, IContextData* data)
            : _hge(hge),
              _rm(rm),
              _data(data)
        { }

        virtual void show() = 0;
        virtual void frameFunc() = 0;
        virtual void renderFunc() = 0;
    protected:
        HGE* _hge;
        ResourceManager* _rm;
        IContextData* _data;
    };

}

#endif // ICONTEXT_H