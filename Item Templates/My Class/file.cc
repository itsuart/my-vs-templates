#include "$itemname$.h"

namespace $rootnamespace$ {
    $itemname$::$itemname$()
    {}

    $itemname$::~$itemname$()
    {}

    $itemname$::$itemname$(const $itemname$& other)
    {
#error implement or delete
    }

    $itemname$& $itemname$::operator=(const $itemname$&& other){
        if (&other == this){
            return *this;
        }
#error implement or delete
    }


    $itemname$::$itemname$($itemname$&& other)
    {
#error implement or delete
    }

    $itemname$& $itemname$::operator=($itemname$&& other){
        if (&other == this){
            return *this;
        }
#error implement or delete
    }

    // returns true iff wrapped resource is valid
    $itemname$::operator bool() const {
        return ok();
    }

    // returns true iff wrapped resource is valid
    bool $itemname$::ok() const{
#error implement or delete
    }
}
