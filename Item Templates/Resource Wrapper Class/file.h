#pragma once

namespace $rootnamespace$ {
    class $itemname$ final {
    public:
        using WrappedType = #error REPLACE WITH PROPER WRAPPED TYPE

        $itemname$();

        explicit $itemname$(WrappedType resource);
        ~$itemname$();

        // Resource types can not be copied

        $itemname$(const $itemname$&) = delete;
        $itemname$& operator=(const $itemname$&) = delete;

        // But can be moved

        $itemname$($itemname$&& other);
        $itemname$& operator=($itemname$&& other);

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        operator WrappedType() const;

        WrappedType Unwrap() const;

        // Force releasing the resource
        void Release();

        WrappedType* p_value();

        const WrappedType* p_value() const;

        static const WrappedType s_invalidValue;

    private:
        WrappedType m_resource;
    };
}
