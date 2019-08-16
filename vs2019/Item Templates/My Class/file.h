#pragma once

namespace $rootnamespace$ {

    class $itemname$ final {
    public:
        explicit $itemname$();
        virtual ~$itemname$();

        $itemname$(const $itemname$& other) = delete;
        $itemname$& operator=(const $itemname$& other) = delete;

        $itemname$($itemname$&& other) = delete;
        $itemname$& operator=($itemname$&& other) = delete;

        // returns true if state of the object is valid
        explicit operator bool() const;

        // returns true if state of the object is valid
        bool ok() const;

    private:

    };
} // namespace
