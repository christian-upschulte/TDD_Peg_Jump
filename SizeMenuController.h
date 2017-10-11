#ifndef SIZE_MENU_CONTROLLER_H
#define SIZE_MENU_CONTROLLER_H

#include "SizeMenuController.h"
#include "SizeMenuView.h"


class SizeMenuController: public SizeMenuViewObserver{
    public:
        int sizeChoice;
    
        SizeMenuController(SizeMenuView &inSMView);
        void go();
        
        virtual void sizeRequested(int choice);
    
    private:
        SizeMenuView &sizeMenuView;
     
        
};

#endif