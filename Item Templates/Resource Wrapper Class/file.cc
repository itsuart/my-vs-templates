#include "$itemname$.h"

namespace $rootnamespace$ {

    void $itemname$::release(){
        if (_resource != invalidValue){
            #error CALL THE RESOURCE RELEASING FUNCTION HERE
            _resource = _invalidValue;
        }
    }

    $itemname$& $itemname$::operator=($itemname$&& other){
        if (&other != this){
            release();
            _resource = other._resource;
            other._resource = invalidValue;
        }

        return *this;
    }
}
