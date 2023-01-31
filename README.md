# pycritty
Pseudo-code interpreter using Bison and Flex as lexical and syntactic processors.

## What it consists of

The interpreter works in a similar way to some currently popular languages such as JavaScript or Python, i.e. it does not compile the code and translate the commands into machine code, it is the interpreter that controls the correct flow of the code at runtime.

The delivered version, pycritty v1.0 contains numeric, alphanumeric, boolean types and a primitive version of dynamically typed dynamic arrays. These allow assignments, arithmetic, logical and alphanumeric operations, loops of different types and auxiliary terminal control functions, such as colour and font control, screen clearing and cursor positioning.

Future versions of Pycritty should finish extending the grammar of vectors such as operators, concatenation and others. Likewise, allowing the declaration of structures and adding some basic ones such as enumerations or lists would be the logical step to take.
