#pragma once

namespace atom
{
    
    class GraphicsContext
    {
    public:
        virtual void StartFrame() = 0;
        virtual void EndFrame() = 0;
        //issue render command
    };

}