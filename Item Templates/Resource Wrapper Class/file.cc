#include "$itemname$.h"

namespace $rootnamespace$ {
    #error  REPLACE WITH PROPER INVALID VALUE
    const $itemname$::WrappedType $itemname$::s_invalidValue = nullptr;

    $itemname$::$itemname$()
    : m_resource(s_invalidValue)
    {}

    $itemname$::$itemname$(WrappedType resource)
    : m_resource(resource)
    {}

    $itemname$::~$itemname$(){
        Release();
    }

    void $itemname$::Release(){
        if (m_resource != s_invalidValue){
            #error CALL THE RESOURCE RELEASING FUNCTION HERE
            m_resource = s_invalidValue;
        }
    }

    $itemname$::$itemname$($itemname$&& other)
    : m_resource(other.m_resource)
    {
        other.Release();
    }

    $itemname$& $itemname$::operator=($itemname$&& other){
        if (&other == this) return *this;
        Release();
        m_resource = other.m_resource;
        other.Release();
    }

    // returns true iff wrapped resource is valid
    $itemname$::operator bool() const {
        return m_resource != s_invalidValue;
    }

    $itemname$::operator WrappedType() const{
        return m_resource;
    }

    $itemname$::WrappedType $itemname$::Unwrap() const {
        return m_resource;
    }

    $itemname$::WrappedType* $itemname$::p_value(){
        return &m_resource;
    }

    const $itemname$::WrappedType* $itemname$::p_value() const{
        return &m_resource;
    }
}
