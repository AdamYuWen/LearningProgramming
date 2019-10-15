# C++ Notes
## Struct
1. Initializing default values for `struct`
    ```cpp
    struct testStruct {
        testStruct() : a(11), b(22) {}

        int a;
        int b;
        int c;
    };
    ```
    Explanation:
    - It initialized *a* as 11 and *b* as 22, not *c*.
    - From C++11, it can be done as following
    ```cpp
    struct testStruct {
        int a = 1;
        int b = 1;
        int c;
    }
    ```