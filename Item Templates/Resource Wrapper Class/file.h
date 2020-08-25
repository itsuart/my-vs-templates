#pragma once

namespace $rootnamespace$ {

    class $itemname$ final {
    public:
        using Resource = #error REPLACE WITH PROPER WRAPPED TYPE

        constexpr $itemname$() : _resource(invalidValue){}

        explicit constexpr $itemname$(Resource value) : _resource(value){}

        ~$itemname$(){
           release();
        }

        // Resource types can not be copied

        $itemname$(const $itemname$&) = delete;
        $itemname$& operator=(const $itemname$&) = delete;

        // But can be moved

        $itemname$($itemname$&& other)
        : _resource(other._resource)
        {
            other._resource = invalidValue;
        }

        $itemname$& operator=($itemname$&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const {
            return ok();
        }

        // returns true iff wrapped resource is valid
        bool ok() const {
            return _resource != invalidValue;
        }

        operator Resource() const{
            return _resource;
        }

        Resource value() const{
            return _resource;
        }

        // Force release the resource
        void release();

        Resource* p_value(){
            return &_resource;
        }

        const Resource* p_value() const{
            return &_resource;
        }

#error  REPLACE WITH PROPER INVALID VALUE
        static constexpr Resource invalidValue = nullptr;

    private:
        Resource _resource;
    };
}
