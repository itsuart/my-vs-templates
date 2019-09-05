#pragma once
#include <type_traits>

namespace $rootnamespace$ {

    class $itemname$ final {
    public:
        using WrappedType = #error REPLACE WITH PROPER WRAPPED TYPE

        // Wraps over s_invalidValue
        $itemname$();

        explicit $itemname$(WrappedType resource);
        ~$itemname$();

        // Resource types can not be copied

        $itemname$(const $itemname$&) = delete;
        $itemname$& operator=(const $itemname$&) = delete;

        // But can be moved

        $itemname$($itemname$&& other) noexcept;
        $itemname$& operator=($itemname$&& other) noexcept;

        // returns true iff wrapped resource is valid
        explicit operator bool() const;

        // returns true iff wrapped resource is valid
        bool ok() const;

        operator WrappedType() const;

        WrappedType unwrap() const;

        // Force release the resource
        void release();

        WrappedType* p_value();

        const WrappedType* p_value() const;

        template<typename = std::enable_if<std::is_pointer<WrappedType>::value> >
        WrappedType operator->() {
            return m_resource;
        }

        template<typename = std::enable_if<std::is_pointer<WrappedType>::value> >
        const WrappedType operator->() const {
            return m_resource;
        }


        static const WrappedType s_invalidValue;

    private:
        WrappedType m_resource;
    };

} // namespace
